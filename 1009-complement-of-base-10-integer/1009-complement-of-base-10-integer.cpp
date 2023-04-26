class Solution {
public:
    int bitwiseComplement(int n) {        
        int sum=0;
        vector<int> v;
        if(!n) v.push_back(0); 
        
        while(n!=0){
            v.push_back(n%2);
            n=n/2;
        }
        
        reverse(v.begin(),v.end());
        for(int i=0;i<=v.size()-1;i++){
            if(v[i]==0){
                v[i]=1;
            }
            else{
                v[i]=0;
            }
        }
        
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==1){
                sum+=pow(2,(v.size()-1)-i);
            }   
        }
        return sum;
    }    
};