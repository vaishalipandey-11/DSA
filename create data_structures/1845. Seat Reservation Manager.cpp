
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
 
class SeatManager {
public: 
vector<int>vec;
int N ;

    SeatManager(int n) {
       N =n ;
       vec.resize(N+1 , -1);
        
    }
    
    int reserve() {
        for(int i =1 ; i<N+1 ; i++){
            if(vec[i]==-1){
                vec[i]=1;
                return i;
            }
        }
       return -1;
        
    }
    
    void unreserve(int seatNumber) {
        vec[seatNumber ]= -1;
        
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SeatManager {
public:
    priority_queue<int , vector<int> , greater<int>> pq;
    SeatManager(int n) {
        for(int i =1 ; i<=n  ; i++){
            pq.push(i);
        }
        
    }
    
    int reserve() {
        if(!pq.empty()){
         auto small = pq.top();
         pq.pop();
         return small;
        }
        return -1;
        
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
        
    }
};

