class Solution {
public:
    int minRemovals(string s) {
        stack<char> st; 
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == ')' && !st.empty() && st.top() == '(') st.pop(); 
            else if(s[i] == '(' || s[i] == ')') st.push(s[i]); 
        }
        int minRemovals = st.size();
        
        return minRemovals;
    }

    map<string,bool> visited; 
    void dfs(string& s, vector<string>& ans, int remove_limit){
        if(visited[s]) return ; 
        else visited[s] = true;
        
        if(remove_limit == 0){
            if(!minRemovals(s) ){
                visited[s] = true;
                ans.push_back(s); 
            }
            return ; 
        }
        
        for(int i =  0; i<s.length(); i++){
            string left = s.substr(0,i); 
            string right = s.substr(i+1); 
            string str = left + right; 
            dfs(str,ans, remove_limit-1);
        }
        
        return ; 
    }

    
    vector<string> removeInvalidParentheses(string s) {    
        int minRemove = minRemovals(s); 
        string sub_ans = ""; vector<string> ans; 
        dfs(s,ans, minRemove);
        
        return ans; 
    }
};