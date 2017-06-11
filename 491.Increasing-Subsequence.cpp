class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> out;
        findsub(nums,0,out,res);
        return vector<vector<int>>(res.begin(),res.end());
    }
    void findsub(vector<int>& nums,int start,vector<int>& out,set<vector<int>>& res){
        if(out.size()>=2)
            res.insert(out);
        for(int i=start;i<nums.size();++i){
            if(!out.empty()&&out.back()>nums[i])
                continue;
            out.push_back(nums[i]);
            findsub(nums,i+1,out,res);
            out.pop_back();
        }
    }
};
