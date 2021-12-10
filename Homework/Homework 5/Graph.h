#pragma once
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Graph {
private:
	vector<vector<int>> matrix;
	int size;
	vector<bool> visited;

public:
	Graph(int mySize) {
		size = mySize;
		matrix.resize(size, vector<int>(size));
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				matrix[i][j] = -1;
			}
		}
		visited.resize(size);
		fill(visited.begin(), visited.end(), false);
	}

	void resetVisited() {
		fill(visited.begin(), visited.end(), false);
	}

	void insertEdge(int v1, int v2, int weight) {
		matrix[v1][v2] = weight;
		matrix[v2][v1] = weight;
	}

	void DFS(int vertex) {
		visited[vertex] = true;
		for (int i = 0; i < size; i++) {
			if (matrix[vertex][i] != -1 && !visited[i]) {
				DFS(i);
			}
		}
	}

	bool edgeCheck() {
		for (int i = 0; i < size; i++) {
			if (!visited[i]) {
				return false;
			}
		}

		return true;
	}

	int MST() {
		int numEdges = 0;
		visited[0] = true;
		int row, col, span = 0;

		while (numEdges < size - 1) {
			int min = INT_MAX;
			row = col = 0;

			for (int i = 0; i < size; i++) {
				if (visited[i]) {
					for (int j = 0; j < size; j++) {
						if (!visited[j] && matrix[i][j] != -1) {
							if (min > matrix[i][j]) {
								min = matrix[i][j];
								row = i;
								col = j;
							}
						}
					}
				}
			}

			span += matrix[row][col];
			visited[col] = true;
			numEdges++;
		}

		return span;
	}
};