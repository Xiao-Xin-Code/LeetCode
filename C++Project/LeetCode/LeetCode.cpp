#include <iostream>
#include <vector>

#include "Solution_001-100.h"
#include "Solution_101-200.h"


using namespace std;

int main()
{
	Solution_101_200::Solution solution;
	/*vector<int> gas = { 1,2,3,4,5 };
	vector<int> cost = { 3,4,5,1,2 };
	cout << solution.canCompleteCircuit(gas, cost) << endl;*/

	vector<int> ratings = { 1,2,2 };
	cout << solution.candy(ratings);
}
