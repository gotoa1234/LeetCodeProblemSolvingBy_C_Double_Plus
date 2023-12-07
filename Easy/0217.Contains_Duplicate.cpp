#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution217
{
#pragma region Paste to execute 
	/*
	#include "Easy\0217.Contains_Duplicate.cpp"
	using namespace Solution217;
	using namespace std;

	Solution217::Contains_Duplicate useClass;
	Solution217::Contains_Duplicate::Contains_Duplicate_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.containsDuplicate(getTestModel.nums);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �]�t���ƶ�
	/// </summary>
	class Contains_Duplicate
	{
#pragma region Model
	public:
		class Contains_Duplicate_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ��� : ���Q�αƧǡA�M��b�M���A�Y�i��X���G ���ƧǪ�O�GO(nlogn) + �M����O�GO(N)
		///       Runtime : 120 ms Beats 98.16 %
		///  Memory Usage :57.2 MB Beats 81.32 %
		/// </summary>
		bool containsDuplicate(vector<int>& nums) 
		{
			sort(nums.begin(), nums.end());
			for (int index = 1; index < nums.size(); index++)
			{
				if (nums[index] == nums[index - 1])
					return true;
			}
			return false;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Contains_Duplicate_Model GetTestData001(void)
		{
			Contains_Duplicate_Model result;
			result.nums = { 1,2,3,1 };			
			return result;// expect : true
		};
		/// <summary>
		/// ���ո��2
		/// </summary>   
		Contains_Duplicate_Model GetTestData002(void)
		{
			Contains_Duplicate_Model result;
			result.nums = { 1,2,3,4 };
			return result;// expect : false
		};

		/// <summary>
		/// ���ո��3
		/// </summary>   
		Contains_Duplicate_Model GetTestData003(void)
		{
			Contains_Duplicate_Model result;
			result.nums = { 1,1,1,3,3,4,3,2,4,2 };
			return result;// expect : true
		};
#pragma endregion TestData
	};
}