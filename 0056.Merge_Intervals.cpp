#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution56
{
#pragma region Paste to execute 
	/*
	#include "0056.Merge_Intervals.cpp"
	using namespace Solution56;
	using namespace std;

	int main()
	{
		Solution56::Merge_Intervals useClass;
		Solution56::Merge_Intervals::Merge_Intervals_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.merge(getTestModel.intervals);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.merge(getTestModel.intervals);
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 合併區間
	/// </summary>
	class Merge_Intervals
	{
#pragma region Model
	public:
		class Merge_Intervals_Model
		{
		public:
			vector<vector<int>> intervals;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 找出規則Merge條件:
		///                1. 先排序後可以得到由小到大的值 
		///                2. (a,b) , (c,d) 當b >= c時 必定可以合併
		///       Runtime：   38 ms Beats 96.35 %
		/// Memory Usage ： 18.8 MB Beats 96.19 %
		/// </summary>	
		vector<vector<int>> merge(vector<vector<int>>& intervals) {
			vector<vector<int>> result;
			sort(intervals.begin(), intervals.end());
			
			//1. 先放入第一個值
			result.push_back(intervals[0]);
			for(int index = 1; index < intervals.size(); index++)
			{
				//2.若可以合併將當前的值元上一個值合併
				if (result.back()[1] >= intervals[index][0])
					result.back()[1] = max(result.back()[1], intervals[index][1]);
				else//3. 不可合併則將當前值放入
					result.push_back(intervals[index]);
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Merge_Intervals_Model GetTestData001(void)
		{
			Merge_Intervals_Model result;
			result.intervals = { {1,3 },{2,6 },{8,10},{15,18 } };
			return result;//except: [[1,6],[8,10],[15,18]]
		};

		/// <summary>
		/// test data 2
		/// </summary>        
		Merge_Intervals_Model GetTestData002(void)
		{
			Merge_Intervals_Model result;
			result.intervals = { {1,4 },{4,5 } };
			return result;//except: [[1,5]]
		};
#pragma endregion TestData

	};
}
