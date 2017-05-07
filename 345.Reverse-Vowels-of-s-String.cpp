class Solution {
public:
    string reverseVowels(string s) {
        for(int start=0,end=s.length()-1;start<end;){
            while(!isVowels(s[start])&&start<end)
                start++;
            while(!isVowels(s[end])&&start<end)
                end--;
            if(isVowels(s[start])&&isVowels(s[end]))
                swap(s[start++],s[end--]);
        }
        return s;
    }
    bool isVowels(char c){
        switch(c){
            case 'a':return true;
            case 'e':return true;
            case 'i':return true;
            case 'o':return true;
            case 'u':return true;
            case 'A':return true;
            case 'E':return true;
            case 'I':return true;
            case 'O':return true;
            case 'U':return true;
            default:return false;
        }
    }
};

/*

class Solution {
public:
    string reverseVowels(string s) {
        for(int start=0,end=s.length()-1;start<end;start++,end--){
            start=s.find_first_of("aeiouAEIOU",start);
            end=s.find_last_of("aeiouAEIOU",end);
            if(start<end)
                swap(s[start],s[end]);
        }
        return s;
    }
};

*/
