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
int t,j,cs=0,n,a,b,i,sa[N],lcp[N],inverse[N];
string s;

struct suffixes{
    int index,rank[2];
};

bool cmp(suffixes a,suffixes b){
    return (a.rank[0]==b.rank[0]) ? (a.rank[1]<b.rank[1] ? 1:0) : (a.rank[0]<b.rank[0] ? 1:0);
}

void suffix_array(){
    struct suffixes suffix[n];
    for(i=0;i<n;i++){
        suffix[i].index=i;
        suffix[i].rank[0]=s[i]-'a';
        suffix[i].rank[1]=(i+1<n) ? s[i+1]-'a':-1;
    }

    sort(suffix,suffix+n,cmp);
    int ind[n];

    for(int k=4;k<2*n;k*=2){
        int r=0,pre_r=suffix[0].rank[0];
        suffix[0].rank[0]=0;
        ind[suffix[0].index]=0;
        for(i=1;i<n;i++){
            if(suffix[i].rank[0]==pre_r && suffix[i].rank[1]==suffix[i-1].rank[1])
                suffix[i].rank[0]=r;
            else{
                pre_r=suffix[i].rank[0];
                suffix[i].rank[0]=++r;
            }
            ind[suffix[i].index]=i;
        }

        for(i=0;i<n;i++){
            int next=suffix[i].index+k/2;
            suffix[i].rank[1]=(next<n) ? suffix[ind[next]].rank[0] : -1;
        }
        sort(suffix,suffix+n,cmp);
    }

    for(i=0;i<n;i++){
        sa[i]=suffix[i].index;
    }
}

void kasai(){
    for(i=0;i<n;i++){
        inverse[sa[i]]=i;
    }
    int k=0;
    for(i=0;i<n;i++){
        if(inverse[i]==n-1){
            k=0;
            continue;
        }
        j=sa[inverse[i]+1];

        while(i+k<n && j+k<n && s[i+k]==s[j+k])
            k++;
        lcp[inverse[i]]=k;
        if(k)
            k--;
    }
}
int main()
{
    cin>>s;
    n=s.size();
    suffix_array();
    kasai();
    for(i=0;i<n;i++)
        cout<<i<<" "<<sa[i]<<" "<<lcp[i]<<endl;

}


