class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }

        vector<int> ans(n);
        vector<int> ancestor(26, -1);

        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';
            int old = ancestor[c];
            ancestor[c] = u;

            ans[u] = 1;
            for (int v : children[u]) {
                int target = ancestor[s[v] - 'a'];
                if (target != -1) {
                    ans[target] += 0;
                }
                dfs(v);
                int newParent = (ancestor[s[v] - 'a'] != -1) ? ancestor[s[v] - 'a'] : u;
                if (newParent != u) {
                } else {
                }
            }
            ancestor[c] = old;
        };

        function<int(int)> dfs2 = [&](int u) {
            ans[u] = 1;
            for (int v : children[u]) {
                ans[u] += dfs2(v);
            }
            return ans[u];
        };

        vector<int> newParent = parent;
        vector<int> stack[26];
        function<void(int)> dfsBuild = [&](int u) {
            int c = s[u] - 'a';
            if (u > 0) {
                if (!stack[c].empty()) {
                    newParent[u] = stack[c].back();
                } else {
                    newParent[u] = parent[u];
                }
            }
            stack[c].push_back(u);
            for (int v : children[u]) {
                dfsBuild(v);
            }
            stack[c].pop_back();
        };

        dfsBuild(0);

        vector<vector<int>> newChildren(n);
        for (int i = 1; i < n; ++i) {
            newChildren[newParent[i]].push_back(i);
        }

        function<int(int)> dfsCalc = [&](int u) {
            int sz = 1;
            for (int v : newChildren[u]) {
                sz += dfsCalc(v);
            }
            return ans[u] = sz;
        };

        dfsCalc(0);
        return ans;
    }
};