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
			return buildTree_105_Extension(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
		}
	private:
		TreeNode* buildTree_105_Extension(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight) {
			if (preLeft > preRight) return nullptr;
			TreeNode* node = new TreeNode(preorder[preLeft]);
			for (int i = inLeft;i <= inRight;i++) {
				if (inorder[i] == preorder[preLeft]) {
					node->left = buildTree_105_Extension(preorder, inorder, preLeft + 1, preLeft + i - inLeft, inLeft, i - 1);
					node->right = buildTree_105_Extension(preorder, inorder, preLeft + i - inLeft + 1, preRight, i + 1, inRight);
					break;
				}
			}
			return node;
		}
	
	public:
		//106
		TreeNode* buildTree_106(vector<int>& inorder, vector<int>& postorder) {
			return buildTree_106_Extension(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
		}
	private:
		TreeNode* buildTree_106_Extension(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight, int postLeft, int postRight) {
			if (postLeft > postRight) return nullptr;
			TreeNode* node = new TreeNode(postorder[postRight]);
			for (int i = inLeft;i <= inRight;i++) {
				if (inorder[i] == postorder[postRight]) {
					node->left = buildTree_106_Extension(inorder, postorder, inLeft, i - 1, postLeft, postLeft + i - inLeft);
					node->right = buildTree_106_Extension(inorder, postorder, i + 1, inRight, postLeft + i - inLeft + 1, postRight - 1);
					break;
				}
			}
			return node;
		}

	public:
		//107
		vector<vector<int>> levelOrderBottom(TreeNode* root) {
			vector<vector<int>> results;
			queue<TreeNode*> nodeQueue;
			nodeQueue.push(root);
			levelOrderBottomExtension(nodeQueue, results);
			return results;
		}
	private:
		void levelOrderBottomExtension(queue<TreeNode*> nodeQueue,vector<vector<int>>& results) {
				if (!nodeQueue.empty()) {
					queue<TreeNode*> tempQueue;
					vector<int> result;
					while (!nodeQueue.empty()) {
						TreeNode* node = nodeQueue.front();
						nodeQueue.pop();
						result.push_back(node->val);
						if (node->left != nullptr) {
							tempQueue.push(node->left);
						}
						if (node->right != nullptr) {
							tempQueue.push(node->right);
						}
					}

					if (!tempQueue.empty()) {
						levelOrderBottomExtension(tempQueue, results);
					}

					if (!result.empty()) {
						results.insert(results.begin(), result);
					}
				}
			}

	public:
		//108
		TreeNode* sortedArrayToBST(vector<int>& nums) {
			return sortedArrayToBSTeExtension(nums, 0, nums.size() - 1);
		}
	private:
		TreeNode* sortedArrayToBSTeExtension(vector<int>& nums, int left, int right) {
			if (left < right) {
				int mid = (left + right) / 2;
				TreeNode* node = new TreeNode(nums[mid]);

				node->left = sortedArrayToBSTeExtension(nums, left, mid - 1);
				node->right = sortedArrayToBSTeExtension(nums, mid + 1, right);
				return node;
			}
			return nullptr;
		}

	public:
		//109
		TreeNode* sortedListToBST(ListNode* head) {

		}
		//110
		bool isBalanced(TreeNode* root) {
			return isBalancedExtension(root) >= 0;
		}
	private:
		int isBalancedExtension(TreeNode* root) {
			if (root == nullptr) return 0;
			int leftDepth = isBalancedExtension(root->left);
			if (leftDepth == -1) return -1;
			int rightDepth = isBalancedExtension(root->right);
			if (rightDepth == -1) return -1;

			if (abs(leftDepth - rightDepth) > 1) {
				return -1;
			}

			return 1 + max(leftDepth, rightDepth);
		}

	public:
		//111
		int minDepth(TreeNode* root) {
			if (root == nullptr) return 0;
			int leftDepth = minDepth(root->left);
			int rightDepth = minDepth(root->right);
			return 1 + min(leftDepth, rightDepth);
		}
		//112
		bool hasPathSum(TreeNode* root, int targetSum) {
			if (root == nullptr) {
				return targetSum == 0;
			}
			return  hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
		}
		//113
		vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
			vector<vector<int>> results;
			pathSumExtension(root, targetSum, results, {});
			return results;
		}
	private: 
		void pathSumExtension(TreeNode* root, int targetSum, vector<vector<int>>& results, vector<int> result) {
			if (root == nullptr) {
				if (targetSum == 0) {
					results.push_back(result);
				}
				return;
			}
			result.push_back(root->val);
			pathSumExtension(root->left, targetSum - root->val, results, result);
			pathSumExtension(root->right, targetSum - root->val, results, result);
			result.pop_back();
		}
	
		//114
	public:
		TreeNode* flatten(TreeNode* root) {
			if (root == nullptr) return nullptr;
			TreeNode* node = new TreeNode(root->val);
			node->right = flatten(root->left);
			if (node->right != nullptr) {
				node->right = flatten(root->right);
			}
			else {
				node->right->right = flatten(root->right);
			}
			return node;
		}
		//115
		int numDistinct(string s, string t) {

		}

	public:
		//116
		BinaryTree::Node* connect_116(BinaryTree::Node* root) {
			using BinaryTree::Node;
			queue<Node*> nodeQueue;
			nodeQueue.push(root);
			connect_116_Extension(nodeQueue);
			return root;
		}
	private:
		void connect_116_Extension(queue<BinaryTree::Node*> nodeQueue) {
			using BinaryTree::Node;
			queue<Node*> tempQueue;
			Node dummy;
			Node* pre = &dummy;
			while (!nodeQueue.empty()) {
				BinaryTree::Node* temp = nodeQueue.front();
				nodeQueue.pop();

				if (temp->left) {
					tempQueue.push(temp->left);
				}
				if (temp->right) {
					tempQueue.push(temp->right);
				}

				if (pre == &dummy) {
					pre == temp;
				}
				else {
					pre->next = temp;
				}
			}
		}
		
	public:
		//117
		BinaryTree::Node* connect_117(BinaryTree::Node* root) {

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
		//121
		int maxProfit_121(vector<int>& prices) {
			int result = 0;
			int minprice = prices[0];
			for (int i = 1;i < prices.size();i++) {
				minprice = min(minprice, prices[i]);
				result = max(result, prices[i] - minprice);
			}
			return result;
		}
		//122
		int maxProfit_122(vector<int>& prices) {

		}
		//123
		int maxProfit_123(vector<int>& prices) {

		}
		//124
		int maxPathSum(TreeNode* root) {

		}
		//125
		bool isPalindrome(string s) {
			int l = 0, r = static_cast<int>(s.length()) - 1;
			while (1 < r) {
				while (l < r && s[l] < 'a' && s[l] > 'z') {
					l++;
				}
				while (l < r && s[r] < 'a' && s[r]>'z') {
					r--;
				}

				if (s[l] != s[r]) {
					return false;
				}
				l++;r--;
			}
			return true;
		}
		//126
		vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

		}
		//127
		int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

		}
		//128
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
		//129
		int sumNumbers(TreeNode* root) {
			vector<int> result;
			sumNumbersExtenion(root, 0, result);

			int sum = 0;
			for (int it : result) {
				sum += it;
			}
			return sum;
		}
	private:
		void sumNumbersExtenion(TreeNode* node, int value, vector<int>& result) {
			if (node == nullptr) {
				result.push_back(value);
				return;
			}
			value = node->val + value * 10;
			sumNumbersExtenion(node->left, value, result);
			sumNumbersExtenion(node->right, value, result);
		}
	
	public:
		//130
		void solve(vector<vector<char>>& board) {

		}
		//131
		vector<vector<string>> partition(string s) {
			vector<vector<string>> results;
			partitionExtension(s, results, {}, 0);
			return results;
		}
	private:
		void partitionExtension(string str, vector<vector<string>>& results, vector<string> result, int start) {
			if (start >= str.length()) {
				cout << "添加" << endl;
				results.push_back(result);
				return;
			}
			for (int i = start;i < str.length();i++) {
				string curstr = str.substr(start, i - start + 1);
				if (isPartition(curstr)) {
					result.push_back(curstr);
					//cout << curstr << endl;
					partitionExtension(str, results, result, i + 1);
					result.pop_back();
				}
				else {
					continue;
				}
			}
		}
		bool isPartition(string str) {
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
		//132
		int minCut(string s) {

		}
		//133
		Graph::Node* cloneGraph(Graph::Node* node) {
			using Graph::Node;
			queue<Node*> nodeQueue;
			nodeQueue.push(node);

			Node* belogNode = nullptr;
			Node* head = nullptr;

			while (!nodeQueue.empty()) {

				Node* sourceNode = nodeQueue.front();
				nodeQueue.pop();

				Node* targetNode = new Node(sourceNode->val);
				if (head == nullptr) {
					head = targetNode;
				}

				if (belogNode == nullptr) {
					belogNode = targetNode;
				}
				else {
					belogNode->neighbors.push_back(targetNode);
				}

				if (!sourceNode->neighbors.empty()) {
					for (Node* it : sourceNode->neighbors) {
						nodeQueue.push(it);
					}
				}
			}

			return head;
		}
		//134
		int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
			int totalGas = 0;
			for (int i = 0;i < gas.size();i++) {
				if (gas[i] >= cost[i]) {
					//可以开始
					totalGas = gas[i] - cost[i];
					int next = i + 1;
					if (next == gas.size()) {
						next = 0;
					}
					if (canCompleteCircuitExtension(gas, cost, totalGas, i, next)) {
						return i;
					}
				}
			}
			return -1;
		}
	private:
		bool canCompleteCircuitExtension(vector<int>& gas, vector<int>& cost, int totalGas, int start, int cur) {
			if (cur == start) {
				return true;
			}
			totalGas = totalGas + gas[cur] - cost[cur];
			if (totalGas >= 0) {
				//切换到下一个

				cur = cur + 1;
				if (cur == gas.size()) {
					cur = 0;
				}
				return canCompleteCircuitExtension(gas, cost, totalGas, start, cur);
			}
			else {
				return false;
			}
		}
	
	public:
		//135
		int candy(vector<int>& ratings) {
			if (ratings.empty())return 0;
			if (ratings.size() == 1) return 1;
			if (ratings.size() == 2) return 3;
			int pre = 1;
			int mid = 1;
			int next = 1;
			int result = 0;
			vector<int> cost(ratings.size(), 1);
			for (int i = 1;i + 1 < ratings.size();i++) {
				if (ratings[i] >= ratings[i + 1]) {
					if (mid <= next) {
						mid = next + 1;
					}
				}
				else {
					if (mid >= next)
					{
						next = mid + 1;
					}
				}
				if (ratings[i] >= ratings[i - 1]) {
					if (mid <= pre) {
						mid = pre + 1;
					}
				}
				else {
					if (mid >= pre) {
						pre = mid + 1;
					}
				}
				result = result + pre;
			}
			result = result + mid + next;
			return result;
		}
		//136
		int singleNumber_136(vector<int> nums) {
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
		//137
		int singleNumber_137(vector<int> nums) {

		}
		//138
		RandomList::Node* copyRandomList(RandomList::Node* head) {
			using RandomList::Node;
			if (!head) return nullptr;
			Node* targetNode = new Node(head->val);
			if (head->next) {
				targetNode->next = copyRandomList(head->next);
			}
			if (head->random) {
				targetNode->random = copyRandomList(head->random);
			}
			return targetNode;
		}
		//139
		bool wordBreak_139(string s, vector<string>& wordDict) {
			return wordBreak_139_Extension(s, wordDict, 0);
		}
	private:
		bool wordBreak_139_Extension(string s, vector<string>& wordDict,int cur) {
			if (cur == s.size()) return true;
			for (string it : wordDict) {
				if (it == s.substr(cur, it.size())) {
					//当前可以使用
					cur = cur + it.size();
					bool result = wordBreak_139_Extension(s, wordDict, cur);
					if (result) {
						return true;
					}
					else {
						cur = cur - it.size();
					}
				}
			}
			return false;
		}

	public:
		//140
		vector<string> wordBreak_140(string s, vector<string>& wordDict) {
			vector<string> results;
			if (!s.empty()) {
				wordBreak_140_Extension(s, wordDict, "", 0, results);
			}
			return results;
		}
	private:
		void wordBreak_140_Extension(string s, vector<string>& wordDict, string curstr, int cur,vector<string>& results) {
			if (cur == s.size()) {
				results.push_back(curstr);
				return;
			}
			for (string it : wordDict) {
				if (it == s.substr(cur, it.size())) {
					//当前可以使用
					string targetStr = curstr + " " + it;
					if (curstr.empty()) {
						targetStr = it;
					}
					wordBreak_140_Extension(s, wordDict, targetStr, cur + it.size(), results);
				}
			}
		}

	public:
		//141
		bool hasCycle(ListNode* head) {
			ListNode* slow = head;
			ListNode* frist = head->next;
			if (frist == nullptr) return false;
			frist = frist->next;

			while (slow != nullptr && frist != nullptr) {
				if (slow == frist) {
					return true;
				}
				slow = slow->next;
				frist = frist->next;
				if (frist == nullptr) return false;
				frist = frist->next;
			}
			return false;
		}
		//142
		ListNode* detectCycle(ListNode* head) {


		}
		//143
		void reorderList(ListNode* head) {
			if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return;
			ListNode* one = head;
			ListNode* two = head->next;
			ListNode* pre = two;
			ListNode* three = head->next->next;
			ListNode* four = head->next->next->next;

			while (three != nullptr) {
				while (three != nullptr) {
					pre->next = four;
					three->next = two;
					one->next = three;
					two = three;
					three = four;
					if (four != nullptr) {
						four = four->next;
					}
					
				}
				one = one->next;
				two = one->next;
				pre = two;
				three = two->next;
				if (three != nullptr) {
					four = three->next;
				}
				
			}
		}
		//144
		vector<int> preorderTraversal(TreeNode* root) {
			vector<int> result;
			preorderTraversalExtension(root, result);
			return result;

		}
	private:
		void preorderTraversalExtension(TreeNode* root, vector<int>& result) {
			if (root == nullptr) {
				return;
			}
			result.push_back(root->val);
			if (root->left != nullptr) {
				preorderTraversalExtension(root->left, result);
			}
			if (root->right != nullptr) {
				preorderTraversalExtension(root->right, result);
			}
		}
	public:
		//145
		vector<int> postorderTraversal(TreeNode* root) {
			vector<int> result;
			postorderTraversalExtension(root, result);
			return result;
		}
	private:
		void postorderTraversalExtension(TreeNode* root, vector<int>& result) {
			if (root == nullptr) {
				return;
			}
			
			if (root->left != nullptr) {
				postorderTraversalExtension(root->left, result);
			}
			if (root->right != nullptr) {
				postorderTraversalExtension(root->right, result);
			}
			result.push_back(root->val);
		}
		//146

	public:
		//147
		ListNode* insertionSortList(ListNode* head) {
			if (head == nullptr || head->next == nullptr) return head;
			ListNode* sortBegin = head;
			ListNode* sortEndPre = head;
			ListNode* cur = head->next;

			while (cur != nullptr) {
				ListNode* tempNext = cur->next;
				ListNode* pre = nullptr;
				bool preToNext = true;
				while (sortBegin != cur) {
					if (sortBegin->val <= cur->val) {
						pre = sortBegin;
						sortBegin = sortBegin->next;
					}
					else {
						if (pre == nullptr) {
							sortEndPre->next = cur->next;
							cur->next = sortBegin;
							head = cur;
						}
						else {
							sortEndPre->next = cur->next;
							cur->next = pre->next;
							pre->next = cur;
						}
						preToNext = false;
						break;
					}
				}
				sortBegin = head;
				if (preToNext)sortEndPre = sortEndPre->next;
				cur = tempNext;
			}
			return head;
		}
		//148
		ListNode* sortList(ListNode* head) {

		}
		//149

		//150

		//151
		string reverseWords(string s) {
			int readIndex = 0;
			int writeIndex = 0;

			while (readIndex < s.length() && s[readIndex] == ' ') {
				readIndex++;
			}

			while (readIndex < s.length()) {
				swap(s[writeIndex], s[readIndex]);
				writeIndex++;
				readIndex++;
			}
			cout << writeIndex << endl;
			while (writeIndex < s.length()) {
				s[writeIndex] = ' ';
				writeIndex++;
			}

			int nullIndex = s.length() - 1;
			while (nullIndex >= 0) {
				if (s[nullIndex] == ' ') {
					s.pop_back();
					nullIndex--;
				}
				else {
					break;
				}
			}

			//反向
			int l = 0, r = s.length() - 1;

			while (l < r) {
				swap(s[l], s[r]);
				l++;
				r--;
			}

			cout << s << endl;

			int sl = 0;
			for (int i = 0;i < s.length();++i) {
				if (s[i] == ' ') {
					int sr = i - 1;
					while (sl < sr) {
						swap(s[sl], s[sr]);
						sl++;
						sr--;
					}
					sl = i + 1;
				}
				else if (i == s.length() - 1) {
					int sr = i;
					while (sl < sr) {
						swap(s[sl], s[sr]);
						sl++;
						sr--;
					}
					sl = i + 1;
				}

			}
			return s;
		}
		//152
		int maxProduct(vector<int>& nums) {
			int maxMul = nums[0];
			int cur = nums[0];

			for (int i = 1;i < nums.size();++i) {
				int temp = nums[i] * cur;
				if (cur == 0) {
					temp = nums[i];
				}
				maxMul = max(maxMul, temp);
				cur = temp;
			}
			return maxMul;
		}
		//153
		int findMin_153(vector<int>& nums) {
			if (nums.size() == 1)return nums[0];
			if (nums.size() == 2)return min(nums[0], nums[1]);
			if (nums[0] < nums[nums.size() - 1]) {
				return nums[0];
			}
			int l = 0, r = nums.size() - 1;
			while (l < r) {
				int mid = (l + r) / 2;

				if (nums[mid] > nums[r]) {
					l = mid + 1;
				}
				else {
					r = mid;
				}
			}
			return nums[l];
		}
		//154
		int findMin_154(vector<int>& nums) {
			if (nums.size() == 1)return nums[0];
			if (nums.size() == 2)return min(nums[0], nums[1]);
			if (nums[0] < nums[nums.size() - 1]) {
				return nums[0];
			}
			int l = 0, r = nums.size() - 1;
			while (l < r) {
				int mid = (l + r) / 2;

				if (nums[mid] > nums[r]) {
					l = mid + 1;
				}
				else if (nums[mid] < nums[r]) {
					r = mid;
				}
				else {
					r--;
				}
			}
			return nums[l];
		}
		//155

		//156

		//157

		//158

		//159

		//160
		ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
			if (headA == nullptr || headB == nullptr)return nullptr;
			ListNode* h1 = headA;
			ListNode* h2 = headB;
			while (h1 != nullptr && h2 != nullptr) {
				if (h1 == h2)
				{
					return h1;
				}
				else {
					h1 = h1->next;
					h2 = h2->next;
				}
			}
			if (h1 == nullptr) {
				h1 = headA;
				while (h2 != nullptr) {
					h1 = h1->next;
					h2 = h2->next;
					if (h1 == nullptr) {
						h1 = headA;
					}
				}
				return h2;
			}
			if (h2 == nullptr) {
				h2 = headB;
				while (h1 != nullptr) {
					h1 = h1->next;
					h2 = h2->next;
					if (h2 == nullptr) {
						h2 = headB;
					}
				}
				return h1;
			}
			return nullptr;
		}
		//161

		//162
		int findPeakElement(vector<int>& nums) {
			return findPeakElementExtension(nums, 0, nums.size() - 1);
		}
	private:
		int findPeakElementExtension(vector<int>& nums, int l, int r) {
			if (l == r) return l;
			int mid = (l + r) / 2;
			if (nums[mid] < nums[mid + 1]) {
				return findPeakElementExtension(nums, mid + 1, r);
			}
			else {
				return findPeakElementExtension(nums, l, mid);
			}
		}

		//163

	public:
		//164
		int maximumGap(vector<int>& nums) {
			if (nums.empty() || nums.size() == 1) return 0;
			bucketSort(nums.begin(), nums.end());
			int maxRange = nums[1] - nums[0];
			for (int i = 2;i < nums.size();++i) {
				maxRange = max(maxRange, nums[i] - nums[i - 1]);
			}
			return maxRange;
		}
		//165
		int compareVersion(string version1, string version2) {
			if (version1 == version2) return 0;
			int r1 = 0;
			int r2 = 0;
			
			while (r1 < version1.length() && r2 < version2.length()) {
				int v1 = 0;
				int v2 = 0;

				while (r1 < version1.length() && version1[r1] != '.') {
					v1 = v1 * 10 + (version1[r1] - '0');
					r1++;
				}
				while (r2 < version2.length() && version2[r2] != '.') {
					v2 = v2 * 10 + (version2[r2] - '0');
					r2++;
				}

				if (v1 < v2) return -1;
				else if (v1 > v2)return 1;
				else {
					r1++;
					r2++;
				}
			}

			while (r1 < version1.length()) {
				if (version1[r1] != '0' && version1[r1] != '.') {
					return 1;
				}
				r1++;
			}

			while (r2 < version2.length()) {
				if (version2[r2] != '0' && version2[r2] != '.') {
					return -1;
				}
				r2++;
			}

			return 0;
		}
		//166

		//167
		vector<int> twoSum(vector<int>& numbers, int target) {
			int l = 0, r = numbers.size() - 1;
			while (l < r) {
				int temp = numbers[l] + numbers[r];
				if (temp > target) {
					r--;
				}
				else if (temp < target) {
					l++;
				}
				else {
					return { l + 1,r + 1 };
				}

			}
			return{};
		}
		//168
		string convertToTitle(int columnNumber) {
			string result;
			while (columnNumber > 0) {
				columnNumber--;
				result = string(1, ('A' + columnNumber % 26)) + result;
				columnNumber = columnNumber / 26;
			}
			return result;

		}
		//169
		int majorityElement(vector<int>& nums) {
			stack<int> numStack;
			for (int it : nums) {
				if (numStack.empty()) {
					numStack.push(it);
				}
				else {
					if (numStack.top() != it) {
						numStack.pop();
						numStack.push(it);
					}
				}
			}
			return numStack.top();
		}
		//170

		//171

		//172

		//173

		//174

		//175

		//176

		//178

		//179
		string largestNumber(vector<int>& nums) {
			vector<string> strs;
			for (int it : nums) {
				strs.push_back(to_string(it));
			}
			quickSort(strs.begin(), strs.end(), [](string a, string b) {return a + b > b + a;});
			string result;
			for (string it : strs) {
				result += it;
			}
			return result;
		}
		//180
		
		//181

		//182

		//183

		//184

		//185

		//186

		//187
		vector<string> findRepeatedDnaSequences(string s) {
			unordered_map<string, int> sequenceMap;

			for (int i = 0;i < s.length() - 9;++i) {
				string seq = s.substr(i, 10);
				if (sequenceMap.count(seq)) {
					sequenceMap[seq]++;
				}
				else {
					sequenceMap[seq] = 1;
				}
			}
			vector<string> result;
			for (auto it = sequenceMap.begin();it != sequenceMap.end();++it) {
				if (it->second > 1) {
					result.push_back(it->first);
				}
			}
			return result;
		}
		//188
		
		//189
		void rotate(vector<int>& nums, int k) {
			int mod = k % nums.size();
			if (mod == 0) {
				return;
			}
			for (int i = 0;i < k;i++) {
				int temp = nums[nums.size() - 1];
				for (int j = nums.size() - 1;j > 0;j--) {
					nums[j] = nums[j - 1];
				}
				nums[0] = temp;
			}
		}
		//190
		int reverseBits(int n) {
			int result = 0;
			while (n > 0) {
				result = (n >> 1) | (result << 1);
				n = n >> 1;
			}
			return result;
		}
		//191
		int hammingWeight(int n) {
			int count = 0;
			while (n > 0) {
				n = n & (n - 1);
				count++;
			}
			return count;
		}
		//192
		
		//193

		//194

		//195

		//196

		//197

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
		//199
		vector<int> rightSideView(TreeNode* root) {
			if (root == nullptr) return {};
			stack<TreeNode*> nodeStack;
			nodeStack.push(root);
			vector<int> result;
			rightSideViewExtension(nodeStack, result);
			return result;
		}
	private:
		void rightSideViewExtension(stack<TreeNode*> nodeStack, vector<int>& result) {
			if (nodeStack.empty()) {
				return;
			}
			stack<TreeNode*> tempStack;
			result.push_back(nodeStack.top()->val);
			while (!nodeStack.empty()) {
				TreeNode* node = nodeStack.top();
				nodeStack.pop();
				if (node->left != nullptr) {
					tempStack.push(node->left);
				}
				if (node->right != nullptr) {
					tempStack.push(node->right);
				}
			}
			if (!tempStack.empty()) {
				rightSideViewExtension(tempStack, result);
			}
		}
		
		int numIslands(vector<vector<char>>& grid) {
			int count = 0;
			for (int i = 0;i < grid.size();++i) {
				for (int j = 0;j < grid[i].size();++j) {
					if (grid[i][j] == '1') {
						count++;
						numIslandsExtension(grid, i, j);
					}
				}
			}
			return count;
		}

		void numIslandsExtension(vector<vector<char>>& grid,int i,int j) {
			if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()) {
				if (grid[i][j] == '0') return;
				grid[i][j] = '0';
				numIslandsExtension(grid, i - 1, j - 1);
				numIslandsExtension(grid, i - 1, j);
				numIslandsExtension(grid, i - 1, j + 1);
				numIslandsExtension(grid, i, j - 1);
				numIslandsExtension(grid, i, j + 1);
				numIslandsExtension(grid, i + 1, j - 1);
				numIslandsExtension(grid, i + 1, j);
				numIslandsExtension(grid, i + 1, j + 1);
			}
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