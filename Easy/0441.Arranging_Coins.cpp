#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution441
{
#pragma region Paste to execute 
	/*
	#include "Easy\0441.Arranging_Coins.cpp"
	using namespace Solution441;

	int main()
	{
		Solution441::Arranging_Coins useClass;
		Solution441::Arranging_Coins::Arranging_Coins_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.findContentChildren(getTestModel.g, getTestModel.s);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.findContentChildren(getTestModel.g, getTestModel.s);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ¤À°t»æ°®
	/// </summary>
	class Arranging_Coins
	{
#pragma region Model
	public:
		class Arranging_Coins_Model
		{
		public:
			vector<int> g;
			vector<int> s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          «ä¸ô : 
		///       Runtime : 
		///  Memory Usage :
		/// </summary>
		int findContentChildren(vector<int>& g, vector<int>& s) {

		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Arranging_Coins_Model GetTestData001(void)
		{
			Arranging_Coins_Model result;
			result.g = { 1, 2, 3 };
			result.s = { 1, 1 };
			return result;//expect : 1
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Arranging_Coins_Model GetTestData002(void)
		{
			Arranging_Coins_Model result;
			result.g = { 1, 2 };
			result.s = { 1, 2, 3 };
			return result;//expect : 2
		};

#pragma endregion TestData
	};
}