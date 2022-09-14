#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution17
{
#pragma region Paste to execute 
	/*
    #include "0017.Letter_Combinations_of_a_Phone_Number.cpp"
    using namespace Solution17;
    using namespace std;
    
    int main()
    {
    	Solution17::Three_Sum_Closet useClass;
    	Solution17::Three_Sum_Closet::Letter_Combinations_of_a_Phone_Number_Model getTestModel = useClass.GetTestData001();
    	vector<string> result = useClass.letterCombinations(getTestModel.digits);
    
    	getTestModel = useClass.GetTestData002();
    	vector<string> result = useClass.letterCombinations(getTestModel.digits);
    
    	getTestModel = useClass.GetTestData003();
    	vector<string> result = useClass.letterCombinations(getTestModel.digits);
    
    	return 0;
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 電話號碼的字母組合
	/// </summary>
	class Three_Sum_Closet
	{
#pragma region Model
	public:
		class Letter_Combinations_of_a_Phone_Number_Model
		{
		public:
			string digits;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：
		///      Runtime : 
		/// Memory Usage : 
		/// </summary>
		vector<string> letterCombinations(string digits) {
			return {""};
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Letter_Combinations_of_a_Phone_Number_Model GetTestData001(void)
		{
			Letter_Combinations_of_a_Phone_Number_Model result;
			result.digits = "23";
			return result;//except: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Letter_Combinations_of_a_Phone_Number_Model GetTestData002(void)
		{
			Letter_Combinations_of_a_Phone_Number_Model result;
			result.digits = "";
			return result;//expect: []
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Letter_Combinations_of_a_Phone_Number_Model GetTestData003(void)
		{
			Letter_Combinations_of_a_Phone_Number_Model result;
			result.digits = "2";
			return result;//expect: ["a","b","c"]
		};
#pragma endregion TestData

	};
}