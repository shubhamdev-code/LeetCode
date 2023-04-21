class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; 
        int prev = nums[0], prev2 = 0, ans1 = prev; 
        for(int i = 1; i<nums.size()-1; i++){
            prev2 += nums[i]; 
            ans1 = max(prev2,prev); 
            prev2 = prev; 
            prev = ans1; 
        }
        
        prev = nums[1]; prev2 = 0; int ans2 = prev;  
        for(int i = 2; i<nums.size(); i++){
            prev2 += nums[i]; 
            ans2  = max(ans2,prev2); 
            prev2 = prev; 
            prev  = ans2; 
        }
        return max(ans1,ans2); 
    }
};