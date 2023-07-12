#include<bits/stdc++.h>
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

const int N=20005;
long long  mod=1e9+9;
int t,j,cs=0,n,a,b,i,dxx[]={1,0,0,-1},dyy[]={0,-1,1,0},k,m;
vi adj[N];
map<string,int> map_;
map<int,int> mp;
bool ans;
string s1,s2;

void allclear(){
    for(i=0;i<N;i++){
        adj[i].clear();
    }
    //cout<<1<<endl;

    mp.clear();
    map_.clear();
    k=0;
    ans=true;
}

void dfs(int s){
    mp[s]=1;
    if(ans==false) return ;
    for(auto it:adj[s]){
        if(mp[it]==0)
            dfs(it);
        else if(mp[it]==1){
            ans=false;
            return ;
        }
    }
    mp[s]=2;
    return ;
}

int main()
{
    w(t){
        scanf("%d",&n);
        allclear();
        rep(i,n-1){
            cin>>s1>>s2;
            if(!map_[s1]) map_[s1]=k++;
            if(!map_[s2]) map_[s2]=k++;
            adj[map_[s1]].pb(map_[s2]);
        }
        for(i=0;i<k && ans ;i++){
            if(mp[i]==0) dfs(i);
        }
        if(ans)
            printf("Case %d: Yes\n",++cs);
        else
            printf("Case %d: No\n",++cs);

    }
}


