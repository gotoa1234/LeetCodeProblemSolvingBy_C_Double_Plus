#include <iostream>
#include <vector>
using namespace std;

namespace Solution123
{
#pragma region Paste to execute 
	/*
	#include "0123.Best_Time_to_Buy_and_Sell_Stock_III.cpp"
	using namespace Solution123;
	using namespace std;

	Solution123::Best_Time_to_Buy_and_Sell_Stock_III useClass;
	Solution123::Best_Time_to_Buy_and_Sell_Stock_III::Best_Time_to_Buy_and_Sell_Stock_III_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.maxProfit(getTestModel.prices);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.maxProfit(getTestModel.prices);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.maxProfit(getTestModel.prices);
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
		///          ����G
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
		Best_Time_to_Buy_and_Sell_Stock_III_Model GetTestData001(void)
		{
			Best_Time_to_Buy_and_Sell_Stock_III_Model result;
			result.prices = { 7,1,5,3,6,4 };
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