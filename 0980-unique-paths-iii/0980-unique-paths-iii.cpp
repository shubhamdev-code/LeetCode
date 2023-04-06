class Solution {
public:
    int ans = 0, empty = 1;
    void dfs(vector<vector<int>>& grid, int i, int j, int cnt) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1) return;
        
        if (grid[i][j] == 2) {
            if(empty == cnt) ans++; 
            return;
        }
        grid[i][j] = -1;
        
        dfs(grid, i+1, j, cnt+1);
        dfs(grid, i-1, j, cnt+1);
        dfs(grid, i, j+1, cnt+1);
        dfs(grid, i, j-1, cnt+1);
        
        grid[i][j] = 0;   
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x, y;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1){
                    x = i; y = j; 
                } 
                else if (grid[i][j] == 0) empty++;
            }
        }
        dfs(grid, x, y, 0);
        return ans;
    }
};