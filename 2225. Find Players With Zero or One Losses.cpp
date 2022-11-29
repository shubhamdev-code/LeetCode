//Problem Link - https://leetcode.com/problems/find-players-with-zero-or-one-losses/
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> losses; 
        for(int i = 0; i<matches.size(); i++){
            if(losses.find(matches[i][0]) == losses.end()) losses[matches[i][0]] = 0; 
            losses[matches[i][1]]++; 
        }
    
        vector<vector<int>> ans(2,vector<int>()); 
        for(auto i : losses){
            if(i.second == 0) ans[0].push_back(i.first); 
            else if(i.second == 1) ans[1].push_back(i.first);  
        }
        return ans;
    }
};
