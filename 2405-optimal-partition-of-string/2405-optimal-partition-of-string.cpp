class Solution {
public:
    int partitionString(string s) {
        vector<int> frq(26); int ans = 1; 
        for(int i = 0; i<s.length(); i++){
            frq[s[i]-'a']++; 
            if(frq[s[i]-'a'] > 1){
                for(int j = 0; j < 26; ++j) frq[j] = 0;
                frq[s[i]-'a'] = 1; 
                ans++; 
            }
        }
        return ans; 
    }
};