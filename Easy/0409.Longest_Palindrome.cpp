#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution409
{
#pragma region Paste to execute 
	/*
	#include "0409.Longest_Palindrome.cpp"
	using namespace Solution409;
	using namespace std;

	Solution409::Longest_Palindrome useClass;
	Solution409::Longest_Palindrome::Longest_Palindrome_Model getTestModel = useClass.GetTestData001();
	int result = useClass.longestPalindrome(getTestModel.s);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 找出最長回文長度
	/// </summary>
	class Longest_Palindrome
	{
#pragma region Model
	public:
		class Longest_Palindrome_Model
		{
		public:
			string s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路:用Hash紀錄每個字元出現的次數，回文2個為一對，最後若輸入字串大於計算回文的結果
		///               表示必定有個獨立的字元可作為回文中心要再+1。
		///      Runtime :   0 ms, faster than 100.00% of C++ online submissions for Longest Palindrome.
		/// Memory Usage : 6.7 MB,   less than 49.99 % of C++ online submissions for Longest Palindrome.
		/// </summary>
		int longestPalindrome(string s) {
			//1. 找出字元種類與數量
			unordered_map<char, int> hashMap;
			for (int index = 0; index < s.size(); index++)
			{
				hashMap[s[index]]++;
			}
			int result = 0;

			//2. 找出成對的字元
			for (auto item = hashMap.begin(); item != hashMap.end(); item++)
			{
				result += (item->second / 2) * 2;
			}
			//3. 有可以獨立的字元做為中心
			return result < s.size() ? result + 1 : result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Longest_Palindrome_Model GetTestData001(void)
		{
			Longest_Palindrome_Model result;
			result.s = "abccccdd";
			return result;
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Longest_Palindrome_Model GetTestData002(void)
		{
			Longest_Palindrome_Model result;
			result.s = "a";
			return result;
		};
#pragma endregion TestData
	};
}