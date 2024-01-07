/*******************************************************************
* File Name: prettifying.cpp
* Description: Source file that prettify xml file 
********************************************************************/


#include "prettifying.h"


string prettifying(const string input) {
    string output;
    int indentLevel = 0;

    size_t pos = 0;
    while (pos < input.size()) {
        size_t startTag = input.find('<', pos);
        size_t endTag = input.find('>', startTag);

        if (startTag != string::npos && endTag != string::npos) {
            string tag = input.substr(startTag, endTag - startTag + 1);

            if (tag.find("</") != string::npos) {
                --indentLevel;
            }

            for (int i = 0; i < indentLevel; ++i) {
                output += "    ";  // 4 spaces for each level of indentation
            }

            output += tag;

            size_t nextTagStart = input.find('<', endTag);
            if (nextTagStart != string::npos) {
                string data = input.substr(endTag + 1, nextTagStart - endTag - 1);

                // Trim leading and trailing whitespaces
                size_t first = data.find_first_not_of(" \t\n\r\f\v");
                size_t last = data.find_last_not_of(" \t\n\r\f\v");

                if (first != string::npos && last != string::npos) {
                    data = data.substr(first, last - first + 1);

                    output += '\n'; // Move the newline here
                    for (int i = 0; i <= indentLevel; ++i) {
                        output += "    ";  // Indentation for data
                    }
                    output += data;
                }
            }

            if (tag.find("</") == string::npos) {
                ++indentLevel;
            }

            output += '\n';

            pos = endTag + 1;
        }
        else {
            // No more tags found, copy the remaining content as is
            output += input.substr(pos);
            break;
        }
    }

    return output;
}
