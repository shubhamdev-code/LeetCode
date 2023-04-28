class Solution {
public:
    int uniquePaths(int m, int n) {
        int distance = m+n-2,rows = m-1; 
        double ans = 1; 
        
        for(int i = 1; i<=rows; i++){
            ans = ans * (distance-rows+i)/i; 
        }
        return (int)ans; 
    }
};