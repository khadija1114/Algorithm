#include<bits/stdc++.h>
#define mod 1e9+9
#define make_pair mp
#define push_back pb
typedef long long ll;
using namespace std;

vector <int> largest_pre_suf(string s)
{
    vector<int> ans(s.size());
    int index=0,i;
    for(i=1;i<s.size();){
        if(s[i]==s[index]){
            ans[i]=index+1;
            index++;
            i++;
        }
        else{
            if(index!=0){
                index=ans[index-1];
            }
            else{
                ans[i]=0;
                i++;
            }
        }
    }
    return ans;
}
int main()
{
    int t,i,j,cs=0,n;
    string s;
    cin>>s;
    vector<int> v=largest_pre_suf(s);
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

