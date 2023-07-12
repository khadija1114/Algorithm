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

const int N=1e6+2;
long long  mod=1e9+9;
int t,j,cs=0,n,a,b,i,sa[N];
string s;

struct suffixes{
    int index;
    int rank[2];
};

bool cmp(suffixes a,suffixes b){
    return (a.rank[0]==b.rank[0])?(a.rank[1]<b.rank[1] ? 1 : 0) : (a.rank[0]<b.rank[0] ? 1 : 0);
}

void suffix_array(){
    struct suffixes suffix[n];

    for(i=0;i<n;i++){
        suffix[i].index=i;
        suffix[i].rank[0]=s[i]-'a';
        suffix[i].rank[1]=(i+1 < n ) ? (s[i+1]-'a') : -1;
    }

    sort(suffix,suffix+n,cmp);
    int ind[n];
    for(int k=4 ; k<2*n ; k*=2){
        int r=0,pre_r=suffix[0].rank[0];
        suffix[0].rank[0]=0;
        ind[suffix[0].index]=0;

        for(i=1;i<n;i++){
            if(suffix[i].rank[0]==pre_r && suffix[i-1].rank[1]==suffix[i].rank[1]){
                suffix[i].rank[0]=r;
            }
            else{
                pre_r=suffix[i].rank[0];
                r++;
                suffix[i].rank[0]=r;
            }
            ind[suffix[i].index]=i;
        }

        for(i=0;i<n;i++){
            int nextindex=suffix[i].index+k/2;
            suffix[i].rank[1]=(nextindex<n) ? suffix[ind[nextindex]].rank[0] : -1;
        }

        sort(suffix,suffix+n,cmp);
    }

    for(i=0;i<n;i++){
        sa[i]=suffix[i].index;
    }
}
int main()
{
    cin>>s;
    n=s.size();
    suffix_array();

    for(i=0;i<n;i++)
        cout<<i+1<<" "<<sa[i]<<endl;
}

