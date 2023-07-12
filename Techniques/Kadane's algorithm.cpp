///to print largest contiguous sub-array

#include<bits/stdc++.h>
#define w(x) scanf("%d",&x); while(x--)
#define endl "\n"
using namespace std;

void Kadane()
{
    int n, i, st = 0, en = 0, max_so_far, max_ending_here = 0, ind = 0;
    cin >> n;
    int ar[n];

    for (i = 0; i < n; i++)
        cin >> ar[i];
    max_so_far = ar[0];

    for (i = 0; i < n; i++){
        max_ending_here += ar[i];

        if (max_ending_here > max_so_far){
            max_so_far = max_ending_here;
            st = ind;
            en = i;
        }

        if (max_ending_here < 0){
            max_ending_here = 0;
            ind = i+1;
        }
    }

    for (i = st; i <= en; i++){
        cout << ar[i] << " ";
    }
    cout << "\n";

}
int main()
{
    int t;
    w(t){
        Kadane();
    }
}

