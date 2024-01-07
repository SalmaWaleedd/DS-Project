
/*******************************************************************
* File Name: Parsing_graph.h
********************************************************************/
#ifndef PARSING_GRAPH_H
#define PARSING_GRAPH_H


#include "Graph.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Parsing_graph.h"
#include<vector>


using namespace std;

void ParsingXml(string fileContents , SocialNetwork * network);  // Use const reference for efficiency
int getUserNumber(string fileContents);
string removeLeadingSpaces(string input);

#endif // PARSING_H
