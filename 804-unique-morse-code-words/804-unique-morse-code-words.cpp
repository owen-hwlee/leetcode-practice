class Solution {
public:
    string morse_code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    int uniqueMorseRepresentations(vector<string>& words) {
        if (words.size() == 1) return 1;
        
        unordered_map<string, int> freq_mapping = unordered_map<string, int>();
        
        for (string word: words) {
            string transformation;
            for (char c: word) {
                transformation.append(morse_code[c - 'a']);
            }
            ++freq_mapping[transformation];
        }
        
        return freq_mapping.size();
    }
};