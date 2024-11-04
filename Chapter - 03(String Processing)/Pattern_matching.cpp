#include <bits/stdc++.h>
using namespace std;

int main(){
    string str = "To be or not 2B, that is the ?";
    string pattern = "2B,";

    int str_len = str.length();
    int pattern_len = pattern.length();
    
    int index = -1;
    if (pattern_len <= str_len){
        int k = 0, max = str_len - pattern_len + 1;
        while (k < max){
            int l;
            for (l = 0; l < pattern_len; l++){
                if (pattern[l] != str[l + k])
                    break;
            }
            if (l == pattern_len){
                index = k;
                break;
            }
            k++;
        }
    }
    
    cout << "Index is : " << index << endl;
    return 0;
}
