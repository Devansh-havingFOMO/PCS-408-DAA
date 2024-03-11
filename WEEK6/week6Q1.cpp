#include <iostream>
#include<vector>
using namespace std;
bool ispath(const vector<vector<int>>&graph,int source,int destination,vector<bool>& visited)
{
    if(source == destination)
    {
        return true;
    }
    visited[source] = true;
    for(int i=0;i < graph[source].size();i++)
    {
        if(graph[source][i] == 1 && !visited[i])
        {
            if(ispath(graph,i,destination,visited))
            {
                return true;
            }
        }
    }
    return false;
}
void pathexist(const vector<vector<int>>& graph,int source,int destination)
{
    int numVertices  = graph.size();
    vector<bool> visited(numVertices, false);
    if(ispath(graph,source,destination,visited))
    {
        cout<<"Yes Path exists."<<endl;
    }
    else
    {
        cout<<"No such path exists."<<endl;
    }
}
int main()
{
    vector<vector<int>> adjancencyMatrix = 
    {
        {0,1,0,0},
        {0,0,1,1},
        {0,0,0,1},
        {0,0,0,0}
    };
    
    int sourceVertex = 0;
    int destinationVertex = 0;
    pathexist(adjancencyMatrix,sourceVertex,destinationVertex);
    return 0;
}
    
