class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for (string log: logs) {
            if (log == "../") {         // go to parent
                if (count > 0) {
                    --count;
                }
            } else if (log != "./") {   // go to child
                ++count;
            }
        }
        return count;
    }
};