class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> dupli;
        for (int num : nums) {
            if (dupli.count(num)) {
                return true;
            }
            dupli.insert(num);
        }
        return false;
    }
};