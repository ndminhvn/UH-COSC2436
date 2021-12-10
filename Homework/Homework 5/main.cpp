#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char* argv[]) {
	int numTeams, invalidPaths = 0, shouldMove = 0;
	cin >> numTeams;

	for (int j = 0; j < numTeams; j++) {
		int numVertices, v1, v2, weight, start;

		cin >> numVertices;

		Graph myGraph(numVertices);
		int i = 0;
		while (cin >> v1 >> v2 >> weight) {
			if (v1 == -1 && v2 == -1 && weight == -1) {
				break;
			}
			if (i == 0) {
				start = v1;
			}
			myGraph.insertEdge(v1, v2, weight);
			i++;
		}

		myGraph.DFS(start);

		if (!myGraph.edgeCheck()) {
			cout << "No path is formed from each location to every other" << endl << endl;
			invalidPaths++;

			myGraph.resetVisited();
			
         cin >> v1 >> v2 >> weight;
			myGraph.insertEdge(v1, v2, weight);
		}
		else {
			cout << "A path is formed!" << endl;

			myGraph.resetVisited();

			int origMST = myGraph.MST();

			myGraph.resetVisited();

			cin >> v1 >> v2 >> weight;
			myGraph.insertEdge(v1, v2, weight);
			int newMST = myGraph.MST();
			cout << "Original MST was: " << origMST << endl;
			cout << "New MST is: " << newMST << endl;

			if (origMST > newMST) {
				cout << "Employee's office should be moved" << endl << endl;
				shouldMove++;
			} else {
				cout << "Employee's office should NOT be moved" << endl << endl;
			}
		}
	}

	cout << "Number of employees' offices with invalid paths: " << invalidPaths << "/" << numTeams << endl;
	cout << "Number of employees who would benefit from moving offices: " << shouldMove << "/" << numTeams << endl;

	return 0;
}