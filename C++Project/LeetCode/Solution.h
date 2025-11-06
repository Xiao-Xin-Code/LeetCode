#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <set>



#include "Extension.h"

using namespace std;

class Solution {
//001
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
//002
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
//003
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
//004
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
//005
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
//006
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
//007
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
//008
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
//009
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
//010
public:
	bool isMatch(string s, string p) {
		int sIndex = 0;
		int pIndex = 0;

		/*if (pIndex + 1 < p.length()) {
			if (p[pIndex + 1] == '*') {
				if (s[sIndex - 1] == s[sIndex] && (s[sIndex] == p[pIndex] || p[pIndex] == '.')) {
					sIndex++;
				}
				else {
					pIndex++;
				}
			}
			else {
				if (s[sIndex] == p[pIndex] || p[pIndex] == '.') {
					sIndex++;
					pIndex++;
				}
				else {
					return false;
				}
			}
		}
		else {
			if (s[sIndex] == p[pIndex] || p[pIndex] == '.') {
				sIndex++;
				pIndex++;
			}
			else {
				return false;
			}
		}*/
		


		while (sIndex < s.length() && pIndex < p.length()) {
			if (p[pIndex] == '.') {
				sIndex++;
				pIndex++;
			}
			else if (p[pIndex] == '*') {
				if (sIndex - 1 >= 0) {
					if (s[sIndex - 1] == s[sIndex]) {
						sIndex++;
					}
					else {
						pIndex++;
					}
				}
				else {
					pIndex++;
				}
			}
			else if (p[pIndex] == s[sIndex]) {
				sIndex++;
				pIndex++;
			}
			else if (p[pIndex != s[sIndex]]) {
				if (p[pIndex + 1] == '*') {
					pIndex += 2;
				}
				else {
					return false;
				}
			}
		}

		if (sIndex < s.length()) {
			return false;
		}

		while (pIndex < p.length()) {
			if (p[pIndex] != '*') {
				if (pIndex + 1 < p.length()) {
					if (p[pIndex + 1] == '*') {
						pIndex += 2;
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
			}
			else {
				pIndex++;
			}
		}
		return true;
	}

private:
	void isMatchExtension(string s, string p, int sIndex, int pIndex) {



		

	}
//011
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
//012
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
//013
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
//014
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
//015
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
//016
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
//017
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
//018
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
//019
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
//020
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
//021
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
//022
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
//023
public:
	ListNode* mergeKLists(vector<ListNode*> listNode) {
		ListNode* head = nullptr;
		ListNode* cur = nullptr;

		while (!listNode.empty()) {
			if (head == nullptr) {
				mergeKListsExtension(listNode, 0, listNode[0], cur);
				//cout << "CUR" << (cur == nullptr) << endl;
				head = cur;
			}
			else {
				mergeKListsExtension(listNode, 0, listNode[0], cur);
			}


		}
		//cout << "数量" << listNode.size() << endl;
		return head;
	}

private:
	void mergeKListsExtension(vector<ListNode*>& lists, int curIndex, ListNode*& minNode, ListNode*& curNode) {
		//cout << lists.size() << endl;
		if (curIndex == lists.size()) {
			//cout << "返回数值"<< minNode->val << endl;
			if (minNode == nullptr) return;
			if (curNode == nullptr) {
				curNode = minNode;
			}
			else {
				curNode->next = minNode;
				curNode = curNode->next;
			}
			minNode = minNode->next;
			return;
		}
		else {
			if (lists[curIndex] == nullptr) {
				lists.erase(lists.begin() + curIndex);
				mergeKListsExtension(lists, curIndex, minNode, curNode);
			}
			else {
				if (lists[curIndex]->val < minNode->val) {
					mergeKListsExtension(lists, curIndex + 1, lists[curIndex], curNode);
				}
				else {
					mergeKListsExtension(lists, curIndex + 1, minNode, curNode);
				}
			}
		}
	}

//024
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
//025

	
//026
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
//027
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
//028
public:
	int strStr(string haystack, string needle) {
		for (int i = 0;i <= haystack.length() - needle.length();i++) {
			if (haystack[i] == needle[0]) {
				if (needle == haystack.substr(i, needle.length())) {
					return i;
				}
			}
		}
		return 0;
	}
//029
public:
	int divide(int dividend,int divisor) {
		int count = 0;
		while (dividend >= divisor) {
			int tempdivisor = divisor;
			int curMul = 1;
			while (dividend-tempdivisor > tempdivisor) {
				tempdivisor += tempdivisor;
				curMul += curMul;
			}
			dividend -= tempdivisor;
			count += curMul;
		}
		return count;
	}
//030
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		int index = 0;
		vector<int> result;
		set<int> hashset;

		while (index < s.length()) {
			for (int i = 0;i < words.size();i++) {
				if (hashset.count(i)) {
					continue;
				}
				else {
					if (s.substr(index, words[i].length()) == words[i]) {
						hashset.insert(i);
						result.push_back(i);
						index += static_cast<int>(words[i].length());
						break;
					}
				}
			}
		}
		return result;
	}
//031
public:
	void nextPermutation(vector<int>& nums) {
		int index = static_cast<int>(nums.size()) - 2;
		while (index >= 0 && nums[index] > nums[index + 1])index--;
		
		if (index >= 0) {
			int i = static_cast<int>(nums.size()) - 1;
			while (nums[i] <= nums[index])i--;
			swap(nums[index], nums[i]);
		}

		sort(nums.begin() + index + 1, nums.end());
	}
//032
public:
	int longestValidParenttheses(string s) {
		int maxLength = 0;
		for (int start = 0;start < s.length() - 1;start++) {
			int leftCount = 0;
			int curLength = 0;
			for (int cur = start;cur < s.length();cur++) {
				if (s[cur] == '(') {
					leftCount++;
					curLength++;
				}
				else {
					if (leftCount > 0) {
						leftCount--;
						curLength++;
					}
					else {
						break;
					}
				}
			}
			if (leftCount > 0) {
				continue;
			}
			else {
				maxLength = maxLength > curLength ? maxLength : curLength;
			}
		}
		return maxLength;

	}
//033
public:
	int search(vector<int>& nums, int target) {
		if (target<nums[0] && target>nums[nums.size()]) {
			return -1;
		}

		int l = 0, r = static_cast<int>(nums.size()) - 1;
		while (l < r) {

			int mid = (l + r) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			else if (nums[mid] > target) {
				if (nums[mid - 1] > nums[mid]) {
					return -1;
				}
				r = mid - 1;
			}
			else {
				if (nums[mid + 1] < nums[mid]) {
					return -1;
				}
				l = mid + 1;
			}
		}
		return l;
	}
//034
public:
	int searchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		int index = -1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] == target) {
				left = mid;
				right = right;
				break;
			}
			else if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		while (left > 0) {
			if (nums[left -1] != target) {
				break;
			}
			left--;
		}
		while (right < nums.size() - 1) {
			if (nums[right + 1] != target) {
				break;
			}
			right++;
		}

	}
//035
public:
	int searchInsert(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l < r) {

			int mid = (l + r) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			else if (nums[mid] > target) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		return l;
	}
//036
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool rows[9][9] = { false };
		bool cols[9][9] = { false };
		bool boxes[9][9] = { false };
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				int v = board[i][j] - '1';
				if (rows[i][v]) {
					return false;
				}
				if (cols[j][v]) {
					return false;
				}
				int boxindex = (i / 3) * 3 + j / 3;
				if (boxes[boxindex][v]) {
					return false;
				}

				rows[i][v] = true;
				cols[j][v] = true;
				boxes[boxindex][v] = true;
			}
		}
		return true;
	}
//037
public:
	void solveSudoku(vector<vector<char>>& board) {
		solveSudokuExtension(board);
	}

private:
	bool solveSudokuExtension(vector<vector<char>>& board) {
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				if (board[i][j] == '.') {
					for (char c = '1';c <= '9';c++) {
						bool isvalid = true;
						for (int n = 0;n < 9;n++) {
							if (board[i][n] == c) {
								isvalid = false;
							}
							if (board[n][j] == c) {
								isvalid = false;
							}
							if (board[3 * (i / 3) + n / 3][3 * (j / 3) + n % 3] == c) {
								isvalid = false;
							}
						}
						if (isvalid) {
							board[i][j] = c;
							if (solveSudokuExtension(board)) {
								return true;
							}
							board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}
//038
public:
	string countAndSay(int n) {
		string temp = "1";
		int i = 2;
		while (i <= n) {
			string result = "";
			int count = 1;
			for (int x = 1;x < temp.length();x++) {
				if (temp[x - 1] == temp[x]) {
					count++;
				}
				else {
					result = result + (char)(count + '0') + temp[x - 1];
					count = 1;
				}
			}
			if (count > 0) {
				result = result + (char)(count + '0') + temp[temp.length() - 1];
			}
			temp = result;
			i++;
		}
		return temp;
	}
//039
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> results;
		commbinationSumExtension(candidates, target, 0, results, {}, 0);
		cout << results.size() << endl;
		return results;
	}

private:
	void commbinationSumExtension(vector<int>& candidates, int target, int start,  vector<vector<int>>& results, vector<int> result, int cur) {
		for (int i = start;i < candidates.size();i++) {
			if (cur + candidates[i] == target) {
				result.push_back(candidates[i]);

				for (int j = 0;j < result.size();j++) {
					cout << result[j];
				}
				cout<<endl;
				results.push_back(result);
				return;
			}
			else if (cur + candidates[i] < target) {
				result.push_back(candidates[i]);
				commbinationSumExtension(candidates, target, i, results, result, cur + candidates[i]);
				result.pop_back();
			}
			else {
				return;
			}
		}
	}
//040
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> results;
		sort(candidates.begin(), candidates.end());
		combinationSum2Extension(candidates, target, 0, results, {}, 0);
		cout << results.size() << endl;
		return results;
	}

private:
	void combinationSum2Extension(vector<int>& candidates, int target, int start, vector<vector<int>>& results, vector<int> result, int cur) {
		for (int i = start;i < candidates.size();i++) {
			if (i > start && candidates[i] == candidates[i - 1]) continue;
			if (cur + candidates[i] == target) {
				result.push_back(candidates[i]);

				for (int j = 0;j < result.size();j++) {
					cout << result[j];
				}
				cout << endl;
				results.push_back(result);
				return;
			}
			else if (cur + candidates[i] < target) {
				result.push_back(candidates[i]);
				combinationSum2Extension(candidates, target, i + 1, results, result, cur + candidates[i]);
				result.pop_back();
			}
			else {
				return;
			}
		}
	}
//041
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0;i < nums.size();i++) {
			if (nums[i] < 0) {
				nums[i] = 0;
			}
		}
		for (int i = 0;i < nums.size();i++) {
			if (nums[i] != 0 && abs(nums[i]) <= nums.size()) {
				nums[abs(nums[i])-1] = -abs(nums[abs(nums[i]) - 1]);
			}
		}
		for (int i = 0;i < nums.size();i++) {
			if (nums[i] > 0) {
				return i + 1;
			}
		}
		return nums.size() + 1;
	}
//042
public:
	int trap(vector<int>& nums) {
		int l = 0;
		int all = 0;
		while (l < nums.size() - 2) {
			if (nums[l] == 0) {
				l++;
			}
			else {
				int r = l + 1;
				int cur = 0;
				bool farg = false;
				for (int i = r;i < nums.size();i++) {
					if (nums[i] >= nums[l]) {
						all += cur;
						l = i;
						farg = true;
						break;
					}
					else {
						cur = cur + nums[l] - nums[i];
					}
				}
				if (farg) {
					continue;
				}
				l++;
			}
		}
		return all;
	}
//043
public:
	string multiply(string num1,string num2) {
		if (num1 == "0" || num2 == "0")return "0";
		if (num1 == "1") return num2;
		if (num2 == "1") return num1;

		vector<int> nums(num1.size() + num2.size());
		for (int i = num2.size() - 1;i >= 0;i--) {

			for (int j = num1.size() - 1;j >= 0;j--) {
				int temp = (num2[i] - '0') * (num1[j] - '0');
				int sum = temp + nums[i + j + 1];
				
				nums[i+j+1] = sum % 10;
				nums[i+j] += sum / 10;
			}
		}

		string result = "";
		for (int i = 0;i < nums.size();i++) {
			result = result + (char)(nums[i] + '0');
			cout<<nums[i] <<endl;
		}
		return result;
	}
//044


	
//045
public:
	int jump(vector<int>& nums) {
		int count = 0;int currentEnd = 0; int farthest = 0;
		for (int i = 0;i < nums.size() - 1;i++) {
		    farthest = max(farthest, i + nums[i]);
			if (i == currentEnd) {
				count++;
				currentEnd = farthest;
			}
		}
		return count;
	}
//046
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> results;
		vector<bool> frags(nums.size(),false);
		permuteExtension(nums, frags, {}, results);
		return results;
	}

private:
	void permuteExtension(vector<int>& nums,vector<bool>& frags,vector<int> result,vector<vector<int>>& results) {
		if (result.size() == nums.size()) {
			results.push_back(result);
			return;
		}
		for (int i = 0;i < nums.size();i++) {
			if (!frags[i]) {
				result.push_back(nums[i]);
				frags[i] = true;
				permuteExtension(nums, frags, result, results);
				result.pop_back();
				frags[i] = false;
			}
			else {
				continue;
			}
		}
	}
//047
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> results;
		vector<bool> frags(nums.size(), false);
		permuteUniqueExtension(nums, frags, {}, results);
		return results;
	}

private:
	void permuteUniqueExtension(vector<int>& nums, vector<bool>& frags, vector<int> result, vector<vector<int>>& results) {
		if (result.size() == nums.size()) {
			results.push_back(result);
			return;
		}
		for (int i = 0;i < nums.size();i++) {
			if (frags[i] || (i > 0 && nums[i - 1] == nums[i] && !frags[i - 1])) {
				continue;
			}
			else {
				result.push_back(nums[i]);
				frags[i] = true;
				permuteUniqueExtension(nums, frags, result, results);
				result.pop_back();
				frags[i] = false;
			}
		}
	}
//048
public:
	void rotate(vector<vector<int>>& nums) {
		size_t t = nums.size() - 1;
		int left = 0;int right = nums.size() - 1;
		while (left < right) {

			for (int i = 0;i <= right - left;i++) {
				int temp = nums[left][left + i];
				nums[left][left + i] = nums[right - i][left];
				nums[right - i][left] = nums[right][right - i];
				nums[right][right - i] = nums[left + i][right];
				nums[left + i][right] = temp;
			}
			left++;
			right--;
		}
	}


public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> results;
		vector<bool> useds(strs.size(), false);

		for (int i = 0;i < strs.size();i++) {
			if (!useds[i]) {
				groupAnagramsExtension(strs, useds, results, { strs[i] }, i);
				useds[i] = true;
			}
		}
		return results;
	}

private:
	void groupAnagramsExtension(vector<string>& strs, vector<bool>& useds,vector<vector<string>> results,vector<string> result,int cur) {
		unordered_map<char, int> charCountMap;
		for (int i = 0;i < strs[cur].length();i++) {
			charCountMap[strs[cur][i]]++;
		}

		for (int i = 0;i < strs.size();i++) {
			if (useds[i]||strs[cur].size()!=strs[i].size()) {
				continue;
			}

			unordered_map<char, int> tempMap = charCountMap;
			for (int j = 0;j < strs[i].length();j++) {
				if (tempMap.count(strs[i][j])) {
					tempMap[strs[i][j]]--;
				}
				else {
					break;
				}
			}
			if (tempMap.empty()) {
				//添加
				result.push_back(strs[i]);
				useds[i] = true;
			}
		}
		results.push_back(result);
	}

public:
	double myPow(double x, int n) {
		bool iseven = n % 2 == 0;
		bool isnegative = n < 0;
		int result = 1;
		int absN = abs(n);
		while (absN > 0) {
			if (absN % 2 == 1) {
				result *= x;
			}
			absN = absN / 2;
			x = x * x;
		}
		if (isnegative) return 1 / result;
		return result;
	}

public:
	vector<int> maxSubArray(vector<int>& nums) {
		int currentSum = nums[0];
		int maxSum = nums[0];
		int start = 0, end = 0;
		int tempstart = 0;

		for (int i = i;i < nums.size();i++) {
			if (currentSum < 0) {
				currentSum = nums[i];
				tempstart = i;
			}
			else {
				currentSum += nums[i];
			}

			if (currentSum > maxSum) {
				start = tempstart;
				end = i;
				maxSum = currentSum;
			}
		}
		return vector<int>(nums.begin() + start, nums.begin() + end + 1);
	}

public:
	vector<int> loopArray(vector<vector<int>>& nums) {
		int rowleft = 0, rowright = nums.size() - 1;
		int colleft = 0, colright = nums[0].size() - 1;
		vector<int> result;
		while (rowleft <= rowright && colleft <= colright) {
			for (int i = colleft;i <= colright;i++) {
				result.push_back(nums[rowleft][i]);
			}

			for (int i = rowleft + 1;i <= rowright;i++) {
				result.push_back(nums[i][colright]);
			}

			for (int i = colright - 1;i >= colleft;i--) {
				result.push_back(nums[rowright][i]);
			}

			for (int i = rowright - 1;i >= rowleft + 1;i--) {
				result.push_back(nums[i][colleft]);
			}

			rowleft++;
			rowright--;
			colleft++;
			colright--;
		}
		return result;
	}

public:
	bool isPath(vector<int>& nums) {
		int farthest = 0;
		for (int i = 0;i < nums.size();i++) {
			if (i > farthest) {
				return false;
			}
			farthest = max(farthest, nums[i] + i);
			if (farthest >= nums.size() - 1) {
				return true;
			}
		}
		return false;
	}

};