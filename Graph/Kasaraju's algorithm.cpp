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
int t,j,cs=0,n,a,b,i,dxx[]={1,0,0,-1},dyy[]={0,-1,1,0},k=1,m;
vi component,order,adj[N],rev[N];
bool vis[N];

void dfs1(int s)
{
    vis[s]=1;
    for(auto it:adj[s]){
        if(!vis[it])
            dfs1(it);
    }
    order.pb(s);
    return ;
}

void dfs2(int s)
{
    vis[s]=1;
    component.pb(s);
    for(auto it:rev[s]){
        if(!vis[it])
            dfs2(it);
    }
    return ;
}

int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        adj[a].pb(b);
        rev[b].pb(a);
    }
    for(i=1;i<=n;i++){
        if(!vis[i])
            dfs1(i);
    }
    rep(i,n) vis[i]=0;
    reverse(order.bg,order.en);
   // for(auto it:order) cout<<it<<" ";
    for(auto it:order){
        if(!vis[it]){
            dfs2(it);
            cout<<k++<<" ";
            for(auto itt:component)
                cout<<itt<<" ";
                cout<<endl;
            component.clear();
        }
    }
}

