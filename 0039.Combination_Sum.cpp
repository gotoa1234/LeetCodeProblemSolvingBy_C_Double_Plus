#include <iostream>
#include <unordered_map>
#include <algorithm>
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
		result = useClass.combinationSum(getTestModel.candidates, getTestModel.target);

		getTestModel = useClass.GetTestData002();
		result = useClass.combinationSum(getTestModel.candidates, getTestModel.target);

		getTestModel = useClass.GetTestData003();
		result = useClass.combinationSum(getTestModel.candidates, getTestModel.target);
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
		///     thinking： 利用遞迴DFS，先排序由小到大，然後由第Vector<int>第0個開始窮舉法到最後，組成所有解
		///       Runtime：
		/// Memory Usage ：
		/// </summary>
		vector<vector<int>> _result = {};
		vector<int> _combinations = {};
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

			//1. 排序資料由小到大
			sort(candidates.begin(), candidates.end());
			//2. 進行遞迴
			Sum(candidates, target, 0);

			return _result;
		}

		void Sum(vector<int>& candidates, int target, int moveIndex)
		{
			//3. 每次遞迴 target 都會被減去一個值，當target為0時，表示組成的 _combinations就是答案
			if (target == 0)
			{
				_result.push_back(_combinations);
				return;
			}

			//4. index 由0到最後，每次減少當前值，若為負數表示當前值不合適需要
			while (moveIndex < candidates.size() && 
				   target - candidates[moveIndex] >= 0
				)
			{
				//5. 每次將一個值放入
				_combinations.push_back(candidates[moveIndex]);
				Sum(candidates, target - candidates[moveIndex], moveIndex);
				//6. 當找到或者沒找到時都會往下個值前進(準備當下個遞迴的當前值)
				moveIndex++;
				_combinations.pop_back();
			}
			return;
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