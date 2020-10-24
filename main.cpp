#include <algorithm>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "../utils/PrintUtils.hpp"
#include "../utils/VectorUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

// https://leetcode.com/problems/add-strings/

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() { // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  char digit2char(char ch) { return 'a' + (ch - '1'); }

  char str2char(string &s, int start) {
    int end = start + 2;
    if (end >= s.length() || s[end] != '#')
      return 0;
    return 'j' + stoi(s.substr(start, 2)) - 10;
  }
  string freqAlphabets(string &s) {
    stringstream ss;
    int start = 0;
    char next;
    while (start < s.length()) {
      next = str2char(s, start);
      PV2(s[start], next);
      if (next == 0) {
        PV2(start, s[start]);
        ss << digit2char(s[start]);
        ++start;
      } else {
        ss << next;
        start += 3;
      }
    }
    return ss.str();
  }
};

void test1() { // test
  string s = "10#11#12";
  cout << "jkab ? " << Solution().freqAlphabets(s) << endl;
  string s2 = s = "1326#";
  cout << "acz ? " << Solution().freqAlphabets(s2) << endl;
}

void test2() {}

void test3() {}