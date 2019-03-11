#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h> 
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

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
  for(int i = 0; i < numVerts; i++) {
    for(int j = 0; j < numVerts; j++)
    {
      printf("%i ", matrix.at(i).at(j));
    }
    printf("\n");
  }

  return 0;
}

vector<int> BFS(vector<vector<int> > matrix, int s) {
  //
}

int Diameter(vector<vector<int> > matrix) {
  // If the graph is connected, 
  // use BFS to find and return the length of
  // the longest shortest path between two nodes 
  // Else, return -1
  int diameter = 0;
  for(int i = 0; i < matrix.size(); i++) {
    vector<int> visited = BFS(matrix, i);
    int disconnected = count(visited.begin(), visited.end(), 0);
    int max = *max_element(visited.begin(), visited.end());
    if (disconnected > 1) {
      diameter = -1; 
      break;
    } else if (max > diameter) {
      diameter = max;
    }
  }
  
  return diameter;
}

void Components(vector<vector<int> > matrix) {
  // If the graph was disconnected,
  // use BFS from 0-n to find all separate parts of the graph,
  // and print out the list of vertices in each part.
}