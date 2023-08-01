#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <numeric>

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
		///     thinking：題目給的k是1~9 不重複，因此使用貪婪演算法也部會時間複雜度超時
		///               利用遞迴，每次將一個數值放入，如果累計到K 並且計算到指定的n數值即可加入到結果中
		///       Runtime：  0 ms Beats 100 %
		/// Memory Usage ：6.3 MB Beats	86.55 %
		/// </summary>
		vector<vector<int>> _result{};
		vector<vector<int>> combinationSum3(int k, int n) {
			vector<int> compose{};
			FindCompose(1, k, n, compose);
			return _result;
		}

		void FindCompose(int currentIndex, int composeSize, int maxValue, vector<int>& compose)
		{
			//1. 被減去後當前若小於0跳出
			if (maxValue < 0)
				return;
			//2. 組成數量達到k 
			if (compose.size() == composeSize)
			{			
				//3. 並且達到n 就加入
				if (0 == maxValue)
				{
					_result.push_back(compose);
				}
				return;
			}

			for (int index = currentIndex; index <= 9; index++)
			{
				compose.push_back(index);
				FindCompose(index + 1, composeSize, maxValue - index, compose);
				compose.pop_back();
			}
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