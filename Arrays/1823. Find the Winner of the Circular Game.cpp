class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>vec;
        for(int i=1 ; i<=n ; i++){
            vec.push_back(i);
        }

        int i=0;
        while(vec.size() >1){
            int idx = (i+k-1)%vec.size();
            vec.erase(vec.begin() + idx);
            i=idx;
        }
        return vec[0];
        
    }
};