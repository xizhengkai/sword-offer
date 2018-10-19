int partion(vector<int>& nums, int left, int right)
{
	int pivot = nums[left];              //以左边值为枢纽
	int low = left;
	int high = right;
	while (low<high)
	{
		while (low<high && nums[high] >= pivot)     //和下一个while顺序不能交换，以左边为枢纽，必须先从high开始
			high--;                                 //如果以右边为枢纽，要先从low开始
		nums[low] = nums[high];
		while (low<high && nums[low] <= pivot)
			low++;
		nums[high] = nums[low];
	}
	nums[low] = pivot;
	return low;
}
void quickSort(vector<int>& nums, int left, int right)
{
	if (left < right)                     //left<right，判定条件很重要，不然无法结束递归
	{
		int part = partion(nums, left, right);
		quickSort(nums, part + 1, right);
		quickSort(nums, left, part - 1);
	}
}