
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long >v(n , 0);
        for(int i=0 ; i<n ; i++){
             priority_queue<long long >pq;
            for(int j=0 ; j<n ; j++){

                if(i==j) continue;
                else {
                    if(nums1[i]> nums1[j]){
                        pq.push(nums2[j]);
                    }                    
                }
            }
            int K=k;
            int sum =0;
            while(K!=0 && !pq.empty()){
                sum += pq.top();
                pq.pop();
                K--;
            }

            v[i]=sum;
        }
        return v;
    }
};




class Solution {
public:
typedef long long ll;

    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<int>> v;
        for(int i=0; i<n ; i++){
            v.push_back({nums1[i], i , nums2[i]});
        }

        sort(v.begin(), v.end());

        vector<ll >result(n,0);

        priority_queue<int , vector<int> , greater<int>> p;
        ll sum =0;
        for(int i=0 ; i<n ; i++){
           
            if(i>0 &&  v[i-1][0]== v[i][0]){
                result[v[i][1]]=result[v[i-1][1]];
            }else{
                result[v[i][1]]=sum ;
            }

            p.push(v[i][2]);
            sum += v[i][2];
            if(p.size() > k){
                sum -= p.top();
                p.pop();
            }

        }
        return result ;



        
    }
};