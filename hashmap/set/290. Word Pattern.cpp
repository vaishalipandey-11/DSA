#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;
#include <vector>
// This code checks if a given pattern matches a string of words.
// The pattern consists of characters, and the string is a sequence of words.
// Each character in the pattern corresponds to a unique word in the string.
// If the same character appears multiple times in the pattern, it must correspond to the same word each time.

class Solution {
public:
    bool wordPattern(string pattern, string s) {
      unordered_map<char , string>charToWord;
      unordered_set<string>usedword;
      vector<string>words;

    // tokanize the string first  
      stringstream ss(s);
      string word ;
      while(getline(ss , word ,' ' )) {
        words.push_back(word);

      }
      // what if the string and pattern are not equal in size
      if (words.size() != pattern.size()) return false;

    // now put in map and check for avail..interating on pattern 
    for(int i =0 ; i<pattern.length() ; i++){
      char charofpattern = pattern[i];

     // if already mapped 
      if(charToWord.count(charofpattern) ){
        if(charToWord[charofpattern] != words[i]) return false;
      }  else{
        if(usedword.count(words[i])) return false;
      }

     charToWord[charofpattern] = words[i];
     usedword.insert(words[i]);

    }
    return true ;
    }
    
};