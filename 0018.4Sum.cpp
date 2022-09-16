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
	/// 4�Ӽƭȥ[�`
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
		///          ����G3Sum�������A4sum�ݭn�A�h�T�w�@�Ӧ�m�i��B��C
		///       Runtime:  166 ms, faster than 53.28% of C++ online submissions for 4Sum.
		/// Memory Usage : 12.9 MB,   less than 99.43% of C++ online submissions for 4Sum.
		/// </summary>
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>> result;
			//1. �ư����ؤp��4�Ӫ����p
			if (nums.size() < 4)
				return result;
			sort(nums.begin(), nums.end());
			int middleIndex = 0;
			int rightIndex = 0;
			int tempIndex = 0;
			long long tempSumValue = 0;
			//2. �T�w�Ĥ@�Ӧ�m
			for (int lastIndex = 0; lastIndex < nums.size() - 3; lastIndex++)
			{
				//3. �T�w�ĤG�Ӧ�m�A�M��Q��3Sum���Ѫk
				for (int secondIndex = lastIndex + 1; secondIndex < nums.size() - 2; secondIndex++)
				{
					middleIndex = secondIndex + 1;
					rightIndex = nums.size() - 1;
					while (middleIndex < rightIndex)
					{
						//3-1. �`�N�A�o��4��int�ۥ[���i�෸��A²�氵�k�O��long�Ȧs
						tempSumValue = 0;
						tempSumValue += nums[lastIndex];
						tempSumValue += nums[secondIndex];
						tempSumValue += nums[middleIndex];
						tempSumValue += nums[rightIndex];
						if (tempSumValue == target)//3-2. ����ɬ���
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
		/// ���ո��1
		/// </summary>        
		Four_Sum_Model GetTestData001(void)
		{
			Four_Sum_Model result;
			result.nums = { 1,0,-1,0,-2,2};
			result.target = 0;
			return result;//except: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Four_Sum_Model GetTestData002(void)
		{
			Four_Sum_Model result;
			result.nums = { 2,2,2,2,2 };
			result.target = 8;
			return result;//expect:[[2,2,2,2]]
		};

		/// <summary>
		/// ���ո��3
		/// </summary>   
		Four_Sum_Model GetTestData003(void)
		{
			Four_Sum_Model result;
			result.nums = { 0 };
			result.target = 0;
			return result;//expect:[]
		};

		/// <summary>
		/// ���ո��4
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