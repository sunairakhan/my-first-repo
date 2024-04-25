#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector<pair<int,int>>adjmat[N];
int main()
{
   // int adjmat[100][100];
   int vertex,edge;
   cin>>vertex>>edge;
    for(int i=0;i<edge;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adjmat[a].push_back({b,w});
        //adjmat[b].push_back({a,w});
    }
    
    for(int i=1;i<=vertex;i++)
    {
        cout<<"list"<<" "<<i<<" "<<":";
        for(auto j:adjmat[i])
        {
            cout<<"("<<j.first<<","<<j.second<<"),"<<" ";
        }
        cout<<endl;
    }

    return 0;
}
