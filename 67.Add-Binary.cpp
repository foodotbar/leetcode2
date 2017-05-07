class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0,i=a.length()-1,j=b.length()-1;
        string ret;
        while(carry||i>=0||j>=0){
            carry=(i>=0?a[i--]-'0':0)+(j>=0?b[j--]-'0':0)+carry;
            ret.insert(ret.begin(),carry%2+'0');
            carry/=2;
        }
        return ret;
    }
};

/*

class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0,lenA=a.length()-1,lenB=b.length()-1;
        string ret;
        while(carry||lenA>=0||lenB>=0){
            int sum=(lenA>=0?a[lenA]-'0':0)+(lenB>=0?b[lenB]-'0':0)+carry;
            carry=sum/2;
            ret.insert(ret.begin(),sum%2+'0');
            lenA--;
            lenB--;
        }
        return ret;
    }
};

*/
