impl Solution {
    pub fn reverse_words(s: String) -> String {
        let mut i: usize = 0;
        let mut j: usize = 0;
        let size: usize = s.len();
        let mut s: Vec<u8> = s.into_bytes();

        fn swap_char(s: &mut Vec<u8>, start: &usize, end: &usize) {
            let num_swap: usize = (end + 1 - start) / 2;
            for k in 0..num_swap {
                s.swap(start + k, end - k);
            }
        }

        for k in 1..size {
            if (s[k] == (' ' as u8)) {
                swap_char(&mut s, &i, &j);
                i = k + 1;      // no need to update j because next char is guaranteed to update j
            } else {
                j = k;
            }
        }
        swap_char(&mut s, &i, &j);

        unsafe { String::from_utf8_unchecked(s) }
        // String::from_utf8(s).unwrap()
    }
}