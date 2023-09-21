#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution188
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0188.Best_Time_to_Buy_and_Sell_Stock_IV.cpp"
    using namespace Solution188;

    int main()
    {
        Solution188::Best_Time_to_Buy_and_Sell_Stock_IV useClass;
        Solution188::Best_Time_to_Buy_and_Sell_Stock_IV::Best_Time_to_Buy_and_Sell_Stock_IV_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.calculateMinimumHP(getTestModel.dungeon);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.calculateMinimumHP(getTestModel.dungeon);
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ¦a«°¹CÀ¸   
    /// </summary>
    class Best_Time_to_Buy_and_Sell_Stock_IV
    {
#pragma region Model
    public:
        class Best_Time_to_Buy_and_Sell_Stock_IV_Model
        {
        public:
            int k;
            vector<int> prices;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         «ä¸ô ¡G
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>        
        int maxProfit(int k, vector<int>& prices) {
            return {};
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Best_Time_to_Buy_and_Sell_Stock_IV_Model GetTestData001(void)
        {
            Best_Time_to_Buy_and_Sell_Stock_IV_Model result;
            result.k = 2;
            result.prices = { 3,2,6,5,0,3 };
            return result;//expect: 2
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Best_Time_to_Buy_and_Sell_Stock_IV_Model GetTestData002(void)
        {
            Best_Time_to_Buy_and_Sell_Stock_IV_Model result;
            result.k = 2;
            result.prices = { 3,2,6,5,0,3};
            return result;//expect:7
        };

#pragma endregion TestData
    };
}