#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!word.empty()) {      // only push if a valid word
                    st.push(word);
                    word = "";
                }
            } else {
                word += s[i];
            }
        }

        if (!word.empty()) st.push(word); // push the last word

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) ans += " ";
        }

        return ans;
    }
};


class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.length() - 1;
        string temp = "";
        string ans = "";

        while (left <= right) {
            char ch = s[left];
            if (ch == ' ') {
                if (!temp.empty()) {
                    if (!ans.empty()) ans = temp + " " + ans;
                    else ans = temp;
                    temp = "";
                }
            } else {
                temp += ch;
            }
            left++;
        }

        // last word
        if (!temp.empty()) {
            if (!ans.empty()) {
                ans = temp + " " + ans;
            } else {
                ans = temp;
            }
        }
        return ans;
    }
};