#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution263
{
#pragma region Paste to execute 
	/*
	#include "Easy\0263.Ugly_Number.cpp"
	using namespace Solution263;

	int main()
	{

		Solution263::Ugly_Number useClass;
		Solution263::Ugly_Number::Ugly_Number_Model getTestModel = useClass.GetTestData001();
		bool result = useClass.isUgly(getTestModel.n);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 醜數
	/// </summary>
	class Ugly_Number
	{
#pragma region Model
	public:
		class Ugly_Number_Model
		{
		public:
			int n;			
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 醜數定義為可以給質因數2,3,5整除的數
		///       Runtime :  0 ms Beats 100 %
		///  Memory Usage :  6 MB Beats 5.6 %
		/// </summary>
		bool isUgly(int n) {
			if (n == 0)
				return false;
			while (n % 2 == 0) n = n / 2;
			while (n % 3 == 0) n = n / 3;
			while (n % 5 == 0) n = n / 5;
			return n == 1;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Ugly_Number_Model GetTestData001(void)
		{
			Ugly_Number_Model result;
			result.n = 6;		
			return result;//expect : true
		};
		/// <summary>
		/// 測試資料2
		/// </summary>   
		Ugly_Number_Model GetTestData002(void)
		{
			Ugly_Number_Model result;
			result.n = 1;			
			return result;//expect : true
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Ugly_Number_Model GetTestData003(void)
		{
			Ugly_Number_Model result;
			result.n = 14;
			return result;//expect : false
		};
#pragma endregion TestData
	};
}