#pragma once

struct ListNode {
	int val;
	ListNode* next;

	ListNode() : ListNode(0, nullptr) {}
	ListNode(int val) : ListNode(val, nullptr) {}
	ListNode(ListNode* next) : ListNode(0, next) {}
	ListNode(int val, ListNode* next) : val(val), next(next) {}
};