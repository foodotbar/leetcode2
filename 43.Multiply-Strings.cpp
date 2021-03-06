class Solution {
public:
    string multiply(string num1, string num2) {
        string product(num1.size()+num2.size(),'0');
        
        for(int i=num1.size()-1;i>=0;i--){
            int carry=0;
            for(int j=num2.size()-1;j>=0;j--){
                int tmp= (product[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0') + carry;
                product[i+j+1] = tmp%10 + '0';
                carry=tmp/10;
            }
            product[i]+=carry;
        }
        size_t startpos=product.find_first_not_of("0");
        if(string::npos !=startpos)
            return product.substr(startpos);
        return "0";
    }
};
