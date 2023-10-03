use std::collections::HashMap;

impl Solution {
    pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
        // the order of good pairs doesn't matter
        // can treat question as counting number of edges in fully connected graph
        // i.e. number of good pairs for n counts of the same number = n(n-1)/2
        // first count frequency of each element
        // then iterate over the hashmap to find elements with >= 2 frequency
        // add n(n-1)/2 to total tally for each valid element

        if nums.len() < 2 {
            return 0;
        }

        let mut map: HashMap<i32, i32> = HashMap::new();

        for i in nums {
            map.entry(i)
               .and_modify(|x| *x += 1)
               .or_insert(1);
        }

        let mut count: i32 = 0;
        for (num, freq) in map {
            if freq >= 2 {
                count += freq * (freq - 1) / 2;
            }
        }
        count
    }
}