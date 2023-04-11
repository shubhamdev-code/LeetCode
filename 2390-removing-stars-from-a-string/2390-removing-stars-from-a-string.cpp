class Solution {
public:
    string removeStars(string s) {
        deque<char> dq; 
        for(int i = 0; i<s.length(); i++){
            if(s[i] != '*') dq.push_back(s[i]); 
            else dq.pop_back(); 
        }
        
        string ans = ""; 
        while(!dq.empty()){
            ans += dq.front();
            dq.pop_front(); 
        }
        return ans; 
    }
};