class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, N = s.size(), cnt[128] = {}, dup = 0, ans = 0;
        while (j < N) {
            dup += ++cnt[s[j++]] == 2;
            while (dup) dup -= --cnt[s[i++]] == 1;
            ans = max(ans, j - i);
        }
        return ans;
    }
};