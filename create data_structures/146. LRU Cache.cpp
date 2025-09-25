
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class LRUCache {
public:
    int capacity ;
    list<pair<int,int>> dll;
    unordered_map<int, list<pair<int,int>>::iterator >mp;
    LRUCache(int capacity) {
      this->capacity=capacity;
    }
    
    int get(int key) {
        if(mp.find(key ) == mp.end()) return -1;

        auto it = mp[key];
        int val = it->second;
        dll.erase(it);
        dll.push_back({key,val});
        mp[key]= --dll.end();

        return val;

        
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
           dll.erase(mp[key]);

        }else if(dll.size() == capacity){
            auto [oldkey , oldval] = dll.front();
            dll.pop_front();
            mp.erase(oldkey);
        }
        dll.push_back({key, value});
        mp[key] = --dll.end();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */