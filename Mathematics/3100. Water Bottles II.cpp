class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottledrunk = numBottles;
        int emptybottle = numBottles;

        while(emptybottle >= numExchange){

            bottledrunk +=1;
            emptybottle = emptybottle - numExchange +1;
            numExchange++;
        }
        return bottledrunk;
        
    }
};