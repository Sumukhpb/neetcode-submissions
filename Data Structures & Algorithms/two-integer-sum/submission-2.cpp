class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> imap;

        for (int i = 0; i < nums.size(); i++) {
           imap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int val = target - nums[i];

            if (imap.find(val) != imap.end() && imap[val] != i) {
                return {i, imap[val]};
            }
        }
        return {};
    }
};
