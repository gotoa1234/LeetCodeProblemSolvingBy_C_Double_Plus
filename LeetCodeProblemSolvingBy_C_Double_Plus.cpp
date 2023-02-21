#include "Medium\0122.Best_Time_to_Buy_and_Sell_Stock_II.cpp"
using namespace Solution122;
using namespace std;

int main()
{
	Solution122::Best_Time_to_Buy_and_Sell_Stock_II useClass;
	Solution122::Best_Time_to_Buy_and_Sell_Stock_II::Best_Time_to_Buy_and_Sell_Stock_II_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.maxProfit(getTestModel.prices);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.maxProfit(getTestModel.prices);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.maxProfit(getTestModel.prices);
}