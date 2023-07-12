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

const int N=1e6+2;
long long  mod=1e9+9;
int t,j,cs=0,n,a,b,i,dxx[]={1,0,0,-1},dyy[]={0,-1,1,0},k,m,blc[1000],sqr=sqrt(N)+1,ar[N];

void build()
{
    for(i=0;i<n;i++){
        blc[i/sqr]+=ar[i];
    }
}

int query()
{
    int l,r,sum=0;
    cin>>l>>r;
    int left=l/sqr,right=r/sqr;
    if(left==right){
        for(i=l;i<=r;i++)
            sum+=ar[i];
        return sum;
    }
    for(int i=l,lim=(left+1)*sqr;i<lim;i++)
        sum+=ar[i];
    for(i=left+1;i<right;i++){
        sum+=blc[i];
    }
    for(i=right*sqr;i<=r;i++)
        sum+=ar[i];

    return sum;
}

int main()
{
    cin>>n;
    rep(i,n-1) cin>>ar[i];
    build();
    int q;
    w(q){
        cin>>a;
        if(a==1)
        cout<<query()<<endl;
        else{
            int l;
            cin>>l>>b;
            blc[l/sqr]+=b-ar[l];
            ar[l]=b;
        }
    }
}



