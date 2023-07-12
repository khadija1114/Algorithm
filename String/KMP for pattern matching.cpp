#include<bits/stdc++.h>
#define mod 1e9+9
#define make_pair mp
#define push_back pb
typedef long long ll;
using namespace std;

vector<int> largest_suf_pre(string s){
    int n=s.size(),i,j,index=0;
    vector<int> lps(n);
    for(i=1;i<n;){
        if(s[i]==s[index]){
            index++;
            lps[i]=index;
            i++;
        }
        else {
            if(index!=0){
                index=lps[index-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

bool kmp(string a,string b){
    int i=0,j=0;
    vector<int> lps=largest_suf_pre( b );
    while(i<a.size() && j< b.size()){
        if(a[i]==b[j]){
            i++;j++;
        }
        else {
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(j==b.size()) return true;
    else return false;
}

int main()
{
    int t,i,j,cs=0,n;
    string a,b;
    cin>>a;
    reverse(a.begin(),a.end());
    vector<int> v=largest_suf_pre(a);
    for(auto it: v) cout<<it<<" ";
    cin>>a>>b;
    if(kmp(a,b)) cout<<"Found";
    else cout<<"Not Found";
    cout<<endl;


}

