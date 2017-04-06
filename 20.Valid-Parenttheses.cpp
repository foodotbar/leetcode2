class Solution {
public:
    bool isValid(string s) {
        stack<char> pattern;
        for(char &c:s){
            switch(c){
                case '(':
                case '{':
                case '[':pattern.push(c);break;
                case ')':if(pattern.empty()||pattern.top()!='(') return false;else pattern.pop();break;
                case '}':if(pattern.empty()||pattern.top()!='{') return false;else pattern.pop();break;
                case ']':if(pattern.empty()||pattern.top()!='[') return false;else pattern.pop();break;
                default:;
            }
        }
        return pattern.empty();
    }
};
