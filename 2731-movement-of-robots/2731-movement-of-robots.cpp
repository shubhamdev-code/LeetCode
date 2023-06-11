class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        for(int i = 0; i < nums.size(); i++){
            if(s[i] == 'R') nums[i] += d; 
            else nums[i] -= d; 
        }
        
        sort(nums.begin(),nums.end()); 
        long long ans = 0 ;
        long long prefix_sum =  0; 
        for(int i = 0; i <nums.size(); i++){
            ans += (long long)i * (nums[i]) - prefix_sum; 
            ans %= (long long)(1e9 + 7); 
            prefix_sum += nums[i]; 
        }
        return ans; 
    }
};