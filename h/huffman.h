
/*******************************************************************
* File Name: huffman.h
* Description: Header file that contains algorithm for compressing
               and decompressing
********************************************************************/
#pragma once
#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <unordered_map>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;
struct HuffmanNode {
    int value;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(int val, int freq);
};

struct CompareNodes {
    bool operator()(const HuffmanNode* a, const HuffmanNode* b) const;
};

using HuffmanPriorityQueue = 





priority_queue<HuffmanNode*, 
    
    
    vector<HuffmanNode*>, CompareNodes>;

HuffmanNode* buildHuffmanTree(const  unordered_map<char, int>& frequencies);

void writeHuffmanTree(ofstream& outFile, HuffmanNode* root);
HuffmanNode* readHuffmanTree(ifstream& inFile);
void buildHuffmanCodes(HuffmanNode* root, const  string& code,  unordered_map<char,  string>& codes);

#endif // HUFFMAN_H
