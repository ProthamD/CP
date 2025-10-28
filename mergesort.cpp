#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int>& arr, int low, int mid, int high){
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = 0; i < temp.size(); i++){
        arr[low + i] = temp[i];
    }
}
void mergesort(vector<int>& arr, int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}


int main(){
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();
    mergesort(arr, 0, n - 1);
    for(int i : arr) {
        cout << i << " ";
    }
    return 0;
}