class Solution {
public:
    void findFish(vector<vector<int>>& grid, int i , int j , int &curr_ans, vector<vector<bool>>& visited){
        if(i < 0 || i >= grid.size() || j <0 || j>= grid[0].size() || visited[i][j] || grid[i][j] == 0)
            return ; 
        
        visited[i][j] = true; 
        curr_ans += grid[i][j]; 
        findFish(grid,i+1,j,curr_ans,visited); 
        findFish(grid,i-1,j,curr_ans,visited); 
        findFish(grid,i,j-1,curr_ans,visited); 
        findFish(grid,i,j+1,curr_ans,visited); 
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0 ; 
        for(int i = 0; i<grid.size(); i++){
            for(int j =0; j<grid[0].size(); j++){
                if(grid[i][j]){
                    int curr_ans =0; vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false)); 
                    findFish(grid,i,j,curr_ans,visited); 
                    ans= max(ans,curr_ans); 
                }
            }
        }
        return ans; 
    }
};