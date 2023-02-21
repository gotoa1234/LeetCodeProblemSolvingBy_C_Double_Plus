#include <iostream>
#include <vector>
using namespace std;

namespace Solution123
{
#pragma region Paste to execute 
	/*
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
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 找出最佳買賣股票3
	/// </summary>
	class Best_Time_to_Buy_and_Sell_Stock_III
	{
#pragma region Model
	public:
		class Best_Time_to_Buy_and_Sell_Stock_III_Model
		{
		public:
			vector<int> prices;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：此題要用121的解法，求出由左而右最大值與由右而左最大值
		///            EX: 3,3,5,0,0,3,1,4   => 可以得出左往右遞增天數最大可獲利益為 [0,0,2,2,2,3,3,4]
		///                3,3,5,0,0,3,1,4   => 可以得出右往左遞減天數最大可獲利益為 [4,4,4,4,4,3,3,0]
		///                遍歷索引x 可以得到(left[x] + right[x]) 最大為6
		///      Runtime :  150 ms Beats 90.42 %
		/// Memory Usage : 78.4 MB Beats 71.59 %
		/// </summary>
		int maxProfit(vector<int>& prices) {
			int days = prices.size();
			vector<int> leftParts(days);

			int minPrice = prices[0];
			int leftProfit = 0;		
			//1. 求出左遞增最大值
			for (int index = 1; index < days; index++)
			{
				leftProfit = max(leftProfit, prices[index] - minPrice);
				if (minPrice > prices[index])
					minPrice = prices[index];
				leftParts[index] = leftProfit;
			}
			int maxPrice = prices[days - 1];
			int rightProfit = 0;
			int totalMAX = 0;
			//2. 求出右遞增最大值
			for (int index = days - 1; index >= 0; index--)
			{
				rightProfit = max(rightProfit, maxPrice - prices[index]);
				if (maxPrice < prices[index])
					maxPrice = prices[index];
				//3. 再算的同時計算最大左+右的對應索引值，為了加快效能省去存在右邊的Vector<int>
				totalMAX = max(totalMAX, leftParts[index] + rightProfit);
			}
			return totalMAX;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Best_Time_to_Buy_and_Sell_Stock_III_Model GetTestData001(void)
		{
			Best_Time_to_Buy_and_Sell_Stock_III_Model result;
			result.prices = { 3,3,5,0,0,3,1,4 };
			return result;//Expect: 6
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Best_Time_to_Buy_and_Sell_Stock_III_Model GetTestData002(void)
		{
			Best_Time_to_Buy_and_Sell_Stock_III_Model result;
			result.prices = { 1,2,3,4,5 };
			return result;//Expect:4
		};

		/// <summary>
		/// test 3
		/// </summary>   
		Best_Time_to_Buy_and_Sell_Stock_III_Model GetTestData003(void)
		{
			Best_Time_to_Buy_and_Sell_Stock_III_Model result;
			result.prices = { 7,6,4,3,1 };
			return result;//Expect:0
		};
#pragma endregion TestData
	};
}