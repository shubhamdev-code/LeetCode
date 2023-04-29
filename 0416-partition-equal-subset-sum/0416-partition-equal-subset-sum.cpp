class Solution {
public:    
    bool subsetSum(vector<int>& nums, int k) {
        vector<vector<bool>> dp(nums.size(),vector<bool>(k+1,false)); 
        
        for(int i = 0; i<nums.size(); i++){
            dp[i][0] = true;
        }
        
        if(nums[0] <= k) dp[0][nums[0]] = true; 
        
        for(int i = 1; i<nums.size(); i++){
            for(int target = 1; target<=k; target++){
                bool nottake = dp[i-1][target]; 
                bool take = false; 
                if(nums[i] <= target) take = dp[i-1][target-nums[i]]; 
                dp[i][target] = take || nottake; 
            }
        }
        return dp[nums.size()-1][k]; 
    }        
    
    bool canPartition(vector<int>& nums) {
        int sum =0 , target = sum; 
        for(auto i : nums) sum += i; 
        if(sum % 2 == 1) return false; 
        else target = sum/2; 
        return subsetSum(nums,target);
    }
};