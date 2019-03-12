#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h> 
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> BreadthFirstSearch(vector<vector<int> > graph, int vertex) {
  vector<int> visited(graph.size(), -1);

  queue<int> toVisit;
  int current = vertex;

  visited[vertex] = 0; //printf("%i", visited[vertex]);

  toVisit.push(vertex);

  while(!toVisit.empty()) {
    current = toVisit.front();
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

int Diameter(vector<vector<int> > matrix) {
  // If the graph is connected, 
  // use BFS to find and return the length of
  // the longest shortest path between two nodes 
  // Else, return -1
  int diameter = 0;
  for(int i = 0; i < matrix.size(); i++) {
    vector<int> visited = BreadthFirstSearch(matrix, i);
    int max = *max_element(visited.begin(), visited.end());
    int min = *min_element(visited.begin(), visited.end());
    if (min < 0) {
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
  vector<int> visited(matrix.size());

  printf("Components:\n");

  for (int i = 0; i < matrix.size(); i++) {
    if (visited[i] == 0) {
      visited[i] = 1;
      vector<int> component = BreadthFirstSearch(matrix, i);
      printf ("{ ");
      for (int j = 0; j < component.size(); j++) {
        if (component[j] >= 0) {
          visited[j] = 1;
          printf("%i ", j);
        }
      }
      printf("}\n");
    }
  }
}

int main(int argc, char ** argv) {
  int numVerts = atoi(argv[1]);
  // printf("Number of Vertices: %i\n", numVerts);
  vector<vector<int> > matrix(numVerts, vector<int>(numVerts));

  for (int k = 0; k < (argc - 2)/2; k++) {
    int first = atoi(argv[k * 2 + 2]);
    int second = atoi(argv[k * 2 + 3]);
    // printf("Edge created: %i, %i\nNumber of edges: %i\n", first, second, k+1);
    matrix[first][second] = 1;
    matrix[second][first] = 1;
  }

  cout << "Adjacency matrix:" << endl;
  for(int i = 0; i < numVerts; i++) {
    for(int j = 0; j < numVerts; j++)
    {
      printf("%i ", matrix[i][j]);
    }
    printf("\n");
  }

  int diameter = Diameter(matrix);

  if (diameter < 0) {
    Components(matrix);
  } else {
    printf("Diameter of G = %i\n", diameter);
  }
  
  return 0;
}


