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
		}
	}
};