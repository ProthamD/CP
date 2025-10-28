#include <iostream>
#include <vector>
using namespace std;

struct student{
    int marks;
    string name;
};

void merge(vector<student>& students, int low, int mid, int high){
    int left = low;
    int right = mid + 1;
    vector<student> temp;
    while(left <= mid && right <= high){
        if(students[left].marks <= students[right].marks){
            temp.push_back(students[left]);
            left++;
        }
        else{
            temp.push_back(students[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(students[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(students[right]);
        right++;
    }
    for(int i =low; i <= high; i++){
        students[i] = temp[i - low];
    }
}

void mergesort(vector<student>& arr, int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main(){
    vector<student> arr = {{34, "abc"}, {23, "def"}, {45, "ghi"}};
    mergesort(arr, 0, arr.size() - 1);
    for(auto i : arr) {
        cout << i.name << " " << i.marks << endl;
    }   
    return 0;


}