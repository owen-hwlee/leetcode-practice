class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            // Array length too short to have 132 pattern
            return false;
        }

        int min = nums[0];          // keeps track of potential nums[i]
        stack<pair<int, int>> s;    // monotone decreasing stack for (nums[j], nums[i]) pairs
                                    //  essentially pair of (n, minLeft)

        for (size_t t = 1; t < nums.size(); ++t) {
            const int& n = nums[t];

            while (!s.empty() && s.top().first <= n) {
                // pop smaller values to maintain monotone decrease for n aka pair[0]
                s.pop();
            }
            if (!s.empty() && s.top().second < n) {
                // check if current element can be nums[k] aka '2'
                // s.top() == (nums[j], nums[i])
                // n < s.top().first aka nums[k] < nums[j] has already been satisfied in the while loop
                return true;
            }

            // min is guaranteed to exist before n, can push to stack
            s.push(make_pair(n, min));
            if (min > n) {
                min = n;
            }
        }
        return false;
    }
};