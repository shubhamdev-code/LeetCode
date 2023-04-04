class Solution {
public:
    int partitionString(string s) {
        vector<int> last_pos(26,-1); 
        
        int curr_start = 0, ans = 1; 
        for(int i = 0; i<s.length(); i++){
            if(last_pos[s[i]-'a'] >= curr_start){
                ans++; 
                curr_start = i; 
            }
            last_pos[s[i]-'a'] = i; 
        }
        return ans; 
    }
};