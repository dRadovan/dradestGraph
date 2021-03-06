#ifndef DRADEST_GRAPH_H
#define DRADEST_GRAPH_H

#include <vector>

// undirected graph using adjacency list representation
class dradestGraph 
{ 
private:

     int V; // number of vertices 

     // subset for union-find algorithm
     struct subset {
          int parent, rank;
     };

     // Pointer to an array containing adjacency lists 
     std::vector<int> *adj;    

     // helper function used by recursiveDFS()
     void helpDFS(int n, bool visited[], std::vector<int>* dfs);
     // helper function to detect a cycle reachable from n
     bool helpCycle(int n, bool visited[], int parent);
     // helper functions to use in union-find
     int find(struct subset subsets[], int i);
     void Union(struct subset subsets[], int x, int y);
     // helper function to use in Dijkstra's algorithm
     // returns node with minimum distance value from nodes not yet included in shortest path tree
     int minDistance(int distance[], bool included[]);

public: 

     // constructor
     dradestGraph(int x);
     // copy constructor
     dradestGraph(const dradestGraph& drg);
     // destructor
     ~dradestGraph();
     // utility function to add an edge between u and w
     void addEdge(int u, int w);
     // utility function to print the adjacency list representation of the graph
     void printGraph();
     // utility function to perform a breadth first search starting from node n
     std::vector<int> BFS(int n);
     // utility function to perform a depth first search starting from node n, iteratively
     std::vector<int> iterativeDFS(int n);
     // utility function to perform a depth first search starting from node n, recursively
     std::vector<int> recursiveDFS(int n);
     // utility function to detect a cycle in the graph based on DFS
     bool hasCycle();
     // utility function that uses union-find to detect a cycle in the graph
     bool containsCycle();
     // utility function to find minimum spanning tree using Prim's algorithm
     std::vector<int>* primMST();
     // utility function to find minimum spanning tree using Kruskal's algorithm
     std::vector<int>* kruskalMST();
     // utility function to find shortest paths tree from root using Dijkstra's algorithm 
     void dijkstraSPT(int root);

}; 

#endif