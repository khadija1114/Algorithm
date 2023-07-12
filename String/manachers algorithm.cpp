#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define w(x) scanf("%d",&x);getchar();while(x--)
#define rep(i,a,b) for(i=a;i<=b;i++)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 2*acos(0.0)
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef vector<int> vi;

long long int mod = 1e9+9;
const int N = 100000;
int t, i, j, cs = 0, n, a, b;


string convertToNewString (const string &s)
{
    string newString = "@";

    for (int i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}

string largest_palindromic_string (const string& ch)
{
    int r = 0, l = 0, c = 0, mirror, len = 0;
    string s = convertToNewString( ch );
    int n = s.size();
    int p[n] = {};

    for(i = 1; i < s.size(); i++){
        mirror = 2*c - i;
        if (i < r) p[i] = min (r-i , p[mirror]);
        while (s[i + p[i] + 1] == s[i - p[i] - 1])
            p[i]++;
        if (i + p[i] + 1 == n) break;
        if(i + p[i] > r){
            r = i + p[i];
            c = i;
        }
    }

    for(i = 1; i < n; i++){
        if(len < p[i]){
            len = p[i];
            c = i ;
        }
    }
   // cout<<len<<" "<<c<<endl;
    return ch.substr(( c - 1 - len ) / 2, len);
}


int main()
{
    string s;
    getline (cin, s);
    string ch = largest_palindromic_string(s);
    cout << ch << endl;
}

