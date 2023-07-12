#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N=1e5+2;
int maxpath, x;
bool visited[N];
vector<int> adj[N];

void dfs(int v, int cnt, int p){
    cnt++;
    visited[v] = true;
    for(auto u: adj[v]){
        if (u == p) continue;
        if(cnt >= maxpath){
            maxpath = cnt;
            x = u;
        }
        dfs(u, cnt, v);

    }
}

void clear_( ){
   for (auto &it: visited) it = false;
}

int diameter(int n){
    clear_();

    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dfs(i, 0, i);
            dfs(x, 0, x);

            cout << x << " " << maxpath << endl;
        }
    }

}

int main()
{
    int n, m; cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    diameter (n);

    cout<<maxpath<<endl;
}

