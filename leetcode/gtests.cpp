// Copyright decordel 2022
#include <gtest/gtest.h>
#include <vector>

#include "solution.cpp"

Solution test;

// TEST(HelloTest, Basic) {
//     std::string test1 = "abcabcbb";
//     std::string test2 = "bbbbb";
//     std::string test3 = "pwwkew";
//     std::string test4 = "dvdf";
//     std::string test5 = "dv";
//     std::string test6 = "ohomm";
//     EXPECT_EQ(test.lengthOfLongestSubstring(test1), 3);
//     EXPECT_EQ(test.lengthOfLongestSubstring(test2), 1);
//     EXPECT_EQ(test.lengthOfLongestSubstring(test3), 3);
//     EXPECT_EQ(test.lengthOfLongestSubstring(test4), 3);
//     EXPECT_EQ(test.lengthOfLongestSubstring(test5), 2);
//     EXPECT_EQ(test.lengthOfLongestSubstring(test6), 3);
// }

// TEST(MedianOfTwoSortedArrays, BasicAssertions) {
//     vector<int> nums1 = {1, 3};
//     vector<int> nums2 = {2};

//     EXPECT_DOUBLE_EQ(test.findMedianSortedArrays(nums1, nums2), 2.00000);
// }
// TEST(MedianOfTwoSortedArrays, Case1) {
//     vector<int> nums1 = {1, 2};
//     vector<int> nums2 = {3, 4};

//     EXPECT_DOUBLE_EQ(test.findMedianSortedArrays(nums1, nums2), 2.50000);
// }
// TEST(MedianOfTwoSortedArrays, Case2) {
//     vector<int> nums1 = {1, 4, 8, 17};
//     vector<int> nums2 = {5, 19};

//     EXPECT_DOUBLE_EQ(test.findMedianSortedArrays(nums1, nums2), 6.50000);
// }
// TEST(MedianOfTwoSortedArrays, Case3) {
//     vector<int> nums1 = {};
//     vector<int> nums2 = {3, 4};

//     EXPECT_DOUBLE_EQ(test.findMedianSortedArrays(nums1, nums2), 3.50000);
// }
// TEST(MedianOfTwoSortedArrays, Case4) {
//     vector<int> nums1 = {1, 2};
//     vector<int> nums2 = {};

//     EXPECT_DOUBLE_EQ(test.findMedianSortedArrays(nums1, nums2), 1.50000);
// }


TEST(is_palindrome, Case1) {
    string str = "abba";

    EXPECT_TRUE(Solution::is_palindrome(str.begin(), str.end() - 1));
}
TEST(is_palindrome, Case2) {
    string str = "ababa";

    EXPECT_TRUE(Solution::is_palindrome(str.begin(), str.end() - 1));
}
TEST(is_palindrome, Case3) {
    string str = "a";

    EXPECT_TRUE(Solution::is_palindrome(str.begin(), str.end() - 1));
}
TEST(is_palindrome, Empty) {
    string str = "";

    EXPECT_TRUE(Solution::is_palindrome(str.begin(), str.end() - 1));
}
TEST(is_palindrome, Case4) {
    string str = "ba";

    EXPECT_TRUE(!(Solution::is_palindrome(str.begin(), str.end() - 1)));
}
TEST(is_palindrome, Case5) {
    string str = "baa";

    EXPECT_TRUE(!(Solution::is_palindrome(str.begin(), str.end() - 1)));
}


TEST(LongestPalindrome, Case1) {
    string a = "aba";
    string b = "bab";

    auto result = test.longestPalindrome("babad");
    EXPECT_TRUE(result == b || result == a);
}
TEST(LongestPalindrome, Case2) {
    string a = "bb";

    auto result = test.longestPalindrome("cbbd");
    EXPECT_TRUE(result == a);
}
TEST(LongestPalindrome, Case3) {
    string a = "bb";

    auto result = test.longestPalindrome("bb");
    // cout << result << endl;
    EXPECT_TRUE(result == a);
}
TEST(LongestPalindrome, Case4) {
    string a = "b";

    auto result = test.longestPalindrome("bc");
    // cout << result << endl;
    EXPECT_TRUE(result == a || result == "c");
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
