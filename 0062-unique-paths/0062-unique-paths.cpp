class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> arr(n,1);
        int prev_ans =1, curr_ans = 1; 
        for(int i = 1; i<m; i++){
            prev_ans = 1; 
            for(int j = 1; j<n; j++){
                curr_ans = prev_ans + arr[j];
                arr[j] = curr_ans; 
                prev_ans = curr_ans;  
            }
        }
        return curr_ans; 
    }
};