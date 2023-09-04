#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution448
{
#pragma region Paste to execute 
	/*
	#include "Easy\0448.Find_All_Numbers_Disappeared_in_an_Array.cpp"
	using namespace Solution448;

	int main()
	{
		Solution448::Find_All_Numbers_Disappeared_in_an_Array useClass;
		Solution448::Find_All_Numbers_Disappeared_in_an_Array::Find_All_Numbers_Disappeared_in_an_Array_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.addStrings(getTestModel.num1);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.addStrings(getTestModel.nums);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// тア计皚
	/// </summary>
	class Find_All_Numbers_Disappeared_in_an_Array
	{
#pragma region Model
	public:
		class Find_All_Numbers_Disappeared_in_an_Array_Model
		{
		public:
			vector<int> nums;			
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          隔 : 肈ヘ璶―ぃノ肂O(n) 丁ゲ斗ノ夹癘皚璽计よΑ程逞タ计ゲア计
		///                 “ノnums 肈ヘ块タ计疭┦ノ璽计
		///       Runtime :  31 ms Beats 98.25 %
		///  Memory Usage :33.8 MB Beats 61.46 %
		/// </summary>
		vector<int> findDisappearedNumbers(vector<int>& nums) {
			vector<int> result{};
			//1. 盢セ皚Τ夹癘璽计
			for (int index = 0; index < nums.size(); index++)
			{
				int positiveVal = abs(nums[index]);
				if (nums[positiveVal - 1] > 0)
					nums[positiveVal - 1] = -nums[positiveVal - 1];
			}
			//2. 逞0ゲ﹚琌簗计
			for (int index = 0; index < nums.size(); index++)
			{
				if (nums[index] > 0)
					result.push_back(index + 1);
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Find_All_Numbers_Disappeared_in_an_Array_Model GetTestData001(void)
		{
			Find_All_Numbers_Disappeared_in_an_Array_Model result;
			result.nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
			return result;//expect : { 5, 6}
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Find_All_Numbers_Disappeared_in_an_Array_Model GetTestData002(void)
		{
			Find_All_Numbers_Disappeared_in_an_Array_Model result;
			result.nums = { 1, 1 };			
			return result;//expect :{2}
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Find_All_Numbers_Disappeared_in_an_Array_Model GetTestData003(void)
		{
			Find_All_Numbers_Disappeared_in_an_Array_Model result;
			result.nums = {5, 4, 6, 7, 9, 3, 10, 9, 5, 6};
			return result;//expect :{1, 2, 8}
		};
		

#pragma endregion TestData
	};
}