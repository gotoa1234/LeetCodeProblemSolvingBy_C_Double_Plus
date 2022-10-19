#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution39
{
#pragma region Paste to execute 
	/*
	#include "0039.Combination_Sum.cpp"
	using namespace Solution39;
	using namespace std;

	int main()
	{
		vector<vector<int>> result = {};
		Solution39::Combination_Sum useClass;
		Solution39::Combination_Sum::Combination_Sum_Model getTestModel = useClass.GetTestData001();
		result = useClass.countAndSay(getTestModel.candidates, getTestModel.target);

		getTestModel = useClass.GetTestData002();
		result = useClass.countAndSay(getTestModel.candidates, getTestModel.target);

		getTestModel = useClass.GetTestData003();
		result = useClass.countAndSay(getTestModel.candidates, getTestModel.target);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 組合總和
	/// </summary>
	class Combination_Sum
	{
#pragma region Model
	public:
		class Combination_Sum_Model
		{
		public:
			vector<int> candidates;
			int target;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 
		///       Runtime：
		/// Memory Usage ：
		/// </summary>
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			return {};
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Combination_Sum_Model GetTestData001(void)
		{
			Combination_Sum_Model result;
			result.candidates = { 2, 3, 6, 7 };
			result.target = 7;
			return result;//except: [[2,2,3],[7]]
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Combination_Sum_Model GetTestData002(void)
		{
			Combination_Sum_Model result;
			result.candidates = {2,3,5};
			result.target = 8;
			return result;//except: [[2,2,2,2],[2,3,3],[3,5]]
		};

		/// <summary>
		/// test data 3
		/// </summary>   
		Combination_Sum_Model GetTestData003(void)
		{
			Combination_Sum_Model result;
			result.candidates = { 2 };
			result.target = 1;
			return result;//except: []
		};
#pragma endregion TestData

	};
}