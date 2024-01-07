
/*******************************************************************
* File Name: visualization.cpp
* Description: Header file that generate graph visualization
********************************************************************/

#include "visualization.h"

void generateDOTFile(vector<User*> users) {
    ofstream dotFile("Graph.dot");

    if (!dotFile.is_open()) {
        cout << "Error: Unable to open DOT file." << std::endl;
        return;
    }

    // Write DOT file content based on your graph structure
    dotFile << "digraph G {\n";
    dotFile << "node [ shape = \"record\"]" << endl;
    

    for (auto user : users) {
        dotFile << user->getId() << " [ label = \"{ " << user->getName() << " | " << "id = " << user->getId() << " " << "}\"]" << endl;
        dotFile << user->getId() << "->" << "{";
        auto followers = user->following;

        for (auto f_iter = followers.begin(); f_iter != followers.end(); ++f_iter) {
            dotFile << (*f_iter)->getId();

            // Add comma if it's not the last element
            if (next(f_iter) != followers.end()) {
                dotFile << ",";
            }
        }
        dotFile << "}\n";
      
    }
    dotFile << "}\n";
    dotFile.close();
    system("dot -Tpng Graph.dot -o Graph.png");
}