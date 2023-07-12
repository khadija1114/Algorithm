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
int t,j,cs=0,n,a,b,i,dxx[]={1,0,0,-1},dyy[]={0,-1,1,0},k,m,timer,low[N],st[N];
bool vis[N],cutpoint[N];
vi adj[N];

void dfs(int s,int p=-1)
{
    vis[s]=1;
    int ch=0;
    st[s]=low[s]=timer++;
    for(auto v:adj[s]){
        if(v==p) continue;
        if(vis[v]){
            low[s]=min(low[s],st[v]);
        }
        else{
            dfs(v,s);
            low[s]=min(low[s],low[v]);
            if(low[v]>=st[s] && p!=-1){
                cutpoint[s]=1;
            }
            ch++;
        }
    }
    if(p==-1 && ch>1) cutpoint[s]=1;
    return ;
}

void find_point()
{
    rep(i,n-1)
        if(!vis[i+1])
            dfs(i+1);
}

int main()
{
    scanf("%d%d",&n,&m);
    rep(i,m-1){
        scanf("%d%d",&a,&b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    find_point();
    for(i=1;i<=n;i++)
       if(cutpoint[i]) cout<<i<<" ";
}

