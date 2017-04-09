class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(), longest=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(i);
            else{
                if(!st.empty()){
                    if(s[st.top()]=='(')
                        st.pop();
                    else
                        st.push(i);
                }
                else
                    st.push(i);
            }
        }
        if(st.empty())
            longest=n;
        else{
            int tail=n,head=0;
            while(!st.empty()){
                head=st.top();
                st.pop();
                longest=max(longest,tail-head-1);
                tail=head;
            }
            longest=max(longest,tail);
        }
        return longest;
    }
};
