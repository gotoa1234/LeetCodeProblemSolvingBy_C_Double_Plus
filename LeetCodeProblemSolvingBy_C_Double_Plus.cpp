#include "0031.Next_Permutation.cpp"
#include <string> 
using namespace Solution31;
using namespace std;

int main()
{
	Solution31::Next_Permutation useClass;
	Solution31::Next_Permutation::Next_Permutation_Model getTestModel = useClass.GetTestData001();
	useClass.nextPermutation(getTestModel.nums);

	getTestModel = useClass.GetTestData002();
	useClass.nextPermutation(getTestModel.nums);

	getTestModel = useClass.GetTestData003();
	useClass.nextPermutation(getTestModel.nums);


	vector<int> origin = { 1,2,3,4 };
	vector<int> nums = origin;
	string record = "";
	string current = "";
	do {
		next_permutation(nums.begin(), nums.end());
		current = to_string(nums[0]) + " , " + to_string(nums[1]) + " , " + to_string(nums[2]) + " , " + to_string(nums[3]) + "\n";
		record.append(current);
	} while (nums != origin);

	return 0;
}
