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
					mask |= (1 << (c - 'a'));
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

		int coinChange(vector<int>& coins, int amount) {
			sort(coins.begin(), coins.end());
			return coinChangeExtension(coins, amount, static_cast<int>(coins.size()) - 1, 0);
		}
		int coinChangeExtension(vector<int>& coins, int amount, int index, int curcount) {
			if (index < 0)return -1;
			int count = amount / coins[index];
			int mod = amount % coins[index];
			if (count == 0) {
				cout << "直接下一个" << endl;
				return coinChangeExtension(coins, amount, index-1, curcount);
			}
			if (mod == 0) {
				cout << "整除" << index << endl;
				return curcount + count;
			}
			else {
				for (int c = count;c >= 0;--c) {
					cout << "数量：" << c << endl;
					int temp = coinChangeExtension(coins, amount - coins[index] * c, index-1, curcount + c);
					if (temp > 0) {
						return temp;
					}
				}
			}
			return -1;
		}

		void wiggleSort(vector<int>& nums) {
			for (int i = 1;i < nums.size();++i) {
				int mode = i % 2;
				if ((mode == 1 && nums[i] < nums[i - 1]) || (mode == 0 && nums[i] > nums[i - 1])) {
					swap(nums[i - 1], nums[i]);
				}
			}
		}

		bool isPowerOfThree(int n) {
			return n > 0 && (1162261467 % n == 0);
		}

		ListNode* oddEvenList(ListNode* head) {
			if (head == nullptr) return head;
			ListNode* jFirst = nullptr;
			ListNode* jLast = nullptr;
			ListNode* oFirst = nullptr;
			ListNode* oLast = nullptr;
			while (head != nullptr) {
				ListNode* next = head->next;
				if (head->val % 2 == 0) {
					if (oLast != nullptr) {
						oLast->next = head;
					}
					else {
						oFirst = head;
					}
					oLast = head;
					oLast->next = nullptr;
				}
				else {
					if (jLast != nullptr) {
						jLast->next = head;
					}
					else {
						jFirst = head;
					}
					jLast = head;
				}
				head = next;
			}

			if (oLast != nullptr) {
				oLast->next = nullptr;
			}
			if (jLast != nullptr) {
				jLast->next = oFirst;
				return jFirst;
			}
			else {
				return oFirst;
			}
		}

		int isListNode(vector<int>& nums) {
			int index = 0;
			isListNodeExtension(nums, index);
			return index;
		}

		void isListNodeExtension(vector<int>& nums,int& index) {
			if (nums[index] == 0) {
				return;
			}
			if (index + 1 < nums.size()) {
				index++;
				if (nums[index] != 0) {
					isListNodeExtension(nums, index);
				}
			}
			if (index + 1 < nums.size()) {
				index++;
				if (nums[index] != 0) {
					isListNodeExtension(nums, index);
				}
			}
			index--;
			
		}

		bool isValidSerialization(string preorder) {
			if (preorder.empty())return false;
			if (preorder[0] == '#') return false;
			int last = static_cast<int>(preorder.length()) - 1;
			while (last >= 0) {
				if (preorder[last] != '#') {
					break;
				}
				last--;
			}
			if (last > 2) {
				int start = 0;
				string one;
				string two;
				while (start < preorder.length()) {
					if (preorder[start] == ',') {
						if (one == "#" && two == "#") {
							return false;
						}
						one = two;
						two = "";
					}
					else {
						two = two + preorder[start];
					}
					start++;
				}
			}
			return true;
		}

		bool increasingTriplet(vector<int>& nums) {
			int first = INT_MAX, second = INT_MAX;
			for (int it : nums) {
				if (it < first) first = it;
				else if (it < second) second = it;
				else return true;
			}
			return false;
		}

		int price(TreeNode* root) {
			if (root == nullptr) return 0;
			int choose_root = root->val;
			if (root->left) {
				choose_root += price(root->left->left) + price(root->left->right);
			}
			if (root->right) {
				choose_root += price(root->right->left) + price(root->right->right);
			}
			int unchoose_root = price(root->left) + price(root->right);
			return max(choose_root, unchoose_root);
		}

		//338
		vector<int> cuntBits(int n) {
			vector<int> ans(n + 1, 0);
			for (int i = 1;i <= n;++i) {
				ans[i] = ans[i >> 1] & (i & 1);
			}
			return ans;
		}

		bool isPowerOfFour(int n) {
			return n > 0 && (1073741824 % n) == 0 && (n & 0xAAAAAAAA) == 0;
		}
		//343
		int integerBreak(int n) {
			int count = n / 3;
			int mod = n % 3;
			if (mod == 0) {
				return (int)pow(3, count);
			}
			else if (mod == 1) {
				return (int)pow(3, count - 1) * 4;
			}
			else {
				return (int)pow(3, count)* mod;
			}
		}

		void reverseString(vector<char>& s) {
			int l = 0;
			int r = s.size() - 1;
			while (l < r) {
				swap(s[l], s[r]);
				l++;
				r--;
			}
		}

		string reverseVowels(string s) {
			unordered_set<char> vowels = { 'a','e','i','o','u','A','E','I','O','U' };
			int l = 0;
			int r = s.length() - 1;

			while (l < r) {
				while (l < r && !vowels.count(s[l])) l++;
				while (l < r && !vowels.count(s[r])) r--;
				if (l < r) {
					swap(s[l], s[r]);
				}
				l++;
				r--;
			}

			return s;
		}

		vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
			vector<int> result;
			unordered_set<int> frags;
			for (int it : nums1) {
				if (!frags.count(it)) {
					frags.insert(it);
				}
			}
			for (int it : nums2) {
				if (frags.count(it)) {
					result.push_back(it);
					frags.erase(it);
				}
			}
			return result;
		}

		vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
			unordered_map<int, int> fragscount;
			vector<int> result;
			for (int it : nums1) {
				if (fragscount.count(it)) {
					fragscount[it]++;
				}
				else {
					fragscount[it] = 1;
				}
			}
			for (int it : nums2) {
				if (fragscount.count(it) && fragscount[it] > 0) {
					result.push_back(it);
					fragscount[it]--;
				}
			}
			return result;
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