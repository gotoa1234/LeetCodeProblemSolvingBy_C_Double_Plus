#include <iostream>
using namespace std;

namespace Solution292
{
#pragma region Paste to execute 
	/*
	#include "Easy\292.Nim_Game.cpp"
	using namespace Solution292;
	using namespace std;

	Solution292::Nim_Game useClass;
	Solution292::Nim_Game::Nim_Game_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.canWinNim(getTestModel.n);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// nim 遊戲
	/// </summary>
	class Nim_Game
	{
#pragma region Model
	public:
		class Nim_Game_Model
		{
		public:
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 只有兩種狀態1.小於4的時候必定玩家勝利 2.否則只要n能整除4都是玩家輸，這是一個先手優勢的遊戲，有75%以上的獲勝機率
		///       Runtime :   0 ms Beats 100.00 %
		///  Memory Usage : 6.1 MB Beats  48.85 %
		/// </summary>
		bool canWinNim(int n) {
			if (n < 4)
				return true;
			return n % 4 == 0 ? false : true;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Nim_Game_Model GetTestData001(void)
		{
			Nim_Game_Model result;
			result.n = 4;			
			return result;//expect : false
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Nim_Game_Model GetTestData002(void)
		{
			Nim_Game_Model result;
			result.n = 1;			
			return result;//expect: true
		};
#pragma endregion TestData
	};
}