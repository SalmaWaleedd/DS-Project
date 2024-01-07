
/*******************************************************************
* File Name: Decompress.h
* Description: Source file that decompress xml file
********************************************************************/

#include "decompress.h"


string decompress(const string& compressed, HuffmanNode* root) {
    string decompressed;
    HuffmanNode* currentNode = root;

    for (char bit : compressed) {
        if (bit == '0') {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }

        if (!currentNode->left && !currentNode->right) {
            decompressed += static_cast<char>(currentNode->value);
            currentNode = root;
        }
    }
    return decompressed;
}





string readAndDecompressFromFile(const  string& fileName) {
     ifstream inFile(fileName,  ios::binary);

    // Read Huffman tree from the file
    HuffmanNode* decompressionRoot = readHuffmanTree(inFile);
    unsigned char padding_n;
    inFile.read(reinterpret_cast<char*>(&padding_n), sizeof(unsigned char));

     string compressedFromFile;
    char byte;
    while (inFile.get(byte)) {
        compressedFromFile += byte;
    }

    inFile.close();

    // Convert each character back to 8 bits
     string decompressedBits;
    for (size_t i = 0; i < compressedFromFile.size(); i++) {
         bitset<8> bits(static_cast<unsigned char>(compressedFromFile[i]));

        // Include all bits if it's not the last byte, otherwise exclude padding bits
        size_t bitsToRead = (i == compressedFromFile.size() - 1) ? (8 - padding_n) : 8;
        decompressedBits += bits.to_string().substr(0, bitsToRead);
    }

    // Decompress the data
    return decompress(decompressedBits, decompressionRoot);
}
