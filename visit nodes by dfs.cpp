#include<bits/stdc++.h>
using namespace std;
int nodes, edges;
vector <int> nod[1000];
int vis[1000], noOfNodes=0;
void DFS(int u)
{
    vis[u] = 1;
    noOfNodes++;
    cout<<u<<" ";
    for(int i=0; i<nod[u].size(); i++)
    {
        int v = nod[u][i];
        if(vis[v] == 0){
            DFS(v);
        }
    }
}
int main()
{
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;
        nod[u].push_back(v);
        nod[v].push_back(u);
    }
    cout<<"Visit nodes: ";
    DFS(1);
    cout<<endl;
    cout<<"Number of nodes: "<<noOfNodes<<endl;
}
/*

5 7
5 2
3 5
2 3
2 1
3 4
4 1
3 1

*/


