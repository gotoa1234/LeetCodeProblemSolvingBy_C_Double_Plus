#include <vector>
#include "Easy\0374.Guess_Number_Higher_or_Lower.cpp"
using namespace Solution374;

int main()
{
	Solution374::Guess_Number_Higher_or_Lower useClass;
	Solution374::Guess_Number_Higher_or_Lower::Guess_Number_Higher_or_Lower_Model getTestModel = useClass.GetTestData001();
	useClass.SetPick(getTestModel.pick);
	auto result1 = useClass.guessNumber(getTestModel.n);

	getTestModel = useClass.GetTestData002();
	useClass.SetPick(getTestModel.pick);
	auto result2 = useClass.guessNumber(getTestModel.n);

	getTestModel = useClass.GetTestData003();
	useClass.SetPick(getTestModel.pick);
	auto result3 = useClass.guessNumber(getTestModel.n);
	return 0;
}