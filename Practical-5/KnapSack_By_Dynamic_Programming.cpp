#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val) {

    int n = val.size();

    vector<int> dp(W + 1, 0);
    vector<vector<bool>> selected(n, vector<bool>(W + 1, false));

    for (int i = 0; i < n; i++) {

        for (int w = W; w >= wt[i]; w--) {

            if (dp[w] < dp[w - wt[i]] + val[i]) {
                dp[w] = dp[w - wt[i]] + val[i];
                selected[i][w] = true;
            }
        }
    }

    // Find selected items
    int w = W;

    cout << "Selected items:" << endl;

    for (int i = n - 1; i >= 0; i--) {
        if (selected[i][w]) {
            cout << "Weight = " << wt[i]
                 << ", Profit = " << val[i] << endl;

            w = w - wt[i];
        }
    }

    return dp[W];
}

int main() {

    int capacity = 8;

    vector<int> profits = {1, 2, 5, 6};
    vector<int> weights = {2, 3, 4, 5};

    int result = knapsack(capacity, weights, profits);

    cout << "Maximum profit: " << result << endl;

    return 0;
}
