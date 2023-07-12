#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e6+2;
int ar[N];

void heapify( int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && ar[l] > ar[largest])
        largest = l;

    if (r < n && ar[r] > ar[largest])
        largest = r;

    if (largest != i)
    {
        swap(ar[i], ar[largest]);

        heapify(  n, largest);
    }
}

void heapSort( int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify( n, i);

    for (int i=n-1; i>0; i--)
    {
        swap(ar[0], ar[i]);

        heapify(i, 0);
    }
}

int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>ar[i];

    heapSort(n);

    for(i=0;i<n;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
}

