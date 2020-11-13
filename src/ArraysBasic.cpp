

#include "ArraysBasic.h"

vector<int> Shuffle::shuffle(vector<int>& nums, int n)
{
	vector<int> result(nums.size());
	
	for (int i = 0; i < nums.size(); i++) {
		int resPos = i < n ? i*2 : (i-n)*2+1;
		result[resPos] = nums[i];
	}
	return result;
}

vector<int> RunningSum::runningSum(const vector<int>& nums)
{
	vector<int> result(nums.size());
	result[0] = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		result[i] = result[i-1] + nums[i];
	}
    return result;
}

