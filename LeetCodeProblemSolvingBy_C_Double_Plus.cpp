#include "Easy\0441.Arranging_Coins.cpp"
using namespace Solution441;

int main()
{
	Solution441::Arranging_Coins useClass;
	Solution441::Arranging_Coins::Arranging_Coins_Model getTestModel = useClass.GetTestData001();
	auto result = useClass.arrangeCoins(getTestModel.n);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.arrangeCoins(getTestModel.n);
}