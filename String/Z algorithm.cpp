///implementation of Z algorithm from handbook
#include<bits/stdc++.h>
using namespace std;


vector<int> Z (string s)
{
    int x = 0, y = 0, k = 0, n = s.size();
    vector <int> z(n);

    for (k = 1; k < n; k++){

        z[k] = max (0, min (z[k-x], y-k+1));
        while(k+z[k] < n && s[z[k]] == s[k+z[k]]){
            x = k;
            y = k+z[k];
            z[k]++;
        }
    }

    return z;
}


int main()
{
    string s, a, b;
    while(cin >> b >> a){

        int n = b.size(), i = 0;

        s = b + '$' + a;
        vector<int> z = Z(s);
        int sz = s.size();

        for (i = n; i < sz ; i++)
            if (z[i] == n) printf("%d\n", i-n-1);

        cout << "\n";
    }
}
