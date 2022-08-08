class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& A) {
        int N = s.size(), M = A[0].size(), len = M * A.size();
        unordered_map<string, int> cnt, tmp;
        for (auto &w : A) cnt[w]++;
        vector<int> ans;
        for (int start = 0; start < M; ++start) {
            tmp.clear();
            int matched = 0;
            for (int i = start; i < N; i += M) {
                auto w = s.substr(i, M);
                if (cnt.count(w) && ++tmp[w] <= cnt[w]) matched++;
                if (i - len >= 0) {
                    auto rm = s.substr(i - len, M);
                    if (cnt.count(rm) && --tmp[rm] < cnt[rm]) matched--;
                }
                if (matched == A.size()) ans.push_back(i - len + M);
            }
        }
        return ans;
    }
};