
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        function<void(int, int)> solve = [&](int index, int sum) {
            if (sum == target) {
                ans.push_back(temp);
                return;
            }

            if (sum > target || index == candidates.size())
                return;

            temp.push_back(candidates[index]);
            solve(index, sum + candidates[index]);

            temp.pop_back();
            solve(index + 1, sum);
        };

        solve(0, 0);
        return ans;
    }
};
