class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frq; 
        for(int i =0; i<nums.size(); i++)
            frq[nums[i]]++; 
        

        vector<vector<int>> bucket_sort(nums.size()+1); 
        for(auto i : frq){
            bucket_sort[i.second].push_back(i.first); 
        }
        
        
        vector<int> ans; 
        for(int i = nums.size(); i>=0 ;  i--){
            for(int j= 0; j<bucket_sort[i].size(); j++){
                if(k) ans.push_back(bucket_sort[i][j]); 
                else break;
                k--; 
            }   
            if(!k) break; 
        }
        
        return ans;
    }
};
