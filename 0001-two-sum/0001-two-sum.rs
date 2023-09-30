impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        use std::collections::HashMap;
        let mut map: HashMap<i32, i32> = HashMap::new();

        for (i, n) in nums.iter().enumerate() {
            let complement: i32 = target - n;
            if (map.contains_key(&complement)) {
                return vec![map[&complement], i as i32];
            } else {
                map.insert(*n, i as i32);
            }
        }
        return vec![];
    }
}