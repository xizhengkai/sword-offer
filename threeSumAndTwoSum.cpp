#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
 
 
 //twoSum 思想：一个头指针，一个尾指针，指向排好序的数组，如果和大于目标值头指针++，
 //如果和小于目标值尾指针--，终止条件为low>high
vector<vector<int>> twoSum(vector<int>& nums,int target)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	int low = 0;
	int high = nums.size() - 1;
	while (low < high)
	{
		int sum = nums[low] + nums[high];
		if (sum < target)
			low++;
		else if (sum>target) 
			high--;
		else
		{
			res.push_back({ nums[low], nums[high] });
			low++;
			while (low < nums.size() && nums[low] + nums[high] == target)
			{
				low++;
			}
		}
	}
	return res;
}

// threeSum 思想：用到了twosum的思路，首先固定一个值，下标从0开始，low=i+1，high=size-1,
//下标每动一次，就计算一次twosum
//将threesum中的目标值换成target，可求出任意目标值的threesum
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.size()<3) return res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i<nums.size(); i++)
	{
		if (i>0 && nums[i] == nums[i - 1]) continue;
		if (nums[i]>0) break;                           //注意，目标值换了后，不可再break，需要遍历到size-3,
		int low = i + 1;
		int high = nums.size() - 1;
		while (low<high)
		{
			int sum = nums[i] + nums[low] + nums[high];
			if (sum == 0)
			{
				res.push_back({ nums[i], nums[low], nums[high] });
				low++;
			}
			else if (sum>0)
				high--;
			else
				low++;
			while (low < nums.size() && nums[i] + nums[low] + nums[high] == 0) low++;   //这块很重要，跳过low指针指向的相同的值
		}
	}
	return res;
}
int main()
{
	vector<int> nums{ -1, 0, 1, 2, -1, -4 };
	vector<vector<int>>res;
	res = threeSum(nums);
	//res=twoSum(nums);
}