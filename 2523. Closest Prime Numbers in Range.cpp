#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//Approach-1 (Using Sieve Of Eratosthenes)
//T.C : O(Rlog(log(R)) + (R-L))
//S.C : O(R)
class Solution {
public:
    
    vector<bool>sieve(int right){
      vector<bool>isprime(right+1 , true);
        isprime[0]= false;
        isprime[1]= false;
        for(int i =2 ; i*i<=right ; i++){
            if(isprime[i]==true){
                for(int j = 2 ; i*j<=right ; j++){
                    isprime[i*j]=false;
                }
            }
        }
        return isprime;

    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool>isprime = sieve(right);
        //ans 
        vector<int>primes;
        for(int i=left ; i<=right ; i++){
            if(isprime[i]==true){
                primes.push_back(i);
            }
        }
         int mindiff = INT_MAX;
         int diff = 0;
         vector<int>ans = {-1,-1};
        for(int i =1 ; i<primes.size() ; i++){
            diff = primes[i]-primes[i-1];

            if(mindiff > diff){
                    mindiff = diff;
                    ans[0] = primes[i-1];
                    ans[1] = primes[i];

            } 
        }

            return ans;
        
    }
};
//Approach-2 (Using Sieve Of Eratosthenes)
//T.C : O((R-L) * sqrt(R))
//S.C : O(R-L)
class Solution {
public:
    bool isPrime(int num) {
        if(num == 1) { //not a prime
            return false;
        }
        for(int div = 2; div*div <= num; div++) {
            if(num % div == 0) {
                return false;
            }
        }

        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;

        for(int num = left; num <= right; num++) {
            if(isPrime(num) == true) {
                if(!primes.empty() && num - primes.back() <= 2) {
                    return {primes.back(), num}; //Early return
                }

                primes.push_back(num);
            }
        }


        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};
        for(int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i-1];
            if(diff < minDiff) {
                minDiff = diff;
                result = {primes[i-1], primes[i]};
            }
        }

        return result;
    }
};