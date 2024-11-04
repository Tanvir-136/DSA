#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "To be or not 2B, that is the ?";
    string pattern = "2B, ";
    
    int index = s.find(pattern); 
    while(index != -1){
        s.erase(index, pattern.length());
        index = s.find(pattern);
    }
    cout << s << endl;
}   