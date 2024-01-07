
/*******************************************************************
* File Name: parsing.h
* Description: Header file that parse xml file into a string
********************************************************************/
#pragma once
#ifndef PARSING_H
#define PARSING_H

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


/*******************************************************************
* Name: ReadXml
* paramters: file path
* Return Type: string
* Description: Parse xml file into a string
********************************************************************/

string ReadXml(string filePath);



#endif
