#ifndef PARSING_H
#define PARSING_H

#include <string>
#include "Graph.h"

using namespace std;

void ParsingXml(string fileContents , SocialNetwork * network);  // Use const reference for efficiency
int getUserNumber(string fileContents);
string removeLeadingSpaces(string input);

#endif // PARSING_H
