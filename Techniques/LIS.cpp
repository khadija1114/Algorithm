#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define w(x) scanf("%d",&x);while(x--)
#define rep(i,b) for(i=0;i<=b;i++)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 2*acos(0.0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

long long int mod=1e9+9;
const int N=1e6+1;
int T,i,j,cs=0,n,a,b,len;
string s;
int ar[N],t[N];

int ceilindex(int x){
    int st=0,en=len,md;
    while(st<=en){
            md=(st+en)/2;
        if( md<len && t[md]<x && t[md+1]>=x)
            return md+1;
        else if(t[md]>x){
            en=md-1;
        }
        else
            st=md+1;
    }
}
void lis(int n){
    rep(i,n-1){
        t[i]=0;
    }
    len=0;
    t[0]=ar[0];
    for(i=1;i<n;i++){
        if(ar[i]<t[0]){
            t[0]=ar[i];
        }
        else if(ar[i]>t[len]){
            len++;
            t[len]=ar[i];
        }
        else{
            int index=ceilindex(ar[i]);
            t[index]=ar[i];
        }
    }

}
int main()
{
    w(T){
        cin>>n;
        rep(i,n-1){
            cin>>ar[i];
        }
        lis(n);
        rep(i,len){
            cout<<t[i]<<" ";
        }
    }
}

