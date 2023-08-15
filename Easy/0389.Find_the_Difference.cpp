#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

namespace Solution389
{
#pragma region Paste to execute 
	/*
	#include <vector>
	#include "Easy\0389.Find_the_Difference.cpp"
	using namespace Solution389;

	int main()
	{
		Solution389::Find_the_Difference useClass;
		Solution389::Find_the_Difference::Find_the_Difference_Model getTestModel = useClass.GetTestData001();
		int result = useClass.findTheDifference(getTestModel.s, getTestModel.t);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 找出差異字元
	/// </summary>
	class Find_the_Difference
	{
#pragma region Model
	public:
		class Find_the_Difference_Model
		{
		public:
			string s;
			string t;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          Think :用Xor 或 一維陣列都可以達到0 ms的效能，差異不大
		///        Runtime :  0 ms Beats 100 %
		///   Memory Usage :6.7 MB Beats 56.43 %
		/// <returns></returns>
		char findTheDifference(string s, string t) 
		{
			//好理解版本，用一維陣列放進每個字母，最後看哪個字母不是0 就是有差異的字母			
			vector<int> charTable(26, 0);
			for (int index = 0; index < s.size(); index++)
			{
				charTable[s[index] - 97]++;
				charTable[t[index] - 97]--;				
			}
			charTable[t[t.size() - 1] - 97]--;
			for (int index  =0 ; index < charTable.size(); index++)
			{
				if (charTable[index] != 0)
					return index + 97;
			}
			return ' ';
		}

		char Resolve(string s, string t)
		{
			//邏輯閘版本 用 xor 每個值都走過，最後的值就是有差異的字母
			int temp = 0;
			for (int index = 0; index < s.size(); index++)
			{
				temp ^= s[index];
				temp ^= t[index];
			}
			temp ^= t[t.size() - 1];
			return temp;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Find_the_Difference_Model GetTestData001(void)
		{
			Find_the_Difference_Model result;
			result.s = "abcd";
			result.t = "abcde";
			return result;//expect:e
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Find_the_Difference_Model GetTestData002(void)
		{
			Find_the_Difference_Model result;
			result.s = "";
			result.t = "y";
			return result;//expect:y
		};
		//expect : t   why:q
#pragma endregion TestData
	};
}