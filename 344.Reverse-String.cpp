class Solution {
public:
    string reverseString(string s) {
        for(int start=0,end=s.length()-1;start<end;start++,end--){
            swap(s[start],s[end]);
        }
        return s;
    }
};
