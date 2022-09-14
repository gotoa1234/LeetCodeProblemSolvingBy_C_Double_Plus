#include "0017.Letter_Combinations_of_a_Phone_Number.cpp"
using namespace Solution17;
using namespace std;

int main()
{
	Solution17::Three_Sum_Closet useClass;
	Solution17::Three_Sum_Closet::Letter_Combinations_of_a_Phone_Number_Model getTestModel = useClass.GetTestData001();
	vector<string> result = useClass.letterCombinations(getTestModel.digits);

	getTestModel = useClass.GetTestData002();
	result = useClass.letterCombinations(getTestModel.digits);

	getTestModel = useClass.GetTestData003();
	result = useClass.letterCombinations(getTestModel.digits);

	return 0;
}