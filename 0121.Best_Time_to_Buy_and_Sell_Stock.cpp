#include <iostream>
#include <vector>
using namespace std;

namespace Solution121
{
#pragma region Paste to execute 
	/*
	#include "0121.Best_Time_to_Buy_and_Sell_Stock.cpp"
	using namespace Solution121;
	using namespace std;

	Solution121::Best_Time_to_Buy_and_Sell_Stock useClass;
	Solution121::Best_Time_to_Buy_and_Sell_Stock::Best_Time_to_Buy_and_Sell_Stock_Model getTestModel = useClass.GetTestData001();
	int result = useClass.maxProfit(getTestModel.prices);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 一維陣列，找出最佳買賣股票的索引起訖
	/// </summary>
	class Best_Time_to_Buy_and_Sell_Stock
	{
#pragma region Model
	public:
		class Best_Time_to_Buy_and_Sell_Stock_Model
		{
		public:
			vector<int> prices;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路： 找出陣列中最小Value的索引，並在該索引之後找最大於最小Value的索引值
		///      Runtime :  175 ms, faster than 69.64% of C++ online submissions for Best Time to Buy and Sell Stock.
        /// Memory Usage : 93.3 MB,   less than 89.58% of C++ online submissions for Best Time to Buy and Sell Stock.
		/// </summary>
		int maxProfit(vector<int>& prices) {
			int minPrice = prices[0];
			int maxCaculation = 0;
			for (int index = 0; index < prices.size(); index++)
			{
				minPrice = min(prices[index], minPrice);
				maxCaculation = max(prices[index] - minPrice, 
					                maxCaculation);
			}
			return maxCaculation;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Best_Time_to_Buy_and_Sell_Stock_Model GetTestData001(void)
		{
			Best_Time_to_Buy_and_Sell_Stock_Model result;
			result.prices = { 7,1,15,13,16,14,500 };
			return result;
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Best_Time_to_Buy_and_Sell_Stock_Model GetTestData002(void)
		{
			Best_Time_to_Buy_and_Sell_Stock_Model result;
			result.prices = { 7,6,4,3,1 };
			return result;
		};
#pragma endregion TestData
	};
}