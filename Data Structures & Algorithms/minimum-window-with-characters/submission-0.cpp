class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()){
            return "";
        }

        unordered_map<char, int> window, target;

        for(char c : t){
            target[c]++;
        }

        int required = target.size();
        int formed = 0;

        int left = 0, right = 0;
        int minLen = INT_MAX;
        int start = 0;

        while(right < s.length()){
            char c = s[right];
            window[c]++;

            if(target.count(c) && window[c] == target[c]){
                formed++;
            }

            while(left <= right && formed == required){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                char c = s[left];
                window[c]--;
                
                if(target.count(c) && window[c] < target[c]){
                    formed--;
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
