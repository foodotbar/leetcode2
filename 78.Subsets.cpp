class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subs;
        vector<int> sub;
        dfs(nums,0,sub,subs);
        return subs;
    }
    void dfs(vector<int> &nums,int start,vector<int> &sub,vector<vector<int>> &subs){
        subs.push_back(sub);
        for(int i=start;i<nums.size();i++){
            sub.push_back(nums[i]);
            dfs(nums,i+1,sub,subs);
            sub.pop_back();
        }
    }
};

/*

                        []        
                   /          \        
                  /            \     
                 /              \
              [1]                []
           /       \           /    \
          /         \         /      \        
       [1 2]       [1]       [2]     []
      /     \     /   \     /   \    / \
  [1 2 3] [1 2] [1 3] [1] [2 3] [2] [3] []  


*/

/*

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subs(1);
        for(int i=0;i<nums.size();i++){
            int n=subs.size();
            for(int j=0;j<n;j++){
                subs.push_back(subs[j]);
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
};

*/

/*

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subs;
        int max=1<<nums.size();
        for(int i=0;i<max;i++){
            vector<int> sub=convertInt2Set(nums,i);
            subs.push_back(sub);
        }
        return subs;
    }
    vector<int> convertInt2Set(vector<int>& nums,int i){
        vector<int> sub;
        int idx=0;
        for(int j=i;j>0;j>>=1){
            if((j&1)==1)
                sub.push_back(nums[idx]);
            idx++;
        }
        return sub;
    }
};

*/
