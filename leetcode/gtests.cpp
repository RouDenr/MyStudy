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


// TEST(is_palindrome, Case1) {
//     string str = "abba";

//     EXPECT_TRUE(Solution::is_palindrome(str.begin(), str.end() - 1));
// }
// TEST(is_palindrome, Case2) {
//     string str = "ababa";

//     EXPECT_TRUE(Solution::is_palindrome(str.begin(), str.end() - 1));
// }
// TEST(is_palindrome, Case3) {
//     string str = "a";

//     EXPECT_TRUE(Solution::is_palindrome(str.begin(), str.end() - 1));
// }
// TEST(is_palindrome, Empty) {
//     string str = "";

//     EXPECT_TRUE(Solution::is_palindrome(str.begin(), str.end() - 1));
// }
// TEST(is_palindrome, Case4) {
//     string str = "ba";

//     EXPECT_TRUE(!(Solution::is_palindrome(str.begin(), str.end() - 1)));
// }
// TEST(is_palindrome, Case5) {
//     string str = "baa";

//     EXPECT_TRUE(!(Solution::is_palindrome(str.begin(), str.end() - 1)));
// }


// TEST(LongestPalindrome, Case1) {
//     string a = "aba";
//     string b = "bab";

//     auto result = test.longestPalindrome("babad");
//     EXPECT_TRUE(result == b || result == a);
// }
// TEST(LongestPalindrome, Case2) {
//     string a = "bb";

//     auto result = test.longestPalindrome("cbbd");
//     EXPECT_TRUE(result == a);
// }
// TEST(LongestPalindrome, Case3) {
//     string a = "bb";

//     auto result = test.longestPalindrome("bb");
//     // cout << result << endl;
//     EXPECT_TRUE(result == a);
// }
// TEST(LongestPalindrome, Case4) {
//     string a = "b";

//     auto result = test.longestPalindrome("bc");
//     // cout << result << endl;
//     EXPECT_TRUE(result == a || result == "c");
// }


// TEST(ZigzagConversion, Case1) {
//     string s = "PAYPALISHIRING";
//     string expect = "PINALSIGYAHRPI";
//     int numRows = 4;

//     EXPECT_EQ(test.convert(s, numRows), expect);
// }
// TEST(ZigzagConversion, Case2) {
//     string s = "PAYPALISHIRING";
//     string expect = "PAHNAPLSIIGYIR";
//     int numRows = 3;

//     EXPECT_EQ(test.convert(s, numRows), expect);
// }
// TEST(ZigzagConversion, Case3) {
//     string s = "A";
//     int numRows = 1;
//     string expect = "A";

//     EXPECT_EQ(test.convert(s, numRows), expect);
// }
// TEST(ZigzagConversion, Case4) {
//     string s = "AB";
//     int numRows = 1;
//     string expect = "AB";

//     EXPECT_EQ(test.convert(s, numRows), expect);
// }

// TEST(ReverseInteger, Case1) {
//     int x = 123;
//     int expect = 321;

//     EXPECT_EQ(test.reverse(x), expect);
// }
// TEST(ReverseInteger, Case2) {
//     int x = -123;
//     int expect = -321;

//     EXPECT_EQ(test.reverse(x), expect);
// }
// TEST(ReverseInteger, Case3) {
//     int x = 120;
//     int expect = 21;

//     EXPECT_EQ(test.reverse(x), expect);
// TEST(myAtoi, Case1) {
//     string s = "42";
//     int expect = 42;
//     int result = test.myAtoi(s);
//     EXPECT_EQ(result, expect);
// }
// TEST(myAtoi, Case1Space) {
//     string s = "     42";
//     int expect = 42;
//     int result = test.myAtoi(s);
//     EXPECT_EQ(result, expect);
// }
// TEST(myAtoi, Case2) {
//     string s = "-42";
//     int expect = -42;

//     int result = test.myAtoi(s);
//     EXPECT_EQ(result, expect);
// }
// TEST(myAtoi, Case3) {
//     string s = "2147483647";
//     int expect = INT32_MAX;

//     EXPECT_EQ(test.myAtoi(s), expect);
// }
// TEST(myAtoi, Case4) {
//     string s = "-2147483648";
//     int expect = INT32_MIN;

//     EXPECT_EQ(test.myAtoi(s), expect);
// }
// TEST(isPalindrome, CaseTrue1) {
//     int x = 121;
//     bool expect = true;

//     EXPECT_EQ(test.isPalindrome(x), expect);
// }
// TEST(isPalindrome, CaseTrue2) {
//     int x = 1001;
//     bool expect = true;

//     EXPECT_EQ(test.isPalindrome(x), expect);
// }
// TEST(isPalindrome, CaseFalse1) {
//     int x = -121;
//     bool expect = false;

//     EXPECT_EQ(test.isPalindrome(x), expect);
// }
// TEST(isPalindrome, CaseFalse2) {
//     int x = 10;
//     bool expect = false;

//     EXPECT_EQ(test.isPalindrome(x), expect);
// }
// TEST(isPalindrome, CaseFalse3) {
//     int x = 1021;
//     bool expect = false;

//     EXPECT_EQ(test.isPalindrome(x), expect);
// }

TEST(isMatch, CaseTrue1) {
    string s = "aa";
    string p = "a*";
    bool expect = true;

    EXPECT_EQ(test.isMatch(s, p), expect);
}
TEST(isMatch, CaseTrue2) {
    string s = "ab";
    string p = ".*";
    bool expect = true;

    EXPECT_EQ(test.isMatch(s, p), expect);
}
TEST(isMatch, CaseTrue3) {
    string s = "ab";
    string p = "ab";
    bool expect = true;

    EXPECT_EQ(test.isMatch(s, p), expect);
}
TEST(isMatch, CaseTrue4) {
    string s = "aab";
    string p = "c*a*b";
    bool expect = true;

    EXPECT_EQ(test.isMatch(s, p), expect);
}
TEST(isMatch, CaseTrue5) {
    string s = "aaa";
    string p = "a*a";
    bool expect = true;

    EXPECT_EQ(test.isMatch(s, p), expect);
}
// TEST(isMatch, CaseTrue4) {
//     string s = "afasdb";
//     string p = "a*b";
//     bool expect = true;

//     EXPECT_EQ(test.isMatch(s, p), expect);
// }
TEST(isMatch, PointTrueCase) {
    string s = "atb";
    string p = "a.b";
    bool expect = true;

    EXPECT_EQ(test.isMatch(s, p), expect);
}
TEST(isMatch, PointFalseCase) {
    string s = "ab";
    string p = "a.b";
    bool expect = false;

    EXPECT_EQ(test.isMatch(s, p), expect);
}
TEST(isMatch, CaseFalse1) {
    string s = "aa";
    string p = "a";
    bool expect = false;

    EXPECT_EQ(test.isMatch(s, p), expect);
}
TEST(isMatch, CaseFalse2) {
    string s = "mississippi";
    string p = "mis*is*p*.";
    bool expect = false;

    EXPECT_EQ(test.isMatch(s, p), expect);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
