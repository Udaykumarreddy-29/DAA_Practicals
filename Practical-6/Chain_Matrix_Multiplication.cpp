#include <iostream>
using namespace std;
const int INF = 1e9; 
int matrixChainOrder(const int arr[], int size) {
    int dp[100][100] = {0}; 
    for (int l = 2; l < size; l++) {
        for (int i = 1; i < size - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INF;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }   
    return dp[1][size - 1];
}

int main() {
    
    int arr[] = {10, 20, 30, 40};
    int size = sizeof(arr) / sizeof(arr[0]);    
    int minOps = matrixChainOrder(arr, size);
    cout << "Minimum number of multiplications is: " << minOps << endl;
    return 0;
}
