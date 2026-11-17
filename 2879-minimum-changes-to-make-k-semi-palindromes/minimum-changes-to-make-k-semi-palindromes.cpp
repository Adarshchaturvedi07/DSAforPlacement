
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                int best = INT_MAX;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int cnt = 0;

                    for (int x = 0; x < d; x++) {
                        int l = i + x;
                        int r = i + len - d + x;

                        while (l < r) {
                            if (s[l] != s[r]) cnt++;
                            l += d;
                            r -= d;
                        }
                    }

                    best = min(best, cnt);
                }

                cost[i][j] = best;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX / 2));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int p = 2; p <= i; p++) {
                    dp[i][j] = min(dp[i][j],
                        dp[i - p][j - 1] + cost[i - p][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};
