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

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int start = 0;
        int end = n * m - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] < target) {
                start = mid + 1;
            } else if (matrix[row][col] > target) {
                end = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};