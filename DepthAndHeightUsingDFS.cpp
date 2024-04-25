#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int>adjmat[N];
bool visited[N];
int depth [N];
int height[N];
void dfs(int u)
{  

    visited[u]= true;
   // cout<<"visiting node: "<<u<<" "<<endl;
   
    for(int v: adjmat[u])
    {
  
        if(visited[v]== true) continue;
        depth[v]=depth[u]+1;
         dfs(v);
        height[u]=max(height[u],height[v]+1);
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
        for(int i=1;i<=vertex;i++)
        {
            cout<<"Depth of the Node "<<i<<": "<<depth[i]<<endl;
        }
        cout<<endl<<"_____________________________________"<<endl<<endl;
        for(int i=1;i<=vertex;i++)
        {
             cout<<"Height of the Node "<<i<<": "<<height[i]<<endl;
        }
    
    return 0;
}
