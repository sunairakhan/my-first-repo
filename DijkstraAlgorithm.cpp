#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+5;
const int INF = 1e9+10;
vector<pii>adj[N];
vector<int>dis(N,INF);
vector<bool>visited(N);
void dijkstra( int source)
{
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    dis[source] = 0;
    pq.push({dis[source],source});

    while (!pq.empty())
    {
       int u = pq.top().second;
       pq.pop();
       visited[u] = true; 
       for( pii vpair : adj[u])
       {
            int v = vpair.first;
            int w = vpair.second;
            if(visited[v]) continue;

            if(dis[v]> dis[u]+w)
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v],v});
            }
       }
    }
    
}
int main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    for(int i=0;i<edge;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    dijkstra(1);
    for(int i=1;i<=vertex;i++)
    {
        cout<<"Distance of Node : "<<i<<": ";
        cout<<dis[i]<<endl;
    }
    

    return 0;
}
