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
		///          思路：排序，然後遍歷將最左邊的數值(0)固定，然後將(1)與最後值(nums.size())，三個相加，若結果小於0 將(1) -> (2);若大於0則
		///                (nums.size() -1) 當交界時遍歷起點為(1) ......重複後取得結果
		///      Runtime:   128 ms, faster than 64.67% of C++ online submissions for 3Sum.
		/// Memory Usage : 19.8 MB,   less than 95.65% of C++ online submissions for 3Sum.
		/// </summary>
		vector<vector<int>> ThreeSum(vector<int>& nums) {
			vector<vector<int>> result;
			int leftIndex = 0;
			int rightIndex = 0;
			int middleValue = 0;
			int rightValue = 0;
			int numsMax = nums.size();
			//1. 排序
			sort(nums.begin(), nums.end());
			//2. 遍歷
			for (int index = 0; index < numsMax; index++)
			{
				//3.選擇兩個點(最左、最右)
				leftIndex = index + 1;
				rightIndex = numsMax - 1;

				//當交集時跳出
				while (leftIndex < rightIndex)
				{
					middleValue = nums[leftIndex];
					rightValue = nums[rightIndex];
					if (nums[index] + middleValue + rightValue == 0)
					{
						//找到時做紀錄
						result.push_back({ nums[index] ,middleValue , rightValue });

						//以下是找出相同數值時往右與往左
						int tempMiddleValue = nums[leftIndex];
						int tempRightValue = nums[rightIndex];
						while (leftIndex < rightIndex && nums[leftIndex] == tempMiddleValue)
							leftIndex++;
						while (rightIndex > 0 && nums[rightIndex] == tempRightValue)
							rightIndex--;
					}
					else if (nums[index] + middleValue + rightValue < 0)//小於0，往右讓數值變大，趨近0
						leftIndex++;
					else//大於0，往左讓數值變小，趨近0
						rightIndex--;
				}
				//以下是找出起點相同數值時往右
				while (index + 1 < numsMax && nums[index + 1] == nums[index])
					index++;
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