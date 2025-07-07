#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>>adj ;
        // create a adj list for pairs 
        for(auto &pair : adjacentPairs){
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        } 

        //ab find kro kii start kaha se krna h build krna toh aisa ele jo single ho okay
        int start =0;
        for(auto &[node , neighbors] : adj){
            if(neighbors.size()==1){
                start = node;
                break;
            }
        }

        // now build the vector by looking at adj and starting from start 
        vector<int>result ;
        unordered_set<int>visited;
        int prev =-1, curr =start;
        
        while(result.size() < adj.size()){
            result.push_back(curr);
            visited.insert(curr);

            //visit the next neighbor that has not been visited yet
            for( auto &neighbor : adj[curr]){
                if(!visited.count(neighbor) ){ 
                    // check if the next value is in visited of not if not then update values 
                    prev = curr ;
                    curr = neighbor;
                    break;
                }
            }

        }
        return result;


    }
};
//tc is 0(n)+0(n) + 0(n) = 0(n)
//sc is 0(n) for adj and visited and result
// so overall tc is 0(n) and sc is 0(n)
// this is a simple graph traversal problem where we are building the array from the adjacent pairs
// we are using a map to store the adjacency list and a set to keep track of visited
// we are starting from the node that has only one neighbor and then traversing the graph to build the array
// this is a simple graph traversal problem where we are building the array from the adjacent pairs
// we are using a map to store the adjacency list and a set to keep track of visited nodes
// we are starting from the node that has only one neighbor and then traversing the graph to build the array
// this is a simple graph traversal problem where we are building the       