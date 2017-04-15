class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length(), sum = 0;
        string ret;
        if( n1 < 1 && n2 <1 )
            return ret;
        if( n1 < 1 )
            return num2;
        if( n2 < 1 )
            return num1;
        while( n1 >0 || n2 > 0){
            int tmp1 = (n1-1) >=0 ? num1[n1-1] - '0' : 0;
            int tmp2 = (n2-1) >=0 ? num2[n2-1] - '0' : 0;
            sum += tmp1 + tmp2;
            ret.insert(ret.begin(), sum%10+'0');
            sum /= 10;
            n1--;
            n2--;
        }
        if( sum > 0 )
            ret.insert(ret.begin(), sum%10+'0');
        return ret;
    }
};
