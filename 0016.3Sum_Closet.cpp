#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution16
{
#pragma region Paste to execute 
	/*
	#include "0016.3Sum_Closet.cpp"
	using namespace Solution16;
	using namespace std;

	int main()
	{
		Solution16::Three_Sum_Closet useClass;
		Solution16::Three_Sum_Closet::Three_Sum_Closet_Model getTestModel = useClass.GetTestData001();
		int result = useClass.threeSumClosest(getTestModel.nums, getTestModel.target);

		getTestModel = useClass.GetTestData002();
		result = useClass.threeSumClosest(getTestModel.nums, getTestModel.target);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 3Sum Closet
	/// </summary>
	class Three_Sum_Closet
	{
#pragma region Model
	public:
		class Three_Sum_Closet_Model
		{
		public:
			vector<int> nums;
			int target;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：同0015. 只是判斷的地方要用絕對值來取當前距離
		///      Runtime :  426 ms, faster than  57.20% of C++ online submissions for Remove Nth Node From End of List.
		/// Memory Usage : 16.2 MB,   less than  84.47% of C++ online submissions for Remove Nth Node From End of List.
		/// </summary>
		int threeSumClosest(vector<int>& nums, int target) {
			int distance = 10001;//10^4 = 10000
			int result = 10001;
			int tempDistance = 0;
			int middleIndex = 0;
			int rightIndex = 0;
			sort(nums.begin(), nums.end());
			for (int index = 0; index < nums.size(); index++)
			{
				middleIndex = index + 1;
				rightIndex = nums.size() - 1;
				while (middleIndex < rightIndex)
				{
					tempDistance = abs(target - (nums[index] + nums[middleIndex] + nums[rightIndex]));
					if (tempDistance < distance)
					{
						distance = tempDistance;
						result = nums[index] + nums[middleIndex] + nums[rightIndex];

						if (result == target)
						{
							return result;
						}
					}
					else if (nums[index] + nums[middleIndex] + nums[rightIndex] < target)
						middleIndex++;
					else
						rightIndex--;
				}
				while (index + 1 < nums.size() && nums[index] == nums[index + 1])
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
		Three_Sum_Closet_Model GetTestData001(void)
		{
			Three_Sum_Closet_Model result;
			result.nums = { -1,2,1,-4 };
			result.target = 1;
			return result;//except: 2
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Three_Sum_Closet_Model GetTestData002(void)
		{
			Three_Sum_Closet_Model result;
			result.nums = { 0,0,0 };
			result.target = 1;
			return result;//expect: 0
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Three_Sum_Closet_Model GetTestData003(void)
		{
			Three_Sum_Closet_Model result;
			result.nums = { 0,1,2 };
			result.target = 3;
			return result;//expect: 3
		};
#pragma endregion TestData

	};
}