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

struct Node {
	int val;
	Node* left;
	Node* right;
	Node* next;
	
	Node() :Node(0, nullptr, nullptr, nullptr) {}
	Node(int val) : Node(val, nullptr, nullptr, nullptr) {}
	Node(Node* left, Node* right) : Node(0, left, right, nullptr) {}
	Node(int val, Node* left, Node* right, Node* next) :val(val), left(left), right(right), next(next) {}
};