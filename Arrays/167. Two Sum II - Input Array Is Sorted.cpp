//2poointer approach
#include <vector>
using namespace std;    
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0 ;
        int r =  numbers.size()-1;
        while(l<r){
            if(numbers[l]+numbers[r]==target) return {l+1, r+1}; // 1 based index so 
            if(numbers[l]+numbers[r] > target){
                r--;
            }else{
                l++;
            }
        }
        return {};
    }
};

//bf
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i =0 ; i<n ; i++){
            for(int j =i+1 ; j<n ;j++){
                if(numbers[i]+numbers[j]==target) return {i+1,j+1}; // because its 1 indexed okay 
            }
        }
        return {};
        
    }
};