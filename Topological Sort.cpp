#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> nod[1000], result;
int visited[100] = {0};

void dfs(int s)
{
    visited[s] = 1;
    for(int i=0; i<nod[s].size(); i++){
        int next = nod[s][i];
        if(visited[next]==0){
            dfs(next);
        }
    }
    result.push_back(s);
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int nodes, edges;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;
        nod[u].push_back(v);
    }

    for(int i=1; i<=nodes; i++){
        if(visited[i]==0){
            dfs(i);
        }
    }
    reverse(result.begin(), result.end());
    cout<<"The topological sorted list"<<endl;
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<' ';
    }
    cout<<endl;


    return 0;
}



/*

6 6
1 3
3 4
3 2
2 6
2 5
4 5

*/



