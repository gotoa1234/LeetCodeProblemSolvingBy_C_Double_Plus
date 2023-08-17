#include <iostream>
#include <stack>
#include <string>
using namespace std;

namespace Solution374
{
#pragma region Paste to execute 
	/*
	#include <vector>
	#include "Easy\0374.Guess_Number_Higher_or_Lower_Model.cpp"
	using namespace Solution374;

	int main()
	{
		Solution374::Guess_Number_Higher_or_Lower useClass;
		Solution374::Guess_Number_Higher_or_Lower::Guess_Number_Higher_or_Lower_Model getTestModel = useClass.GetTestData001();
		int result = useClass.isPerfectSquare(getTestModel.num);

		getTestModel = useClass.GetTestData002();
		result = useClass.isPerfectSquare(getTestModel.num);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 
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
		///          Think : 				
		///        Runtime : 
		///   Memory Usage : 
		/// <returns></returns>
		int guessNumber(int n) {
			return {};
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
			result.n = 1;
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