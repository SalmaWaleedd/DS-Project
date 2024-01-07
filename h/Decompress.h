
/*******************************************************************
* File Name: Decompress.h
* Description: Header file that decompress xml file
********************************************************************/
#pragma once
#ifndef DECOMPRESS_H
#define DECOMPRESS_H


#include <string>
#include "huffman.h"
#include <bitset>
#include <iostream>
#include <fstream>

using namespace std;


string decompress(const string& compressed, HuffmanNode* root);
string readAndDecompressFromFile(const string& fileName);

#endif // DECOMPRESS_H
