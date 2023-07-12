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

long long int mod=1e9+9;
const int N=100000;
int t,i,j,cs=0,n,a,b;
string s;

int main()
{
    w(t){
        cin>>n;
        vi v[n+1];

        for(i=1;i<n;i++){
            cin>>b;
            for(j=0;j<b;j++){
                 cin>>a;
                v[i].pb(a);
            }
        }
        for(i=1;i<n;i++){
            sort(v[i].begin(),v[i].end());
        }
        vi ans(n+1,-1);
        ans[1]=0;
        queue<int> q;
        q.push(1);
        bool flag=false;
        while(!q.empty() && !flag){
            a=q.front();
            q.pop();

            for(auto it=v[a].begin();it!=v[a].end();it++){
                if(ans[*it]==-1){
                    ans[*it]=a;
                    if(*it==n){
                        flag=true;
                        break;
                    }
                    q.push(*it);
                }
            }
        }
        if(!flag){
            cout<<-1<<endl<<endl;
            continue;
        }
        vi result;
        for(i=ans[n];i!=0;i=ans[i]){
            result.pb(i);
        }
        cout<<result.size()<<endl;
        for(auto it=result.rbegin();it!=result.rend();it++){
            cout<<*it<<" ";
        }
        cout<<endl<<endl;

    }
}



