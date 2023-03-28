#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
 
void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}
int partition (int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
 
    for (int j = p; j <= r- 1; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap (&A[i], &A[j]);
        }
    }
    swap (&A[i + 1], &A[r]);
    return (i + 1);
}
 
void quickSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p,r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

void quickSortIterative(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];
  
    // initialize top of stack
    int top = -1;
  
    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;
  
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];
  
        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);
  
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
  
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}


int main() {
 
  srand(time(nullptr)); // Seed the random number generator with the current time
    
    // Generate five random arrays with lengths in the range of [3, 20]
    for (int i = 0; i < 10; i++) {
        int length = rand() % 20000 + 10000; // Randomly choose a length between 3 and 20
        //cout<<"number of elements:" << length << endl;
        int* arr = new int[length]; // Allocate memory for the array
        
        // Fill the array with random numbers between 0 and 99
        for (int j = 0; j < length; j++) {
            arr[j] = rand() % 100;
        }

     
        
        auto start_timei = high_resolution_clock::now();
        
        quickSort(arr,0,length-1);
        auto end_timei = high_resolution_clock::now();
        auto durationi = duration_cast<milliseconds>(end_timei - start_timei);
        cout<<"Total elements in quick sort array: "<<length<<endl;
        cout << "Time taken to  recursively quick sort the array: " << durationi.count() << " milliseconds" << endl;
      //cout<<"\n"<<endl;

      auto start_timei2 = high_resolution_clock::now();        
        quickSortIterative(arr,0, length - 1);
        auto end_timei2 = high_resolution_clock::now();
        auto durationi2 = duration_cast<milliseconds>(end_timei2 - start_timei2);
       // cout<<"Total elements in merge sort array: "<<length<<endl;
        cout << "Time taken to iteratively merge sort the array: " << durationi2.count() << " milliseconds" << endl;
      cout<<"\n"<<endl;
    }
  return 0;
}