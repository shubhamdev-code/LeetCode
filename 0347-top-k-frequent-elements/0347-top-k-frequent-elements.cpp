class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> frq; 
        for(int i =0; i<nums.size(); i++){
            frq[nums[i]]++; 
        }
        
        map<int,vector<int>,greater<int>> sorted_by_val; 
        for(auto i : frq){
            sorted_by_val[i.second].push_back(i.first);    
        }
        
        int j =0 ; 
        for(auto i : sorted_by_val){
            for(auto k : i.second)
                nums[j++] = k;
        }

        vector<int> ans; 
        while(k--){
            ans.push_back(nums[k]);
        }
        return ans;
    }
};
