char* longestCommonPrefix(char** strs, int strsSize) {
    int i=0,j=0,shortlen=INT_MAX,commonprefix=0;
    if(strsSize<1)
        return strs;
    if(strsSize==1)
        return strs[0];
    for(i=0;i<strsSize;i++){
        int tmp=strlen(strs[i]);
        if(tmp<shortlen)
            shortlen=tmp;
    }
    for(i=0;i<shortlen;i++){
        char tmp=strs[0][i];
        int flag=0;
        for(j=1;j<strsSize;j++){
            if(strs[j][i]==tmp)
                flag++;
            else
                break;
        }
        if(flag==strsSize-1)
            commonprefix++;
        else
            break;
    }
    char* ans=(char*)malloc((commonprefix+1)*sizeof(char));
    for(i=0;i<commonprefix;i++)
        ans[i]=strs[0][i];
    ans[i]='\0';
    return ans;
}

/*
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix="";
        for(int idx=0;strs.size()>0;prefix+=strs[0][idx++])
            for(int i=0;i<strs.size();i++)
                if(idx>=strs[i].size()||(i>0&&strs[i][idx]!=strs[i-1][idx]))
                    return prefix;
        return prefix;
    }
};
*/
