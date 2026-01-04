#include <string>   
using namespace std;
class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        int A =0;
        int B =0;

        for(int i=1; i<n-1 ; i++){
            if(colors[i-1]==colors[i] && colors[i]==colors[i+1]){
                if(colors[i]=='A') A++;
                else B++;
            }
        }
        return A>B;
        
    }
};