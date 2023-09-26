class Solution {
public:
    string removeDuplicateLetters(string s) {
        int freq[26]{};     // frequency array for each letter
        for (int i = 0; i < s.size(); ++i) {
            freq[s[i] - 'a']++;
        }

        stack<char> st;     // monotonic stack maintaining lexicographical order of char
        bool included[26]{};     // track included letters

        for (int i = 0; i < s.size(); ++i) {
            int letterIdx = s[i] - 'a';
            if (included[letterIdx]) {
                // skip included char
                freq[letterIdx]--;
                continue;
            }

            while (!st.empty() && st.top() > s[i] && freq[st.top() - 'a'] > 0) {
                // pop larger char on the condition that char will appear again in the future
                included[st.top() - 'a'] = false;
                st.pop();
            }
            // add current char to stack and track
            st.push(s[i]);
            included[letterIdx] = true;
            freq[letterIdx]--;
        }

        // construct the string from stack
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};