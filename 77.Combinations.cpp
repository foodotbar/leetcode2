class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> combination;
        combineDFS(n,k,1,combination,ret);
        return ret;
    }
    void combineDFS(int n, int k, int curr, vector<int>& combination, vector<vector<int>>& ret){
        if(combination.size()==k){
            ret.push_back(combination);
            return;
        }
        for(int i=curr;i<=n;i++){
            combination.push_back(i);
            combineDFS(n,k,i+1,combination,ret);
            combination.pop_back();
        }
    }
};
