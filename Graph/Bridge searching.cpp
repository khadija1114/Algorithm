#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define pb push_back
#define w(x) scanf("%d",&x);while(x--)
#define ws(x) scanf("%d",&x);getchar();while(x--)
#define rep(i,b) for(i=0;i<=b;i++)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 2*acos(0.0)
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N=1e4+2;
long long  mod=1e9+9;
int t,j,cs=0,n,a,b,i,dxx[]={1,0,0,-1},dyy[]={0,-1,1,0},k,m,low[N],st[N],timer;
bool vis[N];
vi adj[N];
vector<pii> bridge;

void dfs(int s,int p=-1)
{
    vis[s]=1;
   // cout<<s<<" "<<p<<endl;
    low[s]=st[s]=timer++;
    for(auto v:adj[s]){
        if(v==p) continue;
        if(vis[v]){
           // cout<<s<<" "<<v<<" "<<low[s]<<" "<<low[v]<<" "<<st[v]<<endl;
            low[s]=min(low[s],st[v]);
        }
        else{
            dfs(v,s);
            low[s]=min(low[s],low[v]);
            if(low[v]>st[s]){
                bridge.pb({s,v});
            }
        }
    }
    return ;
}

void find_bridge()
{
   for(i=1;i<=n;i++)
    if(!vis[i])
    dfs(i);
}

void allclear()
{
    for(i=0;i<=n+1;i++){
        vis[i]=0;
        adj[i].clear();
    }
    bridge.clear();
    timer=1;
}

int main()
{
    scanf("%d%d",&n,&m);
    allclear();
    rep(i,m-1){
        scanf("%d%d",&a,&b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    find_bridge();
    for(auto it:bridge)
        printf("%d %d\n",it.ff,it.ss);
}

