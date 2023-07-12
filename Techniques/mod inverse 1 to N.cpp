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

const int N=1e6+2;
long long  mod=1e9+9;
int t,j,cs=0,n,a,b,i;
string s;

int main()
{
  //  mod = 3;
    cin>>n;
    int inv[n+1];
    inv[1]=1;
    for(i=2;i<=n;i++){
        inv[i]=(-(mod/i)*inv[mod%i])%mod;
       // cout<<inv[i]<<endl;
        inv[i]+=mod;
    }

    for(i=1;i<=n;i++) cout<<i<<" "<<inv[i]<<endl;

}

