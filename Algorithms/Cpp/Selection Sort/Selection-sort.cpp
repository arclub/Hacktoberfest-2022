//Having two subarrays
//one which is already sorted
//another subarray which we have to sort

#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[], int size){  // arr[n] = {25,3,5,11,4} initializing a arr[0] = min
    for(int i = 0; i < size; i++){
        //for loop finding the smallest element in (i .... size - 1)
        int min = INT_MAX;
        int idx;
        for(int j = i; j < size; j++){
            if(arr[j] < min){
                min = arr[j];
                idx = j;
            }
        }
        swap(arr[i], arr[idx]);
    }
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int size;
    cin>>size;

    int arr[size];
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    SelectionSort(arr, size);
}

//The basic Two steps that are included in the
//Find the smallest element 
//swap the smallest number with some other elements

//This code is contributed by Jayant Verma