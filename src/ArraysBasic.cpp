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

/************************************************************************************/

SubrectangleQueries::SubrectangleQueries(vector<vector<int>>& rectangle) :
    m_rectangle(),
    m_colN(0),
    m_rowN(0)
{
    m_rectangle.swap(rectangle);
    m_rowN = m_rectangle.size();
    if (m_rowN > 0) {
        m_colN = m_rectangle.front().size();
    }
}

void SubrectangleQueries::updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
{
    if (m_colN <= 0 || m_rowN <= 0) {
        return;
    }
    //Prefer memset for performance reasons
    //row-by-row memsets
    for (int rowIdx = row1 ; rowIdx <= row2; ++rowIdx) {
        std::fill(m_rectangle[rowIdx].begin() + col1, m_rectangle[rowIdx].begin() + col2 + 1, newValue);
    }
}

int SubrectangleQueries::getValue(int row, int col)
{
    return m_rectangle[row][col];
}
