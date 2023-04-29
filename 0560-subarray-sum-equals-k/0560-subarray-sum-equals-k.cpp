class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix_sum; 
        prefix_sum[0] = 1; 
        int cnt = 0 , sum = 0; 
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i]; 
            if(prefix_sum.find(sum-k) != prefix_sum.end()){
                cnt += prefix_sum[sum-k];
            }
            prefix_sum[sum]++; 
        }
        return cnt; 
    }        
}; 
