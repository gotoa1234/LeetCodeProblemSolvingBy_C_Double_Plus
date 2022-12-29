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
	/// ��X�̪��^�����
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
		///          ���:��Hash�����C�Ӧr���X�{�����ơA�^��2�Ӭ��@��A�̫�Y��J�r��j��p��^�媺���G
		///               ��ܥ��w���ӿW�ߪ��r���i�@���^�夤�߭n�A+1�C
		///      Runtime :   0 ms, faster than 100.00% of C++ online submissions for Longest Palindrome.
		/// Memory Usage : 6.7 MB,   less than 49.99 % of C++ online submissions for Longest Palindrome.
		/// </summary>
		int longestPalindrome(string s) {
			//1. ��X�r�������P�ƶq
			unordered_map<char, int> hashMap;
			for (int index = 0; index < s.size(); index++)
			{
				hashMap[s[index]]++;
			}
			int result = 0;

			//2. ��X���諸�r��
			for (auto item = hashMap.begin(); item != hashMap.end(); item++)
			{
				result += (item->second / 2) * 2;
			}
			//3. ���i�H�W�ߪ��r����������
			return result < s.size() ? result + 1 : result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Longest_Palindrome_Model GetTestData001(void)
		{
			Longest_Palindrome_Model result;
			result.s = "abccccdd";
			return result;
		};

		/// <summary>
		/// ���ո��2
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