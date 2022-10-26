#include "0041.First_Missing_Positive.cpp"
using namespace Solution41;
using namespace std;

int main()
{
	int result = 0;
	Solution41::First_Missing_Positive useClass;
	Solution41::First_Missing_Positive::First_Missing_Positive_Model getTestModel = useClass.GetTestData001();
	result = useClass.firstMissingPositive(getTestModel.nums);

	getTestModel = useClass.GetTestData002();
	result = useClass.firstMissingPositive(getTestModel.nums);
	int result2 = useClass.firstMissingPositive_in_place_hashing(getTestModel.nums);
	int result3 = useClass.firstMissingPositive_in_place_hashing_AND_Partition(getTestModel.nums);

	getTestModel = useClass.GetTestData003();
	result = useClass.firstMissingPositive(getTestModel.nums);
	result3 = useClass.firstMissingPositive_in_place_hashing_AND_Partition(getTestModel.nums);

	return 0;
}