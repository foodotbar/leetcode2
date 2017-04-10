class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        vector<int> combi;
        combiSum3DFS(ret,nums,combi,0,k,n);
        return ret;
    }
    void combiSum3DFS(vector<vector<int>>& ret,vector<int>& nums,vector<int>& combi,int begin,int k, int n){
        if(n<0||k<0)
            return;
        else if(n==0&&k==0){
            ret.push_back(combi);
            return;
        }else if(n>0&&k>0){
            for(int i=begin;i<nums.size();i++){
                combi.push_back(nums[i]);
                combiSum3DFS(ret,nums,combi,i+1,k-1,n-nums[i]);
                combi.pop_back();
            }
        }
    }
};
