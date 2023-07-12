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
int t,j,cs=0,n,a,b,i,dxx[]={1,0,0,-1},dyy[]={0,-1,1,0},k,m,succ[N][25],q;

int main()
{
    w(t){
        scanf("%d",&n);
        rep(i,n-1){
            scanf("%d%d",&a,&b);
            succ[a][0]=b;
        }
        for(i=1;(1<<i)<=n;i++){
            for(j=1;j<=n;j++){
                int p=succ[j][i-1];
                succ[j][i]=succ[p][i-1];
            }
        }
        printf("Case %d:\n",++cs);
        w(q){
           scanf("%d%d",&a,&b);
           for(i=20;b;i--){
            if(b&(1<<i)){
                b-=(1<<i);
                a=succ[a][i];
            }
           }
           printf("%d\n",a);
        }
    }
}

