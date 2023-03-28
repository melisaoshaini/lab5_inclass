// CPP program to find mean and median of
// an array
#include <bits/stdc++.h>
using namespace std;



// Function for calculating median
double findMedian(int a[], int n)
{
	// First we sort the array
	sort(a, a + n);

	// check for even case
	if (n % 2 != 0)
		return (double)a[n / 2];

	return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}

// Driver code
int main()
{
	int a[] = { 1, 3, 4, 2, 7, 5, 8, 6 };
	int N = sizeof(a) / sizeof(a[0]);
  cout<<"entered array is: ";
  for (int i = 0; i < N; i++) {
    cout << a[i] << " ";
}
    cout<<endl;
  cout<<endl;


  for (int i=1;i<=N;i++){
    int size =i;
    int *newarr = new int[size](); 

    for (int m = 0; m < size; m++) {
    newarr[m] = 0;
}
    
    for(int k=0;k<size;k++){
      newarr[k]=a[k];
    }
    for (int i = 0; i < size; i++) {
    cout << newarr[i] << " ";
}
    cout<<endl;

    

   // int p = sizeof(newarr) / sizeof(newarr[0]);

   cout << "Median = " << findMedian(newarr, size) << endl; 
    delete[] newarr;
    cout<<endl;
  }
  


	
	return 0;
}
