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
int t,j,cs=0,n,a,b,i,sum;
string s;

int main()
{
    cin>>n>>sum;
    int ar[n];
    rep(i,n-1) cin>>ar[i];
    int cnt=0;
    for(i=0,j=0;i<n;i++){
        if(i) cnt-=ar[i-1];
        while(cnt+ar[j]<=sum && j<n){
            //if(cnt+ar[j]>=sum) break;
            cnt+=ar[j];
            j++;
        }
        if(cnt==sum){
            break;
        }
    //    cout<<i<<" "<<j-1<<" "<<cnt<<endl;
    }
    if(cnt==sum) cout<<"YES"<<endl<<i+1<<" "<<j<<endl;
    else cout<<"NO"<<endl;
}
/*
8 8 1 3 2 5 1 1 2 3
8 5 3 3 1 3 4 4 2 5
*/

