#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {4, 3, 2, 8, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int item = 10;
    bool flag = false;
    for(int i = 0; i < size; ++i){
        if(arr[i] == item){
            flag = true;
            cout << i << endl;
        }
    }
    if(!flag){
        cout << -1 << endl;
    }
    return 0;
}