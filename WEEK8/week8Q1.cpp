#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<unordered_map>
using namespace std;
typedef pair<int,int> pii;

int prim(const unordered_map<int, vector<pii>>& graph)
{
    int total_cost = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(graph.size(), false);
    int start_vertex = graph.begin()->first;
    visited[start_vertex] =  true;
    for(const auto&neighbor : graph.at(start_vertex))
    {
        pq.push(neighbor);
    }
    while(!pq.empty())
    {
        pii edge = pq.top();
        pq.pop();
        int u = edge.second;
        int weight = edge.first;
        if(!visited[u])
        {
            visited[u] = true;
            total_cost += weight;
            for(const auto&neighbor : graph.at(u))
            {
                if(!visited[neighbor.second])
                {
                    pq.push(neighbor);
                }
            }
        }
    }
    return total_cost;
}

int main()
{
    int num_cities , num_roads;
    cout<<"Enter the number of cities and roads";
    cin>> num_cities >> num_roads;
    unordered_map<int, vector<pii>> graph;
    cout<<"Enter the roads as 'city1 city2 cost':"<<endl;
    for(int i=0; i<num_roads ;++i )
    {
        int city1, city2, cost;
        cin>>city1>>city2>>cost;
        graph[city1].push_back({cost,city2});
        graph[city2].push_back({cost,city1});
    }
    int min_cost = prim(graph);
    cout<< min_cost;
}
