#include <vector>
using namespace std;
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int l =0; int h = n-1;
        
        while(l<h){
            int mid = l+(h-l)/2;
            if(arr[mid]<arr[h]){//and mid bhi ho skta h or phle bhi uske 
                h= mid;
            }else{
                l=mid+1;
            }
            
        }
        return h;
    }
};
