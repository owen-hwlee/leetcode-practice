class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        regex re("^[a-z0-9]+\/$");
        for (string log: logs) {
            if (log.compare("../") == 0 && count > 0) {     // go to parent
                --count;
            } else if (regex_match(log, re)) {              // go to child
                ++count;
            }
        }
        return count;
    }
};