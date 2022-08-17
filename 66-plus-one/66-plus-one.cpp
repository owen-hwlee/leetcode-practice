class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int counter = digits.size() - 1;
        bool needsNextDigitIncrement;
        
        do {
            needsNextDigitIncrement = false;
            digits[counter] += 1;
            if (digits[counter] > 9) {
                digits[counter--] %= 10;
                needsNextDigitIncrement = true;
                if (counter < 0) {
                    digits.insert(digits.begin(), 1);
                    break;
                }
            }
        } while (needsNextDigitIncrement);
        
        return digits;
    }
};