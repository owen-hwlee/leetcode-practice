class Solution {
public:
    bool isValid(string s) {
        if (s.size() & 1) return false;
        vector<char> stack;
        for (char c: s) {
            switch (c) {
                // opening brackets
                case '(':
                case '[':
                case '{':
                    stack.push_back(c);
                    break;
                // closing brackets
                default:
                    if (stack.empty()) return false;    // closing parenthesis in front of opening
                    if (!isCorrectClose(stack.back(), c)) {
                        return false;       // wrong closing parenthesis
                    } else {
                        stack.pop_back();   // parenthesis closed
                    }
            }
        }
        return stack.empty();
    }
    
private:
    inline bool isCorrectClose(char& open, char& close) {
        switch (open) {
            case '(':
                return close == ')';
            case '[':
                return close == ']';
            case '{':
                return close == '}';
        }
        return false;
    }
};