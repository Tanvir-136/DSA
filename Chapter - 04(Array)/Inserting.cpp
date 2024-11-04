#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[5] = {1, 2, 4, 5, 6};
    int cur_size = 5;
    int item = 3;
    int pos = 2;

    for(int i = cur_size; i > pos; --i){
        arr[i] = arr[i - 1];
    }

    arr[pos] = item;
    ++cur_size;

    for (int i = 0; i < cur_size; i++) {
        cout << arr[i] << " ";
    }

}