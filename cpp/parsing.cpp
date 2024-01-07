
/*******************************************************************
* File Name: parsing.cpp
* Description: Source file that parse xml file into a string
********************************************************************/


#include "parsing.h"


/*******************************************************************
* Name: ReadXml
* paramters: file path
* Return Type: string
* Description: Parse xml file into a string
********************************************************************/

string ReadXml(string filePath) {

    // Open the file
    ifstream inputFile(filePath);

    // Check if the file is open
    if (!inputFile.is_open()) {
        return "error";
    }
    // Read the file content into a stringstream
    stringstream buffer;
    buffer << inputFile.rdbuf();

    // Close the file
    inputFile.close();

    // Extract the content from the stringstream
    string fileContent = buffer.str();

    // Display the content (you can remove this in your final code)
    return fileContent;
}