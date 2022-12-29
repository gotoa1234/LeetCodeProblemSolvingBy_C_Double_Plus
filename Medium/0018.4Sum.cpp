#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution18
{
#pragma region Paste to execute 
	/*
    #include "0018.4Sum.cpp"
    using namespace Solution18;
    using namespace std;
    
    int main()
    {
    	Solution18::Four_Sum useClass;
    	Solution18::Four_Sum::Four_Sum_Model getTestModel = useClass.GetTestData001();
    	vector<vector<int>> result = useClass.fourSum(getTestModel.nums, getTestModel.target);
    
    	getTestModel = useClass.GetTestData002();
    	result = useClass.fourSum(getTestModel.nums, getTestModel.target);
    
    	return 0;
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 4個數值加總
	/// </summary>
	class Four_Sum
	{
#pragma region Model
	public:
		class Four_Sum_Model
		{
		public:
			vector<int> nums;
			int target;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：3Sum的延伸，4sum需要再多固定一個位置進行運算。
		///       Runtime:  166 ms, faster than 53.28% of C++ online submissions for 4Sum.
		/// Memory Usage : 12.9 MB,   less than 99.43% of C++ online submissions for 4Sum.
		/// </summary>
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>> result;
			//1. 排除項目小於4個的狀況
			if (nums.size() < 4)
				return result;
			sort(nums.begin(), nums.end());
			int middleIndex = 0;
			int rightIndex = 0;
			int tempIndex = 0;
			long long tempSumValue = 0;
			//2. 固定第一個位置
			for (int lastIndex = 0; lastIndex < nums.size() - 3; lastIndex++)
			{
				//3. 固定第二個位置，然後利用3Sum的解法
				for (int secondIndex = lastIndex + 1; secondIndex < nums.size() - 2; secondIndex++)
				{
					middleIndex = secondIndex + 1;
					rightIndex = nums.size() - 1;
					while (middleIndex < rightIndex)
					{
						//3-1. 注意，這邊4個int相加有可能溢位，簡單做法是用long暫存
						tempSumValue = 0;
						tempSumValue += nums[lastIndex];
						tempSumValue += nums[secondIndex];
						tempSumValue += nums[middleIndex];
						tempSumValue += nums[rightIndex];
						if (tempSumValue == target)//3-2. 當找到時紀錄
						{
							result.push_back({ nums[lastIndex] ,nums[secondIndex], nums[middleIndex] , nums[rightIndex] });
							tempIndex = middleIndex;
							while (middleIndex < nums.size() - 1 && nums[middleIndex] == nums[tempIndex])
								middleIndex++;
							tempIndex = rightIndex;
							while (rightIndex > 0 && nums[rightIndex] == nums[tempIndex])
								rightIndex--;
						}
						else if (tempSumValue < target)
							middleIndex++;
						else
							rightIndex--;
					}
					while (secondIndex < nums.size() - 2 && nums[secondIndex] == nums[secondIndex+1])
						secondIndex++;
				}
				while (lastIndex < nums.size() - 3 && nums[lastIndex] == nums[lastIndex + 1])
					lastIndex++;
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Four_Sum_Model GetTestData001(void)
		{
			Four_Sum_Model result;
			result.nums = { 1,0,-1,0,-2,2};
			result.target = 0;
			return result;//except: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Four_Sum_Model GetTestData002(void)
		{
			Four_Sum_Model result;
			result.nums = { 2,2,2,2,2 };
			result.target = 8;
			return result;//expect:[[2,2,2,2]]
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Four_Sum_Model GetTestData003(void)
		{
			Four_Sum_Model result;
			result.nums = { 0 };
			result.target = 0;
			return result;//expect:[]
		};

		/// <summary>
		/// 測試資料4
		/// </summary>   
		Four_Sum_Model GetTestData004(void)
		{
			Four_Sum_Model result;
			result.nums = { 1000000000, 1000000000, 1000000000, 1000000000 };
			result.target = 0;
			return result;//expect:[]
		};

#pragma endregion TestData

	};
}