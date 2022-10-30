#include <iostream>
#include <string>
#include <cstdint>
#include <set>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:






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





    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return 2.00000;
    }


};
