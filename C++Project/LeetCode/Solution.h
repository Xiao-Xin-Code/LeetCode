#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>



#include "Extension.h"
#include "Sort.h"

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

		int curIndex{};
		int n1Index{};
		int n2Index{};
		double prev{};
		double cur{};

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

		while (sIndex < s.length() && pIndex < p.length()) {
			if (p[pIndex] == '.') {
				sIndex++;
				pIndex++;
			}
			else if (p[pIndex] == '*') {
				if (sIndex >= 1) {
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
		int left = 0, right = static_cast<int>(nums.size()) - 1;
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
		int l = 0, r = static_cast<int>(nums.size()) - 1;
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
		return static_cast<int>(nums.size()) + 1;
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
		for (int i = static_cast<int>(num2.size()) - 1;i >= 0;i--) {

			for (int j = static_cast<int>(num1.size()) - 1;j >= 0;j--) {
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
		int left = 0;int right = static_cast<int>(nums.size()) - 1;
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
		bool isnegative = n < 0;
		double result = 1.0;
		int absN = abs(n);
		while (absN > 0) {
			if (absN % 2) {
				result = result * x;
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
		int rowleft = 0, rowright = static_cast<int>(nums.size()) - 1;
		int colleft = 0, colright = static_cast<int>(nums[0].size()) - 1;
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
//056
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int>b) {
			return a[0] < b[0];
		});
		int operateIndex = 0;
		for (int i = 1;i < intervals.size();i++) {
			if (intervals[i][0] <= intervals[operateIndex][1]) {
				intervals[operateIndex][1] = max(intervals[i][1], intervals[operateIndex][1]);
			}
			else {
				operateIndex++;
				intervals[operateIndex] = intervals[i];
			}
		}
		return vector<vector<int>>(intervals.begin(), intervals.begin() + operateIndex + 1);
	}
//057
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> result;
		int i = 0, n = static_cast<int>(intervals.size());
		while (i < n && intervals[i][1] < newInterval[0]) {
			result.push_back(intervals[i]);
			i++;
		}
		while (i < n && intervals[i][0] <= newInterval[1]) {
			newInterval[0] = min(newInterval[0], intervals[i][0]);
			newInterval[1] = max(newInterval[1], intervals[i][1]);
			i++;
		}
		result.push_back(newInterval);
		while (i < n) {
			result.push_back(intervals[i]);
			i++;
		}
		return result;
	}
//058
public:
	int lengthOfLastWord(string s) {
		int count = 0;
		for (int i = static_cast<int>(s.length()) - 1;i >= 0;i--) {
			if (s[i] == ' ') {
				return count;
			}
			else {
				count++;
			}
		}
		return count;
	}
//059
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n));
		int l = 0, r = n - 1;
		int index = 1;
		while (l <= r) {
			for (int i = l;i <= r;i++) {
				result[l][i] = index;
				index++;
			}
			for (int i = l + 1;i <= r;i++) {
				result[i][r] = index;
				index++;
			}
			for (int i = r - 1;i >= l;i--) {
				result[r][i] = index;
				index++;
			}
			for (int i = r - 1;i >= l + 1;i--) {
				result[i][l] = index;
				index++;
			}
			l++;
			r--;
		}
		return result;
	}
//061
public:
	ListNode* rotateRight(ListNode* head,int k) {
		ListNode* slow = head;
		ListNode* first = head;
		
		while (k > 0) {
			if (first->next == nullptr) {
				first = head;
			}
			else {
				first = first->next;
			}
			k--;
		}
		if (slow == first) {
			return head;
		}
		while (first->next != nullptr) {
			first = first->next;
			slow = slow->next;
		}
		first->next = head;
		head = slow->next;
		slow->next = nullptr;
		return head;
	}
//062
public:
	int uniquePaths(int m, int n) {
		vector<int> dp(n, 1);
		for (int i = 1;i < m;i++) {
			for (int j = 0;j < n;j++) {
				if (j == 0) {
					dp[j] = 1;
				}
				else {
					dp[j] = dp[j - 1] + dp[j];
				}
			}
		}
		return dp[n];
	}
//063
public:
	int uniquePathWithObjstacles(vector<vector<int>>& obstacleGrid) {
		vector<int> dp(obstacleGrid[0].size());
		for (int i = 0;i < obstacleGrid[0].size();i++) {
			if (obstacleGrid[0][i] == 1) {
				dp[i] = 0;
			}
			else {
				dp[i] = 1;
			}
		}

		for (int i = 1;i < obstacleGrid.size();i++) {
			for (int j = 0;j < obstacleGrid[0].size();j++) {
				if (obstacleGrid[i][j] == 1) {
					dp[j] = 0;
				}
				else {
					if (j == 0) {
						dp[j] = 1;
					}
					else {
						dp[j] = dp[j - 1] + dp[j];
					}
				}
			}
		}
		return dp[obstacleGrid[0].size()];
	}
//064
public:
	int minPathSum(vector<vector<int>>& grid) {
		for (int i = 1;i < grid.size();i++) {
			for (int j = 0;j < grid[i].size();j++) {
				if (j == 0) {
					grid[i][j] = grid[i - 1][j] + grid[i][j];
				}
				else {
					grid[i][j] = min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
				}
			}
		}
		return grid[grid.size() - 1][grid[grid.size() - 1].size()];
	}

//066
public:
	vector<int> plusOne(vector<int>& digits) {
		int carry = 0;
		int cur = static_cast<int>(digits.size()) - 1;
		while (cur >= 0) {
			int sum = digits[cur] + carry;
			digits[cur] = sum % 10;
			carry = sum / 10;;
			if (carry == 0) {
				return digits;
			}
			else {
				if (cur == 0) {
					digits.insert(digits.begin(), carry);
				}
			}
			cur--;
		}
		return digits;
	}
//067
public:
	string addBinary(string a, string b) {
		int ar = static_cast<int>(a.size()) - 1;
		int br = static_cast<int>(a.size()) - 1;
		string result;
		bool carry = false;
		while (ar >= 0 && br >= 0) {
			if (carry) {
				if (a[ar] == '1'&& b[br] == '1') {
					carry = true;
					result = '1' + result;
				}
				else if (a[ar] == '1' || b[br] == '1') {
					carry = true;
					result = '0' + result;
				}
				else {
					carry = false;
					result = '1' + result;
				}
			}
			else {
				if (a[ar] == '1' && b[br] == '1') {
					carry = true;
					result = '0' + result;
				}
				else if (a[ar] == '1' || b[br] == '1') {
					carry = false;
					result = '1' + result;
				}
				else {
					carry = false;
					result = '0' + result;
				}
			}
			ar--;
			br--;
		}
		while (ar >= 0) {
			if (carry) {
				if (a[ar] == '1') {
					result = "0" + result;
				}
				else {
					result = a[ar] + result;
				}
			}
			else {
				result = a[ar] + result;
			}
			ar--;
		}
		while (br >= 0) {
			if (carry) {
				if (b[br] == '1') {
					result = "0" + result;
				}
				else {
					result = b[br] + result;
				}
			}
			else {
				result = b[br] + result;
			}
			br--;
		}
		if (carry)result = '1' + result;
		return result;
	}

//070
public:
	int climbStairs(int n) {
		vector<int> dp = { 1, 1, 2 };
		dp.resize(n + 1);

		for (int i = 3;i < n;i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}

public:
	string path(string path) {
		string result;
		vector<string> results;
		string cur = "/";

		for (int i = 0;i < path.length();i++) {
			if (path[i] == '/' && cur == "/") {
				continue;
			}

			if (path[i] == '/') {
				if (cur == "/") {
					continue;
				}
				else {
					results.push_back(cur);
					cur = "/";
				}
			}
			else {
				if (cur == "/") {
					results.push_back(cur);
					cur = path[i];
				}
				else {
					cur = cur + path[i];
				}

			}
		}
		if (cur != "/") {
			results.push_back(cur);
		}

		vector<int> removeIndexs;
		for (int i = 0;i < results.size();i++) {
			if (results[i] == "..") {
				removeIndexs.push_back(i - 2);
				removeIndexs.push_back(i - 1);
				removeIndexs.push_back(i);
			}
		}

		for (int i = 0;i < removeIndexs.size();i++) {
			if (i >= 0) {
				results.erase(results.begin() + removeIndexs[i]);
			}
		}

		
		return result;
	}

public:
	void resetZero(vector<vector<int>>& matrix) {
		bool colHasZero, rowHasZero;
		for (int i = 0;i < matrix[0].size();i++) {
			if (matrix[0][i] == 0) colHasZero = true;
		}
		for (int i = 0;i < matrix.size();i++) {
			if (matrix[i][0] == 0) rowHasZero = true;
		}

		for (int i = 1;i < matrix.size();i++) {
			for (int j = 1;j < matrix[i].size();j++) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		for (int i = 1;i < matrix.size();i++) {
			for (int j = 1;j < matrix[i].size();j++) {
				if (matrix[0][j] == 0 || matrix[i][0] == 0) {
					matrix[i][j] = 0;
				}
			}
		}

		if (colHasZero) {
			for (int i = 0;i < matrix[0].size();i++) {
				matrix[0][i] = 0;
			}
		}
		if (rowHasZero) {
			for (int i = 0;i < matrix.size();i++) {
				matrix[i][0] = 0;
			}
		}
	}


//074
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		for (int i = 0;i < matrix.size();i++) {
			if (matrix[i][0] > target) {
				return false;
			}
			else if (matrix[i][matrix[i].size() - 1] < target) {
				continue;
			}
			else {
				for (int j = 0;j < matrix[i].size();j++) {
					if (matrix[i][j] == target) {
						return true;
					}
				}
				return false;
			}
		}
		return false;
	}

public:
	void color(vector<int>& nums) {
		int l = 0, r = static_cast<int>(nums.size()) - 1;
		int i = 0;

		if (nums[i] == 0) {
			swap(nums[i], nums[l]);
			l++;
			i++;
		}
		else if (nums[i] == 2) {
			swap(nums[i], nums[r]);
			r++;
		}
		else {
			i++;
		}
	}
//077
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> results;
		for (int i = 0;i < n;i++) {
			combineExtension(results, {}, n, k, i);
		}
		return results;
	}

private:
	void combineExtension(vector<vector<int>>& results, vector<int> result, int n, int k,int cur) {
		result.push_back(cur);
		if (result.size() == k) {
			results.push_back(result);
		}
		else {
			for (int i = cur + 1;i < n;i++) {
				combineExtension(results, result, n, k, i);
			}
		}
		result.pop_back();
	}

public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> results;
		results.push_back({});
		subsetsExtension(nums, results, {}, 0);
		return results;
	}

public:
	void subsetsExtension(vector<int>& nums, vector<vector<int>>& results, vector<int> result,int start) {
		for (int i = start;i < nums.size();i++) {
			result.push_back(nums[i]);
			results.push_back(result);
			subsetsExtension(nums, results, result, start + 1);
			result.pop_back();
		}
	}

public:
	bool searchWord(vector<vector<char>>& nums,string word) {
		for (int i = 0;i < nums.size();i++) {

			for (int j = 0;j < nums[i].size();j++) {
				if (searchWordExtension(nums, word, 0, i, j)) {
					return true;
				}
			}
		}
		return false;
	}

private:
	bool searchWordExtension(vector<vector<char>>& nums, string word, int curIndex, int i, int j) {
		if (nums[i][j] == word[curIndex]) {
			char temp = nums[i][j];
			nums[i][j] = '\0';

			if (i >= 1) {
				if (searchWordExtension(nums, word, curIndex + 1, i - 1, j)) {
					return true;
				}
			}
			if (j >= 1) {
				if (searchWordExtension(nums, word, curIndex + 1, i, j - 1)) {
					return true;
				}
			}
			if (i + 1 < nums.size()) {
				if (searchWordExtension(nums, word, curIndex + 1, i + 1, j)) {
					return true;
				}
			}
			if (j + 1 < nums[i].size()) {
				if (searchWordExtension(nums, word, curIndex + 1, i, j + 1)) {
					return true;
				}
			}

			nums[i][j] = temp;
			return false;
		}
		else {
			return false;
		}
	}

public:
	int removeSame(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1 || nums.size() == 2) return static_cast<int>(nums.size());

		//quickSort(nums.begin(), nums.end());
		int index = 1;
		int curIndex = 1;
		while (index + 1 < nums.size()) {
			if (nums[index] == nums[index - 1]) {
				if (nums[index] != nums[index + 1]) {
					nums[curIndex] = nums[index];
					curIndex++;
				}
			}
			else {
				nums[curIndex] = nums[index];
				curIndex++;
			}
			index++;
		}
		nums[curIndex] = nums[index];
		return curIndex + 1;
	}

public:
	bool hasRotateArray(vector<int>& nums, int target) {
		if (nums.empty()) false;

		if (nums[0] > target&&nums[nums.size()-1]<target) {
			return false;
		}
		else if (target <= nums[nums.size() - 1]) {
			for (auto it = nums.end() - 1;it >= nums.begin();--it) {
				if (it == nums.begin()) {
					return *it == target;
				}
				else {
					if (*(it - 1) > *it) {
						return *it == target;
					}
					else {
						if (*it == target) {
							return true;
						}
						else if (*it > target) {
							continue;
						}
						else {
							return false;
						}
					}
				}
			}
		}
		else {
			for (auto it = nums.begin();it < nums.end();++it) {
				if (it == nums.end() - 1) {
					return *it == target;
				}
				else {
					if (*(it + 1) < *it) {
						return *it == target;
					}
					else {
						if (*it == target) {
							return true;
						}
						else if (*it < target) {
							continue;
						}
						else {
							return false;
						}
					}
				}
			}
		}
		return false;
	}

public:
	ListNode* removeSameListNode(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode* first = head;
		ListNode* last = head->next;
		while (last != nullptr) {
			if (last->val == first->val) {
				first->next = last->next;
			}
			else {
				first = last;
			}
			last = last->next;
		}
		return head;
	}
//086
public:
	ListNode* partition(ListNode* head,int x) {
		ListNode* cur = head;
		ListNode* minFirst = nullptr;
		ListNode* curMin = nullptr;
		ListNode* maxFirst = nullptr;
		ListNode* curMax = nullptr;
		while (cur != nullptr) {
			if (cur->val < x) {
				if (minFirst == nullptr) {
					minFirst = cur;
					curMin = minFirst;
				}
				else {
					curMin->next = cur;
					curMin = curMin->next;
				}
				curMin->next = nullptr;
			}
			else {
				if (maxFirst == nullptr) {
					maxFirst = cur;
					curMax = maxFirst;
				}
				else {
					curMax->next = cur;
					curMax = curMax->next;
				}
			}
			cur = cur->next;
		}

		curMin->next = maxFirst;
		return minFirst;
	}

public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int cur = m + n - 1;
		while (m >= 0 && n >= 0) {
			if (nums1[m] > nums2[n]) {
				nums1[cur] = nums1[m];
				--m;
			}
			else {
				nums1[cur] = nums2[n];
				--n;
			}
			++cur;
		}
	}

public:
	vector<vector<int>> subArray(vector<int>& nums) {
		vector<vector<int>> results;
		subArrayExtension(nums, results, {}, 0);
		return results;
	}

public:
	void subArrayExtension(vector<int>& nums, vector<vector<int>>& results, vector<int> result, int start) {
		for (int i = start;i < nums.size();i++) {
			if (i > start && nums[i - 1] == nums[i]) {
				continue;
			}
			result.push_back(nums[i]);
			results.push_back(result);
			subArrayExtension(nums, results, result, i + 1);
			result.pop_back();
		}
	}

public:
	ListNode* rotateListNode(ListNode* head, int left, int right) {
		ListNode* prevNode = nullptr;
		ListNode* curPrevNode = nullptr;
		ListNode* curNode = head;
		ListNode* resultHead = head;
		int index = 0;
		while (curNode != nullptr) {
			if (index <= left) {
				if (index + 1 == left) {
					prevNode = curNode;
				}
				else if (index == right) {
					return head;
				}
				curPrevNode = curNode;
				curNode = curNode->next;
				++index;
			}
			else {
				if (prevNode == nullptr) {
					head->next = curNode->next;
					curNode->next = resultHead;
					resultHead = curNode;
				}
				else {
					curPrevNode->next = curNode->next;
					curNode->next = prevNode->next;
					prevNode->next = curNode;
				}
				curNode = curNode->next->next;
				if (index == right) {
					return head;
				}
				++index;
			}
		}
		return resultHead;
	}

public:
	vector<vector<string>> checkIp(string s) {
		vector<vector<string>> results;
		if (s.length() > 12) return results;
		checkIpExtension(s, results, {}, 0);
		return results;
	}

private:
	void checkIpExtension(string s,vector<vector<string>>& results,vector<string> result,int startIndex) {

		if (startIndex >= s.length()) {
			if (!result.empty() && result.size() == 4) {
				results.push_back(result);
			}
		}

		if (s[startIndex] == '0') {
			result.push_back(s.substr(startIndex, 1));
			checkIpExtension(s, results, result, startIndex + 1);
		}
		else {
			for (int i = 1;i <= 3;i++) {
				result.push_back(s.substr(startIndex, i));
				checkIpExtension(s, results, result, startIndex + i);
				result.pop_back();
			}
		}
	}

public:
	vector<int> midRead(TreeNode* root) {
		vector<int> result;
		midReadExtension(root, result);
		return result;
	}

private:
	void midReadExtension(TreeNode* root, vector<int>& result) {
		if (root == nullptr) {
			return;
		}
		if (root->left != nullptr) {
			midReadExtension(root->left, result);
		}
		result.push_back(root->val);
		if (root->right != nullptr) {
			midReadExtension(root->right, result);
		}
	}

public:
	vector<TreeNode*> search(int n) {
		vector<TreeNode*> nodes;
		for (int i = 1;i <= n;i++) {
			TreeNode* root = new TreeNode(i);
			nodes.push_back(root);
		}

	}

private:
	void searchExtension(int start,int end,TreeNode* root) {


		for (int i = start;i <= end;i++) {

			/*TreeNode* root = new TreeNode(i);
			searchExtension(0, i - 1, root);
			TreeNode* root = new TreeNode(i);
			searchExtension(i + 1, end, root);*/

		}



		

	}


public:
	bool mergeString(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length()) return false;

		int s1Index = 0, s2Index = 0, s3Index = 0;
		while (s1Index < s1.length() && s2Index < s2.length() && s3Index < s3.length()) {
			if (s1[s1Index] == s3[s3Index]) {
				++s1Index;
				++s3Index;
			}
			else if (s2[s2Index] == s3[s3Index]) {
				++s2Index;
				++s3Index;
			}
			else {
				return false;
			}
		}

		while (s1Index < s1.length()) {
			if (s1[s1Index] == s3[s3Index]) {
				++s1Index;
				++s3Index;
			}
			else {
				return false;
			}
		}
		
		while (s2Index < s2.length()) {
			if (s2[s2Index] == s3[s3Index]) {
				++s2Index;
				++s3Index;
			}
			else {
				return false;
			}
		}
		return true;
	}

public:
	bool sameTreeNode(TreeNode* root1,TreeNode* root2) {
		if (root1 == nullptr && root2 == nullptr) return true;
		if (root1 == nullptr || root2 == nullptr) return false;
		if (root1->val != root2->val) return false;
		bool sameLeft = sameTreeNode(root1->left, root2->left);
		if (sameLeft == false) return false;
		bool sameRight = sameTreeNode(root1->right, root2->right);
		if (sameRight == false) return false;
		return true;
	}

public:
	bool hlafTreeNode(TreeNode* root) {
		if (root == nullptr) return false;
		return hlafTreeNodeExtension(root->left, root->right);
	}

private:
	bool hlafTreeNodeExtension(TreeNode* root1,TreeNode* root2) {
		if (root1 == nullptr && root2 == nullptr) return true;
		if (root1 == nullptr || root2 == nullptr)return false;
		if (root1->val != root2->val) return false;

		bool sameW = hlafTreeNodeExtension(root1->left, root2->right);
		if (sameW == false) return false;
	    bool sameN = hlafTreeNodeExtension(root1->right, root2->left);
		if (sameN == false) return false;
		return true;

	}

public:
	void cengNode(TreeNode* node) {
		queue<TreeNode*> q;
		q.size();
	}

private:
	void cengNodeExtension(queue<TreeNode*> nodeQueue,vector<int>& result) {
		if (!nodeQueue.empty()) {
			queue<TreeNode*> tempQueue;
			for (int i = 0;i < nodeQueue.size();++i) {
				TreeNode* node = nodeQueue.front();
				nodeQueue.pop();
				result.push_back(node->val);
			}
			if (!tempQueue.empty()) {
				cengNodeExtension(tempQueue, result);
			}
		}
	}

private:
	void cengNodeEx(vector<TreeNode*> nodes, vector<int>& results,bool state) {
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
				for (int i = nodes.size() - 1;i >= 0;--i) {
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
	void resetNode(vector<int>& nums1, vector<int>& nums2) {
		
		int rootIndex = -1;
		for (int i = 0;i < nums2.size();i++) {
			if (nums2[i] == nums1[0]) {
				rootIndex = i;
			}
		}
		//[0,rootindex-1][rootindex+1,nums2.size()-1]

		
	}

private:
	void nodeExtension(vector<int>& nums1, vector<int>& nums2, TreeNode* root, int start, int end, int cur) {
		
		for (int i = start;i <= end;i++) {
			if (nums2[i] == root->val) {

			}
		}
	}

private:
	void resetNodeExtension(vector<int>& nums1, vector<int>& nums2, TreeNode* root, int rootIndex, int start, int end, int cur) {
		
		for (int i = start;i < rootIndex - 1;++i) {
			if (nums2[i] == nums1[cur]) {
				rootIndex = i;
			}
		}

		for (int i = rootIndex + 1;i < end;++i) {
			if (nums2[i] == nums1[cur]) {
				rootIndex = i;
			}
		}




	}
//118
public:
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
public:
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
public:
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

public:
	int maxprices(vector<int>& prices) {
		int result = 0;
		int minprice = prices[0];
		for (int i = 1;i < prices.size();i++) {
			minprice = min(minprice, prices[i]);
			result = max(result, prices[i] - minprice);
		}
		return result;
	}

public:
	bool checkStr(string str) {
		int l = 0, r = str.length() - 1;
		while (1 < r) {
			while (l < r && str[l] < 'a' && str[l] > 'z') {
				l++;
			}
			while (l < r && str[r] < 'a' && str[r]>'z') {
				r--;
			}

			if (str[l] != str[r]) {
				return false;
			}
			l++;r--;
		}
		return true;
	}





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
