#include <iostream>
#include <vector>

#include "Solution.h"


using namespace std;

int main()
{
    Solution solution;
   /* vector<int> ver = vector<int>{ 1, 2, 3, 4, 5 };
    vector<int> temp = solution.twoSum(ver, 6);*/

    //cout << solution.myAtoi("-12-3") << endl;
   
   /* vector<int> temp = { -1,-1,0,1,3,2,-2 };
    vector<vector<int>> result = solution.threeSum(temp);
    for (int i = 0;i < result.size();i++) {

        for (int j = 0;j < result[i].size();j++) {
            cout << result[i][j];
        }
        cout << endl;
    }

    cout << solution.threeSumClosest(temp, 7) << endl;*/

    //vector<string> result = solution.letterCombinations("23");
    //for (int i = 0;i < result.size();i++) {
    //    cout << result[i] << endl;
    //}


    //ListNode* l = new ListNode(1);
    //l->next = new ListNode(2);
    //l->next->next = new ListNode(3);
    //l->next->next->next = new ListNode(4);
    //l->next->next->next->next = new ListNode(5);

    //ListNode* n = solution.removeNthFromEnd(l, 2);
    //while (n != nullptr) {
    //    cout << n->val << endl;
    //    n = n->next;
    //}

    /*ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    ListNode* list2 = new ListNode(2);

    ListNode* n = solution.mergeTwoLists(list1, list2);
    while (n != nullptr) {
        cout << n->val << endl;
        n = n->next;
    }*/

   /* vector<string> results = solution.generateParenthesis(3);
    for (int i = 0;i < results.size();i++) {
        cout << results[i] << endl;
    }*/

   /* ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);

    ListNode* n = solution.swapPairs(list);
    while (n != nullptr) {
        cout << n->val << endl;
        n = n->next;
    }*/

    /*vector<int> nums = { 1,1,2,2,3,3,4 };
    cout << solution.removeDuplicates(nums) << endl;*/


    ListNode* list1 = new ListNode(1);
   /* list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);*/

    ListNode* list2 = new ListNode(0);
    /*list2->next = new ListNode(2);
    list2->next->next = new ListNode(3);
    list2->next->next->next = new ListNode(4);*/

    ListNode* list3 = new ListNode(2);
   /* list3->next = new ListNode(2);
    list3->next->next = new ListNode(3);
    list3->next->next->next = new ListNode(4);*/

    vector<ListNode*> nodes = { list1,list2,list3 };

   /* ListNode* head = solution.mergeKLists(nodes);
    cout << "是否为空" << (head == nullptr) << endl;
    while (head != nullptr) {
        cout << "结果" << head->val << endl;
        head = head->next;
    }*/
    //vector<string> words = { "ab","cd","ef" };

    //cout << solution.findSubstring("abcdef", words).size() << endl;

  /*  vector<int> nums = { 1,2,3,4 };

    solution.nextPermutation(nums);
    for (int i = 0;i < nums.size();i++) {
        cout << nums[i];
    }
    solution.nextPermutation(nums);
    for (int i = 0;i < nums.size();i++) {
        cout << nums[i];
    }
    solution.nextPermutation(nums);
    for (int i = 0;i < nums.size();i++) {
        cout << nums[i];
    }*/
    vector<int> nums = { 1,2,3 };
    int count = solution.combine(10, 10).size();
    cout << count << endl;
}
