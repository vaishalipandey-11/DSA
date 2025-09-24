
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class RandomizedSet {
public:
vector<int>vec;
unordered_map<int,int>mp;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        vec.push_back(val);
        mp[val] = vec.size()-1;
        return true;
        
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int idx = mp[val];
        int lastele = vec.back();
        vec.back()= val;

        vec[idx]= lastele;
        mp[lastele]=idx;
        vec.pop_back();
        mp.erase(val);
        return true;
        
    }
    
    int getRandom() {
        int n = vec.size();
        return vec[rand()%n];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */