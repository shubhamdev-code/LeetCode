class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = nums[0], prev2 = 0 , ans  = prev; 
        for(int i = 1; i<nums.size(); ++i){
            prev2 += nums[i]; 
            ans = max(prev,prev2);
            prev2 = prev; 
            prev = ans; 
        }
        return ans; 
    }
};