#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mat[n][n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
            // if (mat[i][j] == 0)      
            //     mat[i][j] = (int)1e7;
        }
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                //mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]); // for shortest path                
                mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]); // for path matrix
            }
        }
    }

    cout << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}