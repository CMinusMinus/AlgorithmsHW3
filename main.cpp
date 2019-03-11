#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h> 
#include <vector>
#include <set>

using namespace std;

int main(int argc, char ** argv) {
  std::vector<int>* vertices = new std::vector<int>();
  set<int*>* edges = new set<int*>();

  int numVerts = atoi(argv[1]);
  printf("Number of Vertices: %i\n", numVerts);
  for (int i = 0; i < numVerts; i++) {
    vertices->push_back(i);
  }

  for (int j = 0; j < (argc - 2)/2; j++) {
    int* edgeToAdd = new int;
    int first = atoi(argv[j * 2 + 2]);
    int second = atoi(argv[j * 2 + 3]);
    if (first < second) {
      edgeToAdd[0] = atoi(argv[j * 2 + 2]);
      edgeToAdd[1] =  atoi(argv[j * 2 + 3]);
    } else {
       edgeToAdd[0] =  atoi(argv[j * 2 + 3]);
      edgeToAdd[1] = atoi(argv[j * 2 + 2]);
    }
    edges->insert(edgeToAdd);
    printf("Edge created: %i, %i\nNumber of edges: %i\n", edgeToAdd[0], edgeToAdd[1], edges->size());
    // cout << "Edge created: [" << argv[j*2 + 1] >> ", " << argv[(j+1) * 2] << "]" << endl;
  }

  return 0;
}