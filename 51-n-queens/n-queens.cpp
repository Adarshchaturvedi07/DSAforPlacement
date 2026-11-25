
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<int> col(n, 0);
        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);

        function<void(int)> solve = [&](int row) {
            if (row == n) {
                ans.push_back(board);
                return;
            }

            for (int j = 0; j < n; j++) {
                if (col[j] || diag1[row - j + n - 1] || diag2[row + j])
                    continue;

                board[row][j] = 'Q';
                col[j] = 1;
                diag1[row - j + n - 1] = 1;
                diag2[row + j] = 1;

                solve(row + 1);

                board[row][j] = '.';
                col[j] = 0;
                diag1[row - j + n - 1] = 0;
                diag2[row + j] = 0;
            }
        };

        solve(0);
        return ans;
    }
};
