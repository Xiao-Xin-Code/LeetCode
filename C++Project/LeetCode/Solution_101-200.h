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

namespace Solution_101_200 {
	class Solution {
	public:
		//101
		bool isSymmetric(TreeNode* root) {
			if (root == nullptr) return false;
			return isSymmetricExtension(root->left, root->right);
		}
	private:
		bool isSymmetricExtension(TreeNode* root1, TreeNode* root2) {
			if (root1 == nullptr && root2 == nullptr) return true;
			if (root1 == nullptr || root2 == nullptr)return false;
			if (root1->val != root2->val) return false;

			bool sameW = isSymmetricExtension(root1->left, root2->right);
			if (sameW == false) return false;
			bool sameN = isSymmetricExtension(root1->right, root2->left);
			if (sameN == false) return false;
			return true;
		}
		
	public:
		//102
		vector<vector<int>> levelOrder(TreeNode* root) {
			queue<TreeNode*> q;
			//q.size();
		}
	private:
		void levelOrderExtension(queue<TreeNode*> nodeQueue, vector<int>& result) {
			if (!nodeQueue.empty()) {
				queue<TreeNode*> tempQueue;
				for (int i = 0;i < nodeQueue.size();++i) {
					TreeNode* node = nodeQueue.front();
					nodeQueue.pop();
					result.push_back(node->val);
				}
				if (!tempQueue.empty()) {
					levelOrderExtension(tempQueue, result);
				}
			}
		}
		
	public:
		//103
		vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

		}
	private:
		void zigzagLevelOrder(vector<TreeNode*> nodes, vector<int>& results, bool state) {
			if (!nodes.empty()) {
				vector<TreeNode*> tempNodes;
				if (state) {
					for (int i = 0;i < nodes.size();i++) {
						if (nodes[i]->left != nullptr) {
							tempNodes.push_back(nodes[i]->left);
						}
						if (nodes[i]->right != nullptr) {
							tempNodes.push_back(nodes[i]->right);
						}
						results.push_back(nodes[i]->val);
					}
				}
				else {
					for (int i = static_cast<int>(nodes.size()) - 1;i >= 0;--i) {
						if (nodes[i]->right != nullptr) {
							tempNodes.push_back(nodes[i]->right);
						}
						if (nodes[i]->left != nullptr) {
							tempNodes.push_back(nodes[i]->left);
						}
						results.push_back(nodes[i]->val);
					}

				}
				state = !state;
			}
		}
		
	public:
		//104
		int maxDepth(TreeNode* root) {

		}
		//105
		TreeNode* buildTree_105(vector<int>& preorder, vector<int>& inorder) {

			int rootIndex = -1;
			for (int i = 0;i < inorder.size();i++) {
				if (inorder[i] == preorder[0]) {
					rootIndex = i;
				}
			}
			//[0,rootindex-1][rootindex+1,nums2.size()-1]


		}
		//106
		TreeNode* buildTree_106(vector<int>& inorder, vector<int>& postorder) {

		}
		//118
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> results;
			results.push_back({ 1 });
			int n = 2;
			while (n <= numRows) {
				vector<int> result(n);
				result[0] = 1;
				result[n - 1] = 1;
				for (int i = 1;i < n - 1;i++) {
					result[i] = results[n - 1][i - 1] + results[n - 1][i];
				}
				results.push_back(result);
				n++;
			}
			return results;
		}
		//119
		vector<int> getRow(int rowIndex) {
			vector<int> result = { 1 };
			int n = 2;
			while (n <= rowIndex) {
				vector<int> temp(n);
				temp[0] = 1;
				temp[n - 1] = 1;
				for (int i = 1;i < n - 1;i++) {
					temp[i] = result[i - 1] + result[i];
				}
				result = temp;
				n++;
			}
			return result;
		}
		//120
		int minimumTotal(vector<vector<int>>& triangle) {
			int curMin = 0;
			for (int i = 0;i < triangle.size();i++) {
				curMin = triangle[i][0] + triangle[i - 1][0];
				for (int j = 1;j < triangle[i].size();j++) {
					if (j == 0) {
						triangle[i][j] += triangle[i - 1][j];
					}
					else if (j == triangle[i].size() - 1) {
						triangle[i][j] += triangle[i - 1][j - 1];
					}
					else {
						triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
					}

					curMin = min(curMin, triangle[i][j]);
				}
			}
			return curMin;
		}

		int maxprices(vector<int>& prices) {
			int result = 0;
			int minprice = prices[0];
			for (int i = 1;i < prices.size();i++) {
				minprice = min(minprice, prices[i]);
				result = max(result, prices[i] - minprice);
			}
			return result;
		}

		bool checkStr(string str) {
			int l = 0, r = static_cast<int>(str.length()) - 1;
			while (1 < r) {
				while (l < r && str[l] < 'a' && str[l] > 'z') {
					l++;
				}
				while (l < r && str[r] < 'a' && str[r]>'z') {
					r--;
				}

				if (str[l] != str[r]) {
					return false;
				}
				l++;r--;
			}
			return true;
		}

		int longestConsecutive(vector<int>& nums) {
			quickSort(nums.begin(), nums.end());
			int maxcount = 1;
			int count = 1;
			int i = 1;
			while (i < nums.size()) {
				if (nums[i - 1] + 1 == nums[i]) {
					count++;
				}
				else {
					maxcount = max(maxcount, count);
					count = 1;
					i++;
				}
				i++;
			}
			maxcount = max(maxcount, count);
			return maxcount;
		}

		int valueNode(TreeNode* root) {
			vector<int> result;
			valueNodeExtenion(root, 0, result);

			int sum = 0;
			for (int it : result) {
				sum += it;
			}
			return sum;
		}
	private:
		void valueNodeExtenion(TreeNode* node, int value, vector<int>& result) {
			if (node == nullptr) {
				result.push_back(value);
				return;
			}
			value = node->val + value * 10;
			valueNodeExtenion(node->left, value, result);
			valueNodeExtenion(node->right, value, result);
		}

	public:
		void loopStr(string str, vector<vector<string>>& results, vector<string> result, int start) {
			if (start >= str.length()) {
				cout << "Ìí¼Ó" << endl;
				results.push_back(result);
				return;
			}
			for (int i = start;i < str.length();i++) {
				string curstr = str.substr(start, i - start + 1);
				if (loopStrExtension(curstr)) {
					result.push_back(curstr);
					//cout << curstr << endl;
					loopStr(str, results, result, i + 1);
					result.pop_back();
				}
				else {
					continue;
				}
			}
		}
	private:
		bool loopStrExtension(string str) {
			int l = 0, r = str.length() - 1;
			while (l < r) {
				if (str[l] != str[r]) {
					return false;
				}
				l++;
				r--;
			}
			return true;
		}

	public:
		int onlyOne(vector<int> nums) {
			quickSort(nums.begin(), nums.end());
			int cur = nums[0];
			bool hascount = false;
			for (int i = 1;i < nums.size();i++) {
				if (nums[i] == nums[i - 1]) {
					hascount = true;
				}
				else {
					if (hascount) {
						hascount = false;
					}
					else {
						return cur;
					}
					cur = nums[i];
				}
			}
			return cur;
		}


		//198
	public:
		int rob(vector<int>& nums) {
			vector<int> dp(nums.size());
			dp[0] = nums[0];
			dp[1] = max(dp[0], nums[1]);
			dp[2] = max(dp[0] + nums[2], dp[1]);
			for (int i = 3;i < nums.size();i++) {
				dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 2]);
			}
			return dp[nums.size() - 1];
		}
		//221
	public:
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
	public:
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
	public:
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