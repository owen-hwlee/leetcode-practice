impl Solution {
    pub fn winner_of_game(colors: String) -> bool {
        if colors.len() < 3 {
            return false;
        }

        let mut turn_diff: i32 = 0;
        let mut count: i32 = 0;
        let mut curr: char = '\0';

        for c in colors.chars() {
            if c == curr {
                count += 1;
                if count >= 3 {
                    turn_diff += if c == 'A' { 1 } else { -1 };
                }
            } else {
                curr = c;
                count = 1;
            }
        }

        turn_diff > 0
    }
}