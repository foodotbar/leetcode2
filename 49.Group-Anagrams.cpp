class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;
        for(auto s:strs){
            string t=s;
            sort(t.begin(), t.end());
            mp[t].insert(s);
        }
        vector<vector<string>> ret;
        for(auto idx:mp){
            vector<string> anagram(idx.second.begin(), idx.second.end());
            ret.push_back(anagram);
        }
        return ret;
    }
};
