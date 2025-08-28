class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        // covert the whole into string first ans is string
        vector<string >arr;
        for(auto & it : nums){
            arr.push_back(to_string(it));
        }

        //sort
        auto mycomparator = [](string s1 , string s2){
            return s1+s2 > s2+s1;
        };

        sort(arr.begin()  , arr.end() , mycomparator);
        if(arr[0]=="0") return "0"; // leading 0 case 

        string result = "";
        for(auto &it : arr){
            result+=it;
        }

        return result ;
       
    }
};