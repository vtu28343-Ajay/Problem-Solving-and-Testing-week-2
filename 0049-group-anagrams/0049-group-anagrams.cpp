class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (const string& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            
            // Build a unique key representation from character frequencies
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += "#" + to_string(count[i]);
            }
            
            mp[key].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto& pair : mp) {
            ans.push_back(pair.second);
        }
        
        return ans;
    }
};