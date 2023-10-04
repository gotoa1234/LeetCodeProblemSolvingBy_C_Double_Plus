#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution541
{
#pragma region Paste to execute 
	/*
	#include "Easy\0541.Reverse_String_II.cpp"
	using namespace Solution541;

	int main()
	{
		Solution541::Reverse_String_II useClass;
		Solution541::Reverse_String_II::Reverse_String_II_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.reverseStr(getTestModel.s,getTestModel.k);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.reverseStr(getTestModel.s,getTestModel.k);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.reverseStr(getTestModel.s,getTestModel.k);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 反轉字串2
	/// </summary>
	class Reverse_String_II
	{
#pragma region Model
	public:
		class Reverse_String_II_Model
		{
		public:
			string s;
			int k;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 題目規定先換 k 然後再換 k*2 個位置的k個字元，因此可用一個O(n)的迴圈完成此題
		///       Runtime :    3 ms Beats 88.58 %
		///  Memory Usage :	 7.7 MB Beats 34.50 %
		/// </summary>
		string reverseStr(string s, int k) {			
			for (int interval = 0; interval < s.size() - 1; interval += (k * 2))
			{
				int removeRange = (k + interval) > s.size() - 1 ? s.size()
					                                            : (k + interval);
				reverse(s.begin() + interval, s.end() - (s.size() - removeRange));
			}
			return s;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Reverse_String_II_Model GetTestData001(void)
		{
			Reverse_String_II_Model result;
			result.s= "abcdefg";
			result.k = 2;
			return result;//expect : bacdfeg
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Reverse_String_II_Model GetTestData002(void)
		{
			Reverse_String_II_Model result;
			result.s = "abcd";
			result.k = 2;
			return result;//expect : bacd
		};

		Reverse_String_II_Model GetTestData003(void)
		{
			Reverse_String_II_Model result;
			result.s = "abcdefg";
			result.k = 8;
			return result;//expect : gfedcba
		};
#pragma endregion TestData
	};
}