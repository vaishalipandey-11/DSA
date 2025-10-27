#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n = matrix.size();//row
      int m = matrix[0].size(); // col
      int i=0 ;int j =m-1;
      while(i<n && j>=0){
        if(matrix[i][j] > target){
            j--;
        }else if(matrix[i][j] < target){
           i++;
        }else{
            return true ;
        }
      }
      return false;
    }
};