class Solution {
public:
    string reverseWords(string s) {
        string res="";
        int n=s.length();
        int i=0;

        
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
                if(i>=n)break;
            }
            int j=i; bool flag = false; 
            while(j<n && s[j]!=' '){
                flag = true; 
                j++;
            }
            
            string sub=s.substr(i,j-i);
            if(res.length()==0){
                res=sub;
            }
            else{
                if(flag) 
                    res=sub+" "+res;            
            }
            i=j;
        }
        
        return res;
        
    }
};