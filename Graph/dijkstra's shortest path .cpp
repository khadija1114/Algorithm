#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define w(x) scanf("%d",&x);while(x--)
#define rep(i,b) for(i=0;i<=b;i++)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 2*acos(0.0)
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

long long  mod=1e9+9;
const int N=1e6+2;
int t,i,j,cs=0,n,a,b,c,u,v,w,m,inf=1e8+7;
vector<pii> adj[N];
int dis[N],prn[N];
bool visited[N];

void dijkstra(int s){
   // cout<<1<<endl;
    dis[s]=0;
    for(i=1;i<=n;i++){
       // cout<<i<<" " ;
        u=-1;
        for(j=1;j<=n;j++){
            if(!visited[j] &&(u==-1||dis[u]>dis[j]))
                u=j;
        }
       // cout<<u<<endl;
        if(dis[u]==inf)
            break;
        visited[u]=true;
        for(int it=0;it<adj[u].size();it++){
            v=adj[u][it].ff,w=adj[u][it].ss;
            if(dis[u]+w<dis[v]) {
                dis[v]=dis[u]+w;
                prn[v]=u;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    rep(i,m-1){
        cin>>a>>b>>c;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
    }
     for(i=0;i<=n;i++)
        dis[i]=inf;
    dijkstra(1);
    for(i=1;i<=n;i++)
        cout<<i<<" "<<dis[i]<<endl;
}

