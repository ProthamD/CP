#include<iostream>
#include<vector>
using namespace std;

int partitioning(vector<int>& arr, int low, int high) {
    // 1. init the pivoty point
    int pivot = arr[high];
    int Pi = low;
    for(int i = low; i < high; i++) {
        if(arr[i] <= pivot){
            swap(arr[i], arr[Pi]);
            Pi++;
        }
    }
    swap(arr[Pi], arr[high]);
    return Pi;
}

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int Pi = partitioning(arr, low, high);// first lefts do partitioning
        quicksort(arr, low, Pi - 1); //  then if we could have from low to Pi-1
        quicksort(arr, Pi + 1, high);// then if we could have from Pi+1 to high
    }
}

int main(){
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quicksort(arr, 0, n - 1);
    for(int i : arr) {
        cout << i << " ";
    }
    return 0;
}