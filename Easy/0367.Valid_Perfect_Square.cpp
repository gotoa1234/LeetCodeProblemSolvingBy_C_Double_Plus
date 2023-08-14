#include <iostream>
#include <stack>
#include <string>
using namespace std;

namespace Solution367
{
#pragma region Paste to execute 
	/*
	#include <vector>
	#include "Easy\0367.Valid_Perfect_Square_Model.cpp"
	using namespace Solution367;

	int main()
	{
		Solution367::Valid_Perfect_Square useClass;
		Solution367::Valid_Perfect_Square::Valid_Perfect_Square_Model getTestModel = useClass.GetTestData001();
		int result = useClass.isPerfectSquare(getTestModel.num);

		getTestModel = useClass.GetTestData002();
		result = useClass.isPerfectSquare(getTestModel.num);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 驗證完美正方形
	/// </summary>
	class Valid_Perfect_Square
	{
#pragma region Model
	public:
		class Valid_Perfect_Square_Model
		{
		public:
			int num;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          Think : 利用數學的特性，在一個完美正方形有以下規則，因此用一個奇數每次累加2並且減去輸入值，若為0表示完美正方形
		///                 1 -> 4 -> 9 -> 16 -> 25 -> 36 -> 49
		///          累加值    3    5    7     9     11    13
		///        Runtime : 0 ms Beats 100 %
		///   Memory Usage : 6 MB Beats 33.33 %
		/// <returns></returns>
		bool isPerfectSquare(int num) {
			for (int oddValue = 1; num > 0; oddValue += 2)			
				num -= oddValue;			
			return num == 0;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Valid_Perfect_Square_Model GetTestData001(void)
		{
			Valid_Perfect_Square_Model result;
			result.num = 16;
			return result;//expect:true
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Valid_Perfect_Square_Model GetTestData002(void)
		{
			Valid_Perfect_Square_Model result;
			result.num = 14;
			return result;//expect:false
		};

#pragma endregion TestData
	};
}