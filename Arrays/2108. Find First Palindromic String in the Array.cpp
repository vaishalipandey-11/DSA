class Solution {
public:
   
    string firstPalindrome(vector<string>& words) {
        for(auto w : words){
            string temp = w;
            reverse(temp.begin(), temp.end());
           if( w ==temp ) return w;
        }
        return "";

        
    }
};