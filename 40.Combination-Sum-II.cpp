class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ret;
        vector<int> combination;
        combSum2(candidates,target,ret,combination,0);
        return ret;
    }
    void combSum2(vector<int>& candidates, int target, vector<vector<int>>& ret,vector<int>& combination, int begin){
        if(!target){
            ret.push_back(combination);
            return;
        }
        for(int i=begin;i!=candidates.size()&&target>=candidates[i];i++){
            if(i==begin||candidates[i]!=candidates[i-1]){
                combination.push_back(candidates[i]);
                combSum2(candidates,target-candidates[i],ret,combination,i+1);
                combination.pop_back();
            }
        }
    }
};
