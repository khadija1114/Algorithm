#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
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

long long  mod=1e9+9;
const int N=1e6+2;
int t,i,j,cs=0,n,a,b,k;
string s;

vector<int> pre_fun(string s){
    n=s.size();
    vi pf(n);
    for(i=0;i<n;i++){
        for(k=i;k>=0;k--){
            if(s.substr(0,k)==s.substr(i-k+1,k)){
                pf[i]=k;
                break;
            }
        }
    }
    return pf;
}

int main()
{
    ws(t){
        cin>>s;
        vi pf=pre_fun(s);
        for(auto it: pf)
            cout<<it<<" ";
        cout<<endl;
    }
}

