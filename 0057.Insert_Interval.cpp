#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution57
{
#pragma region Paste to execute 
	/*
	#include "0057.Insert_Interval.cpp"
	using namespace Solution57;
	using namespace std;

	int main()
	{
		Solution57::Insert_Interval useClass;
		Solution57::Insert_Interval::Insert_Interval_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.insert(getTestModel.intervals, getTestModel.newInterval);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.insert(getTestModel.intervals, getTestModel.newInterval);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.insert(getTestModel.intervals, getTestModel.newInterval);

		getTestModel = useClass.GetTestData004();
		auto result4 = useClass.insert(getTestModel.intervals, getTestModel.newInterval);
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 合併插入區間
	/// </summary>
	class Insert_Interval
	{
#pragma region Model
	public:
		class Insert_Interval_Model
		{
		public:
			vector<vector<int>> intervals;
			vector<int> newInterval;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking：分三個區段
		///                1. 排序，然後找出合適的插入位置
		///                2. 將插入值不斷更新，最小-最大 找出區間插入
		///                3. 將剩下的數組填入結果 (此時與Merge無關)
		///       Runtime：
		/// Memory Usage ：
		/// </summary>	
		vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
			vector<vector<int>> result{};
			//1-1. 排序
			sort(intervals.begin(), intervals.end());
			int findIndex = 0;
			
			//1-2.找出 newInterval[0] 合適排序的位置
			for (findIndex = 0; 
				 findIndex < intervals.size() && intervals[findIndex][1] < newInterval[0];
			  	 findIndex++)
			{
				result.push_back(intervals[findIndex]);
			}
			//2. 將插入的起訖不斷替換，直到跳出並插入
			for (;
				findIndex < intervals.size() && intervals[findIndex][0] <= newInterval[1];
				findIndex++)
			{
				newInterval[0] = min(newInterval[0], intervals[findIndex][0]);
				newInterval[1] = max(newInterval[1], intervals[findIndex][1]);
			}
			result.push_back(newInterval);
			
			//3. 將剩下的資料補回
			while (findIndex < intervals.size())
			{
				result.push_back(intervals[findIndex]);
				findIndex++;
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Insert_Interval_Model GetTestData001(void)
		{
			Insert_Interval_Model result;
			result.intervals = { {1,3 },{6,9 } };
			result.newInterval = { 2, 5};
			return result;//except:  [[1, 5], [6, 9]]
		};

		/// <summary>
		/// test data 2
		/// </summary>        
		Insert_Interval_Model GetTestData002(void)
		{
			Insert_Interval_Model result;
			result.intervals = { {1,2 },{3,5 },{6,7 },{8,10 },{12,16 } };
			result.newInterval = {4, 8};
			return result;//except:  [[1, 2], [3, 10], [12, 16]]
		};

		/// <summary>
		/// test data 3
		/// </summary>        
		Insert_Interval_Model GetTestData003(void)
		{
			Insert_Interval_Model result;
			result.intervals = { {1,2 },{3,4 }};
			result.newInterval = { 5, 6 };
			return result;//except:  [[1,2],[3,4],[5,6]]
		};

		/// <summary>
		/// test data 4
		/// </summary>        
		Insert_Interval_Model GetTestData004(void)
		{
			Insert_Interval_Model result;
			result.intervals = { {1,2 },{4,5 } };
			result.newInterval = { 3, 6 };
			return result;//except:  [[1,2],[3,6]]
		};
#pragma endregion TestData

	};
}
