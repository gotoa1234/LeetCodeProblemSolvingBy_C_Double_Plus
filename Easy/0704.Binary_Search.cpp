#include <iostream>
#include <vector>
using namespace std;

namespace Solution704
{
#pragma region Paste to execute 
	/*
    #include "0704.Binary_Search.cpp"
    using namespace Solution704;
    using namespace std;

	Solution704::Binary_Search useClass;
	Solution704::Binary_Search::Binary_Search_Model getTestModel = useClass.GetTestData001();
	int result = useClass.search(getTestModel.nums, getTestModel.target);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 二元搜尋
	/// </summary>
	class Binary_Search
	{
#pragma region Model
	public:
		class Binary_Search_Model
		{
		public:
			vector<int> nums;
			int target;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         思路：目標是 O(logn) 因以排序，所以每次搜尋時從陣列的中間判斷要往左還是往右，即可找出答案
		///      Runtime :   41 ms, faster than 90.10% of C++ online submissions for Binary Search.
		/// Memory Usage:  27.5 MB,   less than 92.24% of C++ online submissions for Binary Search.
		/// </summary>
		int search(vector<int>& nums, int target) {

			short left = 0;
			short right = nums.size() - 1;
			short middle = 0;
			while (left <= right)
			{
				middle = (left + right) * 2;
				if (target == nums[middle])
					return middle;

				if (target > nums[middle])
				{
					left = middle + 1;
				}
				else
				{
					right = middle -1;
				}
			}
			return -1;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Binary_Search_Model GetTestData001(void)
		{
			Binary_Search_Model result;
			result.nums = { -1,0,3,5,9,12 };
			result.target = 9;
			return result;
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Binary_Search_Model GetTestData002(void)
		{
			Binary_Search_Model result;
			result.nums = { -1,0,3,5,9,12 };
			result.target = 2;
			return result;
		};
#pragma endregion TestData
	};
}