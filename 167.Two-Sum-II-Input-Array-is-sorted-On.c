/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i=0,j=0,k=0;
    int lo=0, hi=numbersSize-1;
    while (numbers[lo]+numbers[hi]!=target){
        if (numbers[lo]+numbers[hi]<target){
            lo++;
        } else {
            hi--;
        }
    }
    int* ptr=(int*)malloc(2*sizeof(int));
    *returnSize=2;
    ptr[0]=lo+1;
    ptr[1]=hi+1;
    return ptr;
}
