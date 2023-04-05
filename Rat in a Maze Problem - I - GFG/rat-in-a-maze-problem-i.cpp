//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(vector<vector<int>>& m , int n, int i , int j , string& curr_path, vector<string>& ans){
        if(i < 0 || j < 0 || i > n-1 || j > n-1 || m[i][j] == 0 || m[i][j] == -1){
            return ; 
        }
        if(i == n-1 && j == n-1){
            ans.push_back(curr_path); 
            return ; 
        }
        m[i][j] = -1;
        
        curr_path += 'D'; 
        dfs(m,n,i+1,j,curr_path,ans);
        curr_path.pop_back();
        curr_path += 'L'; 
        dfs(m,n,i,j-1,curr_path,ans); 
        curr_path.pop_back(); 
        curr_path += 'R'; 
        dfs(m,n,i,j+1,curr_path,ans); 
        curr_path.pop_back(); 
        curr_path += 'U'; 
        dfs(m,n,i-1,j,curr_path,ans); 
        curr_path.pop_back(); 
        
        m[i][j] = 1; 
        return ; 
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[n-1][n-1] ==0 || m[0][0] == 0 ) return {}; 
        // Your code goes here
        vector<string> path; 
        string curr_path = ""; 
        dfs(m,n,0,0,curr_path,path); 
        return path; 
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends