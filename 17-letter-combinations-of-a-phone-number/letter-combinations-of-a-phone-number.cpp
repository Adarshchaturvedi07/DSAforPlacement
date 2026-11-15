
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string temp;

        function<void(int)> solve = [&](int i) {
            if (i == digits.size()) {
                ans.push_back(temp);
                return;
            }

            for (char c : mp[digits[i] - '0']) {
                temp.push_back(c);
                solve(i + 1);
                temp.pop_back();
            }
        };

        solve(0);
        return ans;
    }
};
