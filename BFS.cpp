#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector<int>adjmat[N];
bool visited[N];
int level[N];
void bfs(int s)
{  
  queue<int>q;
  q.push(s);
  visited[s]=true;
  level[s]=0;
  while(!q.empty())
  {
    int u=q.front();
    q.pop();
    cout<<"visiting node :"<<u<<endl;
  
  for(int v : adjmat[u])
  {
    if(visited[v]==true) continue;
    q.push(v);
    visited[v]=true;
    level [v]=level[u]+1;
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
        bfs(1);
        cout<<endl<<"_________________________________"<<endl<<endl;
        for(int i=1;i<=vertex;i++)
        {
            cout<<"Level of "<<i<<": "<<level[i]<<endl;
        }
    
    return 0;
}
