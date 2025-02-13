#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include<vector>
class Solution {
public:
// brute force approach
    void row(vector<vector<int>>& matrix, int i, int m) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -100000;
            }
        }
    }

    void col(vector<vector<int>>& matrix, int j, int n) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -100000;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();  // Number of rows
        int m = matrix[0].size();  // Number of columns

        // Mark all elements as -1 where a 0 is found
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row(matrix, i, m);
                    col(matrix, j, n); 
                }
            }
        }

        // Replace all -1 with 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -100000) { 
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); // row
        int m = matrix[0].size(); //col
        //flag array
        vector<int>row(n,0);
        vector<int>col(m,0);
        // traverse whole matrix for 0
        for(int i =0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        //traverse and look at the flag to change value 
        for(int i =0 ;i<n ; i++){
            for(int j =0 ; j<m ; j++){
                if(row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
        }


    }
};