///determining the sum of unique values in given range

#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define w(x) scanf("%d",&x);while(x--)
#define rep(i,a,b) for(i=a;i<=b;i++)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 2*acos(0.0)
using namespace std;
typedef long long ll;
typedef pair<int ,int > pii;
typedef vector<int> vi;

long long int mod=1e9+9;
const int N=1e6+2;
int t,i,j,cs=0,n,a,b,q,l,r,ans[N],freq[N],cnt,ar[N],blc=555;
string s;
struct node{
    int L,R,pos;
}Q[N];

bool cmp(node x, node y){
    if(x.L/blc!=y.L/blc)
        return x.L/blc<y.L/blc;
    return x.R<y.R;
}

void remove(int position){
    freq[ar[position]]--;
    if(freq[ar[position]]==0)
        cnt-=ar[position];
}
void add(int position){
    freq[ar[position]]++;
    if(freq[ar[position]]==1)
        cnt+=ar[position];
}
int main()
{
    w(t){
    cnt=0;
    for(i=0;i<N;i++) freq[i]=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    scanf("%d",&q);

    for(i=0;i<q;i++){
        scanf("%d%d",&Q[i].L,&Q[i].R);
        Q[i].L--;
        Q[i].R--;
        Q[i].pos=i;
    }
    sort(Q,Q+q,cmp);

    int start=0,end=0;

    for(i=0;i<q;i++){
        l=Q[i].L,r=Q[i].R;
        while(start<l){
            remove(start);
            start++;
        }
        while(start>l){
            add(start-1);
            start--;
        }
        while(end<=r){
            add(end);
            end++;
        }
        while(end > r+1){
            remove(end-1);
            end--;
        }
        ans[Q[i].pos]=cnt;
       // cout<<Q[i].L<<" "<<Q[i].R<<" "<<cnt<<endl;
    }
    for(i=0;i<q;i++)
        printf("%d\n",ans[i]);
}
}


