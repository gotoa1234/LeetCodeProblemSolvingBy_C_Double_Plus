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
			int distance = INT_MAX;
			int result = INT_MAX;
			sort(nums.begin(), nums.end());
			int middleIndex = 0;
			int rightIndex = 0;
			int tempDistance = 0;
			for (int index = 0; index < nums.size() - 1; index++)
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
							return result;
					}
					if (nums[index] + nums[middleIndex] + nums[rightIndex] < target)
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

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Three_Sum_Closet_Model GetTestData004(void)
		{
			Three_Sum_Closet_Model result;
			result.nums = { -43,57,-71,47,3,30,-85,6,60,-59,0,-46,-40,-73,53,68,-82,-54,88,73,20,-89,-22,39,55,-26,95,-87,-57,-86,28,-37,43,-27,-24,-88,-35,82,-3,39,-85,-46,37,45,-24,35,-49,-27,-96,89,87,-62,85,-44,64,78,14,59,-55,-10,0,98,50,-75,11,97,-72,85,-68,-76,44,-12,76,76,8,-75,-64,-57,29,-24,27,-3,-45,-87,48,10,-13,17,94,-85,11,-42,-98,89,97,-66,66,88,-89,90,-68,-62,-21,2,37,-15,-13,-24,-23,3,-58,-9,-71,0,37,-28,22,52,-34,24,-8,-20,29,-98,55,4,36,-3,-9,98,-26,17,82,23,56,54,53,51,-50,0,-15,-50,84,-90,90,72,-46,-96,-56,-76,-32,-8,-69,-32,-41,-56,69,-40,-25,-44,49,-62,36,-55,41,36,-60,90,37,13,87,66,-40,40,-35,-11,31,-45,-62,92,96,8,-4,-50,87,-17,-64,95,-89,68,-51,-40,-85,15,50,-15,0,-67,-55,45,11,-80,-45,-10,-8,90,-23,-41,80,19,29,7,255 };
			result.target = 255;
			return result;//expect: 255
		};
#pragma endregion TestData

	};
}