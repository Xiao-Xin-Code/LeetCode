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

public:
	double finMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int length = static_cast<int>(nums1.size() + nums2.size());
		int target = length / 2;

		int curIndex;
		int n1Index;
		int n2Index;
		double prev;
		double cur;

		while (curIndex <= target) {
			prev = cur;
			if (n1Index < nums1.size() && n2Index < nums2.size()) {
				if (nums1[n1Index] <= nums2[n2Index]) {
					cur = nums1[n1Index];
					n1Index++;
				}
				else {
					cur = nums2[n2Index];
					n2Index++;
				}
			}
			else if (n1Index < nums1.size()) {
				cur = nums1[n1Index];
				n1Index++;
			}
			else if (n2Index < nums2.size()) {
				cur = nums2[n2Index];
				n2Index++;
			}
			curIndex++;
		}

		if (length % 2 == 0) {
			return (prev + cur) / 2;
		}
		else {
			return cur;
		}
	}

public:
	string longestPalindrome(string s) {
		int max_length = 0;
		int max_start = 0;

		for (int i = 0;i < s.length();i++) {
			int left = i;
			int right = i;
			while (left >= 0 && right < s.length() && s[left] == s[right]) {
				int tempLength = right - left + 1;
				if (max_length < tempLength) {
					max_length = tempLength;
					max_start = left;
				}
				left--;
				right++;
			}
			left = i;
			right = i + 1;
			while (left >= 0 && right < s.length() && s[left] == s[right]) {
				int tempLength = right - left + 1;
				if (max_length < tempLength) {
					max_length = tempLength;
					max_start = left;
				}
				left--;
				right++;
			}
		}

		return s.substr(max_start, max_length);
	}

public:
	string convert(string s, int numRows) {
		vector<string> strs = vector<string>(numRows);
		int curIndex = 0;
		int dir = 1;
		for (int i = 0;i < s.length();i++) {
			strs[curIndex] = strs[curIndex] + s[i];
			if (curIndex == numRows - 1) {
				dir = -1;
			}
			else if (curIndex == 0) {
				dir = 1;
			}
			curIndex = curIndex + dir;
		}

		string result;
		for (int i = 0;i < strs.size();i++) {
			result.append(strs[i]);
		}
		return result;
	}

public:
	int reverse(int x) {
		long long result = 0;
		while (x != 0) {
			int temp = x % 10;
			result = result * 10 + temp;
			x = x / 10;
		}

		if (result > INT_MAX) {
			return INT_MAX;
		}
		else if (result < INT_MIN) {
			return INT_MIN;
		}
		else {
			return result;
		}
	}

public:
	int myAtoi(string s) {
		bool isNeg = false;
		int cur = 0;
		for (int i = 0;i < s.length();i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				cur = cur * 10 + (s[i] - '0');
			}
			else {
				if (i == 0 && s[i] == '-') {
					isNeg = true;
				}
				else {
					break;
				}
			}
		}

		return isNeg ? -cur : cur;
	}

public:
	bool isPalindrome(int v) {
		if (v < 0)return false;
		if (v == 0)return true;

		int result = 0;
		while (v > result) {
			result = result * 10 + v % 10;
			if (result == v) {
				return true;
			}
			v = v / 10;
			if (result == v) {
				return true;
			}
		}
		return false;
	}

public:
	int maxLength(vector<int> nums) {

		int left = 0;
		int right = nums.size() - 1;
		int maxHigh = 0;

		while (left < right) {
			int count = right - left;
			int lHigh = nums[left];
			int rHigh = nums[right];
			
			if (lHigh < rHigh) {
				maxHigh = maxHigh < lHigh* count ? lHigh * count : maxHigh;
				left++;
			}
			else {
				maxHigh = maxHigh < rHigh * count ? rHigh * count : maxHigh;
				right--;
			}
		}


	}
};