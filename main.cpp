#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h> 
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<int> BreadthFirstSearch(vector<vector<int> > graph, int vertex) {
  vector<int> visited(graph.size(), -1);
  // for (int i = 0; i < visited.size(); i++) {
  //   printf("Distance to %i: %i\n", i, visited[i]);
  // }
  queue<int> toVisit;
  int current = vertex;

  visited[vertex] = 0; //printf("%i", visited[vertex]);

  toVisit.push(vertex);

  while(!toVisit.empty()) {
    current = toVisit.front(); printf("%i", current);
    toVisit.pop();
    for (int i = 0; i < graph.size(); i++) {
      int isAdjacent = graph[current][i];
      if (isAdjacent == 1) {
        if (visited[i] < 0) {
          visited[i] = visited[current] + 1;
          toVisit.push(i);
        }
      }
    }
  }

  return visited;
}

int main(int argc, char ** argv) {
  int numVerts = atoi(argv[1]);
  printf("Number of Vertices: %i\n", numVerts);
  vector<vector<int> > matrix(numVerts, vector<int>(numVerts));

  for (int k = 0; k < (argc - 2)/2; k++) {
    int first = atoi(argv[k * 2 + 2]);
    int second = atoi(argv[k * 2 + 3]);
    printf("Edge created: %i, %i\nNumber of edges: %i\n", first, second, k+1);
    // cout << "Edge created: [" << argv[k*2 + 1] >> ", " << argv[(k+1) * 2] << "]" << endl;
    matrix.at(first).at(second) = 1;
    matrix.at(second).at(first) = 1;
  }

  cout << "Adjacency matrix:" << endl;
  for(int i = 0; i < numVerts; i++)
  {
    for(int j = 0; j < numVerts; j++)
    {
      printf("%i ", matrix.at(i).at(j));
    }
    printf("\n");
  }

  vector<int> bfsTest = BreadthFirstSearch(matrix, 0);
  printf("Breadth First Search From 0:\n");
  for (int i = 0; i < bfsTest.size(); i++) {
    printf("Distance to %i: %i\n", i, bfsTest[i]);
  }

  return 0;
}

int Diameter(vector<vector<int> > matrix) {
  // If the graph is connected, 
  // use BFS to find and return the length of
  // the longest shortest path between two nodes 
  // Else, return -1
}