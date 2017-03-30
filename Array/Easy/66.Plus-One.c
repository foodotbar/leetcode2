/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for(int i=digitsSize-1;i>=0;i--){
        if(digits[i]!=9){
            digits[i]++;
            break;
        }else
        digits[i]=0;
    }
    if(digits[0]==0){
        int* ptr=(int*)malloc((digitsSize+1)*sizeof(int));
        ptr[0]=1;
        *returnSize=digitsSize+1;
        for(int j=1;j<digitsSize+1;j++)
            ptr[j]=0;
        return ptr;
    }else
    {
        int* ptr=(int*)malloc((digitsSize)*sizeof(int));
        *returnSize=digitsSize;
        ptr=digits;
        return ptr;
        
    }
}
