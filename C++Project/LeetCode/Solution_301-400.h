#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <unordered_set>


#include "Extension.h"
#include "Sort.h"

using namespace std;

namespace Solution_301_400 {
	class Solution {
	public:
		bool add(string s) {
			for (int i = 0;i < s.length();++i) {
				cout << "第一个数量：" << (i + 1) << endl;
				int v1 = stoi(s.substr(0, i + 1));
				for (int j = i + 1;j < s.length();++j) {
					cout << "第二个数量：" << (j - i) << endl;
					int v2 = stoi(s.substr(i + 1, j - i));
					bool state = addExtension(s, v1, v2, j + 1);
					if (state) return true;
					if (s[i + 1] == '0') break;
				}
				if (s[0] == '0')break;
			}
			return false;
		}
	private:
		bool addExtension(string s, int one, int two, int index) {
			if (index >= s.length())return false;
			int value = one + two;
			for (int i = index;i < s.length();++i) {
				int three = stoi(s.substr(index, i - index + 1));
				cout << "检测" << one << "+" << two << "=" << s.substr(index, i - index + 1)<< "相等" << (value == stoi(s.substr(index, i - index + 1))) << endl;

				if (three > value) {
					cout << "大于已经失败" << endl;
					return false;
				}
				else if (value == stoi(s.substr(index, i - index + 1))) {
					if (i + 1 == s.length()) {
						cout << "返回正确" << endl;
						return true;
					}
					bool state = addExtension(s, two, value, i + 1);
					if (state) return true;
				}
				if (s[index] == '0') break;
			}
			return false;
		}




		//740
		int deleteAndEarn(vector<int>& nums) {
			unordered_map<int, int> numSum;
			for (int num : nums) {
				numSum[num] += num;
			}
			vector<int> uniqueNum;
			for (auto& p : numSum) {
				uniqueNum.push_back(p.first);
			}
			sort(uniqueNum.begin(), uniqueNum.end());

			vector<int> dp(nums.size() + 1);
			dp[0] = 0;
			dp[1] = numSum[uniqueNum[0]];
			for (int i = 2;i <= uniqueNum.size();i++) {
				int curNum = uniqueNum[i - 1];
				int prevNum = uniqueNum[i - 2];

				if (curNum == prevNum + 1) {
					dp[i] = max(dp[i - 1], dp[i - 2] + numSum[curNum]);
				}
				else {
					dp[i] = dp[i - 1] + numSum[curNum];
				}
			}
			return dp[uniqueNum.size()];
		}
		//746
		int minCostClimbingStairs(vector<int>& cost) {
			vector<int> dp(cost.size() + 1);
			dp[0] = 0;
			dp[1] = 0;
			dp[2] = min(dp[0] + cost[0], dp[1] + cost[1]);

			for (int i = 3;i < cost.size();i++) {
				dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
			}
			return dp[cost.size()];
		}

	};
}