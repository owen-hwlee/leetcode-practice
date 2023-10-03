class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> map;
        for (const int& num: nums) {
            ++map[num];
        }

        int pairs = 0;
        for (const pair<int, int>& p: map) {
            const int& freq = p.second;
            if (freq > 1) {
                pairs += freq * (freq - 1) / 2;
            }
        }
        return pairs;
    }
};