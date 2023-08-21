#include <iostream>
#include <stack>
#include <string>
using namespace std;

namespace Solution374
{
#pragma region Paste to execute 
	/*
	#include <vector>
	#include "Easy\0374.Guess_Number_Higher_or_Lower.cpp"
	using namespace Solution374;

	int main()
	{
		Solution374::Guess_Number_Higher_or_Lower useClass;
		Solution374::Guess_Number_Higher_or_Lower::Guess_Number_Higher_or_Lower_Model getTestModel = useClass.GetTestData001();
		useClass.SetPick(getTestModel.pick);
		auto result1 = useClass.guessNumber(getTestModel.n);

		getTestModel = useClass.GetTestData002();
		useClass.SetPick(getTestModel.pick);
		auto result2 = useClass.guessNumber(getTestModel.n);

		getTestModel = useClass.GetTestData003();
		useClass.SetPick(getTestModel.pick);
		auto result3 = useClass.guessNumber(getTestModel.n);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �q���Ʀr���٬O��C
	/// </summary>
	class Guess_Number_Higher_or_Lower
	{
#pragma region Model
	public:
		class Guess_Number_Higher_or_Lower_Model
		{
		public:
			int n;
			int pick;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          Think : �Q�ΤG���j�M�k��X����			
		///        Runtime : 0 ms Beats 100 %
		///   Memory Usage : 6 MB Beats 45.23 %
		/// <returns></returns>
		
		int guessNumber(int n) {
			int left = 0;
			int right = INT_MAX;			
			while (guess(n) != 0)
			{
				if (guess(n) == -1)
				{
					right = n;
				}
				else
				{
					left = n;
				}	
				n = left + (right - left) / 2;
			}			
			return n;
		}

		//�H�U�N�X�O���æbLeetCode�������A�ڭ̥u�n�t�d�I�sguess(int n) ��k
		int _pick = 0;
		void SetPick(int pick)
		{
			_pick = pick;
		}

		int guess(int n)
		{
			if (n == _pick)
				return 0;
			else if (n > _pick)
				return -1;
			else
				return 1;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Guess_Number_Higher_or_Lower_Model GetTestData001(void)
		{
			Guess_Number_Higher_or_Lower_Model result;
			result.n = 10;
			result.pick = 6;
			return result;//expect:6
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Guess_Number_Higher_or_Lower_Model GetTestData002(void)
		{
			Guess_Number_Higher_or_Lower_Model result;
			result.n = 1;
			result.pick = 1;
			return result;//expect:1
		};

		/// <summary>
		/// test 3
		/// </summary>   
		Guess_Number_Higher_or_Lower_Model GetTestData003(void)
		{
			Guess_Number_Higher_or_Lower_Model result;
			result.n = 2;
			result.pick = 1;
			return result;//expect:1
		};

#pragma endregion TestData
	};
}