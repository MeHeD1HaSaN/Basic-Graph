#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int INF = 1e9+10;

int dis[1003][1003];
int nodes, edges;

void floyd()
{
    for(int k=1; k<=nodes; k++){
        for(int i=1; i<=nodes; i++){
            for(int j=1; j<=nodes; j++){
                if(dis[i][k]!=INF && dis[k][j]!=INF){
                     dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
}

int main() {

    cin>>nodes>>edges;

    for(int i=0; i<=nodes; i++){
        for(int j=0; j<=nodes; j++){
            if(i==j) dis[i][j]=0;
            else dis[i][j] = INF;
        }
    }

    for(int i = 0; i<edges; i++) {
        int u, v, w;
        cin>>u>>v>>w;

        dis[u][v] = w;
    }

    floyd();

    for(int i=1; i<=nodes; i++){
        for(int j=1; j<=nodes; j++){
            if(dis[i][j]==INF) cout<<"i"<<" ";
            else cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }

}

/*

6 9
1 2 1
1 3 5
2 3 2
3 5 2
2 5 1
2 4 2
4 5 3
4 6 1
5 6 2


*/

