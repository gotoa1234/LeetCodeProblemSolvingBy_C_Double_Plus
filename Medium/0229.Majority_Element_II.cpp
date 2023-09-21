#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

namespace Solution229
{
#pragma region Paste to execute 
	/*
	#include "Medium\0229.Majority_Element_II.cpp"
	using namespace Solution229;
	using namespace std;

	int main()
	{
		vector<vector<int>> result = {};
		Solution229::Majority_Element_II useClass;
		Solution229::Majority_Element_II::Majority_Element_II_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.majorityElement(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.majorityElement(getTestModel.nums);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.majorityElement(getTestModel.nums);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 
	/// </summary>
	class Majority_Element_II
	{
#pragma region Model
	public:
		class Majority_Element_II_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking¡G linear time and in O(1) space?
		///       Runtime¡G
		/// Memory Usage ¡G
		/// </summary>
		vector<int> majorityElement(vector<int>& nums) {
			
			int target = nums.size() / 3 + 1;			
			int count = 0;
			if (count == target)
				return nums;
			
			sort(nums.begin(), nums.end());
			int last = nums[0];
			for (int index = 1; index < nums.size(); index++)
			{
				if (last == nums[index])
				{					
				}			
			}

			return {};
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Majority_Element_II_Model GetTestData001(void)
		{
			Majority_Element_II_Model result;
			result.nums = { 3,2,3 };
			return result;//except: [3]
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Majority_Element_II_Model GetTestData002(void)
		{
			Majority_Element_II_Model result;
			result.nums = { 1 };
			return result;//except: [1]
		};

		/// <summary>
		/// test data 3
		/// </summary>   
		Majority_Element_II_Model GetTestData003(void)
		{
			Majority_Element_II_Model result;
			result.nums = { 1,2 };
			return result;//except: [1, 2]
		};
#pragma endregion TestData

	};
}