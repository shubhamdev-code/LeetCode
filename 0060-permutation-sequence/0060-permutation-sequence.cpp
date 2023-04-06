class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers; int fact = 1; 
        for(int i = 1; i<n; i++){
            fact *= i; 
            numbers.push_back(i);
        }
        numbers.push_back(n); 
        
        string ans = "";  k = k-1; 
        while(numbers.size()){
            string pick = to_string(numbers[k/fact]); 
            ans += pick; 
            numbers.erase(numbers.begin() + k/fact);
            k = k % fact; 
            if(numbers.size()) fact /= numbers.size();
        }
        return ans;
    }
};