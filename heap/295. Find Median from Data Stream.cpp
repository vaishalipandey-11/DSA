
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;

class MedianFinder {
public:

    priority_queue<int> left_max;
    priority_queue<int, vector<int>, greater<int>> right_min;

    MedianFinder() {}

    void addNum(int num) {

        if (left_max.empty() || num < left_max.top())
            left_max.push(num);
        else 
            right_min.push(num);
         
        if(left_max.size()  > right_min.size()+1){
            right_min.push(left_max.top());
            left_max.pop();
        }

        else if( left_max.size() < right_min.size()){
            left_max.push(right_min.top());
            right_min.pop();
        }

        
        }
    

    double findMedian() {

       if(left_max.size() == right_min.size()) 
       return  ( ((double)left_max.top() + (double)right_min.top()) / 2.0);
    
        else
            return left_max.top();
    }
};
