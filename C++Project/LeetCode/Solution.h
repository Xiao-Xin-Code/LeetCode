#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>



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
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int maxHeight = 0;

		while (left < right) {
			int count = right - left;
			int lHeight = height[left];
			int rHeight = height[right];
			
			if (lHeight < rHeight) {
				maxHeight = maxHeight < lHeight* count ? lHeight * count : maxHeight;
				left++;
			}
			else {
				maxHeight = maxHeight < rHeight * count ? rHeight * count : maxHeight;
				right--;
			}
		}

		return maxHeight;
	}

public:
	string intToRoman(int num) {
		vector<pair< int, string>> maps = { {1000, "M"}, {900,"CM"}, {500,"D"}, {400,"CD"}, {100,"C"}, {90,"XC"}, {50,"L"}, {40,"XL"}, {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1,"I"} };
		string result;
		
		for (int i = 0;i < maps.size();i++) {
			int count = num / maps[i].first;
			for (int c = 0;c < count;c++) {
				result.append(maps[i].second);
			}
			num = num - count * maps[i].first;
		}
		return result;
	}

public:
	int romanToInt(string s) {
		unordered_map<string, int> maps = { {"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},{"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1} };
		int result = 0;
		for (int i = 0;i < s.length();) {
			if (maps.count(s.substr(i, 2))) {
				result += maps[s.substr(i, 2)];
				i += 2;
			}
			else if (maps.count(s.substr(i, 1))) {
				result += maps[s.substr(i, 1)];
				i++;
			}
			else {
				throw invalid_argument(s.substr(i, 1));
			}
		}
		
		return result;
	}

public:
	string longestCommonPrefix(vector<string>& strs) {
		string result;
		for (int i = 0;i < strs[0].length();i++) {


			for (int j = 1;j < strs.size();j++) {
				if (strs[j][i] != strs[0][i]) {
					return result;
				}
			}
			result += strs[0][i];
		}
		return result;

	}

public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int i = 0;i < nums.size() - 2;i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int target = -nums[i];
			int l = i + 1;
			int r = nums.size() - 1;

			while (l < r) {
				int cur = nums[l] + nums[r];

				if (target == cur) {
					vector<int> temp = { nums[i],nums[l],nums[r] };
					result.push_back(temp);

					while (l < r && nums[l + 1] == nums[l]) l++;
					while (l < r && nums[r - 1] == nums[r]) r--;
					l++;
					r--;
				}
				else if (cur < target) {
					l++;
				}
				else
				{
					r--;
				}
			}
		}
		return result;
	}

public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int result = nums[0] + nums[1] + nums[2];
		for (int i = 0;i < nums.size() - 2;i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;

			int l = i + 1;
			int r = nums.size() - 1;

			while (l < r) {
				int cur = nums[i] + nums[l] + nums[r];

				if (abs(target - cur) < abs(target - result)) {
					result = cur;
				}
				else if (cur == target) {
					return cur;
				}
				else if (cur < target) {
					l++;
				}
				else {
					r--;
				}	
			}
		}
		return result;
	}

public:
	vector<string> letterCombinations(string digits) {
		unordered_map<char, string> maps = { {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
		vector<string> results;

		letterCombinationsExtension(maps, results, digits, "", 0);

		return results;
	}

private:
	void letterCombinationsExtension(unordered_map<char,string>& maps, vector<string>& results, string digits, string result, int curIndex) {
		if (curIndex == digits.length()) {
			results.push_back(result);
		}
		else {
			for (int i = 0;i < maps[digits[curIndex]].length();i++) {
				letterCombinationsExtension(maps, results, digits, result + maps[digits[curIndex]][i], curIndex + 1);
			}
		}
	}

public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		for (int i = 0;i < nums.size() - 3;i++) {
			if (i > 0 && nums[i] == nums[i - 1])continue;
			int cur = target - nums[i];
			for (int j = i + 1;j < nums.size() - 2;j++) {
				if (j > i + 1 && nums[j] == nums[j - 1])continue;
				int curTarget = cur;
				int l = j + 1;
				int r = nums.size() - 1;

				while (l < r) {
					int sum = nums[l] + nums[r];
					if (sum == curTarget) {
						vector<int> temp = { nums[i],nums[j],nums[l],nums[r] };
						result.push_back(temp);

						l++;
						r--;

						while (l < r && nums[l + 1] == nums[l]) l++;
						while (l < r && nums[r - 1] == nums[r])r--;
					}
					else if (sum < curTarget) {
						l++;
					}
					else {
						r--;
					}
				}
			}
		}
		return result;
	}

public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr) return nullptr;
		ListNode* fast = head;
		ListNode* slow = head;

		while (n > 0) {
			if (fast == nullptr) {
				fast = head;
			}
			else {
				fast = fast->next;
			}
			n--;
		}

		while (n > 0) {
			fast = fast->next;
			n--;
		}

		while (fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next;
		}

		if (slow->next != nullptr) {
			slow->next = slow->next->next;
		}
		return head;
	}
};