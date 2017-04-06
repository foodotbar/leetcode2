class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()<1)
            return ans;
        static const vector<string> pad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        ans.push_back("");
        for(int i=0;i<digits.size();i++){
            vector<string> tmp;
            string chars=pad[digits[i]-'0'];
            for(int c=0;c<chars.size();c++)
                for(int j=0;j<ans.size();j++)
                    tmp.push_back(ans[j]+chars[c]);
            ans=tmp;
        }
        return ans;
    }
};
