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

const int N=1e5+2;
long long  mod=1e9+9;
int t,j,cs=0,n,a,b,i,tree[N],ar[N],k,m,inf=1e7;
string s;

void build_tree(int pos,int l,int r){
    if(l==r){
        tree[pos]=ar[l];
        return ;
    }
    int mid=(l+r)/2;
    build_tree(2*pos+1,l,mid);
    build_tree(2*pos+2,mid+1,r);
    tree[pos]=min(tree[2*pos+1],tree[2*pos+2]);
    return ;
}

void allclear()
{
    rep(i,N-2){
        tree[i]=inf;
        ar[i]=inf;
    }
}

int query(int pos,int high,int low,int l,int r)
{
    if(high<l || low>r )
        return inf;
    if(high<=r && low>=l)
        return tree[pos];
    int mid=(high+low)/2;
    return min(query(2*pos+1,mid,low,l,r),query(2*pos+2,high,mid+1,l,r));
}

int main()
{
    allclear();
    cin>>n;
    rep(i,n-1) cin>>ar[i];
    build_tree(0,0,n-1);
//    rep(i,2*n-1)
//    cout<<tree[i]<<" ";
    int q,l,r;
    w(q){
        cin>>l>>r;
        cout<<query(0,n-1,0,l,r)<<endl;
    }
}



