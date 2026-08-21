#include <iostream>
#include <vector>
using namespace std;

int main() {
    int wt[] = {1, 2, 5, 6};
    int val[] = {2, 3, 4, 5};

    int n = 4;
    int W = 8;

    int dp[n + 1][W + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w],
                    val[i - 1] + dp[i - 1][w - wt[i - 1]]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum value = " << dp[n][W] << endl;

    return 0;
}
