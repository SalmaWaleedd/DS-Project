
/*******************************************************************
* File Name: compress.h
* Description: Header file that compress xml file
********************************************************************/
#pragma once
#ifndef COMPRESS_H
#define COMPRESS_H

#include <string>
#include <unordered_map>
#include "huffman.h"
#include <bitset>
#include <iostream>
#include <fstream>

using namespace std;




double calculateCompressionRatio(const string& original, const string& compressed);

unordered_map<char, int> calculateFrequencies(const string& input);


void compressAndWriteToFile(const string& input, const string& filePath, const string& fileName);
string compress(const string& input);

#endif // COMPRESS_H
