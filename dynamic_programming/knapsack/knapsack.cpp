#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> val(n + 1), wt(n + 1);   // 1-indexed
    for (int i = 1; i <= n; i++) {
        cin >> val[i] >> wt[i];          // value then weight
    }

    // dp[i][j] = max value using first i items with capacity j
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            // 1. Don't take item i
            dp[i][j] = dp[i - 1][j];

            // 2. Take item i (only if it fits)
            if (j >= wt[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - wt[i]] + val[i]);
            }
        }
    }

    cout << dp[n][W] << "\n";
}