#include <iostream>
#include <vector>
using namespace std;

namespace Solution35
{
#pragma region Paste to execute 
	/*
	#include "0035.Search_Insert_Position.cpp"
	using namespace Solution35;
	using namespace std;

	int main()
	{
		Solution35::Search_Insert_Position useClass;
		Solution35::Search_Insert_Position::Search_Insert_Position_Model getTestModel = useClass.GetTestData001();
		int result = useClass.searchInsert(getTestModel.nums, getTestModel.target);

		getTestModel = useClass.GetTestData002();
		result = useClass.searchInsert(getTestModel.nums, getTestModel.target);

		getTestModel = useClass.GetTestData003();
		result = useClass.searchInsert(getTestModel.nums, getTestModel.target);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 查詢適合插入位置的索引
	/// </summary>
	class Search_Insert_Position
	{
#pragma region Model
	public:
		class Search_Insert_Position_Model
		{
		public:
			vector<int> nums;
			int target;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///      thinking： 二分搜尋法查出索引位置，因為題目的Array已經排序
		///       Runtime：   3 ms Beats 95.55 %
		/// Memory Usage ： 9.7 MB Beats 71.67 %
		/// </summary>
		int searchInsert(vector<int>& nums, int target) {
			int leftIndex = 0;
			int rightIndex = nums.size() - 1;
			int middleIndex = 0;
			while (leftIndex <= rightIndex)
			{
				middleIndex = (rightIndex + leftIndex) / 2;
				if (nums[middleIndex] == target)
					return middleIndex;

				if (target < nums[middleIndex])
					rightIndex = middleIndex - 1;
				else
					leftIndex = middleIndex + 1;
			}
			return leftIndex;
			
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Search_Insert_Position_Model GetTestData001(void)
		{
			Search_Insert_Position_Model result;
			result.nums = { 1,3,5,6 };
			result.target = 5;
			return result;//except: 1
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Search_Insert_Position_Model GetTestData002(void)
		{
			Search_Insert_Position_Model result;
			result.nums = { 1,3,5,6 };
			result.target = 2;
			return result;//except: 1
		};

		/// <summary>
		/// test data 3
		/// </summary>   
		Search_Insert_Position_Model GetTestData003(void)
		{
			Search_Insert_Position_Model result;
			result.nums = { 1,3,5,6 };
			result.target = 7;
			return result;//except: 4
		};

		/// <summary>
		/// test data 4
		/// </summary>   
		Search_Insert_Position_Model GetTestData004(void)
		{
			Search_Insert_Position_Model result;
			result.nums = { 1};
			result.target = 1;
			return result;//except: 0
		};
#pragma endregion TestData

	};
}