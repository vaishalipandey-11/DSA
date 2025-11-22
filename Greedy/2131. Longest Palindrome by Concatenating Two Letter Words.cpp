 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {

        unordered_map<string, int> mp;
        for (auto& word : words) {
            mp[word]++;
        }
        int result = 0;
        bool centerfill = false;

        for (auto& word : words) {
            string rev = word;
            reverse(word.begin(), word.end());

            if (word != rev) { // ab , ba
                if (mp[word] > 0 && mp[rev] > 0) {
                    mp[word]--;
                    mp[rev]--;
                    result += 4;
                }

            } else { // aa
                if (mp[word] >= 2) {
                    mp[word] -= 2;
                    result += 4;
                } else if (mp[word] == 1 && centerfill == false) {
                    mp[word]--;
                    centerfill = true;
                    result += 2;
                }
            }
        }
        return result;
    }
};