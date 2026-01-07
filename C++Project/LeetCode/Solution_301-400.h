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
		
		//301

		//302

		//303

		//304

		//305

	public:
		//306
		bool isAdditiveNumber(string num) {
			for (int i = 0;i < num.length();++i) {
				cout << "第一个数量：" << (i + 1) << endl;
				int v1 = stoi(num.substr(0, i + 1));
				for (int j = i + 1;j < num.length();++j) {
					cout << "第二个数量：" << (j - i) << endl;
					int v2 = stoi(num.substr(i + 1, j - i));
					bool state = isAdditiveNumberExtension(num, v1, v2, j + 1);
					if (state) return true;
					if (num[i + 1] == '0') break;
				}
				if (num[0] == '0')break;
			}
			return false;
		}
	private:
		bool isAdditiveNumberExtension(string num, int one, int two, int index) {
			if (index >= num.length())return false;
			int value = one + two;
			for (int i = index;i < num.length();++i) {
				int three = stoi(num.substr(index, i - index + 1));
				cout << "检测" << one << "+" << two << "=" << num.substr(index, i - index + 1)<< "相等" << (value == stoi(num.substr(index, i - index + 1))) << endl;

				if (three > value) {
					cout << "大于已经失败" << endl;
					return false;
				}
				else if (value == stoi(num.substr(index, i - index + 1))) {
					if (i + 1 == num.length()) {
						cout << "返回正确" << endl;
						return true;
					}
					bool state = isAdditiveNumberExtension(num, two, value, i + 1);
					if (state) return true;
				}
				if (num[index] == '0') break;
			}
			return false;
		}

		//308

		//309

		//310

		//311

		//312

		//313

		//314

	public:
		//315
		vector<int> countSmaller(vector<int>& nums) {
			vector<int> counts(nums.size(), 0);
			for (int i = 0;i < nums.size();++i) {
				for (int j = 0;j < i - 1;++j) {
					if (nums[j] > nums[i]) {
						counts[i]++;
					}
				}
			}
			return counts;
		}
		//316
		string removeDuplicateLetters(string s) {
			string result;
			/***
			* 方法一 O(n^2)
			for (int i = 0;i < s.length();++i) {
				bool hasSame = false;
				for (int j = 0;j < result.length();++j) {
					if (result[j] == s[i]) {
						hasSame = true;
						if (j + 1 < result.length()) {
							if (result[j + 1] < result[j]) {
								cout << "移除" << j << ":" << result[j] << endl;
								result.erase(j, 1);
								result = result + s[i];
								cout << "添加" << s[i] << endl;
								break;
							}
						}
					}
				}
				if (!hasSame) {
					result = result + s[i];
					cout << "添加" << s[i] << endl;
				}
			}
			
			*/
			stack<char> stk;
			unordered_set<char> inStack;
			unordered_map<char, int> charMap;

			for (int i = 0;i < s.length();++i) {
				charMap[s[i]] = i;
			}

			for (int i = 0;i < s.length();++i) {
				if (inStack.count(s[i])) {
					continue;
				}
				else {
					while (!stk.empty() && i<charMap[stk.top()] && stk.top()>s[i]) {
						inStack.erase(stk.top());
						stk.pop();
					}
					stk.push(s[i]);
					inStack.insert(s[i]);
				}
			}
			while (!stk.empty()) {
				result += stk.top();
				stk.pop();
			}
			
			return result;
		}
		//317

		//318
		int maxProduct(vector<string>& words) {
			vector<int> masks(words.size());
			for (int i = 0;i<words.size();++i) {
				int mask = 0;
				for (char c : words[i]) {
					mask|=(1<< c-'a');
				}
				masks[i] = mask;
			}
			int mul = 0;
			for (int i = 0;i < masks.size();++i) {
				int len = 0;
				for (int j = i + 1;j < masks.size();++j) {
					if ((masks[i] & masks[j]) == 0) {
						len = max(len, static_cast<int>(words[j].length()));
					}
				}
				mul = max(mul, static_cast<int>(words[i].length())*len);
			}
			return mul;
		}
		//319
		int bulbSwitch(int n) {
			vector<bool> states(n,true);
			int ncount = 2;
			while (ncount <= n) {
				for (int i = ncount-1;i < n;i+=ncount) {
					states[i] = -states[i];
				}
			}

			int count = 0;
			for (bool it : states) {
				if(it) count++;
			}
			return count;
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