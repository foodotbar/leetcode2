/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int index = 0, i = 0, j = 0;
    int* ptr = (int*)malloc(numsSize*sizeof(int));
	for (i = 0; i < numsSize; i++)
	{
		index = abs(nums[i]) - 1;
		if (nums[index] > 0)
		{
			nums[index] = -nums[index];
		}
	}
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] > 0)
		{
			ptr[j++] = i + 1;
		}
	}
	*returnSize = j;
	return ptr;
}
