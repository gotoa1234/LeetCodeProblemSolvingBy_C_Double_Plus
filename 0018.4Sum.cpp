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
		vector<vector<int>> result = useClass.fourSum(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		result = useClass.fourSum(getTestModel.nums);

		getTestModel = useClass.GetTestData003();
		result = useClass.fourSum(getTestModel.nums);
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
		///          思路：
		///      Runtime:  
		/// Memory Usage : 
		/// </summary>
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>> result;
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
			result.nums = { 0,1,1 };
			result.target = 8;
			return result;//expect:[[2,2,2,2]]
		};
#pragma endregion TestData

	};
}