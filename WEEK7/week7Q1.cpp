#include <iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 9999999
struct Edge
{
    int to;
    int weight;
};
struct Node
{
    int id;
    int dist;
    bool operator >(const Node&other) const
    {
        return dist > other.dist;
    }

};
void dijkstra(vector<vector<Edge>>& graph, int source, vector<int>& distances)
{
    int n = graph.size();
    distances.assign(n,INF);
    vector<bool> visited(n,false);
    priority_queue<Node, vector<Node>, greater <Node>> pq;
    distances[source] = 0;
    pq.push({source,0});
    while(!pq.empty())
    {
        int u = pq.top().id;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(Edge& e : graph[u])
        {
            int v = e.to;
            int weight = e.weight;
            if(distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                pq.push({v,distances[v]});
            }
        }
    }
}
int main()
{
    int num_nodes,num_edges;
    cout<<"Enter number of nodes and edges"<<endl;
    cin>>num_nodes>>num_edges;
    vector<vector<Edge>> graph(num_nodes);
    cout<<"Enter Edges(source,destination,weight)"<<endl;
    for(int i=0;i<num_edges;i++)
    {
        int source,destination,weight;
        cin>>source>>destination>>weight;
        graph[source].push_back({destination,weight});
        graph[destination].push_back({source,weight});

    }
    vector<int> distances;
    dijkstra(graph,0,distances);
    for(int i=1;i<num_nodes;i++)
    {
        cout<<"Shortest distance from friend"<<i<<"to Akshay's house:"<<distances[i]<<endl;
    }

}
