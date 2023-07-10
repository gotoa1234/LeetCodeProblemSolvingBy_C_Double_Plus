#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution228
{
#pragma region Paste to execute 
	/*
	#include "Easy/0228.Summary_Ranges.cpp"
	using namespace Solution228;
	using namespace std;

	Solution228::Summary_Ranges useClass;
	Solution228::Summary_Ranges::Summary_Ranges_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.summaryRanges(getTestModel.nums);

	Solution228::Summary_Ranges::Summary_Ranges_Model getTestModel = useClass.GetTestData001();
	auto result2 = useClass.summaryRanges(getTestModel.nums);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �K�n�d��
	/// </summary>
	class Summary_Ranges
	{
#pragma region Model
	public:
		class Summary_Ranges_Model
		{
		public:
			vector<int> nums;			
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ��� :�T���ܼư����ު��m�ߡA�C���T�w�Ĥ@�ӯ���(�_�I)�A�M��Q�Υt�~��ӯ��ާP�_�̫��m
		///       Runtime :  0 ms Beats  100 %
		///  Memory Usage :6.8 MB Beats 55.4 %
		/// </summary>
		vector<string> summaryRanges(vector<int>& nums) {			
			vector<string> result{};
			int last = 0;
			for (int start = 0; start < nums.size(); start = last)
			{
				int moveIndex = start;
				for (last = moveIndex + 1; last < nums.size(); moveIndex++, last++)
				{
					if (nums[last] == nums[moveIndex] + 1)
						continue;
					break;
				}
				if (moveIndex == start)
					result.push_back(to_string(nums[start]));
				else
					result.push_back(to_string(nums[start]) + "->" + to_string(nums[moveIndex]));
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Summary_Ranges_Model GetTestData001(void)
		{
			Summary_Ranges_Model result;
			result.nums = { 0,1,2,4,5,7 };			
			return result;//expect :   ["0->2","4->5","7"]
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Summary_Ranges_Model GetTestData002(void)
		{
			Summary_Ranges_Model result;
			result.nums = {-2147483648, -2147483647, 2147483647};
			return result;//expect :  ["0","2->4","6","8->9"]
		};

#pragma endregion TestData
	};
}