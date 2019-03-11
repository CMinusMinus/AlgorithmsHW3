#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h> 
#include <vector>
#include <set>

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
  for(int i = 0; i < numVerts; i++)
  {
    for(int j = 0; j < numVerts; j++)
    {
      printf("%i ", matrix.at(i).at(j));
    }
    printf("\n");
  }

  return 0;
}

int Diameter(vector<vector<int> > matrix) {
  // If the graph is connected, 
  // use BFS to find and return the length of
  // the longest shortest path between two nodes 
  // Else, return -1
}