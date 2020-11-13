

#include "ArraysBasic.h"

vector<int> RunningSum::runningSum(const vector<int>& nums)
{
	vector<int> result(nums.size());
	result[0] = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		result[i] = result[i-1] + nums[i];
	}
    return result;
}

