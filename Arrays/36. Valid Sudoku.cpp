#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //lets validate row 
       
        for(int row=0 ;row<9 ; row++){
            set<char>st;
            for(int col =0 ; col<9 ; col++){
                if(board[row][col] =='.') {continue;}
                else{
                    if(st.find(board[row][col]) != st.end()) return false ;
                    st.insert(board[row][col]);
                }
            }
        }

        //validate col
        for(int col=0 ;col<9 ; col++){
            set<char>st;
            for(int row =0 ; row<9 ; row++){
                if(board[row][col] =='.') {continue;}
                else{
                    if(st.find(board[row][col]) != st.end()) return false ;
                    st.insert(board[row][col]);
                }
            }
        }

        // validate cell now 
        //we have sr,er,sc,ec
        for(int sr =0 ; sr<9 ;sr+=3){
            int er=sr+2;
            for(int sc =0 ; sc<9 ; sc+=3){
                int ec=sc+2;
                //now  cell movement
            set<char>st;
                for(int i =sr; i<=er ; i++){
                    for(int j = sc ; j<=ec; j++){
                        if(board[i][j] =='.') {continue;}
                else{
                    if(st.find(board[i][j]) != st.end()) return false ;
                    st.insert(board[i][j]);
                }
                    }
                }
            }
        }
        return true;


        
    }
};