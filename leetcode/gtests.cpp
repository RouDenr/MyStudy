// Copyright decordel 2022
#include <gtest/gtest.h>

#include <vector>
// #include <time>

#include "solution.cpp"
#include "bigtests.h"

Solution test;

TEST(MyTestSuite, TestWithRedirectedIO) {
    // Перенаправляем стандартный ввод
    std::istringstream input_stream("Test Input\n");
    std::streambuf* old_cin_buf = std::cin.rdbuf(input_stream.rdbuf());

    // Перенаправляем стандартный вывод
    std::ostringstream output_stream;
    std::streambuf* old_cout_buf = std::cout.rdbuf(output_stream.rdbuf());

    // Выполняем тестируемую функцию
    std::cout << "Test Output" << std::endl;

    // Получаем результаты перенаправления
    std::string output = output_stream.str();
    std::string input = input_stream.str();

    // Восстанавливаем стандартный ввод-вывод
    std::cin.rdbuf(old_cin_buf);
    std::cout.rdbuf(old_cout_buf);

    // Проверяем результаты перенаправления
    EXPECT_EQ("Test Output\n", output);
    EXPECT_EQ("Test Input\n", input);
}

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
// }
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

// // //! ISMATCH
// TEST(isMatch, CaseTrue1) {
//     string s = "aa";
//     string p = "a*";
//     bool expect = true;

//     EXPECT_EQ(test.isMatch(s, p), expect);
// }
// TEST(isMatch, CaseTrue2) {
//     string s = "ab";
//     string p = ".*";
//     bool expect = true;

//     EXPECT_EQ(test.isMatch(s, p), expect);
// }
// TEST(isMatch, CaseTrue3) {
//     string s = "ab";
//     string p = "ab";
//     bool expect = true;

//     EXPECT_EQ(test.isMatch(s, p), expect);
// }
// TEST(isMatch, CaseTrue4) {
//     string s = "aab";
//     string p = "c*a*b";
//     bool expect = true;

//     EXPECT_EQ(test.isMatch(s, p), expect);
// }
// TEST(isMatch, CaseTrue5) {
//     string s = "aaa";
//     string p = "a*a";
//     bool expect = true;

//     EXPECT_EQ(test.isMatch(s, p), expect);
// }
// TEST(isMatch, PointTrueCase) {
//     string s = "atb";
//     string p = "a.b";
//     bool expect = true;

//     EXPECT_EQ(test.isMatch(s, p), expect);
// }
// TEST(isMatch, PointFalseCase) {
//     string s = "ab";
//     string p = "a.b";
//     bool expect = false;

//     EXPECT_EQ(test.isMatch(s, p), expect);
// }
// TEST(isMatch, CaseFalse1) {
//     string s = "aa";
//     string p = "a";
//     bool expect = false;

//     EXPECT_EQ(test.isMatch(s, p), expect);
// }
// TEST(isMatch, CaseFalse2) {
//     string s = "mississippi";
//     string p = "mis*is*p*.";
//     bool expect = false;

//     EXPECT_EQ(test.isMatch(s, p), expect);
// }
// TEST(isMatch, CaseFalse3) {
//     string s = "mississippi";
//     string p = "mis*is*p*.";
//     bool expect = false;

//     EXPECT_EQ(test.isMatch(s, p), expect);
// }
// // //! ISMATCH end>

// TEST(longestCommonPrefix, Case1) {
//     vector<string> strs = {"flower", "flow", "flight"};
//     string expect = "fl";

//     EXPECT_EQ(test.longestCommonPrefix(strs), expect);
// }

// TEST(longestCommonPrefix, CaseEmptyRes) {
//     vector<string> strs = {"dog", "racecar", "car"};
//     string expect = "";

//     EXPECT_EQ(test.longestCommonPrefix(strs), expect);
// }

// TEST(longestCommonPrefix, CaseEmptyArg) {
//     vector<string> strs = {"", "dog", "car"};
//     string expect = "";

//     EXPECT_EQ(test.longestCommonPrefix(strs), expect);
// }

// TEST(longestCommonPrefix, CaseOneArg) {
//     vector<string> strs = {"a"};
//     string expect = "a";

//     EXPECT_EQ(test.longestCommonPrefix(strs), expect);
// }

// TEST(BinarySearch, CaseDef) {
//     vector<int> nums = {-1, 0, 3, 5, 9, 12};
//     int target = 9;
//     int index_expect = 4;

//     EXPECT_EQ(test.search(nums, target), index_expect);
// }

// TEST(BinarySearch, CaseNotFound) {
//     vector<int> nums = {-1, 0, 3, 5, 9, 12};
//     int target = 2;
//     int index_expect = -1;

//     EXPECT_EQ(test.search(nums, target), index_expect);
// }
// TEST(BinarySearch, CaseEmptyArg) {
//     vector<int> nums = {};
//     int target = 2;
//     int index_expect = -1;

//     EXPECT_EQ(test.search(nums, target), index_expect);
// }
// TEST(BinarySearch, CaseExtremeLeft) {
//     vector<int> nums = {7, 44, 234, 344, 1777};
//     int target = 7;
//     int index_expect = 0;

//     EXPECT_EQ(test.search(nums, target), index_expect);
// }

// TEST(BinarySearch, CaseExtremeRight) {
//     vector<int> nums = {7, 44, 234, 344, 1777};
//     int target = 1777;
//     int index_expect = 4;

//     EXPECT_EQ(test.search(nums, target), index_expect);
// }

// TEST(BinarySearch, CaseMiddle) {
//     vector<int> nums = {7, 44, 234, 344, 1777};
//     int target = 234;
//     int index_expect = 2;

//     EXPECT_EQ(test.search(nums, target), index_expect);
// }

// TEST(BinarySearch, CaseMiddleLeft) {
//     vector<int> nums = {7, 44, 234, 300, 344, 1777};
//     int target = 234;
//     int index_expect = 2;

//     EXPECT_EQ(test.search(nums, target), index_expect);
// }

// TEST(BinarySearch, CaseMiddleRight) {
//     vector<int> nums = {7, 44, 234, 300, 344, 1777};
//     int target = 300;
//     int index_expect = 3;

//     EXPECT_EQ(test.search(nums, target), index_expect);
// }

// TEST(firstBadVersion, CaseDef) {
//     int n = 5;
//     test.bad = 4;

//     EXPECT_EQ(test.firstBadVersion(n), test.bad);
// }

// TEST(firstBadVersion, CaseFirst) {
//     int n = 1;
//     test.bad = 1;

//     EXPECT_EQ(test.firstBadVersion(n), test.bad);
// }

// TEST(SearchInsertPosition, Case1) {
//     vector<int> nums = {1, 3, 5, 6};
//     int target = 5;
//     int index_expect = 2;

//     EXPECT_EQ(test.searchInsert(nums, target), index_expect);
// }

// TEST(SearchInsertPosition, Case2) {
//     vector<int> nums = {1, 3, 5, 6};
//     int target = 7;
//     int index_expect = 4;

//     EXPECT_EQ(test.searchInsert(nums, target), index_expect);
// }

// TEST(SearchInsertPosition, Case3) {
//     vector<int> nums = {1, 3, 5, 6};
//     int target = 2;
//     int index_expect = 1;

//     EXPECT_EQ(test.searchInsert(nums, target), index_expect);
// }

// TEST(SearchInsertPosition, Case4) {
//     vector<int> nums = {1, 3, 5, 6};
//     int target = 0;
//     int index_expect = 0;

//     EXPECT_EQ(test.searchInsert(nums, target), index_expect);
// }
// TEST(SortedSquares, Case1) {
//     vector<int> nums = {-4, -1, 0, 3, 10};
//     vector<int> expect = {0, 1, 9, 16, 100};

//     EXPECT_EQ(test.sortedSquares(nums), expect);
// }
// TEST(SortedSquares, Case2) {
//     vector<int> nums = {-7, -3, 2, 3, 11};
//     vector<int> expect = {4, 9, 9, 49, 121};

//     EXPECT_EQ(test.sortedSquares(nums), expect);
// }
// TEST(SortedSquares, CaseEmpty) {
//     vector<int> nums = {};
//     vector<int> expect = {};

//     EXPECT_EQ(test.sortedSquares(nums), expect);
// }
// TEST(SortedSquares, CaseOnePos) {
//     vector<int> nums = {1};
//     vector<int> expect = {1};

//     EXPECT_EQ(test.sortedSquares(nums), expect);
// }
// TEST(SortedSquares, CaseOneNeg) {
//     vector<int> nums = {-1};
//     vector<int> expect = {1};

//     EXPECT_EQ(test.sortedSquares(nums), expect);
// }
// TEST(SortedSquares, CaseOnlyNegatives) {
//     vector<int> nums = {-111, -77, -35, -6, -1};
//     vector<int> expect = {1, 36, 1225, 5929, 12321};

//     EXPECT_EQ(test.sortedSquares(nums), expect);
// }
// TEST(SortedSquares, CaseOnlyNegatives2) {
//     vector<int> nums = {-5, -3, -2, -1};
//     vector<int> expect = {1, 4, 9, 25};

//     EXPECT_EQ(test.sortedSquares(nums), expect);
// }
// TEST(SortedSquares, CaseOnlyPositives) {
//     vector<int> nums = {1, 7, 35, 66, 111};
//     vector<int> expect = {1, 49, 1225, 4356, 12321};

//     EXPECT_EQ(test.sortedSquares(nums), expect);
// }
// TEST(RotateArray, CaseDef) {
//     vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
//     int k = 3;
//     vector<int> expect = {5, 6, 7, 1, 2, 3, 4};
//     test.rotate(nums, k);

//     EXPECT_EQ(nums, expect);
// }
// TEST(RotateArray, CaseEmptyArr) {
//     vector<int> nums = {};
//     int k = 3;
//     vector<int> expect = {};
//     test.rotate(nums, k);

//     EXPECT_EQ(nums, expect);
// }
// TEST(RotateArray, CaseOneArg) {
//     vector<int> nums = {-1};
//     int k = 3;
//     vector<int> expect = {-1};
//     test.rotate(nums, k);

//     EXPECT_EQ(nums, expect);
// }
// TEST(RotateArray, CaseTwoArg) {
//     vector<int> nums = {-1, -2};
//     int k = 3;
//     vector<int> expect = {-2, -1};
//     test.rotate(nums, k);

//     EXPECT_EQ(nums, expect);
// }
// TEST(RotateArray, CaseEmptyK) {
//     vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
//     int k = 0;
//     vector<int> expect = {1, 2, 3, 4, 5, 6, 7};
//     test.rotate(nums, k);

//     EXPECT_EQ(nums, expect);
// }
// TEST(MoveZeroes, CaseDef) {
//     vector<int> nums = {0, 1, 0, 3, 12};
//     vector<int> expect = {1, 3, 12, 0, 0};
//     test.moveZeroes(nums);

//     EXPECT_EQ(nums, expect);
// }
// TEST(MoveZeroes, CaseNonZeroes) {
//     vector<int> nums = {8, 1, 6, 3, 12};
//     vector<int> expect = {8, 1, 6, 3, 12};
//     test.moveZeroes(nums);

//     EXPECT_EQ(nums, expect);
// }
// TEST(MoveZeroes, CaseOnlyZeroes) {
//     vector<int> nums = {0, 0, 0, 0, 0};
//     vector<int> expect = {0, 0, 0, 0, 0};
//     test.moveZeroes(nums);

//     EXPECT_EQ(nums, expect);
// }
// TEST(MoveZeroes, CaseOneZero) {
//     vector<int> nums = {0};
//     vector<int> expect = {0};
//     test.moveZeroes(nums);

//     EXPECT_EQ(nums, expect);
// }
// TEST(MoveZeroes, CaseOneNonZero) {
//     vector<int> nums = {1};
//     vector<int> expect = {1};
//     test.moveZeroes(nums);

//     EXPECT_EQ(nums, expect);
// }
// TEST(MoveZeroes, CaseEmpty) {
//     vector<int> nums = {};
//     vector<int> expect = {};
//     test.moveZeroes(nums);

//     EXPECT_EQ(nums, expect);
// }

// TEST(TwoSumTwo, Case) {
//     vector<int> nums = {2, 7, 11, 15};
//     int target = 9;
//     vector<int> expect = {1, 2};

//     EXPECT_EQ(test.twoSumTwo(nums, target), expect);
// }
// TEST(TwoSumTwo, Case2) {
//     vector<int> nums = {-1, -3, 2, 5, 7, 11, 15};
//     int target = 9;
//     vector<int> expect = {3, 5};

//     EXPECT_EQ(test.twoSumTwo(nums, target), expect);
// }
// TEST(TwoSumTwo, Case3) {
//     vector<int> nums = {2, 3, 4};
//     int target = 6;
//     vector<int> expect = {1, 3};

//     EXPECT_EQ(test.twoSumTwo(nums, target), expect);
// }
// TEST(TwoSumTwo, Case4) {
//     vector<int> nums = {-1, 0};
//     int target = -1;
//     vector<int> expect = {1, 2};

//     EXPECT_EQ(test.twoSumTwo(nums, target), expect);
// }
// TEST(ReverseString, Case) {
//     vector<char> str = {'h', 'e', 'l', 'l', 'o'};
//     // int target = -1;
//     vector<char> expect = {'o', 'l', 'l', 'e', 'h'};
//     test.reverseString(str);

//     EXPECT_EQ(str, expect);
// }
// TEST(ReverseString, Case2) {
//     vector<char> str = {'h', 'e', 'e', 'l', 'l', 'o'};
//     // int target = -1;
//     vector<char> expect = {'o', 'l', 'l', 'e', 'e', 'h'};
//     test.reverseString(str);

//     EXPECT_EQ(str, expect);
// }

// TEST(ReverseWordsInString, CaseDef) {
//     string str = "Let's take LeetCode contest";
//     string expect = "s'teL ekat edoCteeL tsetnoc";

//     EXPECT_EQ(test.reverseWords(str), expect);
// }
// TEST(ReverseWordsInString, CaseEmpty) {
//     string str = "";
//     string expect = "";
//     EXPECT_EQ(test.reverseWords(str), expect);
// }

// TEST(MiddleOfTheLinkedList, Case) {
//     ListNode *head = new ListNode(
//         1, new ListNode(2, new ListNode(3, new ListNode(4, new
//         ListNode(5)))));
//     auto expect = head->next->next;

//     EXPECT_EQ(test.middleNode(head), expect);
//     delete head;
// }
// TEST(MiddleOfTheLinkedList, Case2) {
//     ListNode *head = new ListNode(
//         1, new ListNode(
//                2, new ListNode(
//                       3, new ListNode(4, new ListNode(5, new
//                       ListNode(6))))));
//     auto expect = head->next->next->next;

//     EXPECT_EQ(test.middleNode(head), expect);
//     delete head;
// }
// TEST(MiddleOfTheLinkedList, Case3) {
//     ListNode *head = new ListNode();
//     auto expect = head;

//     EXPECT_EQ(test.middleNode(head), expect);
//     delete head;
// }
// TEST(MiddleOfTheLinkedList, Case4) {
//     ListNode *head = nullptr;
//     auto expect = head;

//     EXPECT_EQ(test.middleNode(head), expect);
// }

// TEST(RemoveNthNodeFromEndofList, Case) {
//     ListNode *head = new ListNode(
//         1, new ListNode(2, new ListNode(3, new ListNode(4, new
//         ListNode(5)))));
//     int n = 2;
//     auto expect =
//         new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(5))));

//     head = test.removeNthFromEnd(head, n);
//     for (auto i = head, j = expect; i != nullptr || j != nullptr;
//          i = i->next, j = j->next) {
//         EXPECT_EQ(i->val, j->val);
//     }
// }

// TEST(RemoveNthNodeFromEndofList, Case3) {
//     ListNode *head = new ListNode();
//     int n = 1;
//     auto expect = nullptr;
//     head = test.removeNthFromEnd(head, n);

//     EXPECT_EQ(head, expect);
// }
// TEST(RemoveNthNodeFromEndofList, Case4) {
//     ListNode *head = nullptr;
//     int n = 1;
//     auto expect = nullptr;
//     head = test.removeNthFromEnd(head, n);

//     EXPECT_EQ(head, expect);
// }

// TEST(PermutationInString, CaseDef) {
//     string s1 = "ab", s2 = "eidbaooo";
//     auto expect = true;

//     EXPECT_EQ(test.checkInclusion(s1, s2), expect);
// }
// TEST(PermutationInString, CaseFalse) {
//     string s1 = "ab", s2 = "eidboaoo";
//     auto expect = false;

//     EXPECT_EQ(test.checkInclusion(s1, s2), expect);
// }
// TEST(PermutationInString, CaseSubInBegin) {
//     string s1 = "dei", s2 = "eidboaoo";
//     auto expect = true;

//     EXPECT_EQ(test.checkInclusion(s1, s2), expect);
// }
// TEST(PermutationInString, CaseSubInEnd) {
//     string s1 = "oda", s2 = "eiodboaod";
//     auto expect = true;

//     EXPECT_EQ(test.checkInclusion(s1, s2), expect);
// }
// TEST(PermutationInString, CaseLarge) {
//     string s1 =
//         "ckzviabspcfbabslodcxtzanlsnwbqrozvnfadhtskosxhxaxzwcthvirwivsfuyxgkdvv"
//         "dmmaoohvnfegkzdajhzibfiuxvsihpseyyiapmgldyojfselzzudzrxcksvfoqoeimyfhn"
//         "vidryqhhpvjawwpzspcfnvmewnhcbbbwfjifmcuspbrrjyhcusyiuydscwenyicdlfzaoa"
//         "iudsdyjmhmzwmeaozheiaddevjrrgsfgqnyeoyxfvktctazsfizkynlookeorzmdvtloyf"
//         "pbqjgzhjvykdthwkuubnbalrddjxpizysaptrinlytecouekkpsfzbjaitckodcdinydta"
//         "aakbntwbvrcabylllxtgtkdqfkjggvbrnxnvcsfpcutabvazyeqzitpwhhdpcxaklhbjrc"
//         "sqzveytzbgoeqnyrbkvkfnlqhrnedjomfmkuadwabnzomgvtdypocbvipryedcxnrcrqwp"
//         "efqducxxilhpoewlliilidxucjydpahcumngpekrlroftwpbaejfjmohnkulxdglcpcszp"
//         "yqestonhxskshzmdkikjkeymddyiysmigvqjveocbabhcofwyseytwfgiqmufcqrugwofy"
//         "txzwwwiwlxdshtamwneosotqbfjjdxmhjkmzcvpmkuumycqzvlmwvjdwkcikyewupwaotr"
//         "seyomhuykdkohveftgqfoqjcnstlxdasnvimslmuqsqrhvbukyfvpswmlavtxegbcesxgz"
//         "swwnslxymmrdwmpalcazukvyyotlvwvlishtgbmlznrmcjysjemwqfjgbehnowgjlvtgem"
//         "lkkdqpxiuqwhqkqdkexoflxfescoblknurkntbpfqfiervqgeiasguycmjoyzyujgzdfjo"
//         "brswjpxixmadnnkdtazbasmnnlbubokkvomtupdpqwnoddummmqbwbthfhqdgdawdwxlmg"
//         "velhefvqcrpxbkgvhyrpxmfivrvkkqfpxjhzqesiqoeanqzpvbgonwptzqgtajoiiphivx"
//         "tefarwjyoklkxumrndswebdsgiipzrcunpnibmxwlkihnzlswaujflztxxnuhojrpkzldw"
//         "hnuiizxalawskkvaplopthvzjrbqfwpwjfkzrhyciajdsaeusctnvajuubjiqdqsaqjxtx"
//         "gxabpdwxzgiedyyeosfdbkairekywkilyksjratftctphompqoomxucysbzrpywjzumoii"
//         "zklkooilgeapimiixawfgiszfqucihxfrtrwijyeiebudncwnxbnafohhhqaltksafjfeg"
//         "xlbbewetsyrtuxxlngffpcnyfdarqwznsuiuhvqshjpvbiqkxgfwyrkdlorlwgexfinunb"
//         "fzifxlfufalbkyfdekhupuuflsetpbppaahwbtjpjguygpnavimbbaeikwjxurdxyfgmld"
//         "gdbkyxzhvwlxzlpnpmzlyosvhngmuqkrvcsabhiahhguxuakphuaptbjfpxybqnlfazkag"
//         "wlbvzcnzorpymafiwvtkjtilwihwoyelogtpdyipzkurqcghpdqgrfpnmrmahbkbyupxwo"
//         "oblaydongjrlnuhoikoyiexgzlzgonceyhfwypsgypilxcnkdhxvbfddnhvdicolrjyztt"
//         "rymmcvoyswaszbbugsuuewhewtoxgnrbfqsysjqqcutoikssesxaohxxfxofiguvpgzfki"
//         "mmqdjuyljlpndapzygidopwxnaetmmpyaqozybbpfqlonebiilvckmtyaommksfcrmdeyj"
//         "jbjncmpruofaaccnvndkovjugcrzcwkbdhqdiwnvnavnngloshyataygyukrecamzftmee"
//         "phucmofjgrzsexsprpdkazhmtaepqppgzjmxxzlpbkouqlhqcxdpaslrjrsnfbjvbekpyq"
//         "sldzhxarpzbbjteudfwfjdipgcdwylorxivwbjkegazpcngzkokygjfnmfeumbetznsxsm"
//         "yhccurqdzznvhrtawpklrrrbedqzkiczignlaoaiydezgktdecaxwxxecymbuisvhlcjlh"
//         "mnpjuegnaawfxopvvkxihehquxzlveabigomeptsqbfurytjikpbtsotgfghadilylnimx"
//         "csvgtmzjgxjyhabtfawzmomctquctwnolglflghdugeutgdmkitunbkhgoceqyrzvwprot"
//         "iysaiqcnwxflcjgjqobeskizjqqwihnmxyvbeeufyvouupnyuuyauxtmhtqlbgoacjdkvm"
//         "uqohbkpctfwxvwlghevsuozrgxkrrrllnvjloeligxvnvzluxlajszgeilxdjaviawhlth"
//         "txuclqypgdiwgwrhynmzqghyzeednlmyepgxxvtmjsuprisbgyvcojhculwdkjmpmvueaf"
//         "tiujrmdqptrmlrwdyjtjlznuhftzmffbcqsjemrpjrqxtuxhlnqvckgcuvhswgtxonfljj"
//         "wnexdafpjzwjdypdfwhwogikkpsvuckmgehcqmdecriamdqsdsxuhsdqenrpifzjnpvrbp"
//         "vetatbmvsncltabzspzedumeclbxiqnsmdkbqfedikoalfsnxkhewwzyeqxlecfimvdpxd"
//         "nvrtlxlxzakupknvchursvilyjyfxmvdeojclhjjwxtpqiogsfdnzchrlztvxmibbociib"
//         "eraevpjmyqxvcicxuwkmyjlgxhvrjdqbjzdctzwidoplkvazhgsdbkavmrpfjgebydmloy"
//         "kqtxocdhcpwrtvawhofvwnohtwodppmcrbhvrvexzijiwgkptntyljvikjlzpjvpxaejfw"
//         "zyldxrckbzylvhpqmjjeyatmrbcgozvcalcctngwuysjqmkmhjwmyyfxhdjswimahqzptr"
//         "phtjekkabpgopfdnhwaclxzavftmswadgztxceonrkczurtdvxhabiafyzdbdbyorerekj"
//         "zgpueihiamlscdndjjgqwdjsmeweqrfpypfrfsciclvrrqchnmtxscbvbbipzingkeopuv"
//         "lnpqaeqidlpvusbkjhntvxbookqctymjmhqjvsnaiblmnofxphanpxspmkmxmyejooqpyt"
//         "dixgguonbpaipurpwwfqxrrtekvvtpgndabbvjcoxonxciuypxqcfolxirvafnmgsrcren"
//         "wyuxfekuqyfdtvhvmonvkstbmvygsbguiknltpixsebxktczniurulxpyxckrtmhpvgqpb"
//         "vlqwvcqwaocalqtdwomgrjyvryodeikbeeebcrrkugliqgktoohsneynmfafykpmndfgwt"
//         "pdwfrmicenyntbfyyntlqqrujfioycrhopgiadmsjcycucyuqvzufbvachmlwyfxspzrvk"
//         "kvkhuykoqrwshzmyypmvosuezpsgtqtecayj";
//     string s2 =
//         "livsugnixbcmmajhinduvzfjzxtzneixibupxfezifaovcbowfayjtlcdsjogjytuczxbw"
//         "luiktkdyecquebuvkgfobhpiqfbyckfbchvfkdowckrvuiblhbmubugrrovdhbyvevwetl"
//         "usthiyxgtaqcdfytgbkrnnjifdslzntgnryqcmwkumdvqctymyffanmawobfihsfqmtqvi"
//         "vvouunsexpzcfmiituppwxgjyspyoeuspyystyneoonatbojiufzhhfeakqzeypaopkysc"
//         "adbkzsnnjewgflysazhwaigicrzeccanemfmrvrdzxtcbuqvjblrynlhbmtkzhtiqnhrfc"
//         "lxovtijwucgvsreirqmhweoazxdyydksrchvizmljhdkekaxbqkleaolqnepijxpwbcxfa"
//         "dfsxswhzmmffsmoiyfosbwjjcgqpexddwizaiqpsaagwxkajdhqeyouihwlfrmnelakemb"
//         "xwcrvwqyaguvqewjczfmfqiqmjbqxcmfrpqoewszkomwckfgrlkannjefxsulbpkpxlvbr"
//         "gwruvhdonuezoomvnyridrosfzhfvhmqbzdsfvjgfdqvafheuhveaqwrofhgkfobkkevds"
//         "qyumzrvapfjypvjsdzaxxwcnsbxasqewmkmucxbgjqntdsvrbndebttkoiznatcjgtgkll"
//         "jurkkdvpbrtbolvgrqwsnuoubhgvtmbakwgvxypndpqtireuvbdxfjcioqqsbfrqahqsfb"
//         "wfnlkwobnqdbptxrizourrxyjejflgkbcwmrtttqeeqkyzrzdcfakwcfajhjfmcpnsbekw"
//         "tzgpbwrotgsxopaemsnywoxsqxoyricgosfurfggulchgyoocivnkqytgbroijmaduoywb"
//         "udtgwugekikebdadoygtmikcficifdcsvritesbvznlbrgbveudwzatarhbehowrrakimo"
//         "cgqyxzedhlqxzxtqloupbwbdvewcbehkmoahoykouhilivtxukqhwmyjjqmfxqybahsubf"
//         "vnhctudtpxwsnwfmsamavjkqiabzzcqgqssygswavqpdtxfyognqybsogsbkzkktfjqebh"
//         "itvqnawokacbkfkthqoammdscyvxgaaqyaplexhlwweambfwtylvihpdedshaeluxgthre"
//         "jkgkvwrtyzpuygqghtlkmpnzkyjiwyuaqijkxttvdsxddfkmgnnlmamjumsbjmjxqkrgnc"
//         "rwyoyetdsmtanoasirkfklcsxukfdebnlbgobwgyqrthzwjbwpxuxmheplqyjaucgrptfe"
//         "wjahejsfypktnpafmlrzekbjqsgthrwbdxttitsqyglsjgnzmscncgvkooxdlxsmmugeea"
//         "yicndgoagpfckerzuwdphqksijniyckzviabspcfbabslodcxtzanlsnwbqrozvnfadhts"
//         "kosxhxaxzwcthvirwivsfuyxgkdvvdmmaoohvnfegkzdajhzibfiuxvsihpseyyiapmgld"
//         "yojfselzzudzrxcksvfoqoeimyfhnvidryqhhpvjawwpzspcfnvmewnhcbbbwfjifmcusp"
//         "brrjyhcusyiuydscwenyicdlfznoaiudsdyjmcmzwmeaozheiaddevjrrgsfgqnyeoyxfv"
//         "ktctazsfizkynlookeorzmdvtloyfpbqjgzhjvykdthwkuubnbalrddjxpihysaptrinly"
//         "tecouekkpsfzbjaitckodcdinydtaaakbntwbvrcasylllxtgtkdqfkjggvbanxnvcsfph"
//         "utabvazyeqzitpwhhdpcxaklhbjrcsqzveytzbgoeqnyrbkvkfnlqhrnedjomfmkuadwab"
//         "nzomgvtdypocbvipryedcxnrcrqwpefqducxxilhpoewlliilidxucjydpahcumagpekrl"
//         "roftwpbaejfjmohnkulxdglcpcszpyqestonhxskshzmdkikjkeymdfyiysmigvqjveocb"
//         "abhcofwyseytwfgiqmufcqrugwofytxzwwwiwlxdshtamwneosotqbfjjdxmhjkmzcvpmk"
//         "uumycqzvlmwvjdwkcityewupwaotrseyomhuykdkohveftgqfoqjcnstlxdasnvimslmuq"
//         "sqrhvbukyfvpswmlavtxegbcesxgzswwnslxymmrdwmpalcazukvyyotlvwvlishtgbmlz"
//         "nrmcjysjemwqfjgbehnowgjlvtgemlkkdqpxiuqwhqkqdkexoflxfescoblknurkntbpfq"
//         "fiervqgeiesguycmjoyzyujgzdfjobrswjpxixmadnnkdtazbasmnnlbubokkvomtupdpq"
//         "wnoddummmqbwbthfhqdgdawdwxlmgvelhefvqcrpxbkgvhyrpxmfivrvkkqfpxjhzqesiq"
//         "oeanqzpvbgonwptzqgtajoiiphivxtefarwjyoklkxumrndswebdsghipzrcunpnibmxwl"
//         "kihnzlswaujflztxxnuhojrpkzldwhnuiizxalawskkvaplopthvzjrbqfwpwjfkzrhyci"
//         "ajdsaeusctnvajuubjiqdqsaqjxtxgxabpdwxzgiedyyeosfdbkrirekywkilyksjratft"
//         "ctphompqoomxucysbzrpywjzumoiizklkooilgeapimiixawfgiszfqucihxfrtrwijyei"
//         "ebudncwnxbnafohhhqaltksafjfegxlbbewetsyrtuxxlngffpcnyfdarqwznsuiuhvqsh"
//         "jpvbiqkxgfwyrkdlorlwgexfinunbfzifxlfufalbkyddekhupuuflsetpbppaahwbkjpj"
//         "guygpnavimbbaeikwjxurdxyfgmldgdbkyxzhvwlxzlpnpmzlyosvhngmuqkrvcsabhiah"
//         "hguxuakphuaptbjfpxybqnlfazkagwlbvzcnzorpymafiwvtkjtilwihwoyelogtpdyipz"
//         "kurqcghpdqgrfpnmrmahbkbyupxwooblaydongjrlnuhoikoyiexgzlzgonceyhfwypsgy"
//         "pilxcnkdhxvbfddnhvdicolrjyzttrymmcvoyswaszbbugsuuewhawtoxgnrbfqsysjqqc"
//         "utoikssesxaohxxfxofiguvpgzfkimmqdjuyljlpndapzygidopwxnaetmmpyaqozybbpf"
//         "qlonebiilvckmtyaommksfcrmdeyjjbjncmpruofaaccnvndkovjugcrzcwkbdhqdiwnvn"
//         "avnngloshyataygyukrecamzftmeephucmofjgrzsepsprpdkazhmtaepqppgzjmxxzlpb"
//         "kouqlhqcxdpaslrjrsnfbjvbekpyqsldzhxarpzbbjteudfwfjdipgcdwylorxivwbjkeg"
//         "azpcngzkokygjfnmfeumbetznsxsmyhccurqdzznvhrtawpklrrrbedqzkiczignlaoaiy"
//         "dezgktdecaxwxxecymbuisvhlcjlhmnpjuegnaawfxopvvkxihehquxzlveabigomeptsq"
//         "bfurytjikpbtsotgfghadilylnimxcsvgtmzjgxjyhabtfawzmomctquctwnolglflghdu"
//         "geutgdmkitunbkhgoceqyrzvwprotiysaiqcnwnflcjgjqobeskizjqqwihnmxyvbeeufy"
//         "vouupnyuuyauxtmhtqlbgoacjdkvmuqohbkpctfwxvwlgievsuozrgxkrrrllnvjloelig"
//         "xvnvzluxlajszgeilxdjaviawhlthtxuclqypgdiwgwrhynmzqghyzeednlmyepgxxvtmj"
//         "suprisbgyvcojhculwdkjmpmvueaftiujrmdqptrmlrwdyjtjlznuhftzmffbcqsjemrpj"
//         "rqxtuxhlnqvckgcuvhswgtxonfljjwnexdafpjzwjdypdfwhwogikkpsvuckmgehcqmdec"
//         "riamdqsdsxuhsdqenrpifzjnpvrbpvetatbmvsncltabzspzedumeclbxiqnsmdkbqfedi"
//         "koalfsnxkhewwzyeqxlecfimvdpxdnvrtlxlxzakupknvchursvilyjyfxmvdfojclhjjw"
//         "xtpqiogsfdxzczrlztvxmibbociiberaevpjmyqxvcicxuwkmyjlgxhvrjdqbjzdctzwid"
//         "oplkvazhgsdbkavmrpfjgebydmloykqtxocdhcpwrtvawhofvwnohtwodxpmcrbhvrvexz"
//         "ijiwgkptntyljvikjlzpjvpxaejfwzyldxrckbzylvhpqmjjeyatmrbcgozvcalcctngwu"
//         "ysjqmkmhjwmyyfxhdjswimahqzptrphtjekkabpgopfdnhwaclxzavftmswadgztxceonr"
//         "kczurtdvxhabiafyzdbdbyorerekjzgpueihiamlscdndjjgqwdjsmeweqrfpypfrfscic"
//         "lvrrqchnmtxscbvbbipzingkeopuvlnpqaeqidlpvusbkjhntvxbookqctymjmhqjvsnai"
//         "blmnofxphanpxspmkmxmyejooqpytdixgguonbpaipurpwwfqxrrtekvvtpgndabbvjcox"
//         "onxciuypxqcfolxirvafnmgsrcrenwyuxeekuqyfdtvhvmonvkbtbmvygsbguiknltpixs"
//         "ebxktczniurulxpyxckrtmhpvgqpbvlqwvcqwaocalqtdwomgrjyvryodeikbeeebcrrku"
//         "gliqgktoohsneynmfafykpmndfgwtpdwfrmicenyntbfyyntlqqrujfioycrhopgiadmsj"
//         "cycucyuqvzufbvachmlwyfxspzrvkkvkhuykoqrwshzmyypmvosuezpsgtqtecayjdasry"
//         "srmdewxmqntqmuavczczrcrzokjzqtiucdfmijfqkizfftxsddkdwlofkjbuhzodgzeslp"
//         "ezdifpdfktufgekrrbsxfeqduphoemwhncbblqkoyychuwlkjfxjmvdasfhwxnxjmstabg"
//         "iujditpmpnojsfzpgqvupkdipphutiewfynvoxmdaloyxsksaxnyyizreshgejskhokarx"
//         "ddrrkoeglwledovrbarhkfcetrshiuucmbrtqjawsavbhuoijshkzcmogbjurybhwduush"
//         "lmhjzgthhlvftpytayjzzbcxbtvozwhsmtkltgrugyfaoldnnswbohpsqvwbwtjcxeewsv"
//         "fwpkwltxmomlwsylwvcmmrwjvvbbktqxnypfmhjigzaqacmprjfnooinkgbjzzwyuafxsm"
//         "qdcmsxhbfoejjzxizufvfejrrcfaijqovlxdngkgwisvryevivawbcttftuxympktxbxot"
//         "vdycxhfokmtdeqacdceffvhvjpnzfuhqslixvlcxehvbkritokoqqlbmkdkgflthhhdgia"
//         "idjjpvcatctiosolfqzcjmdppttztpklgosnshspna";
//     auto expect = true;

//     EXPECT_EQ(test.checkInclusion(s1, s2), expect);
// }

// TEST(FloodFill, CaseDef) {
//     vector<vector<int> > image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
//     int sr = 1, sc = 1, color = 2;
//     vector<vector<int> > expect = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};

//     EXPECT_EQ(test.floodFill(image, sr, sc, color), expect);
// }
// TEST(FloodFill, CaseZero) {
//     vector<vector<int> > image = {{0, 0, 0}, {0, 0, 0}};
//     int sr = 0, sc = 0, color = 0;
//     vector<vector<int> > expect = {{0, 0, 0}, {0, 0, 0}};

//     EXPECT_EQ(test.floodFill(image, sr, sc, color), expect);
// }

// TEST(MaxAreaOfIsland, CaseDef) {
//     vector<vector<int> > image = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
//                                   {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
//                                   {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
//                                   {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
//                                   {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
//                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
//                                   {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
//                                   {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
//     int expect = 6;

//     EXPECT_EQ(test.maxAreaOfIsland(image), expect);
// }
// TEST(MaxAreaOfIsland, CaseZero) {
//     vector<vector<int> > image = {{0, 0, 0}, {0, 0, 0}};
//     int expect = 0;

//     EXPECT_EQ(test.maxAreaOfIsland(image), expect);
// }

// TEST(MergeTwoBinaryTrees, CaseDef) {
//     TreeNode *root1 = new TreeNode(1, new TreeNode(3, new TreeNode(5),
//     nullptr),
//                                    new TreeNode(2));
//     TreeNode *root2 = new TreeNode(2, new TreeNode(1, nullptr, new
//     TreeNode(4)),
//                                    new TreeNode(3, nullptr, new
//                                    TreeNode(7)));
//     TreeNode *expect =
//         new TreeNode(3, new TreeNode(4, new TreeNode(5), new TreeNode(4)),
//                      new TreeNode(5, nullptr, new TreeNode(7)));
//     EXPECT_EQ(*(test.mergeTrees(root1, root2)) == *expect, true);
// }

// TEST(MergeTwoBinaryTrees, CaseDef2) {
//     TreeNode *root1 = new TreeNode(1);
//     TreeNode *root2 = new TreeNode(1, new TreeNode(2), nullptr);
//     TreeNode *expect = new TreeNode(2, new TreeNode(2), nullptr);
//     EXPECT_EQ(*(test.mergeTrees(root1, root2)) == *expect, true);
// }

// TEST(Matrix01, CaseDef1) {
//     vector<vector<int> > mat = {
//         {0, 0, 0},
//         {0, 1, 0},
//         {0, 0, 0}
//     };
//     vector<vector<int> > expect = {
//         {0, 0, 0},
//         {0, 1, 0},
//         {0, 0, 0}
//     };

//     EXPECT_EQ(test.updateMatrix(mat), expect);
// }
// TEST(Matrix01, CaseDef2) {
//     vector<vector<int> > mat = {
//         {0, 0, 0},
//         {0, 1, 0},
//         {1, 1, 1}
//     };
//     vector<vector<int> > expect = {
//         {0, 0, 0},
//         {0, 1, 0},
//         {1, 2, 1}
//     };

//     EXPECT_EQ(test.updateMatrix(mat), expect);
// }
// TEST(Matrix01, CaseEmpty) {
//     vector<vector<int> > mat = {};
//     vector<vector<int> > expect = {};

//     EXPECT_EQ(test.updateMatrix(mat), expect);
// }

TEST(ContainerWMW, CaseDef) {
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int expect = 49;

    EXPECT_EQ(test.maxArea(heights), expect);
}
TEST(ContainerWMW, CaseLowBig) {
    vector<int> heights = {2, 1, 2, 6, 3, 6, 1, 1, 2, 1};
    int expect = 16;

    EXPECT_EQ(test.maxArea(heights), expect);
}

TEST(ContainerWMW, CaseSimple) {
    vector<int> heights = {1, 1};
    int expect = 1;

    EXPECT_EQ(test.maxArea(heights), expect);
}

TEST(ContainerWMW, CaseEmpty) {
    vector<int> heights = {};
    int expect = 0;

    EXPECT_EQ(test.maxArea(heights), expect);
}
TEST(ContainerWMW, CaseBigData) {
    vector<int> heights = ContainerWMWBIG;
    int expect = 705634720;
    // auto start_time


    EXPECT_EQ(test.maxArea(heights), expect);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
