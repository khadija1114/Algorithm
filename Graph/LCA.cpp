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

const int N=1e5+2;
long long  mod=1e9+9;
int t,j,cs=0,n,a,b,i,k,m,par[21][N],dep[N],q;
bool visited[N];
vi adj[N];
int findparent(int k,int a){
    for(i=0;k>0;i++){
        if(k&(1<<i)){
            k-=(1<<i);
            a=par[i][a];
        }
    }
    return a;
}
int lca(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    a=findparent(dep[a]-dep[b],a);

    if(a==b) return a;
    for(i=20;i>=0;i--){
        if(par[i][a]!=par[i][b]){
            a=par[i][a];
            b=par[i][b];
        }
    }
    return par[0][a];
}
void dfs(int s){
    visited[s]=1;
    for(auto it:adj[s]){
        if(!visited[it]){
            dep[it]=dep[s]+1;
            par[0][it]=s;
            dfs(it);
        }
    }
    return ;
}
int main()
{
    cin>>n;
    for(i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dep[1]=0;
    dfs(1);
    for(i=1;i<=20;i++){
        for(j=1;j<n;j++){
            int p=par[i-1][j];
            p=par[i-1][p];
            par[i][j]=p;
        }
    }
    w(q){
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
}

