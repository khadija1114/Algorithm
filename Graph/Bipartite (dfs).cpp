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
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int N=1e5+2;
long long  mod=1e9+9;
int t,j,cs=0,n,a,b,m,i;
vi adj[N];
string s;
bool color[N],visited[N];
void clear_(){
    for(i=0;i<=n;i++){
        color[i]=0;
        visited[i]=0;
    }
}

bool isbipartite(int v){
        for(auto it: adj[v]){
            if(!visited[it]){
                    visited[it]=true;
                color[it]=!color[v];
                if(!isbipartite(it)){
                    return false;
                }
            }
            else if(color[it]==color[v])
                return false;
        }
    return true;
}
int main()
{
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool ans=true;
    clear_();
    for(i=1;i<=n && ans;i++){
        if(!visited[i]){
            ans=isbipartite(i);
        }
    }
    if(!ans) cout<<"bipartite"<<endl;
    else cout<<"Not Bipartite"<<endl;
}

