#include "Hard\0123.Best_Time_to_Buy_and_Sell_Stock_III.cpp"
using namespace Solution123;
using namespace std;


int main()
{
    Solution123::Best_Time_to_Buy_and_Sell_Stock_III useClass;
    Solution123::Best_Time_to_Buy_and_Sell_Stock_III::Best_Time_to_Buy_and_Sell_Stock_III_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.maxProfit(getTestModel.prices);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.maxProfit(getTestModel.prices);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.maxProfit(getTestModel.prices);
}