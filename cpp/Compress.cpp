
/*******************************************************************
* File Name: compress.cpp
* Description: Source file that compress xml file
********************************************************************/
#include "compress.h"

unordered_map<char, int> calculateFrequencies(const string& input) {
     unordered_map<char, int> frequencies;
    for (char c : input) {
        frequencies[c]++;
    }
    return frequencies;
}
double calculateCompressionRatio(const string& original, const string& compressed) {
    return static_cast<float>(compressed.size()) / original.size();
}


void compressAndWriteToFile(const string& input, const string& filePath, const string& fileName) {
     unordered_map<char, int> frequencies = calculateFrequencies(input);
    HuffmanNode* root = buildHuffmanTree(frequencies);
     string compressed = compress(input);
    string path = filePath + "//" + fileName + ".bin";
    // Write Huffman tree to the file
    ofstream outFile(path, ios::binary);
    writeHuffmanTree(outFile, root);
    outFile.close();

    size_t padding = 8 - (compressed.size() % 8);

    // Write the number of padding bits to the file
     ofstream outFile2(path,  ios::binary |  ios::app);
    outFile2.put(static_cast<char>(padding));
    outFile2.close();

    // Add the padding bits
    compressed +=  string(padding, '0');

    // Convert every 8 bits to a character
   string groupedCompressed;
    for (size_t i = 0; i < compressed.size(); i += 8) {
         bitset<8> bits(compressed.substr(i, 8));
        groupedCompressed += static_cast<char>(bits.to_ulong());
    }

    // Write the modified compressed data to the file
     ofstream outFile3(path,  ios::binary |  ios::app);
    outFile3 << groupedCompressed;
    outFile3.close();

}




string compress(const string& input) {
    unordered_map<char, int> frequencies = calculateFrequencies(input);
    HuffmanNode* root = buildHuffmanTree(frequencies);
    unordered_map<char, string> codes;
    buildHuffmanCodes(root, "", codes);

    string compressed;
    for (char c : input) {
        compressed += codes[c];
    }

    return compressed;
}
