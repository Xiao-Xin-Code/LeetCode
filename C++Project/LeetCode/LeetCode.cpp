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

    vector<string> result = solution.letterCombinations("23");
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << endl;
    }


    ListNode* l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(5);

    ListNode* n = solution.removeNthFromEnd(l, 2);
    while (n != nullptr) {
        cout << n->val << endl;
        n = n->next;
    }

}
