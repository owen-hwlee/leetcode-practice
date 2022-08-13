class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> results;
        int totalWordsLength = 0;
        for (string word: words) {
            totalWordsLength += word.size();
        }
        // input validation
        if (s.size() < totalWordsLength) {
            return results;     // given string s too short, return empty vector
        }

        int wordLength = words[0].size();
        map<string, int> givenWordsOccurrence;
        // store occurrence of given words
        for (string word: words) {
            givenWordsOccurrence[word] += 1;
        }
        
        // for each substring compute occurrence of words and compare against given
        for (int i = 0; i < s.size() - totalWordsLength + 1; ++i) {
            map<string, int> currentWordOccurrence;
            string currentWord = s.substr(i, totalWordsLength);
            for (int j = 0; j < totalWordsLength; j += wordLength) {
                currentWordOccurrence[currentWord.substr(j, wordLength)] += 1;
            }
            if (currentWordOccurrence == givenWordsOccurrence) {
                results.push_back(i);
            }
        }
        
        return results;
    }
    
    // void print_map(map<string, int> const &m) {
    //     cout << "-------------------" << endl;
    //     for (const pair<string, int> p: m) {
    //         cout << "{" << p.first << ": " << p.second << "}\n";
    //     }
    // }
};