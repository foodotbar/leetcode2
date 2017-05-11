class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subs;
        vector<int> sub;
        bfs(nums,0,sub,subs);
        return subs;
    }
    void bfs(vector<int> &nums,int start,vector<int> &sub,vector<vector<int>> &subs){
        subs.push_back(sub);
        for(int i=start;i<nums.size();i++){
            sub.push_back(nums[i]);
            bfs(nums,i+1,sub,subs);
            sub.pop_back();
            while(nums[i]==nums[i+1])
                i++;
        }
    }
};

/*

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subs(1);
        int size=1,last=nums[0];
        for(int i=0;i<nums.size();i++){
            if(last!=nums[i]){
                last=nums[i];
                size=subs.size();
            }
            int n=subs.size();
            for(int j=n-size;j<n;j++){
                subs.push_back(subs[j]);
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
};

*/
