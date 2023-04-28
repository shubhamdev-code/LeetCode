class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1; i<triangle.size(); i++){
            triangle[i][0] += triangle[i-1][0]; 
        }
        
        for(int i = 1; i<triangle.size(); i++){
            for(int j = 1; j<triangle[i].size(); j++){
                if(j == triangle[i].size()-1) triangle[i][j] += triangle[i-1][j-1]; 
                else triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]); 
            }   
        }
        
        
        int ans = INT32_MAX; 
        for(int i = 0; i<triangle[triangle.size()-1].size(); i++){
            ans = min(ans,triangle[triangle.size()-1][i]); 
        }
        return ans;
    }
}; 