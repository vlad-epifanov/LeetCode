#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ArraysBasic.h"

using ::testing::_;
using ::testing::ElementsAre;

/* RunningSum test cases:
   1
   1 2 3
   -2 3 -5
*/
TEST(Arrays, test1) {
    RunningSum rsum;

    auto result = rsum.runningSum({1});
    EXPECT_THAT(result, ElementsAre(1));

    result = rsum.runningSum({1,2,3});
    EXPECT_THAT(result, ElementsAre(1,3,6));

    result = rsum.runningSum({1,-2,3});
    EXPECT_THAT(result, ElementsAre(1,-1,2));
}
