class Solution {
public:
    bool winnerOfGame(string colors) {
        // pieces can only be removed when they are between pieces of the same colour
        // if a contiguous subsequence has n consecutive pieces of the same colour
        // (n - 2) pieces can be taken away, of course given that n >= 3
        // since only middle pieces can be taken away
        // removal does not impact or create new contiguous subsequences that allows removal
        // therefore only need to count number of middle pieces
        // or to remove one more variable, count difference between num for Alice and Bob
        // since Alice moves first, Alice can only win if the diff > 0, else Bob wins

        int turn_diff = 0;      // num_alice - num_bob, +ve -> Alice wins
        int count = 1;
        char curr = colors[0];
        const size_t& size = colors.size();
        
        for (size_t i = 1; i < size; ++i) {
            const char& c = colors[i];
            if (c == curr) {
                ++count;
                if (count >= 3) {
                    turn_diff += (c == 'A') ? 1 : -1;
                }
            } else {
                curr = c;
                count = 1;
            }
        }

        return turn_diff > 0;
    }
};