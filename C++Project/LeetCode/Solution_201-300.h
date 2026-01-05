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

			int l = 0, r = static_cast<int>(nums.size()) - 1;

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
		
	public:
		//217
		bool containsDuplicate(vector<int>& nums) {
			unordered_set<int> numUsed;
			for (int it : nums) {
				if (numUsed.count(it)) {
					return false;
				}
				numUsed.insert(it);
			}
		}
		//218

		//219
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
		//220

		//221
		int maximalSquare(vector<vector<char>>& matrix) {
			int maxSide = 0;
			for (size_t i = 0;i < matrix.size();++i) {
				if (matrix[i][0] == '1') {
					maxSide = 1;
					break;
				}
			}

			for (size_t i = 1;i < matrix.size();++i) {
				for (size_t j = 0;j < matrix[i].size();++j) {
					if (j == 0) {
						maxSide = max(maxSide, matrix[i][j] - '0');
						continue;
					}
					if (matrix[i][j] == '0') {
						continue;
					}
					int left = matrix[i][j - 1] - '0';
					int up = matrix[i - 1][j] - '0';
					int bias = matrix[i - 1][j - 1] - '0';
					int tempSide = min(left, min(up, bias)) + 1;
					matrix[i][j] = tempSide;
					maxSide = max(maxSide, tempSide);
				}
			}
			return maxSide * maxSide;

		}
		//222
		int countNodes(TreeNode* root) {
			if (root->left == nullptr && root->right == nullptr) {
			 	return 1;
			}

			int leftCount = 0;
			int rightCount = 0;

			if (root->left != nullptr) {
				leftCount = countNodes(root->left);
			}
			if (root->right != nullptr) {
				rightCount = countNodes(root->right);
			}

			return leftCount + rightCount;
		}
		//223
		int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
			int minX1 = min(ax1, ax2), maxX1 = max(ax1, ax2), minX2 = min(bx1, bx2), maxX2 = max(bx1, bx2);
			int minY1 = min(ay1, ay2), maxY1 = max(ay1, ay2), minY2 = min(by1, by2), maxY2 = max(by1, by2);
			return max(0, min(maxX1, maxX2) - max(minX1, minX2)) * max(0, min(maxY1, maxY2) - max(minY1, minY2));
		}
		//224

		//225

		//226
		TreeNode* invertTree(TreeNode* root) {
			if (root == nullptr) return nullptr;
			TreeNode* temp = root->left;
			root->left = root->right;
			root->right = temp;
			if (root->left != nullptr) {
				invertTree(root->left);
			}
			if (root->right != nullptr) {
				invertTree(root->right);
			}
			return root;
		}
		//227

		//228
		vector<string> summaryRanges(vector<int>& nums) {
			vector<string> result;
			int start = nums[0];
			int end = nums[0];
			for (int i = 1;i < nums.size();++i) {
				if (nums[i] == nums[i - 1] + 1) {
					end = nums[i];
				}
				else {
					if (start == end) {
						result.push_back(to_string(start));
					}
					else {
						result.push_back(start + "->" + end);
						start = nums[i];
						end = nums[i];
					}
				}
			}
			return result;
		}
		//229
		vector<int> majorityElement(vector<int>& nums) {
			int candidateX = 0, candidateY = 0;
			int countX = 0, countY = 0;
			bool replaceX = false, replaceY = false;

			for (int it : nums) {
				if (countX > 0 && countY > 0) {
					if (it == candidateX) {
						countX++;
					}
					else if (it == candidateY) {
						countY++;
					}
					else {
						countX--;
					}
				}
				else if (countX > 0) {
					if (it == candidateX) {
						countX++;
					}
					else {
						candidateY = it;
						countY = 1;
					}
				}
				else if (countY > 0) {

				}
				else {

				}


				if (countX == 0) {
					candidateX = it;
					countX = 1;
				}
				else {
					if (candidateX == it) {
						countX++;
					}
					else {
						if (countY == 0) {
							candidateY = it;
							countY = 1;
						}
					}

				}


				if (countY == 0) {
					candidateY = it;
				}



			}




		}
		//230
		int kthSmallest(TreeNode* root, int k) {
			if (root == nullptr) return -1;
			if (root->left == nullptr && root->right == nullptr) {
				k--;
				if (k == 0) {
					return root->val;
				}
				
			}
			if (root->right != nullptr) {
				kthSmallest(root->right, k);
			}
			k--;
			if (k == 0) {
				return root->val;
			}
			if (root->left != nullptr) {
				kthSmallest(root->left, k);
			}
		}
		//231

		//232

		//233

		//234
		bool isPalindrome(ListNode* head) {
			ListNode* slow = head;
			ListNode* fast = head;
			while (fast->next != nullptr && fast->next->next != nullptr) {
				slow = slow->next;
				fast = fast->next->next;
			}
			ListNode* pre = nullptr;
			ListNode* cur = slow->next;
			while (cur != nullptr) {
				ListNode* tempNode = cur->next;
				cur->next = pre;
				pre = cur;
				cur = tempNode;
			}
			ListNode* p1 = head;
			ListNode* p2 = pre;
			while (p2 != nullptr) {
				if (p1->val != p2->val) {
					return false;
				}
				p1 = p1->next;
				p2 = p2->next;
			}
			return true;
		}
		//235

		//236

		//237
		void deleteNode(ListNode* node) {
			if (node == nullptr || node->next == nullptr) return;
			ListNode* cur = node;
			ListNode* next = node->next;
			
			while (next->next != nullptr) {
				swap(cur->val, next->val);
				cur = next;
				next = next->next;
			}
			swap(cur->val, next->val);
			cur->next = nullptr;
		}
		//238
		vector<int> productExceptSelf(vector<int>& nums) {
			vector<int> result(nums.size());
			for (int i = 0;i < nums.size();++i) {
				int mulL = 1;
				int mulR = 1;
				for (int l = 0;l < i;++l) {
					mulL *= nums[l];
				}
				for (int r = i + 1;r < nums.size();++r) {
					mulR *= nums[r];
				}
				result[i] = mulL * mulR;
			}
			return result;
		}
		//239
		vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			if (nums.empty() || nums.size() == 1) return nums;
			vector<int> result;
			int curMax = nums[0];
			for (int i = 1;i < k;++i) {
				curMax = max(curMax, nums[i]);
			}
			result.push_back(curMax);
			for (int i = k;i < nums.size();++i) {
				if (nums[i] >= curMax) {
					curMax = nums[i];
				}
				else {
					if (nums[i - k] < curMax) {
					}
					else {
						curMax = nums[i];
						for (int j = i + 1 - k;j < i;++j) {
							curMax = max(curMax, nums[j]);
						}
					}

				}
				result.push_back(curMax);
			}

		}
		//240
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			for (vector<int> it : matrix) {

				if (it[0] >= target && it[it.size() - 1]) {
					for (int v : it) {
						if (v == target) {
							return true;
						}
					}
				}
			}
			return false;
		}
		//241
		
		//242
		bool isAnagram(string s, string t) {
			if (s.size() != t.size()) return false;
			unordered_map<char, int> dict;
			for (char it : s) {
				if (dict.count(it)) {
					dict[it]++;
				}
				else {
					dict[it] = 1;
				}
			}
			for (char it : t) {
				if (dict.count(it)) {
					dict[it]--;
					if (dict[it] == 0) {
						dict.erase(it);
					}
				}
				else {
					return false;
				}
			}
			return dict.empty();
		}
		//243

		//244

		//245

		//246

		//247

		//248

		//249

		//250

		//251

		//252

		//253

		//254

		//255

		//256

		//257
		vector<string> binaryTreePaths(TreeNode* root) {
			vector<string> result;
			binaryTreePathsExtension(root, result, "");
			return result;
		}
	private:
		void binaryTreePathsExtension(TreeNode* node, vector<string>& result, string path) {
			if (node == nullptr) {
				if (!path.empty()) result.push_back(path);
				return;
			}
			if (path.empty()) {
				path = node->val;
			}
			else {
				path += ("->" + node->val);
			}
			binaryTreePathsExtension(node->left, result, path);
			binaryTreePathsExtension(node->right, result, path);
		}
		
	public:
		//258
		int addDigits(int num) {
			int val = 0;
			while (num > 0) {
				val += (num % 10);
				num /= 10;
			}

			if (val < 10) {
				return val;
			}
			else {
				return addDigits(val);
			}

			
		}
		//259

		//260

		//261

		//262

		//263
		bool isUgly(int n) {
			if (n == 0)return false;
			if (n == 1)return true;
			while (n > 1) {
				int temp = n;
				if (n % 2 == 0) {
					n /= 2;
					continue;
				}
				if (n % 3 == 0) {
					n /= 3;
					continue;
				}
				if (n % 5 == 0) {
					n /= 5;
					continue;
				}
				if (n == temp) {
					return false;
				}
			}
			return true;
		}
		//264
		int nthUglyNumber(int n) {
			if (n == 1) return 1;
			int cur = 1;
			while (n > 1) {
				cur = min(cur * 2, min(cur * 3, cur * 5));
				--n;
			}
			return cur;
		}
		//265

		//266

		//267

		//268
		int missingNumber(vector<int>& nums) {
			if (nums.empty()) return 0;
			int sum = 1;
			if (nums.size() > 1) {
				sum = static_cast<int>(nums.size()) * (static_cast<int>(nums.size()) - 1);
			}
			int curSum = 0;
			for (int it : nums) {
				curSum += it;
			}
			return sum - curSum;
		}
		//269

		//270

		//271

		//272

		//273

		//274
		int hIndex_274(vector<int>& cittations) {
			sort(cittations.begin(), cittations.end());
			int maxh = 0;
			for (int i = 0;i < cittations.size();++i) {
				int cur = cittations[i];
				int count = static_cast<int>(cittations.size()) - i;
				if (cur > count) {
					cur = count;
				}
				maxh = max(maxh, cur);
			}
			return maxh;
		}
		//275
		int hIndex_275(vector<int>& cittations) {
			int maxh = 0;
			for (int i = 0;i < cittations.size();++i) {
				int cur = cittations[i];
				int count = static_cast<int>(cittations.size()) - i;
				if (cur > count) {
					cur = count;
				}
				maxh = max(maxh, cur);
			}
			return maxh;
		}
		//276

		//277

		//278
		int firstBadVersion(int n) {
			int l = 1, r = n;
			while (l < r) {
				int mid = (l + r) / 2;
				if (isBadVersion(mid)) {
					r = mid;
				}
				else {
					l = mid + 1;
				}
			}
			return l;
		}
	private:
		bool isBadVersion(int version) {
			return version >= 4;
		}

	public:
		//279
		int numSquares(int n) {
			int count = 1;
			while (count < n) {
				int v = n / count;
				int t = static_cast<int>(sqrt(v));
				if (t * t == v) {
					return count;
				}
				count++;
			}
			return count;
		}

		void moveZeros(vector<int>& nums) {
			int frag = -1;
			for (int i = 0;i < nums.size();++i) {
				if (frag == -1) {
					if (nums[i] == 0) {
						frag = i;
					}
				}
				else {
					if (nums[i] > 0) {
						nums[frag] = nums[i];
						++frag;
					}
				}
			}
			
			for (int i = frag;i < nums.size();++i) {
				nums[i] = 0;
			}
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