#include <iostream>

using namespace std;

namespace FinanceSolver {

    int minCoinsForChange(const int coins[], int coinsSize, int amount) {
        int* dp = new int[amount + 1];
        
        for (int i = 0; i <= amount; ++i) {
            dp[i] = amount + 1;
        }
        
        dp[0] = 0;
        
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coinsSize; ++j) {
                int coin = coins[j];
                
                if (i - coin >= 0) {
                    int alternative = dp[i - coin] + 1;
                    if (alternative < dp[i]) {
                        dp[i] = alternative;
                    }
                }
            }
        }
        
        int result = dp[amount];
        delete[] dp;
        
        return result > amount ? -1 : result;
    }

}

int main() {
    int coins[] = {1, 2, 5};
    int coinsSize = sizeof(coins) / sizeof(coins[0]);
    int amount = 11;
    
    int result = FinanceSolver::minCoinsForChange(coins, coinsSize, amount);
    
    if (result != -1) {
        cout << "Minimum coins required for change: " << result << endl;
    } else {
        cout << "It's impossible to make exact change with the given denominations." << endl;
    }
    
    return 0;
}
