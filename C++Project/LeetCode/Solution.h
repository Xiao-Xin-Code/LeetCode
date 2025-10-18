#pragma once

#include <vector>
#include <unordered_map>

#include "Extension.h"

using namespace std;

class Solution {

public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> maps;
		for (int i = 0;i < nums.size();i++) {
			int temp = target - nums[i];
			if (maps.count(temp)) {
				cout << maps[temp] << "," << i << endl;
				return { maps[temp],i };
			}
			maps[nums[i]] = i;
		}
		return {};
	}

public:
	ListNode* addTwoSum(ListNode* l1, ListNode* l2) {
		int carry = 0;

		ListNode* head = nullptr;
		ListNode* current = nullptr;

		while (l1 != nullptr && l2 != nullptr) {
			int value = l1->val + l2->val + carry;
			carry = value / 10;
			if (carry > 0) {
				value = value % 10;
			}
			l1 = l1->next;
			l2 = l2->next;

			if (head == nullptr) {
				head = new ListNode(value);
				current = head;
			}
			else {
				current->next = new ListNode(value);
				current = current->next;
			}
		}

		while (l1 != nullptr) {
			int value = l1->val + carry;
			carry = value / 10;
			if (carry > 0) {
				value = value % 10;
			}
			l1 = l1->next;

			if (head == nullptr) {
				head = new ListNode(value);
				current = head;
			}
			else {
				current->next = new ListNode(value);
				current = current->next;
			}
		}

		while (l2 != nullptr) {
			int value = l2->val + carry;
			carry = value / 10;
			if (carry > 0) {
				value = value % 10;
			}
			l2 = l2->next;

			if (head == nullptr) {
				head = new ListNode(value);
				current = head;
			}
			else {
				current->next = new ListNode(value);
				current = current->next;
			}
		}

		return head;
	}

public:
	int lengthOfLongestSubstring(string s) {
		int left = 0;
		int length = 0;
		unordered_map<char, int> charIndex;
		for (int right = 0;right < s.length();right++) {
			if (charIndex.count(s[right]) && charIndex[s[right]] >= left) {
				left = charIndex[s[right]] + 1;
			}
			charIndex[s[right]] = right;
			length = max(length, right - left + 1);
		}
		return length;
	}
};