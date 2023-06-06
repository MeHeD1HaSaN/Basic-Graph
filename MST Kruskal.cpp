#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Edge{
    int u;
    int v;
    int wet;
};

vector<Edge> edgeList;
int prnt[1000];

int find(int v){
    if(prnt[v] == v) return v;
    return find(prnt[v]);
}
int mstKruskal(int n, int m){

    int cost=0;
    int nodCount=0, eg=0;
    while(nodCount<n-1 && eg<m){

        int prntOfU = find(edgeList[eg].u);
        int prntOfV = find(edgeList[eg].v);

        if(prntOfU != prntOfV){
            prnt[prntOfU] = prntOfV;
           // cout<<"u: "<<edgeList[eg].u<<" v: "<<edgeList[eg].v<<"  wet: "<<edgeList[eg].wet;
           // cout<<"  parent of "<<edgeList[eg].u<<" : "<<prntOfU<<"  parent of "<<edgeList[eg].v<<" : "<<prntOfV<<endl;
            nodCount++;
            cost+=edgeList[eg].wet;
        }
        eg++;
    }

    return cost;
}
void printEdgeList(){
    for(auto p: edgeList)
		cout<<"src: "<<p.u<<"  dst: "<<p.v<<"  wt: "<<p.wet<<"\n";
	cout<<"============================================================\n";
}
bool comparator(Edge a, Edge b){
    return a.wet < b.wet;
}
int main()
{

   // freopen("input.txt", "r", stdin);

    int nodes, edges;
    cin>>nodes>>edges;
    Edge tmp;
    for(int i=1; i<=nodes; i++){
        prnt[i]=i;
    }
    for(int i=0; i<edges; i++){
        int a, b, c;
        cin>>a>>b>>c;
        tmp.u = a;
        tmp.v = b;
        tmp.wet = c;
        edgeList.push_back(tmp);
    }
    //cout<<"Edge list before sort"<<endl;
    //printEdgeList();
    sort(edgeList.begin(), edgeList.end(), comparator);
    //cout<<"Edge list after sort"<<endl;
    ///printEdgeList();
    int mstCost = mstKruskal(nodes, edges);
    cout<<"Total Cost of MST = "<<mstCost<<endl;

    return 0;
}


/*

8 16
1 6 54
6 3 75
1 3 47
5 3 23
1 5 80
5 2 32
5 7 93
7 8 68
3 7 66
2 7 74
3 4 88
8 4 29
2 8 79
4 2 31
6 2 31
6 4 74

min cost = 259
*/





