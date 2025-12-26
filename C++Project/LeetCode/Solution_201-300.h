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

namespace Solution_201_300 {

	class Solution {	
	public:
		//201
		int rangeBitwiseAnd(int left, int right) {
			int count = 0;
			while (left < right) {
				left = left >> 1;
				right = right >> 1;
				count++;
			}

			return left << count;
		}
		//202
		bool isHappy(int n) {
			unordered_set<int> fargs;
			while (true) {
				int result = 0;
				int mod = n % 10;
				result = result + mod * mod;
				n = n / 10;
				if (result == 1) return true;
				n = result;
				if (fargs.count(result)) {
					return false;
				}
				fargs.insert(result);
			}
		}
		//203
		ListNode* removeElements(ListNode* head, int val) {
			ListNode* cur = nullptr;
			ListNode* result = nullptr;
			while (head != nullptr) {
				if (head->val != val) {
					if (cur == nullptr) {
						cur = head;
						result = head;
					}
					else {
						cur->next = head;
						cur = cur->next;
					}
				}
				head = head->next;
			
			}
			return result;
		}
		//204
		int countPrimes(int n) {

		}
		//205
		bool isIsomorphic(string s, string t) {
			if (s.length() != t.length()) return false;
			unordered_map<char, char> dict;
			int index = 0;
			while (index < s.length()) {
				if (dict.count(s[index])) {
					if (t[index] != dict[s[index]])return false;
				}
				else {
					dict[s[index]] = t[index];
				}
				index++;
			}
			return true;
		}
		//206
		ListNode* reverseList(ListNode* head) {
			ListNode* newHead = nullptr;
			ListNode* next = head;
			while (next != nullptr) {
				ListNode* temp = next->next;
				next->next = newHead;
				newHead = next;
				next = temp;
			}
			return newHead;
		}
		//207
		bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

			

		}
		//208

		//209
		int minSubArrayLen(vector<int>& nums, int target) {
			int result = 0;
			for (int it : nums) {
				result += it;
			}

			if (result < target)return {};

			int l = 0, r = nums.size() - 1;

			while (l < r) {
				if (nums[l] < nums[r]) {
					int temp = result - nums[l];
					if (temp >= target) {
						result = temp;
						l++;
					}
					else {
						break;
					}
				}
				else {
					int temp = result - nums[r];
					if (temp >= target) {
						result = temp;
						r--;
					}
					else {
						break;
					}
				}
			}

			return r - l + 1;
		}
		//210

		//211

		//212

		//213

		//214

		//215

		//216
		vector<vector<int>> combinationSum3(int k, int n) {
			vector<vector<int>> results;
			combinationSum3Extension(k, n, results, {}, 0, 1);
			return results;
		}
	private:
		void combinationSum3Extension(int k,int n,vector<vector<int>>& results,vector<int> result,int sum,int start) {
			if (result.size() == k) {
				if (sum == n) {
					results.push_back(result);
				}
				return;
			}

			for (int i = start;i < 10;++i) {
				int tempSum = sum + i;
				if (tempSum <= n) {
					result.push_back(i);
					combinationSum3Extension(k, n, results, result, tempSum, i + 1);
					result.pop_back();
				}
				else {
					break;
				}
			}
		}

		bool containsDuplicate(vector<int>& nums) {
			unordered_set<int> numUsed;
			for (int it : nums) {
				if (numUsed.count(it)) {
					return false;
				}
				numUsed.insert(it);
			}
		}

		bool containsDuplicate2(vector<int>& nums, int k) {
			unordered_map<int,vector<int>> numUsed;
			for (int i = 0;i < nums.size();++i) {
				if (numUsed.count(nums[i])) {
					for (int it : numUsed[nums[i]]) {
						if (i - it <= k) {
							return true;
						}
					}
					numUsed[nums[i]].push_back(i);
				}
				else {
					numUsed[nums[i]] = { i };
				}
			}
			return false;
		}


		//221
		int maximalSquare(vector<vector<char>>& matrix) {
			int maxLength = 0;
			for (int i = 0;i < matrix[0].size();i++) {
				if (matrix[0][i] == '1') {
					maxLength = 1;
					break;
				}
			}
			for (int i = 1;i < matrix.size();i++) {

				for (int j = 0;j < matrix[i].size();j++) {
					if (j == 0) {
						maxLength = max(maxLength, matrix[i][j] - '0');
					}
					else {
						if (matrix[i][j] == '1') {
							if (matrix[i][j - 1] != '0' && matrix[i - 1][j - 1] != '0' && matrix[i - 1][j] != '0') {
								matrix[i][j] = (char)(min({ matrix[i][j - 1] - '0', matrix[i - 1][j - 1] - '0', matrix[i - 1][j] - '0' }) + 1);
							}
						}
						maxLength = max(maxLength, matrix[i][j] - '0');
					}
				}
			}
			return maxLength * maxLength;
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

