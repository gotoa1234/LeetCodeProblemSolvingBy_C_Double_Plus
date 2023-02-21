#include <iostream>
#include <vector>
using namespace std;

namespace Solution122
{
#pragma region Paste to execute 
	/*
	#include "0122.Best_Time_to_Buy_and_Sell_Stock_II.cpp"
	using namespace Solution122;
	using namespace std;

	Solution122::Best_Time_to_Buy_and_Sell_Stock_II useClass;
	Solution122::Best_Time_to_Buy_and_Sell_Stock_II::Best_Time_to_Buy_and_Sell_Stock_II_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.maxProfit(getTestModel.prices);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.maxProfit(getTestModel.prices);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.maxProfit(getTestModel.prices);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 找出最佳買賣股票2
	/// </summary>
	class Best_Time_to_Buy_and_Sell_Stock_II
	{
#pragma region Model
	public:
		class Best_Time_to_Buy_and_Sell_Stock_II_Model
		{
		public:
			vector<int> prices;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：
		///      Runtime : 
		/// Memory Usage : 
		/// </summary>
		int maxProfit(vector<int>& prices) {
			return {};
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Best_Time_to_Buy_and_Sell_Stock_II_Model GetTestData001(void)
		{
			Best_Time_to_Buy_and_Sell_Stock_II_Model result;
			result.prices = { 7,1,5,3,6,4 };
			return result;//Expect: 7
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Best_Time_to_Buy_and_Sell_Stock_II_Model GetTestData002(void)
		{
			Best_Time_to_Buy_and_Sell_Stock_II_Model result;
			result.prices = { 1,2,3,4,5 };
			return result;//Expect:4
		};

        /// <summary>
		/// test 3
		/// </summary>   
		Best_Time_to_Buy_and_Sell_Stock_II_Model GetTestData003(void)
		{
			Best_Time_to_Buy_and_Sell_Stock_II_Model result;
			result.prices = { 7,6,4,3,1 };
			return result;//Expect:0
		};
#pragma endregion TestData
	};
}