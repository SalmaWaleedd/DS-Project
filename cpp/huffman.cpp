
/*******************************************************************
* File Name: huffman.cpp
* Description: Source file that contains algorithm for compressing
               and decompressing
********************************************************************/

#include "huffman.h"


HuffmanNode::HuffmanNode(int val, int freq) : value(val), frequency(freq), left(nullptr), right(nullptr) {}

bool CompareNodes::operator()(const HuffmanNode* a, const HuffmanNode* b) const {
    return a->frequency > b->frequency;
}

HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& frequencies) {
    HuffmanPriorityQueue pq;

    for (auto& pair : frequencies) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* newNode = new HuffmanNode(0, left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    return pq.top();
}


void writeHuffmanTree(ofstream& outFile, HuffmanNode* root) {
    if (root) {
        outFile << '1';  // '1' indicates an internal node
        outFile.write(reinterpret_cast<const char*>(&root->value), sizeof(root->value));
        writeHuffmanTree(outFile, root->left);
        writeHuffmanTree(outFile, root->right);
    }
    else {
        outFile << '0';  // '0' indicates a leaf node
    }
}

HuffmanNode* readHuffmanTree(ifstream& inFile) {
    char bit;
    inFile.get(bit);
    if (bit == '1') {
        HuffmanNode* newNode = new HuffmanNode(0, 0);
        inFile.read(reinterpret_cast<char*>(&newNode->value), sizeof(newNode->value));
        newNode->left = readHuffmanTree(inFile);
        newNode->right = readHuffmanTree(inFile);
        return newNode;
    }
    else {
        return nullptr;
    }

}

void buildHuffmanCodes(HuffmanNode* root, const string& code,unordered_map<char,  string>& codes) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        codes[root->value] = code;
        return;
    }

    buildHuffmanCodes(root->left, code + "0", codes);
    buildHuffmanCodes(root->right, code + "1", codes);
}
