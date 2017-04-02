/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int i=0,j=0;
    int* ans=(int*)malloc((rowIndex+1)*sizeof(int));
    for(i=0;i<=rowIndex;++i){
        ans[i]=1;
    }
    for(i=0;i<rowIndex+1;i++){
        for(j=i-1;j>=1;j--)
            ans[j]=ans[j]+ans[j-1];
    }
    *returnSize=rowIndex+1;
    return ans;
}
