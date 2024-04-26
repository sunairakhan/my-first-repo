#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int m, int r)
{
    int leftsize = m-l+1;
    int rightsize = r - m;
    int L[leftsize], R[rightsize];
    int k=0;
    for(int i=l;i<=m;i++)
    {
        L[k]=a[i];
        k++;
    }
    k = 0;
    for(int i=m+1;i<=r;i++)
    {
       R[k]=a[i];
       k++;
    }
        int i=0,j=0;
        int cur =l;
    while(i<leftsize && j < rightsize)
    {
        if(L[i]<=R[j])
        {
            a[cur] = L[i];
            i++;
        }
        else
        {
            a[cur]= R[j];
            j++;    
        }
        cur++;
    }
    while(i<leftsize)
    {
        a[cur]=L[i];
        i++;
        cur++;
    }
    while (j<rightsize)
    {
        a[cur]=R[j];
        j++;
        cur++;
    }
    
}   

int main()
{
    
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   {
        cin>>a[i];
   } 
  
    merge(a,0,3,n-1); //10 ta element
                        //1 3 5 10 1 4 6 8 9 15
     //0-3 porjonto =l theke 10 trpr midle=m; trpr m+1 theke n-1 porjonto arkta vag n-1 =r;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
