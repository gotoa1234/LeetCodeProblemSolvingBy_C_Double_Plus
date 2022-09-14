#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution20
{
#pragma region Paste to execute 
	/*
	#include "0020.Valid_Parentheses.cpp"
	using namespace Solution20;
	using namespace std;

	int main()
	{
		Solution20::Valid_Parentheses useClass;
		Solution20::Valid_Parentheses::Valid_Parentheses_Model getTestModel = useClass.GetTestData001();
		bool result = useClass.isValid(getTestModel.s);

		getTestModel = useClass.GetTestData002();
		result = useClass.isValid(getTestModel.s);

		getTestModel = useClass.GetTestData003();
		result = useClass.isValid(getTestModel.s);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 有效括號
	/// </summary>
	class Valid_Parentheses
	{
#pragma region Model
	public:
		class Valid_Parentheses_Model
		{
		public:
			string s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：
		///      Runtime : 
		/// Memory Usage : 
		/// </summary>
		bool isValid(string s) {
			return false;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Valid_Parentheses_Model GetTestData001(void)
		{
			Valid_Parentheses_Model result;
			result.s = "()";
			return result;//except: true
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Valid_Parentheses_Model GetTestData002(void)
		{
			Valid_Parentheses_Model result;
			result.s = "()[]{}";
			return result;//expect: true
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Valid_Parentheses_Model GetTestData003(void)
		{
			Valid_Parentheses_Model result;
			result.s = "(]";
			return result;//expect: false
		};
#pragma endregion TestData

	};
}