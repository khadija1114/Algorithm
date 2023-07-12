#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define w(x) scanf("%d",&x);while(x--)
#define rep(i,a,b) for(i=a;i<=b;i++)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 2*acos(0.0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

long long  mod=1e9+9,cost=0;
const int N=1e6+2;
int t,i,j,cs=0,n,a,b,c,v,e;
string s;

struct edge{
    int u,v,w;
    bool operator<(edge const& other){
        return w<other.w;
    }
};

vector<int> rank_,parent;

int find_set(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find_set(parent[x]);
}

void union_set(int a, int b) {
    a = find_set(a), b = find_set(b);
    if (a != b) {
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
}

int main()
{
    cin >> v >> e;
    vector<edge> graph(e);
    parent.resize(v);
    rank_.resize(v);

    for(i = 0; i < e; i++){
       cin >> graph[i].v >> graph[i].u >> graph[i].w;
       graph[i].u--; graph[i].v--;
    }

    sort(graph.begin(), graph.end());

    for(i = 0; i < v; i++){
       parent[i] = i;
       rank_[i] = 0;
    }

    for(edge node: graph){

        if(find_set(node.u) != find_set(node.v)){
            cost += node.w;
            union_set(node.u, node.v);
        }

    }
    cout<<cost<<endl;

}


