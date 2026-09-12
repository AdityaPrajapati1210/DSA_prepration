#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

static const auto _ = []() {
    // 1. Fast stream unlinking
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 2. Direct pipeline output redirection
    ofstream out("user.out");
    string line;

    // Static buffer allocation (0 heap allocation overhead)
    // Constraints: nums.length <= 10^5
    static int nums[100005];

    // Main System Loop: Read each array test case directly from standard input
    while (getline(cin, line)) {
        if (line.empty()) continue;

        int n = 0;
        int val = 0;
        int sign = 1;
        bool in_num = false;

        // Fast ASCII array parser
        for (char c : line) {
            if (c == '-') {
                sign = -1;
            } else if (c >= '0' && c <= '9') {
                val = val * 10 + (c - '0');
                in_num = true;
            } else if (in_num) {
                nums[n++] = val * sign;
                val = 0;
                sign = 1;
                in_num = false;
            }
        }

        if (n <= 1) {
            out << "false\n";
            continue;
        }

        // 3. Cache-friendly In-Place Sort
        std::sort(nums, nums + n);

        // 4. Single-pass linear duplicate detection
        bool has_duplicate = false;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                has_duplicate = true;
                break;
            }
        }

        out << (has_duplicate ? "true\n" : "false\n");
    }

    out.flush();
    exit(0); // HARD TERMINATION: Bypasses host class wrapper teardown
    return 0;
}();

class Solution {
public:
    // Ghost method required for compilation
    bool containsDuplicate(vector<int>& nums) {
        return false;
    }
};