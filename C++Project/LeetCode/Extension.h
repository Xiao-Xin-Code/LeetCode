#pragma once

struct ListNode {
	int val;
	ListNode* next;

	ListNode() : ListNode(0, nullptr) {}
	ListNode(int val) : ListNode(val, nullptr) {}
	ListNode(ListNode* next) : ListNode(0, next) {}
	ListNode(int val, ListNode* next) : val(val), next(next) {}
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() :TreeNode(0, nullptr, nullptr) {}
	TreeNode(int val) : TreeNode(val, nullptr, nullptr) {}
	TreeNode(TreeNode* left, TreeNode* right) : TreeNode(0, left, right) {}
	TreeNode(int val, TreeNode* left, TreeNode* right) :val(val), left(left), right(right) {}
};