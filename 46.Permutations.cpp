class Solution {
public:
    vector<int> nextPermutation(vector<int> permu) {
        int k=-1;
        for(int i=permu.size()-2;i>=0;i--){
            if(permu[i]<permu[i+1]){
                k=i;
                break;
            }
        }
        if(k==-1){
            reverse(permu.begin(),permu.end());
            return permu;
        }
        int l=-1;
        for(int i=permu.size()-1;i>k;i--){
            if(permu[i]>permu[k]){
                l=i;
                break;
            }
        }
        swap(permu[k],permu[l]);
        reverse(permu.begin()+k+1,permu.end());
        return permu;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> permutation=nums;
        vector<vector<int>> ret;
        ret.push_back(permutation);
        vector<int> start=nextPermutation(permutation);
        while(start!=permutation){
            ret.push_back(start);
            start=nextPermutation(start);
        }
    return ret;
    }
};

/*

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        permuteRecursive(nums,0,ret);
        return ret;
    }
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permuteRecursive(vector<int> &nums,int begin,vector<vector<int>> &result){
        if(begin>=nums.size()){
            result.push_back(nums);
		    // one permutation instance
            return;
        }
        for(int i=begin;i<nums.size();i++){
            swap(nums[begin],nums[i]);
            permuteRecursive(nums,begin+1,result);
            //reset
            swap(nums[begin],nums[i]);
        }
    }
};

*/
