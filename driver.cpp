// driver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "KruskalMST/driver.h"
#include "TopologicalOrdering/driver.h"
#include "DijkstraShortestPath/driver.h"
//#include "TransitiveClosure/driver.h"
//#include "DFS/driver.h"

using namespace std;

int main()
{
    int option;
    string options = "Please enter the number for the program to run\n";
           options += "0. To Exit\n";
           options += "1. KruskalMST\n";
           options += "2. TopologicalOrdering\n";
           options += "3. DijkstraShortestPath\n";
           options += "4. TransitiveClosure\n";
           options += "5. DFS\n";

    cout << options << ">";
    cin >> option;

    while (option != 0) {
        switch (option) {
        case 1:
            kruskalMSTMain();
            break;
        case 2:
            topologicalOrderingMain();
            break;
        case 3:
            dijkstraShortestPathMain();
            break;
        case 4:
            //transitiveClosureMain();
            break;
        case 5:
            //dfsMain();
            break;
        default:
            cout << "Invalid Option (" << option << ")\n";
            break;
        }

        cout << "End.\n\n";

        cout << options << ">";
        cin >> option;
    }

}