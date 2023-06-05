#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

namespace Solution12
{
#pragma region Paste to execute 
	/*
	#include "Medium\0012.Integer_to_Roman.cpp"
	using namespace Solution12;
	using namespace std;

	int main()
	{
		Solution12::Integer_to_Roman useClass;
		Solution12::Integer_to_Roman::Integer_to_Roman_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.intToRoman(getTestModel.num);

		getTestModel = useClass.GetTestData002();
		result = useClass.intToRoman(getTestModel.num);

		getTestModel = useClass.GetTestData003();
		result = useClass.intToRoman(getTestModel.num);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 數字轉羅馬數字
	/// </summary>
	class Integer_to_Roman
	{
#pragma region Model
	public:
		class Integer_to_Roman_Model
		{
		public:
			int num;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：建立一個由大而小的羅馬對應表，逐一將輸入的數值減去為0時完成整個轉換
		///       Runtime:   4 ms Beats 87.49 %
		/// Memory Usage : 9.5 MB Beats 18.9 %
		/// </summary>
		string intToRoman(int num) {
			
			//1. 找出羅馬數字的可能項目，必須由大到小 
			const vector<pair<int, string>> valueSymbols {
				{1000, "M"} , {900, "CM"} , {500, "D"} , {400, "CD"} , {100, "C"} , {90, "XC"} ,
				{50, "L"} , {40, "XL"} , {10, "X"} , {9, "IX"} , {5, "V"} , {4, "IV"} , {1, "I"} 
			};
			string result;

			//2. 將羅馬符號由大而小逐一遍歷
			for (const auto& [value, symbol] : valueSymbols) 
			{
				//3. 遍歷的過程num會不斷減去對應的羅馬數字的值，值到num = 0 ;
				if (num == 0)
					break;
				while (num >= value) 
				{
					num -= value;
					result += symbol;
				}
			}
			//4. 此時轉換完成
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Integer_to_Roman_Model GetTestData001(void)
		{
			Integer_to_Roman_Model result;
			result.num = 3;
			return result;//except: III
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Integer_to_Roman_Model GetTestData002(void)
		{
			Integer_to_Roman_Model result;
			result.num = 58;
			return result;//expect: LVIII
		};

		/// <summary>
		/// test 3
		/// </summary>   
		Integer_to_Roman_Model GetTestData003(void)
		{
			Integer_to_Roman_Model result;
			result.num = 1994;
			return result;//expect: MCMXCIV

		};
#pragma endregion TestData

	};
}