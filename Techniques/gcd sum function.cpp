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

const int N=1e6+2;
long long  mod=1e9+9;
int t,j,cs=0,n,a,b,i,prime[N],k;
bool mark[N];
string s;

void sieve(){
    prime[k++]=2;
    for(i=3;i<N;i+=2){
        if(!mark[i]){
            prime[k++]=i;
            for(j=i;j<N;j+=2*i)
                mark[j]=true;
        }
    }
}

vector<pii> factorization(int n){
    vector<pii> v;
    for(i=0;prime[i]*prime[i]<=n;i++){
        int cnt=0;
        while(n%prime[i]==0){
            cnt++;
            n/=prime[i];
        }
        if(cnt){
            v.pb(mp(prime[i],cnt));
        }
    }
    if(n>1){
        v.pb(mp(n,1));
    }
    return v;
}
int main()
{
    sieve();
    w(t){
        cin>>n;
        vector<pii> factor;
        factor=factorization(n);
        ll gcdsum=1;
        for(auto it:factor){
            ll ppow=1;
            cout<<it.ff<<" "<<it.ss<<endl;
            for(i=0;i<it.ss;i++){
                ppow*=it.ff;
            }
            gcdsum*=(it.ss+1)*ppow-it.ss*ppow/it.ff;
        }

        cout<<gcdsum<<endl;
    }
}

