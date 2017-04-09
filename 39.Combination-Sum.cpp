class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ret;
        vector<int> combination;
        combSum(candidates,target,ret,combination,0);
        return ret;
    }
    void combSum(vector<int>& candidates, int target, vector<vector<int>>& ret,vector<int>& combination, int begin){
        if(!target){
            ret.push_back(combination);
            return;
        }
        for(int i=begin;i!=candidates.size()&&target>=candidates[i];i++){
            combination.push_back(candidates[i]);
            combSum(candidates,target-candidates[i],ret,combination,i);
            combination.pop_back();
        }
    }
};
