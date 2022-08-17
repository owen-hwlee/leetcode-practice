class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> occurrenceMapping = unordered_map<char, int>();
        unordered_map<char, int> indexMapping = unordered_map<char, int>();
        queue<char> charQueue = queue<char>();
        char c;
        
        for (int i = 0; i < s.size(); ++i) {
            c = s[i];
            occurrenceMapping[c]++;
            if (indexMapping.find(c) == indexMapping.end()) {
                indexMapping[c] = i;
                charQueue.push(c);
            }
        }
        
        do {
            c = charQueue.front();
            if (occurrenceMapping[c] == 1) {
                return indexMapping[c];
            }
            charQueue.pop();
        } while (!charQueue.empty());
        
        return -1;
    }
};