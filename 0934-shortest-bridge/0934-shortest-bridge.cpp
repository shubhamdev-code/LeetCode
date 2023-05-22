class Solution {
public:
    
    queue<vector<int>> store; 
    void dfs(vector<vector<int>>& grid, int i , int j ){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1 || grid[i][j] == 0){
            return ; 
        }
        
        grid[i][j] = -1; 
        store.push({i,j}); 
        
        dfs(grid,i+1,j); 
        dfs(grid,i,j+1); 
        dfs(grid,i,j-1); 
        dfs(grid,i-1,j); 
    }

    int bfs(vector<vector<int>>& grid) {
        vector<vector<int>> drs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int curr_ans = 0;
        int ans = INT_MAX;

        while (!store.empty()) {
            int sz = store.size();
            while (sz--) {
                vector<int> point = store.front();
                store.pop();

                for (int i = 0; i < drs.size(); i++) {
                    int r = point[0] + drs[i][0];
                    int c = point[1] + drs[i][1];
                    if (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size()) {
                        if (grid[r][c] != -1) {
                            if (grid[r][c] == 1) {
                                ans = min(ans, curr_ans);
                            } else {
                                store.push({r, c});
                                grid[r][c] = -1;
                            }
                        }
                    }
                }
            }
            curr_ans++;
        }

        return ans;
    }

    
    int shortestBridge(vector<vector<int>>& grid) {
        for(int i = 0; i<grid.size(); i++){
            bool found_one = false; 
            for(int j =0; j <grid[0].size(); j++){
                if(grid[i][j]){
                    dfs(grid,i,j); 
                    found_one = true; 
                    break; 
                }
            }
            if(found_one) break; 
        }
 
        int ans = bfs(grid); 
        
        return ans;
    }
};