#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define w(x) scanf("%d",&x);while(x--)
#define rep(i,b) for(i=0;i<=b;i++)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 2*acos(0.0)
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

long long  mod=1e9+9;
const int N=1e6+2;
int t,i,j,cs=0,n,a,b,inf=1e7,ar[N];

int max(int a,int b){
    return a>b? a:b;
}
int max(int a,int b,int c){
    return max(max(a,b),c);
}

int  find_max_crossing_subarray(int low,int high,int mid){
    int left_sum=-inf,sum=0,right_sum=-inf;
    for(i=mid;i>=low;i--){
        sum+=ar[i];
        if(sum>left_sum){
            left_sum=sum;
        }
    }
    sum=0;
    for(i=mid+1;i<=high;i++){
        sum+=ar[i];
        if(sum>right_sum){
            right_sum=sum;
        }
    }
    return max(left_sum,right_sum,left_sum+right_sum);
}

int find_max_subarray(int low,int high){
    if(high==low){
        return ar[low];
    }
    int mid=(low+high)/2;
    return max(find_max_subarray(low,mid),find_max_subarray(mid+1,high),
               find_max_crossing_subarray(low,high,mid));
}
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
        cin>>ar[i];
    int  o=find_max_subarray(0,n-1);
    cout<<o<<endl;
}

