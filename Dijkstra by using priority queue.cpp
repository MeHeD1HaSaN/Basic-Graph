#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define inf 1000000000012
using namespace std;
const int mx = 100000009;
vector<pair<ll,ll>> edgeList[100005];
ll prevNode[100005];
ll dis[100005];

void printPath(ll v)
{
    if(prevNode[v]==-1) return;
    printPath(prevNode[v]);
    cout<<prevNode[v]<<" ";
}

void seq(ll s, ll d)
{

    for(ll i=0; i<=d; i++) dis[i]=inf;

    dis[s] = 0;
    prevNode[s] = -1;

    priority_queue<pair<ll,ll>> pq;

    pq.push(make_pair(0, s));

    while(!pq.empty()){
        ll u = pq.top().second;
        pq.pop();

        for(ll i=0; i<edgeList[u].size(); i++){
            ll v = edgeList[u][i].first;
            ll w = edgeList[u][i].second;

            if(dis[v] > dis[u] + w){

                dis[v] = dis[u] + w;
                prevNode[v] = u;

                pq.push(make_pair(-dis[v], v));
            }
        }
    }

   if(dis[d]==inf) cout<<-1<<endl;
   else {
        printPath(d);
        cout<<d<<endl;
   }
   //cout<<dis[d]<<endl;

}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);


    #ifndef ONLINE_JUDGE
        // for getting innput from in.txt
        // freopen("input.txt", "r", stdin);
        // for writing output to out.txt
        //freopen("output.txt", "w", stdout);
    #endif

    ll nodes, edges;
    cin>>nodes>>edges;
    for(ll i=1; i<=nodes; i++){
        edgeList[i] = {};
        prevNode[i] = {};
    }
    for(ll i=0; i<edges; i++){
        int u, v, w;
        cin>>u>>v>>w;
        edgeList[u].push_back(make_pair(v, w));
        edgeList[v].push_back(make_pair(u, w));
    }

    seq(1, nodes);

    return 0;
}
