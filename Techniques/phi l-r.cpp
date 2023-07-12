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
int main()
{
    sieve();
    w(t){
        cin>>n;
        int phi[n+1]={};
        bool mark1[n+1]={};
        for(i=0;prime[i]<=n;i++){
            if(n%prime[i]==0){
                for(j=prime[i];j<=n;j+=prime[i]){
                    mark1[j]=true;
                }
            }
        }
        for(i=1;i<=n;i++){
            phi[i]=phi[i-1]+!mark1[i];
        }
        int L=0,R=0;
        cin>>a>>b;
        a--;
        R=(b/n)*phi[n]+phi[b%n];
        L=(a/n)*phi[n]+phi[a%n];
        cout<<R-L<<endl;
    }
}


