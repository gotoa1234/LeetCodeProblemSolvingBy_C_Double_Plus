#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <deque>
using namespace std;

namespace Solution309
{
#pragma region Paste to execute 
    /*
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
        return 0;b
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 有冷卻時間的最佳股票買賣時機
    /// </summary>
    class Best_Time_to_Buy_and_Sell_Stock_with_Cooldown
    {
#pragma region Model
    public:
        class Best_Time_to_Buy_and_Sell_Stock_with_Cooldown_Model
        {
        public:
            vector<int> prices;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///        think :
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage :11.4 MB Beats 74.63 %
        /// </summary>
        /// <returns></returns>   

        int maxProfit(vector<int>& prices) {
            int profit = 0;
            vector<int> dp(prices.size(), 0);
            int maxDiff = INT_MIN;
            for (int index = 0; index < prices.size(); index++) 
            {
                if (index <= 1) {
                    dp[index] = index == 0 ? 0
                                           : max(0, prices[index] - prices[index - 1]);
                    maxDiff = max(maxDiff, -prices[index]);
                }
                else {
                    dp[index] = max(dp[index - 1], 
                                    prices[index] + maxDiff);
                    maxDiff = max(maxDiff, 
                                  dp[index - 2] - prices[index]);
                }
            }
            return dp[prices.size() - 1];
        }


    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Best_Time_to_Buy_and_Sell_Stock_with_Cooldown_Model GetTestData001(void)
        {
            Best_Time_to_Buy_and_Sell_Stock_with_Cooldown_Model result;
            result.prices = { 1,2,3,0,2 };
            return result;//expect: 3
            //transactions = [buy, sell, cooldown, buy, sell]
            //The stock cannot be bought or sold after the sale.
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Best_Time_to_Buy_and_Sell_Stock_with_Cooldown_Model GetTestData002(void)
        {
            Best_Time_to_Buy_and_Sell_Stock_with_Cooldown_Model result;
            result.prices = {1 , 2};
            return result;//expect: 1
        };

#pragma endregion TestData
    };
}