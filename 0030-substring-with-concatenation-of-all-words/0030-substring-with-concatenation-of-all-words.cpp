class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
    int n = s.size(), m = words.size(), k = words[0].size();
    unordered_map<string, int> freqMap;

    // Calculate the frequency of each word in the words array
    for (string word : words) {
        freqMap[word]++;
    }

    // Check all possible starting indices of concatenated substrings
    for (int i = 0; i < n - m * k + 1; i++) {
        unordered_map<string, int> seenMap;
        int j = 0;

        // Check if the current substring is a concatenated substring
        while (j < m) {
            string word = s.substr(i + j * k, k);
            if (freqMap.find(word) == freqMap.end() || seenMap[word] == freqMap[word]) {
                break;
            }
            seenMap[word]++;
            j++;
        }

        // If all words are found in the substring, add the starting index to the result
        if (j == m) {
            result.push_back(i);
        }
    }

    return result;

    }
};