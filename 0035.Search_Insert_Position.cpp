#include <iostream>
#include <vector>
using namespace std;

namespace Solution35
{
#pragma region Paste to execute 
	/*
	#include "0035.Search_Insert_Position.cpp"
	using namespace Solution35;
	using namespace std;

	int main()
	{
		Solution35::Search_Insert_Position useClass;
		Solution35::Search_Insert_Position::Search_Insert_Position_Model getTestModel = useClass.GetTestData001();
		vector<int> result = useClass.searchRange(getTestModel.nums, getTestModel.target);

		getTestModel = useClass.GetTestData002();
		result = useClass.searchRange(getTestModel.nums, getTestModel.target);

		getTestModel = useClass.GetTestData003();
		result = useClass.searchRange(getTestModel.nums, getTestModel.target);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 在旋轉排序數組中搜索
	/// </summary>
	class Search_Insert_Position
	{
#pragma region Model
	public:
		class Search_Insert_Position_Model
		{
		public:
			vector<int> nums;
			int target;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 
		///      Runtime： 
		///Memory Usage ： 
		/// </summary>
		int searchInsert(vector<int>& nums, int target) {
			return 0;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Search_Insert_Position_Model GetTestData001(void)
		{
			Search_Insert_Position_Model result;
			result.nums = { 1,3,5,6 };
			result.target = 5;
			return result;//except: 1
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Search_Insert_Position_Model GetTestData002(void)
		{
			Search_Insert_Position_Model result;
			result.nums = { 1,3,5,6 };
			result.target = 2;
			return result;//except: 1
		};

		/// <summary>
		/// test data 3
		/// </summary>   
		Search_Insert_Position_Model GetTestData003(void)
		{
			Search_Insert_Position_Model result;
			result.nums = { 1,3,5,6 };
			result.target = 7;
			return result;//except: 4
		};
#pragma endregion TestData

	};
}