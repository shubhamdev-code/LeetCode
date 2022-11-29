//Problem Link - https://leetcode.com/problems/insert-delete-getrandom-o1/
class RandomizedSet {
private : 
    unordered_map<int,int> elems;
    vector<int> x; 
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(elems.find(val) != elems.end()) return false; 
        x.push_back(val); 
        elems[val] = x.size()-1; 
        return true;
    }
    
    bool remove(int val) {
        if(elems.find(val) == elems.end()) return false; 
        int last_elem = x.back(); 
        x[elems[val]] = last_elem; 
        x.pop_back(); 
        elems[last_elem] = elems[val]; 
        elems.erase(val); 
        return true; 
    }
    
    int getRandom() {
        return x[rand() % x.size()]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
