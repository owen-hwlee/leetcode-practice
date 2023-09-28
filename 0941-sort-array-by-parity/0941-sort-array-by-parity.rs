impl Solution {
    pub fn sort_array_by_parity(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        let mut leftmost_odd_index: usize = 0;
        let mut is_odd_discovered: bool = false;
        for i in 0..nums.len() {
            if nums[i] % 2 == 1 {
                // odd number: leave it there for now
                if !is_odd_discovered {
                    is_odd_discovered = true;
                    leftmost_odd_index = i;
                }
            } else {
                // even number: swap with leftmost odd number
                // no need to swap if no odd number has been discovered
                if is_odd_discovered {
                    nums.swap(leftmost_odd_index, i);
                    leftmost_odd_index += 1;
                    if nums[leftmost_odd_index] % 2 == 0 {
                        // no more odd numbers before index i
                        is_odd_discovered = false;
                    }
                }
            }
        }
        nums    // shorthand for `return nums;`
    }
}