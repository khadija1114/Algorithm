#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_mset;

int main()
{
    int i, j, n, k;
    cin >> n >> k;

    int ar[n];
    for(auto &it : ar) cin >> it;

    indexed_mset st;

    for (i = 0; i < k-1; i++) st.insert(ar[i]);

    for (i = k-1; i < n; i++){
        st.insert(ar[i]);

        cout << *st.find_by_order((k+1)/2 - 1)<< " ";

        st.erase( st.find_by_order (st.order_of_key(ar[i-k+1])));
    }
    cout << "\n";
}
