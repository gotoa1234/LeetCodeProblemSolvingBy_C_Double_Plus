#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

namespace Solution219
{
#pragma region Paste to execute 
	/*
	#include "Medium\0219.Combination_Sum_III.cpp"
	using namespace Solution219;
	using namespace std;

	int main()
	{
		vector<vector<int>> result = {};
		Solution219::Combination_Sum_III useClass;
		Solution219::Combination_Sum_III::Combination_Sum_III_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.combinationSum3(getTestModel.k, getTestModel.n);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.combinationSum3(getTestModel.k, getTestModel.n);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 組合總和3
	/// </summary>
	class Combination_Sum_III
	{
#pragma region Model
	public:
		class Combination_Sum_III_Model
		{
		public:
			int k;
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking：
		///       Runtime：
		/// Memory Usage ：
		/// </summary>
		vector<vector<int>> _result{};
		vector<vector<int>> combinationSum3(int k, int n) {
			vector<int> compose{};
			

			return {};
		}

		void FindCompose(int index, int& k, int& n)
		{
		
		}

		

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Combination_Sum_III_Model GetTestData001(void)
		{
			Combination_Sum_III_Model result;
			result.k = 3;
			result.n = 7;
			return result;//except: [[1,2,4]]
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Combination_Sum_III_Model GetTestData002(void)
		{
			Combination_Sum_III_Model result;
			result.k = 3;
			result.n = 9;
			return result;//except: [[1,2,6],[1,3,5],[2,3,4]]
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Combination_Sum_III_Model GetTestData003(void)
		{
			Combination_Sum_III_Model result;
			result.k = 4;
			result.n = 1;
			return result;//except: []
		};
#pragma endregion TestData

	};
}