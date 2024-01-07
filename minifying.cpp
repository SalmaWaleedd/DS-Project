
/*******************************************************************
* File Name: minifying.cpp
* Description: Source file that minifying xml file
********************************************************************/


#include "minifying.h"


string minifying(const string input_text) {
    bool insideTag = false;
    bool insideAttributeValue = false;
    string minified_text;

    for (char c : input_text) {
        if (c == '<') {
            insideTag = true;
            insideAttributeValue = false;
        }
        else if (c == '>') {
            insideTag = false;
        }
        else if (c == '\"') {
            insideAttributeValue = !insideAttributeValue;
        }

        if (!insideTag && (c == ' ' || c == '\n' || c == '\r' || c == '\t')) {
            // Skip spaces and newlines outside tags, but only add one whitespace character
            if (!minified_text.empty() && minified_text.back() != ' ') {
                minified_text += ' ';
            }
            continue;
        }

        minified_text += c;
    }

    return minified_text;
}