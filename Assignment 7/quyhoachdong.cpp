#include <iostream>
#include <vector>
using namespace std;
int knapsack(int W, vector<int>& w, vector<int>& v) {
    int n = w.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int weight = 1; weight <= W; weight++) {
            if (w[i - 1] <= weight) {
                dp[i][weight] = max(dp[i - 1][weight], dp[i - 1][weight - w[i - 1]] + v[i - 1]);
            } else {
                dp[i][weight] = dp[i - 1][weight];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W, n;
    cout << "Enter bag weight: ";
    cin >> W;

    cout << "Enter number of stuff: ";
    cin >> n;

    vector<int> w(n);
    vector<int> v(n);

    cout << "Enter weight and value of every stuffs:" << std::endl;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    int result = knapsack(W, w, v);
    cout << "Max value ban cos the lay:" << result << std::endl;

    return 0;
}
