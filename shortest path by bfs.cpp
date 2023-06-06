#include<bits/stdc++.h>
using namespace std;
int nodes, edges;
vector <int> nod[1000], wet[1000];
int BFS(int src, int goal)
{
    int dis[nodes];
    for(int i = 1; i <= nodes; i++) dis[i] = INT_MAX;

    dis[src] = 0;

    queue <int> que;
    que.push(src);

    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int i = 0; i < nod[u].size(); i++){
           int v = nod[u][i];
           int w = wet[u][i];
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                que.push(v);
            }
        }
    }
    return dis[goal];
}
int main()
{
    cin >> nodes >> edges;

    for(int i = 0; i <= nodes; i++) nod[i].clear();

    for(int i = 1; i <= edges; i++){
        int u,v,w;
        cin>> u >> v >> w;
        nod[u].push_back(v);
        nod[v].push_back(u);
        wet[u].push_back(w);
        wet[v].push_back(w);
    }
    int src, goal;
    cin >> src >> goal;
    int ans = BFS(src, goal);
    cout << ans << endl;

    return 0;
}


/*
5 7
1 2 3
1 4 1
2 3 2
2 4 2
4 5 10
3 5 4
2 5 12
1 5
*/



