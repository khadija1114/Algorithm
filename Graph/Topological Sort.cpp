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
typedef pair<ll,ll> pll;
typedef vector<int> vi;

long long  mod=1e9+9;
const int N=1e6+2;
int t,i,j,cs=0,n,a,b,m,u,vv;
string s;
vector<int> v[N];
bool visited[N];
vector<int> ans;
void top_sort(int a){
    visited[a]=true;
    for(j=0;j<v[a].size();j++){
        if(visited[v[a][j]])
            continue;
        top_sort(v[a][j]);
    }
    ans.pb(a);
    return ;
}
int main()
{
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>u>>vv;
        v[u].pb(vv);
    }

    for(i=0;i<n;i++){
        if(visited[i])
            continue;
        top_sort(i);
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans)
        cout<<it<<" ";
    cout<<endl;
}


