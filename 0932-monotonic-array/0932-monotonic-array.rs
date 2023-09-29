impl Solution {
    pub fn is_monotonic(nums: Vec<i32>) -> bool {
        if nums.len() <= 2 {
            return true;
        }

        let mut is_desc: bool = true;
        let mut is_asc: bool = true;

        let mut i: i32 = nums[0];
        for j in 1..nums.len() {
            let j: i32 = nums[j];

            if i < j {
                is_desc = false;
            }
            if i > j {
                is_asc = false;
            }

            if !is_desc && !is_asc {
                return false;
            }

            i = j;
        }

        true
    }
}