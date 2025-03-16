//Approach-1 (Using simple right shift operator)
//T.C : O(1) - because the loop in the code iterates 32 times, which is a constant number regardless of the input n
//S.C : O(1)
class Solution {
public:

    int hammingWeight(int n) {
        int count =0;
        for(int i =31; i>=0; i--){
            if(((n>>i)&1)==1){ // shift kro i se or check if its 1 or not 
                count ++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n); // builtin function
    }
};
class Solution {
public:
    int hammingWeight(int n) {
        int count =0;
        while(n){
            n = (n&(n-1)); // it is used to unset bits == no.of 1's
            count++;
        }
        return  count ;
    }
};