class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last_occurrence(26, -1);
        vector<bool> used(26, false);
        stack<char> st;

        // Calculate the last occurrence of each character in the string
        for (int i = 0; i < s.size(); ++i) {
            last_occurrence[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); ++i) {
            char currChar = s[i];

            if (!used[currChar - 'a']) {
                while (!st.empty() && currChar < st.top() && last_occurrence[st.top() - 'a'] > i) {
                    used[st.top() - 'a'] = false;
                    st.pop();
                }

                st.push(currChar);
                used[currChar - 'a'] = true;
            }
        }

        string result(st.size(), ' ');

        // Construct the result string in reverse order from the stack
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
