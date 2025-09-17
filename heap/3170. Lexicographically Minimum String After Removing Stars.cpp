
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
typedef pair<char , int > p;
    string clearStars(string s) {
        int n = s.size();
        struct comp{
            bool operator() (const pair<char ,int> &p1 ,const pair<char,int>&p2 ){
                if(p1.first == p2.first) return p1.second < p2.second;
                else  return p1.first > p2.first;
            }
        };

        priority_queue<p , vector<p> , comp > pq;

        for(int i=0 ;i<n ; i++){
            if(s[i]== '*'){
               s[pq.top().second]='*';
               pq.pop();
            }else{
               pq.push({s[i], i});
            }
        }
        string result = "";
        for(auto &it : s){
            if(it != '*'){
                 result += it;
            }
           
        }
        
        return result;

         
    }
};


class Solution {
public:
typedef pair<char , int > p;
    string clearStars(string s) {
        int n = s.size();
        struct comp{
            bool operator() (const pair<char ,int> &p1 ,const pair<char,int>&p2 ){
                if(p1.first == p2.first) return p1.second < p2.second;
                else  return p1.first > p2.first;
            }
        };

        priority_queue<p , vector<p> , comp > pq;

        for(int i=0 ;i<n ; i++){
            if(s[i]== '*'){
                pq.pop();
            }else{
               pq.push({s[i], i});
            }
        }
        string result = "";

        priority_queue<pair<int , char >> p;
        while(!pq.empty()){
            auto [x,y] = pq.top(); pq.pop();
            p.push({y ,x});
        }

        while(!p.empty()){
            auto [x,y]= p.top();
            p.pop();
            result += y;
        }
        reverse(result.begin(), result.end());
        return result ;   
    }
};