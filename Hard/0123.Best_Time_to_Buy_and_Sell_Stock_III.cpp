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
	/// ��X�̨ζR��Ѳ�3
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
		///          ����G���D�n��121���Ѫk�A�D�X�ѥ��ӥk�̤j�ȻP�ѥk�ӥ��̤j��
		///            EX: 3,3,5,0,0,3,1,4   => �i�H�o�X�����k���W�ѼƳ̤j�i��Q�q�� [0,0,2,2,2,3,3,4]
		///                3,3,5,0,0,3,1,4   => �i�H�o�X�k��������ѼƳ̤j�i��Q�q�� [4,4,4,4,4,3,3,0]
		///                �M������x �i�H�o��(left[x] + right[x]) �̤j��6
		///      Runtime : 
		/// Memory Usage : 
		/// </summary>
		int maxProfit(vector<int>& prices) {
			int days = prices.size();
			vector<int> leftParts(days);
			vector<int> rightParts(days);			

			int minPrice = prices[0];
			int maxProfit = 0;		
			//1. �D�X�����W�̤j��
			for (int index = 1; index < days; index++)
			{
				maxProfit = max(maxProfit, prices[index] - minPrice);
				if (minPrice > prices[index])
					minPrice = prices[index];
				leftParts[index] = maxProfit;
			}
			int maxPrice = prices[days - 1];
			maxProfit = 0;
			int totalMAX = 0;
			//2. �D�X�k���W�̤j��
			for (int index = days - 1; index >= 0; index--)
			{
				maxProfit = max(maxProfit, maxPrice - prices[index]);
				if (maxPrice < prices[index])
					maxPrice = prices[index];
				rightParts[index] = maxProfit;
				//3. �A�⪺�P�ɭp��̤j��+�k���������ޭ� (�ԥX��i�A���|���C�į�)
				totalMAX = max(totalMAX, leftParts[index] + rightParts[index]);
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