class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int& k : nums) {
            if (s.find(k) != s.end()) return true;
            s.insert(k);
        }
        return false;
    }
};

// sort
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=1;i<nums.size();++i) {
            if (nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};