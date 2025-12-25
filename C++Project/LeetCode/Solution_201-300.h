#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <set>


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
			set<int> fargs;
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

