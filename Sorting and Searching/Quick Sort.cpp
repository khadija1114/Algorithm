#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e6+2;
int ar[N];


int partition ( int low, int high) {
	int pivot = ar[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (ar[j] < pivot)
		{
			i++;
			swap(ar[i], ar[j]);
		}
	}
	swap(ar[i + 1], ar[high]);
	return (i + 1);
}


void quickSort( int low, int high) {
	if (low < high) {
		int pi = partition(low, high);

		quickSort( low, pi - 1);
		quickSort( pi + 1, high);
	}
}


int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
        cin>>ar[i];
	quickSort( 0, n - 1);

    for(i=0;i<n;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
}
