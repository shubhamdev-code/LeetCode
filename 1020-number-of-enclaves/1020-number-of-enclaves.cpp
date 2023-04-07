class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i , int j ){
        if(i < 0 || j < 0 || i>= grid.size() || j >= grid[0].size() || grid[i][j] != 1){
            return ;
        }
        
        grid[i][j] = 0; 
        dfs(grid,i+1,j); 
        dfs(grid,i-1,j); 
        dfs(grid,i,j-1); 
        dfs(grid,i,j+1);         
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(); 
        for(int i = 0; i<n; i++){
            if(grid[i][0]) 
                dfs(grid,i,0); 
            
            if(grid[i][m-1]) 
                dfs(grid,i,m-1);
        }
        
        for(int j = 0; j<m; j++){
            if(grid[0][j])
                dfs(grid,0,j); 
            
            if(grid[n-1][j])
                dfs(grid,n-1,j); 
        }
        
        int ans = 0; 
        for(int i = 0; i<n; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j])
                    ans++; 
            }
        }
        
        return ans;         
    }
};