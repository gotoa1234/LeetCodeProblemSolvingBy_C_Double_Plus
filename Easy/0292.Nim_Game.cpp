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
	/// nim �C��
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
		///          ��� : �u����ت��A1.�p��4���ɭԥ��w���a�ӧQ 2.�_�h�u�nn��㰣4���O���a��A�o�O�@�ӥ����u�ժ��C���A��75%�H�W����Ӿ��v
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
		/// ���ո��1
		/// </summary>        
		Nim_Game_Model GetTestData001(void)
		{
			Nim_Game_Model result;
			result.n = 4;			
			return result;//expect : false
		};

		/// <summary>
		/// ���ո��2
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