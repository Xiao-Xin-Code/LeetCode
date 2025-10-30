#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>



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
			return static_cast<int>(result);
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
		int right = static_cast<int>(height.size()) - 1;
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
			int r = static_cast<int>(nums.size()) - 1;

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
			int r = static_cast<int>(nums.size()) - 1;

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
				int r = static_cast<int>(nums.size()) - 1;

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

		for (int i = 0;i < n;i++) {
			if (fast == nullptr) return head->next;
			else fast = fast->next;
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

public:
	bool isValid(string s) {
		stack<char> stackL;
		for (int i = 0;i < s.length();i++) {
			if (s[i] == '[' || s[i] == '(') {
				stackL.push(s[i]);
			}
			else {
				if (stackL.empty()) return false;
				if (s[i] == ']' && stackL.top() != '[') {
					return false;
				}
				if (s[i] == ')' && stackL.top() != '(') {
					return false;
				}
				stackL.pop();
			}
		}
		return stackL.empty();
	}

public: 
	ListNode* mergeTwoLists(ListNode* list1,ListNode* list2) {
		ListNode* head = nullptr;
		ListNode* cur = head;
		while (list1 != nullptr && list2 != nullptr) {
			if (list1->val < list2->val) {
				if (head == nullptr) {
					head = list1;
					cur = head;
				}
				else {
					cur->next = list1;
					cur = cur->next;
				}
				list1 = list1->next;
			}
			else {
				if (head == nullptr) {
					head = list2;
					cur = head;
				}
				else {
					cur->next = list2;
					cur = cur->next;
				}
				list2 = list2->next;
			}
		}
		
		if (list1 != nullptr) {
			cur->next = list1;
		}
		if (list2 != nullptr) {
			cur->next = list2;
		}

		return head;
	}

public:
	vector<string> generateParenthesis(int n) {
		vector<string> results;
		generateParenthesisExtension(results, "", n, 0, 0, 0);
		return results;
	}

private:
	void generateParenthesisExtension(vector<string> results, string result,int n, int curCount,int leftCount,int rightCount) {
		
		if (curCount == 2 * n) {
			cout << result << endl;
			results.push_back(result);
			return;
		}
		else {
			if (leftCount < n) {
				generateParenthesisExtension(results, result + '(', n, curCount + 1, leftCount + 1, rightCount);
			}

			if (rightCount < n && leftCount > rightCount) {
				generateParenthesisExtension(results, result + ')', n, curCount + 1, leftCount, rightCount + 1);
			}
			
		}
	}

public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}

		ListNode* l1 = head;
		ListNode* l2 = head->next;

		l1->next = swapPairs(l2->next);
		l2->next = l1;

		return l2;
	}

public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return 1;

		int count = 1;
		for (int i = 1;i < nums.size();i++) {
			if (nums[i] != nums[i - 1]) {
				nums[count] = nums[i];
				count++;
			}
		}
		return count;
	}

public:
	int remove(vector<int>& nums,int target) {
		int count = 0;
		for (int i = 0;i < nums.size();i++) {

			if (nums[i] != target) {
				nums[count] = nums[i];
				count++;
			}
		}
		return count;
	}

public:
	ListNode* mergeKLists(vector<ListNode*> listNode) {
		ListNode* head = nullptr;
		ListNode* cur = nullptr;

		mergeKListsExtension(listNode, 0, listNode[0]);
		cout << (listNode[1] == nullptr) << endl;
		return nullptr;
	}

private:
	void mergeKListsExtension(vector<ListNode*> lists,int curIndex,ListNode* minNode) {
		cout << lists.size() << endl;
		if (curIndex == lists.size()) {
			cout << minNode->val << endl;
			minNode = minNode->next;
			return;
		}
		else {
			if (lists[curIndex] == nullptr) {
				cout << "nullptr" << endl;
				mergeKListsExtension(lists, curIndex + 1, minNode);
			}
			else {
				cout << "has" << endl;
				if (lists[curIndex]->val < minNode->val) {
					cout << "<" << endl;
					mergeKListsExtension(lists, curIndex + 1, lists[curIndex]);
				}
				else {
					cout << ">" << endl;
					mergeKListsExtension(lists, curIndex + 1, minNode);
				}
			}
		}
	}


};