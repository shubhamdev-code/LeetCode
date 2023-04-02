class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> index;
        vector<int> ans(2); 
                            
        for(int i = 0; i<nums.size(); i++){
            if(index.find(target-(nums[i])) != index.end()){
                ans[0] = i; 
                ans[1] = index[target-nums[i]]; 
                return ans; 
            }
            index[nums[i]] = i;
        }

        return ans; 
    }
};