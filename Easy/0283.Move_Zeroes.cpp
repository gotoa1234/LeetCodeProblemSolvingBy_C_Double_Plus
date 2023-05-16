#include <iostream>
#include <vector>
using namespace std;

namespace Solution283
{
#pragma region Paste to execute 
	/*
	#include "Easy\0283.Move_Zeroes.cpp"
	using namespace Solution283;
	using namespace std;

	int main()
	{
		Solution283::Move_Zeroes useClass;
	    Solution283::Move_Zeroes::Move_Zeroes_Model getTestModel = useClass.GetTestData001();
	    useClass.moveZeroes(getTestModel.nums);
	    getTestModel = useClass.GetTestData002();
	    useClass.moveZeroes(getTestModel.nums);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 移動零
	/// </summary>
	class Move_Zeroes
	{
#pragma region Model
	public:
		class Move_Zeroes_Model
		{
		public:
			vector<int> nums;			
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路： 利用一個變數紀錄0出現的次數，每出現一次交換的間隔就增加
		///       Runtime :   20 ms Beats 84.26 %
		///  Memory Usage : 19.2 MB	Beats 83.57 %
		/// </summary>
		void moveZeroes(vector<int>& nums) {
			int zeroCount = 0;
			for (int index = 0; index < nums.size(); index++) 
			{
				if (nums[index]) 
				{
					swap(nums[index], nums[zeroCount]);
					zeroCount++;
				}
			}
		}

	public:
		int _badVersion = 0;
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test1
		/// </summary>        
		Move_Zeroes_Model GetTestData001(void)
		{
			Move_Zeroes_Model result;
			result.nums = {0, 1, 0, 3, 12};
			//0,
			//1, 0
			//1, 
			return result;
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Move_Zeroes_Model GetTestData002(void)
		{
			Move_Zeroes_Model result;
			result.nums = {0};			
			return result;
		};

#pragma endregion TestData
	};
}