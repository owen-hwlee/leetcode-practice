class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        const size_t size = nums.size();

        if (size <= 2) {
            // must be monotone
            return true;
        }

        bool is_decr = true;
        bool is_incr = true;

        for (size_t i = 1; i < size; ++i) {
            if (nums[i - 1] < nums[i]) {
                is_decr = false;
            }
            if (nums[i - 1] > nums[i]) {
                is_incr = false;
            }
            
            if (!is_decr && !is_incr) {
                // both boolean flag false means array contains both increase and decrease hence no longer monotone
                return false;
            }
        }

        return true;
    }
};