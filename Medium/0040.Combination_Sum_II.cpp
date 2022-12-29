#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

namespace Solution40
{
#pragma region Paste to execute 
	/*
	#include "0040.Combination_Sum_II.cpp"
	using namespace Solution40;
	using namespace std;

	int main()
	{
		vector<vector<int>> result = {};
		Solution40::Combination_Sum_II useClass;
		Solution40::Combination_Sum_II::Combination_Sum_II_Model getTestModel = useClass.GetTestData001();
		result = useClass.combinationSum2(getTestModel.candidates, getTestModel.target);

		getTestModel = useClass.GetTestData002();
		result = useClass.combinationSum2(getTestModel.candidates, getTestModel.target);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 組合總和2
	/// </summary>
	class Combination_Sum_II
	{
#pragma region Model
	public:
		class Combination_Sum_II_Model
		{
		public:
			vector<int> candidates;
			int target;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 同0039 先排序元素，然後遞迴呼叫，但這次不回傳值，而是找到後中止(只跑一次元素)
		///       Runtime：	   3 ms Beats 96.33 %
		/// Memory Usage ： 10.8 MB Beats 47.83 %
		/// </summary>
		vector<vector<int>> _result = { };
		vector<int> _combination = {};
		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			sort(candidates.begin(), candidates.end());
			FindCombination(candidates, target, 0);
			return _result;
		}

		void FindCombination(vector<int>& candidates, int target, int moveIndex)
		{
			if (target == 0)
			{
				_result.push_back(_combination);
				return;
			}

			for (int index = moveIndex;
				index < candidates.size() && target - candidates[index] >= 0;
				index++)
			{
				_combination.push_back(candidates[index]);
				//每次往下索引+1，不可用相同的元素
				FindCombination(candidates, target - candidates[index], index + 1);
				_combination.pop_back();

				//假設有重複元素值相連的情況，要直接跳過，避免重複計算
				while ((index + 1 < candidates.size()) &&
					(candidates[index] == candidates[index + 1])
					)
				{
					index++;
				}
			}
		}



#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Combination_Sum_II_Model GetTestData001(void)
		{
			Combination_Sum_II_Model result;
			result.candidates = { 10,1,2,7,6,1,5 };
			result.target = 8;
			return result;//except: [[1,1,6], [1, 2, 5], [1, 7], [2, 6]]
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Combination_Sum_II_Model GetTestData002(void)
		{
			Combination_Sum_II_Model result;
			result.candidates = { 2,5,2,1,2 };
			result.target = 5;
			return result;//except: [[1,2,2],[5]]
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Combination_Sum_II_Model GetTestData003(void)
		{
			Combination_Sum_II_Model result;
			result.candidates = { 14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12 };
			result.target = 27;
			return result;//except: 
		};
#pragma endregion TestData

	};
}