class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int l = 0, maxCount = 0;

        for(int r = 0;r < s.size();r++){
            while(set.find(s[r]) != set.end()){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            maxCount = max(maxCount, r - l + 1);
        }
        return maxCount;
    }
};
