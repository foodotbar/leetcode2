/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i=0,j=0,k=0;
    int flag=0;
    for(i=0;i<numbersSize;i++){
        for(j=i+1;j<numbersSize;j++){
            if(numbers[i]+numbers[j]==target&&i<j){
                flag=1;
                break;
            }
        }
        if(flag)
            break;
        flag=0;
    }
    int* ptr=(int*)malloc(2*sizeof(int));
    *returnSize=2;
    ptr[0]=i+1;
    ptr[1]=j+1;
    return ptr;
}
