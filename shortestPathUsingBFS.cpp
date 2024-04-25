#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector<int>adjmat[N];
bool visited[N];
int level[N];
int parent[N];
void bfs(int s)
{  
  queue<int>q;
  q.push(s);
  visited[s]=true;
  level[s]=0;
  parent[s]=-1;
  while(!q.empty())
  {
    int u=q.front();
    q.pop();
    //cout<<"visiting node :"<<u<<endl;
  
  for(int v : adjmat[u])
  {
    if(visited[v]==true) continue;
    q.push(v);
    visited[v]=true;
    level [v]=level[u]+1;
    parent[v]= u;
  }
  }
}
int main()
{
   int vertex,edge;
    cin>>vertex>>edge;
    for(int i=0;i<edge;i++)
    {
        int a,b;
        cin>>a>>b;
        adjmat[a].push_back(b);
        adjmat[b].push_back(a);
    }
       int source,destination;
       cin>>source>>destination;
       bfs(source);
       cout<< "Distance " <<level[destination]<<endl;
       vector<int>path;
       int current = destination;
       while(current != -1)
       {
          path.push_back(current);
          current = parent[current];
       }
       reverse(path.begin(),path.end());
       cout<<"Path : ";
       for(int node : path )
       {
         cout<<node<<" ";
       }

    return 0;
}
