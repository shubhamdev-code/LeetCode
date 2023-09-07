class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true; 
        }
        return false; 
    }
    
    int maxVowels(string s, int k) {
        string x = s.substr(0,k); 
        int cnt = 0; 
        for(int i = 0; i < k; i++){
            if(isVowel(s[i])){
                cnt++; 
            }
        }
        
        int ans = cnt; 
        for(int i = k; i < s.length(); i++){
            if(isVowel(s[i-k]) ) cnt--; 
            if(isVowel(s[i])) cnt++; 
            ans = max(ans, cnt); 
        }
        return ans; 
    }
};