#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution15
{
#pragma region Paste to execute 
	/*
	#include "0015.3Sum.cpp"
	using namespace Solution15;
	using namespace std;

	int main()
	{
		Solution15::Three_Sum useClass;
		Solution15::Three_Sum::Three_Sum_Model getTestModel = useClass.GetTestData001();
		vector<vector<int>> result = useClass.ThreeSum(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		result = useClass.ThreeSum(getTestModel.nums);

		getTestModel = useClass.GetTestData003();
		result = useClass.ThreeSum(getTestModel.nums);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 最長共用前綴
	/// </summary>
	class Three_Sum
	{
#pragma region Model
	public:
		class Three_Sum_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：
		///      Runtime : 
		/// Memory Usage : 
		/// </summary>
		vector<vector<int>> ThreeSum(vector<int>& nums) {
			vector<vector<int>> result;
			sort(nums.begin(), nums.end());
			int leftIndex = 0;
			int leftValue = 0;
			int middleValue = 0;
			int rightValue = 0;
			int useIndex = 0;
			for (int leftIndex = 0, rightIndex = nums.size() - 1; leftIndex <= nums.size() - 3; leftIndex++)
			{
				int startIndex = leftIndex;
				rightIndex = nums.size() - 1;
				leftValue = nums[startIndex];
				rightValue = nums[rightIndex];
				if (leftValue + rightValue >= 0)
				{
					startIndex++;
					useIndex = startIndex;
				}
				else
				{
					rightIndex--;
					useIndex = rightIndex;
				}

				
				while (startIndex < rightIndex)
				{
					middleValue = nums[useIndex];
					if (leftValue + rightValue + middleValue == 0)
					{
						result.push_back({ leftValue ,middleValue, rightValue });
					}

					if (leftValue + rightValue >= 0)
					{
						startIndex++;
						useIndex = startIndex;
					}
					else
					{
						rightIndex--;
						useIndex = rightIndex;
					}
				}
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Three_Sum_Model GetTestData001(void)
		{
			Three_Sum_Model result;
			result.nums = { -1,0,1,2,-1,-4 };
			return result;//except: [[-1,-1,2],[-1,0,1]]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Three_Sum_Model GetTestData002(void)
		{
			Three_Sum_Model result;
			result.nums = { 0,1,1 };
			return result;//expect: []
		};

		/// <summary>
	    /// 測試資料3
	    /// </summary>   
		Three_Sum_Model GetTestData003(void)
		{
			Three_Sum_Model result;
			result.nums = { 0,0,0 };
			return result;//expect: [[0,0,0]]
		};
#pragma endregion TestData
	};
}