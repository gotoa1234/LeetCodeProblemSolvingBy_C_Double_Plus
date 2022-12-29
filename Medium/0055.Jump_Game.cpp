#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution55
{
#pragma region Paste to execute 
	/*
	#include "0055.Jump_Game.cpp"
	using namespace Solution55;
	using namespace std;

	int main()
	{
		Solution55::Jump_Game useClass;
		Solution55::Jump_Game::Jump_Game_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.canJump(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.canJump(getTestModel.nums);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.canJump(getTestModel.nums);

		getTestModel = useClass.GetTestData004();
		auto result4 = useClass.canJump(getTestModel.nums);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 跳躍遊戲
	/// </summary>
	class Jump_Game
	{
#pragma region Model
	public:
		class Jump_Game_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 每次將當前步數可走最大步數更新，每走一步遞減，若當下的索引 nums[Index] 可以到終點表示正確
		///                Time：O(n)  Space：O(1)
		///       Runtime：  63 ms Beats 97.49 %
		/// Memory Usage ：48.3 MB Beats 93.68 %
		/// </summary>	
		bool canJump(vector<int>& nums)
		{
			//1. 尚餘可用最大步數
			int maxStep = 0;
			//2. O(n) 每往前一步最大步數會減1，但離終點 (nums.size() - 1)越接近
			for (int index = 0, maxStep = 0; index < nums.size() && maxStep > -1; index++, maxStep--)
			{
				//3. 如果可跳躍距離增加則可更新最大長度
				maxStep = max(nums[index], maxStep);
				//4. 判斷當前步數是否可以直接到終點
				if (nums[index] + index >= nums.size() - 1)
					return true;
			}
			//沒有辦法到終點
			return false;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Jump_Game_Model GetTestData001(void)
		{
			Jump_Game_Model result;
			result.nums = { 2,3,1,1,4 };
			return result;//except: true
		};

		/// <summary>
		/// test data 2
		/// </summary>        
		Jump_Game_Model GetTestData002(void)
		{
			Jump_Game_Model result;
			result.nums = { 3,2,1,0,4 };
			return result;//except: false
		};

		/// <summary>
		/// test data 3
		/// </summary>        
		Jump_Game_Model GetTestData003(void)
		{
			Jump_Game_Model result;
			result.nums = { 2, 0, 0 };
			return result;//except: true
		};

		/// <summary>
		/// test data 4
		/// </summary>        
		Jump_Game_Model GetTestData004(void)
		{
			Jump_Game_Model result;
			result.nums = { 0 };
			return result;//except: true
		};
#pragma endregion TestData

	};
}
