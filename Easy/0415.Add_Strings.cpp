#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution415
{
#pragma region Paste to execute 
	/*
	#include "Easy\0415.Add_Strings.cpp"
	using namespace Solution415;

	int main()
	{
		Solution415::Add_Strings useClass;
		Solution415::Add_Strings::Add_Strings_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.addStrings(getTestModel.num1, getTestModel.num2);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.addStrings(getTestModel.num1, getTestModel.num2);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.addStrings(getTestModel.num1, getTestModel.num2);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 字串相加
	/// </summary>
	class Add_Strings
	{
#pragma region Model
	public:
		class Add_Strings_Model
		{
		public:
			string num1;
			string num2;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 :題目要求不可以用整數轉型，因此用一個字串做相加，最後Reverse()字串即完成
		///       Runtime :  0 ms Beats   100 %
		///  Memory Usage :6.6 MB Beats 80.36 %
		/// </summary>
		string addStrings(string num1, string num2) {
			int num1Count = num1.size() - 1;
			int num2Count = num2.size() - 1;
			string result{};
			int carry = 0;
			while (num1Count >= 0 || num2Count >= 0)
			{
				int current = carry;
				if (num1Count >= 0)
				{
					current += num1[num1Count] - 48;
					num1Count--;
				}
				if (num2Count >= 0)
				{
					current += num2[num2Count] - 48;
					num2Count--;
				}
				carry = current / 10;
				result.push_back( (current % 10) + 48);
			}
			if (carry > 0)			
				result.push_back(carry + 48);
			reverse(result.begin(), result.end());
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Add_Strings_Model GetTestData001(void)
		{
			Add_Strings_Model result;
			result.num1 = "11";
			result.num2 = "123";
			return result;//expect :"134"
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Add_Strings_Model GetTestData002(void)
		{
			Add_Strings_Model result;
			result.num1 = "456";
			result.num2 = "77";
			return result;//expect :533
		};
		/// <summary>
		/// test 3
		/// </summary>   
		Add_Strings_Model GetTestData003(void)
		{
			Add_Strings_Model result;
			result.num1 = "0";
			result.num2 = "0";
			return result;//expect : 0
		};
#pragma endregion TestData
	};
}