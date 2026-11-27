
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        vector<int> freeCnt(n, 0);

        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeCnt[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];

            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j], dp[j - price] + freeCnt[i] + 1);
            }
        }

        int ans = 0;

        for (int j = 0; j <= budget; j++) {
            ans = max(ans, dp[j] + (budget - j) / minPrice);
        }

        return ans;
    }
};
