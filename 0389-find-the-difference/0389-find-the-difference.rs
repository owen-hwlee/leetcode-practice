impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        // use bitwise XOR on all letters in both s and t to reveal the remaining letter
        
        let mut x: u8 = 0;
        
        // perform bitwise XOR in u8 (which is bitwise equivalent to char)
        for c in s.chars() {
            x ^= (c as u8);
        }
        for c in t.chars() {
            x ^= (c as u8);
        }
        
        return x as char;
    }
}