class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        const int& n = nums.size();

        for (int i = 0; i < n; ++i) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return { map[complement], i };
            } else {
                map[nums[i]] = i;
            }
        }
        return {};
    }
};