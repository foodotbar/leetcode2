int lengthOfLongestSubstring(char* s) {
    if(s==NULL)
        return 0;
    int table[128];
    int i=0,j=0,len=0,max=0;
    while(s[i]!='\0'){
        memset(table,0,sizeof(table));
        len=0;
        j=i;
        while(s[j]!='\0'){
            if(table[s[j]]==0){
                table[s[j]]=1;
                len+=1;
                if(max<=len){
                    max=len;
                }
            }else{
                len=0;
                break;
            }
            j++;
        }
        i++;
    }
    return max;
}
