#pragma once
#include <fstream>
#include <iostream>
#include <string>
#define NodeMaxCount 101
#define INF 2147483647 
using namespace std;

/////////////////////////////////////////////////////////
///  TODO: Add Your Struct or Functions if required /////

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

class Graph{
public:
    Graph() { };
    ~Graph() { };

    int addDirectedEdge(string nodeA, string nodeB);
    int addDirectedEdge(string nodeA, string nodeB, int weight);
    int addUndirectedEdge(string nodeA, string nodeB);
    int addUndirectedEdge(string nodeA, string nodeB, int weight);

    string DFS();
    int getTreeCount();
    string getStronglyConnectedComponent();
    string getDijkstraShortestPath(string source, string destination);
    string getFloydShortestPath(string source, string destination);
    int primMST(ofstream &, string startNode);
    int kruskalMST(ofstream &);


private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////
    int adjmat[NodeMaxCount][NodeMaxCount] = { 0, };
    string vertices[NodeMaxCount];
    int size=0;

    int matrix_dfs[NodeMaxCount][NodeMaxCount] = { 0, };
    string sort_dfs[NodeMaxCount];
    int check_dfs_include[NodeMaxCount] = { 0,};
    void _DFS(int index, string& result,int* check_dfs_include);
    void sorting();

    void floyd(int(*board)[NodeMaxCount], int i, int j, string &result);
    int floyd_mat[NodeMaxCount][NodeMaxCount];   //Floyd's algorithm

    void _dijkstra(int pre[], int i, string &result);
    int dijkstra_mat[NodeMaxCount][NodeMaxCount];

    void _SCC(int idx, int* check_include, int* connect);
    void _SCC_2(int idx, int* check_include, int* connect);
    int max_vertex = 0;
    int num_vertex = 0;
    int max_vertices[NodeMaxCount];
    int con_vertices[NodeMaxCount];
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};
