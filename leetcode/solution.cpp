#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint>
#include <set>
#include <vector>
#include <cstdint>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:


    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            // if (nums[i] > target) continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                // if (nums[j] > target) continue;
                if (nums[j] + nums[i] == target) return vector<int>({i, j});
            }
        }
        return vector<int>();
    }


    static void add_node(ListNode* &node, int sum) {
        ListNode* tmp = new ListNode(sum);
        node->next = tmp;
        node = node->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode((l1->val + l2->val) % 10);
        ListNode* tail = head;
        int plus_next = (l1->val + l2->val) / 10;
        while (l1->next || l2->next) {
            int tmp_sum = 0;
            if (l1->next && l2->next) {
                tmp_sum = (l1->next->val + l2->next->val) + plus_next;
            } else if (l1->next) {
                tmp_sum = l1->next->val + plus_next;
            } else if (l2->next) {
                tmp_sum = l2->next->val + plus_next;
            }
            add_node(tail, tmp_sum % 10);
            plus_next = tmp_sum / 10;
            if (l1->next)
                l1 = l1->next;
            if (l2->next)
                l2 = l2->next;
        }
        if (plus_next)
            add_node(tail, plus_next);
        return head;
    }

    template <typename T>
    static bool setContains(const set<T> &set, const T &key) {
        auto fi = set.find(key);
        return fi != set.end();
    }

    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();
        set<char> substr;
        uint16_t max_size = 1;

        for (uint16_t i = 0; i < s.size() - 1; ++i) {
            substr.insert(s[i]);
            for (uint16_t j = i + 1; j < s.size(); ++j) {
                if (setContains(substr, s[j])) {
                    substr.clear();
                    break;
                }
                substr.insert(s[j]);
                if (max_size < substr.size()) {
                    max_size = substr.size();
                }
            }
        }
        return max_size;
    }




    static double medianSortedArray(const vector<int>& nums) {
        if (nums.size() % 2 != 0) {
            return nums[nums.size() / 2];
        } else {
            auto t = nums.size() / 2;
            return (nums[t] + nums[t-1]) / 2.0;
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) return medianSortedArray(nums2);
        if (nums2.empty()) return medianSortedArray(nums1);

        auto i = nums1.begin();
        auto j = nums2.begin();
        while (j != nums2.end()) {
            if (*i > *j || i == nums1.end()) {
                i = nums1.insert(i, *j);
            } else {
                ++i;
                continue;
            }
            ++j;
        }
        return medianSortedArray(nums1);
    }





    static bool is_palindrome(string::const_iterator begin,
                            string::const_iterator end) {
        if (*begin) {
            while (begin != end) {
                if (*begin != *end)
                    return false;
                if (++begin == end--)
                    break;
            }
        }
        return true;
    }


    string longestPalindrome(string s) {
        auto size = s.size();
        // auto print = [](const char& p) { cout << p; };

        while (size != 1) {
            for (auto i = s.begin(); i + size - 1 != s.end(); ++i) {
                // for_each(i, i + size, print);
                // cout << '\n';
                if (is_palindrome(i, i + size - 1)) {
                    return string(i, i + size);
                }
            }
            --size;
        }

        return string(s.begin(), s.begin() + 1);
    }





    static string mergeStrings(const vector<string> &strings) {
        string result;
        for (auto const &i : strings) {
            result += i;
        }
        return result;
    }

    // Zigzag Conversion
    string convert(string s, int numRows) {
        if (s.size() < numRows || numRows == 1)
            return s;
        string result;
        vector<string> rows(numRows, "");
        // rows.reserve(numRows);

        int indexRow = 0;
        short dir = 1;
        for (auto i = s.begin(); i != s.end(); ++i) {
            rows[indexRow] += *i;
            if ((indexRow == numRows - 1 && dir > 0)
                || (indexRow == 0 && dir < 0))
                dir = -dir;
            indexRow += dir;
        }
        return mergeStrings(rows);
    }

};












// int main () {
//     Solution s;
//     vector<int> nums1 = {1, 2};
//     vector<int> nums2 = {3, 4};
//     auto r = s.findMedianSortedArrays(nums1, nums2);

//     std::cout << "res = " << r << "\n";

//     for (auto &&i : nums1) {
//         std::cout << i << " ";
//     }
// }
