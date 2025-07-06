#include <vector>
using namespace std;
// This code defines a class SmallestInfiniteSet that maintains a set of integers starting from 1 and allows for popping the smallest integer and adding back integers.

class SmallestInfiniteSet {
public:
vector<bool > nums; // define a vector 
int i ;             // define a smallest value
    SmallestInfiniteSet() {
        nums = vector<bool>(1001, true);  // init vec of size 
         i = 1;                            //current smallest value is i
    }
    
    int popSmallest() {                   
        int result = i;      // save the result
        nums[i]= false;      //mark the smallest false bacause you pop it 
        for(int j =i+1 ; j<1001 ; j++){ // find next smallest 
            if(nums[j]==true){
                i=j;
                break;
            }
        }
        return result ;   // return the smallest
        
    }
    
    void addBack(int num) {  
        nums[num] =true ;  // for adding just make it true 
        if(num<i)  i =num; // what if the added one is the smallest one 
    }
};
