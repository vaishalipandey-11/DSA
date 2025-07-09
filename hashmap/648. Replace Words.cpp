#include <vector>
#include <unordered_set>
#include <sstream>
#include <string>
using namespace std;
class Solution {
public:
    string findroot(string& word, unordered_set<string>& st) {
        for (int i = 1; i <= word.length(); i++) { // Start from 1 to avoid empty string
            string prefix = word.substr(0, i);     // prefixes: c, ca, cat, catt...
            if (st.count(prefix)) {
                return prefix; // Found the root
            }
        }
        return word; // No root found, return the original word
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end()); // Store dict in set

        stringstream ss(sentence);
        string word;
        string result;

        while (getline(ss,word,' ')) { // Simple space-separated extraction
            result += findroot(word, st) + " ";
        }

        if (!result.empty()) {
            result.pop_back(); // Remove the trailing space
        }

        return result;
    }
};
