#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector<int>adjmat[N];
bool visited[N];
void dfs(int u)
{  

    visited[u]= true;
    cout<<"visiting node: "<<u<<" "<<endl;
   
    for(int v: adjmat[u])
    {
  
        if(visited[v]== true) continue;
         dfs(v);
   
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
        dfs(1);
    
    return 0;
}
