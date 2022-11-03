// Copyright decordel 2022
#include <gtest/gtest.h>
#include <vector>

#include "matrix.cpp"

Solution test;

TEST(HelloTest, Basic) {
    std::string test1 = "abcabcbb";
    std::string test2 = "bbbbb";
    std::string test3 = "pwwkew";
    std::string test4 = "dvdf";
    std::string test5 = "dv";
    std::string test6 = "ohomm";
    EXPECT_EQ(test.lengthOfLongestSubstring(test1), 3);
    EXPECT_EQ(test.lengthOfLongestSubstring(test2), 1);
    EXPECT_EQ(test.lengthOfLongestSubstring(test3), 3);
    EXPECT_EQ(test.lengthOfLongestSubstring(test4), 3);
    EXPECT_EQ(test.lengthOfLongestSubstring(test5), 2);
    EXPECT_EQ(test.lengthOfLongestSubstring(test6), 3);
}

TEST(MedianOfTwoSortedArrays, BasicAssertions) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    EXPECT_DOUBLE_EQ(test.findMedianSortedArrays(nums1, nums2), 2.00000);
}
TEST(MedianOfTwoSortedArrays, Case1) {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    EXPECT_DOUBLE_EQ(test.findMedianSortedArrays(nums1, nums2), 2.50000);
}
TEST(MedianOfTwoSortedArrays, Case2) {
    vector<int> nums1 = {1, 4, 8, 17};
    vector<int> nums2 = {5, 19};

    EXPECT_DOUBLE_EQ(test.findMedianSortedArrays(nums1, nums2), 6.50000);
}
TEST(MedianOfTwoSortedArrays, Case3) {
    vector<int> nums1 = {};
    vector<int> nums2 = {3, 4};

    EXPECT_DOUBLE_EQ(test.findMedianSortedArrays(nums1, nums2), 3.50000);
}
TEST(MedianOfTwoSortedArrays, Case4) {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {};

    EXPECT_DOUBLE_EQ(test.findMedianSortedArrays(nums1, nums2), 1.50000);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
