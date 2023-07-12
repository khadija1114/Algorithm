///sparse table to calculate min value in range

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int sparse[N][25];


int query (int l, int r)
{

    int k = r-l+1;
    int p = log2(k);

    return min (sparse[l][p], sparse[r-(1<<p)+1][p]);
}

void precal (int n)
{
    int i, j;
    for (j = 1; (1<<j) < n; j++){

        for (i = 0; i+(1<<j)-1 < n; i++){
            sparse[i][j] = min (sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
        }

    }

}

int main()
{
    int i, n, q;
    cin >> n >> q;
    for (i = 0; i < n; i++)
        cin >> sparse[i][0];


    precal (n);

    int l, r;
    while (q--){
        cin >> l >> r;
        cout << query (l-1, r-1) << "\n";
    }

}


