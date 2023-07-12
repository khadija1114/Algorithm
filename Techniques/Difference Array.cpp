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
int t,j,cs=0,n,a,b,i,dxx[]={1,0,0,-1},dyy[]={0,-1,1,0},k,m,q,x,c;
string s;

int main()
{
    w(t){
        cin>>n;
        int ar[n],d[n];
        rep(i,n-1) cin>>ar[i];
        d[0]=ar[0];
        for(i=1;i<n;i++)
            d[i]=ar[i]-ar[i-1];
        w(q){
            cin>>c;
            int l,r;
            if(c==1){
                cin>>l>>r>>x;
                d[l]+=x;
                if(r<n)
                    d[r+1]-=x;
            }
            else{
                cout<<d[0];
                for(i=1;i<n;i++){
                    ar[i]=d[i]+ar[i-1];
                    cout<<" "<<d[i]+ar[i-1];
                }
                cout<<endl;
            }
        }
    }
}



