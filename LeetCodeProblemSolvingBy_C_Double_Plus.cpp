#include <unordered_map>
#include "Medium/0309.Best_Time_to_Buy_and_Sell_Stock_with_Cooldown.cpp"
using namespace Solution309;

int main()
{
    Solution309::Best_Time_to_Buy_and_Sell_Stock_with_Cooldown useClass;
    Solution309::Best_Time_to_Buy_and_Sell_Stock_with_Cooldown::Best_Time_to_Buy_and_Sell_Stock_with_Cooldown_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.maxProfit(getTestModel.prices);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.maxProfit(getTestModel.prices);
    return 0;
}