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

/************************************************************************************/
// BF: check all pairs, pick max areas - O(n^2)
// V1: moving maxes from out to inside
/*
int MostWater::maxArea(vector<int>& height)
{
    int lMax = height.front(), rMax = height.back();
    int lPos = 0, rPos = height.size()-1;
    int maxArea = 0;
    
    while (lPos < rPos) {

        lMax = std::max(lMax, height[lPos]);
        rMax = std::max(rMax, height[rPos]);
        int area = std::min(lMax, rMax) * (rPos - lPos);
        maxArea = std::max(maxArea, area);
        if (lMax < rMax) {
            lPos++;
        } else {
            rPos--;
        }        
    }

    return maxArea;
}
*/

//V2: just moving towards bigger from smaller and calc areas along the way, O(n)
int MostWater::maxArea(vector<int>& height)
{
    int lPos = 0, rPos = static_cast<int>(height.size()-1);
    int maxArea = 0;
    while (lPos < rPos) {
        int area = std::min(height[lPos], height[rPos]) * (rPos - lPos);
        maxArea = std::max(maxArea, area);
        if (height[lPos] < height[rPos]) {
            lPos++;
        } else {
            rPos--;
        }        
    }
    return maxArea;
}

/************************************************************************************/

vector<vector<int>> TransposeMatrix::transpose(vector<vector<int>>& A)
{
    if (A.empty())
        return Vec2D();
    const size_t N = A.size();
    const size_t M = A.front().size();
    Vec2D result(M,Vec(N));

    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            result[i][j] = A[j][i];
        }
    }

    return result;
}

/************************************************************************************
 Possible solutions
 1) O(nm) + O(nm) space - "visited" bool matrix, and just go around until hit visited or border
 2) O(nm) + O(1) space:
     - print 1st row
     - then - go H-1 vertically (down), W-1 horizontally (left), H-2 vert (up), W-2 (right) etc
     - at every H or W step - we do LastNumSteps-1 + invert the direction.
*/

vector<int> SpiralMatrix::spiralOrder(vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix.front().empty())
        return {};
    int yDist = matrix.size() - 1;
    int xDist = matrix.front().size();

    vector<int> result;
    int yDir = 1, xDir = 1;
    int xPos = -1, yPos = 0;

    while (xDist > 0) {
        // handle x
        for (int i = 1; i <= xDist; i++) {
            xPos += xDir;
            result.push_back(matrix[yPos][xPos]);
        }
        xDir = -xDir;
        xDist--;
        // handle y
        if (yDist <= 0)
            break;
        for (int i = 1; i <= yDist; i++) {
            yPos += yDir;
            result.push_back(matrix[yPos][xPos]);
        }
        yDir = -yDir;
        yDist--;
    }
    
    return result;
}
