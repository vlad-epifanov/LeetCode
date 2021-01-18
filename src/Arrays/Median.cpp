#include "Median.h"
#include <set>

class RunningMedian {
    public:
        RunningMedian() {}

        void add(const int val) {
            if (m_top.empty() || val >= *m_top.begin()) {
                m_top.insert(val);
            } else {
                m_bottom.insert(val);
            }
            rebalance();
        }

        void remove(const int val) {
            if (auto it = m_top.find(val); it != m_top.end()) {
                m_top.erase(it);
            } else if (auto it = m_bottom.find(val); it != m_bottom.end()) {
                m_bottom.erase(it);
            }
            rebalance();
        }

        double getMedian() {
            auto bSize = m_bottom.size();
            auto tSize = m_top.size();
            if (bSize == 0 && tSize == 0)
                return 0.0;
            if (bSize > tSize) {
                return *m_bottom.begin();
            } else if (bSize < tSize) {
                return *m_top.begin();
            } else {
                return (static_cast<double>(*m_top.begin()) + static_cast<double>(*m_bottom.begin())) / 2;
            }
        }

        size_t size() {
            return m_bottom.size() + m_top.size();
        }

    private:
        void rebalance() {
            // Assumption: rebalance is always called after adding single element
            // so it is not possible to have difference > 2
            if (m_top.size() > m_bottom.size() + 1) {
                auto val = *m_top.begin();
                m_bottom.insert(val);
                m_top.erase(m_top.find(val));
            } else if (m_bottom.size() > m_top.size() + 1) {
                auto val = *m_bottom.begin();
                m_top.insert(val);
                m_bottom.erase(m_bottom.find(val));
            }
        }
    private:
        multiset<int,greater<int>> m_bottom;
        multiset<int,less<int>> m_top;
};

vector<double> SlidingMedian::medianSlidingWindow(vector<int>& nums, int k)
{
    const size_t N = nums.size();
    vector<double> result(N-k+1);

    RunningMedian rm;
    for (int i = 0; i < k; i++) {
        rm.add(nums[i]);
    }
    result[0] = rm.getMedian();

    for (size_t i = 1; i <= N-k; i++) {
        rm.remove(nums[i-1]);
        rm.add(nums[k+i-1]);
        result[i] = rm.getMedian();
    }

    return result;
}

