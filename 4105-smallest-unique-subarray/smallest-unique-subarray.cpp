class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n;
        int ans = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hasUnique(nums, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

private:
    bool hasUnique(vector<int>& nums, int len) {
        int n = nums.size();
        unordered_map<long long, int> cnt;

        long long hash = 0;
        long long base = 131;
        long long mod = 1e9 + 7;
        long long power = 1;

        for (int i = 0; i < len; i++) {
            hash = (hash * base + nums[i]) % mod;
            if (i < len - 1) power = (power * base) % mod;
        }

        cnt[hash]++;

        for (int i = len; i < n; i++) {
            hash = (hash - nums[i - len] * power % mod + mod) % mod;
            hash = (hash * base + nums[i]) % mod;
            cnt[hash]++;
        }

        for (auto& [h, c] : cnt) {
            if (c == 1) return true;
        }
        return false;
    }
};