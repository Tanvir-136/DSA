#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[5] = {5, 1, 4, 2, 8}; 
    
    int item = 5;
    sort(arr, arr + 5);
    int beg = 0, end = 5 - 1;
    bool flag = false;

    while(beg <= end){
        int mid = (beg + end) / 2;
        if(item > arr[mid]){
            beg = mid + 1;
        }else if(item < arr[mid]){
            end = mid - 1;
        }else{
            flag = true;
            cout << "Found at index: " << mid << endl;
            break;
        }
    }
    if(flag == false){
        cout << "Not Found!" << endl;
    }
    return 0;
}