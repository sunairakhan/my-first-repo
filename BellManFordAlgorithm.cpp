#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
const int INF = 1e9+7;
typedef pair<int,int> pii;
vector<pii>adj[N];
int dis[N];
int vertex,edge;
vector<pair<pii,int>>list_of_edges;
void bellmanford( int s)
{
    for(int i=1;i<=vertex;i++)
        dis[i]=INF;

        dis[s]=0;

        for(int i=1;i<vertex;i++)
        {
            for(int u=1;u<=vertex;u++)  //list of edges use korle ay 2ta loop er poriborte 
            {                           //use kora jabe akta list loop
                for(pii vpair : adj[u]) //for(auto edge : list_of_edges)
                {
                    int v = vpair.first;  // int u = edge.first .first;
                    int w = vpair.second;   // int v = edge .first .second;
                                            //int w = edge.second;
                    if(dis[u]!= INF && dis[v]>dis[u]+w) //ayta same thakbe ar same output asbe
                    {
                        dis[v]= dis [u]+w;
                    }
                }
            }
        }
}
int main()
{

    cin>>vertex>>edge;
    for(int i=0;i<edge;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});//graph e eyvabe push na kore ayvebe korle akta loop e kaj kora jai
        list_of_edges.push_back({{a,b},w});
        
    }
        bellmanford(1);

        for(int i=1;i<=vertex;i++)
        {
            cout<<"distance of "<<i<<": ";
            cout<<dis[i]<<" "<<endl;
        }
    

    return 0;
}
