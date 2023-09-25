#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution344
{
#pragma region Paste to execute 
	/*
#include <vector>
#include "Easy\0344.Reverse_String.cpp"
using namespace Solution344;

int main()
{
	Solution344::Reverse_String useClass;
	Solution344::Reverse_String::Reverse_String_Model getTestModel = useClass.GetTestData001();
	useClass.reverseString(getTestModel.s);

	getTestModel = useClass.GetTestData002();
	useClass.reverseString(getTestModel.s);
	return 0;
}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 兩個陣列的交集 2
	/// </summary>
	class Reverse_String
	{
#pragma region Model
	public:
		class Reverse_String_Model
		{
		public:
			vector<char> s;			
		};
#pragma endregion Model

#pragma region Main
	public:
		///          Think :利用第一個索引與最後一個索引做交換，迴圈到一半 n/2 時交換完成
		///        Runtime :   8 ms Beats 97.36 %
		///   Memory Usage :23.6 MB Beats 11.79 %
		/// <returns></returns>
		void reverseString(vector<char>& s) {
			int temp = 0;
			int lastIndex = s.size() - 1;
			for (int index = 0; index <= (s.size() - 1) / 2; index++)
			{
				temp = s[index];
				s[index] = s[lastIndex - index];
				s[lastIndex - index] = temp;
			}
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Reverse_String_Model GetTestData001(void)
		{
			Reverse_String_Model result;
			result.s = { 'h', 'e', 'l','l', 'o' };
			return result;//expect: ["o", "l", "l", "e", "h"]
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Reverse_String_Model GetTestData002(void)
		{
			Reverse_String_Model result;
			result.s = { 'H', 'a', 'n','n', 'a', 'h'};
			return result;//expect:["h", "a", "n", "n", "a", "H"]
		};
#pragma endregion TestData
	};
}