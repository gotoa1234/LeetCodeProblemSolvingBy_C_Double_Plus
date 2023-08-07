#include <iostream>
#include <stack>
#include <string>
using namespace std;

namespace Solution345
{
#pragma region Paste to execute 
	/*
	#include <vector>
	#include "Easy\0345.Reverse_Vowels_of_a_String.cpp"
	using namespace Solution345;

	int main()
	{
		Solution345::Reverse_Vowels_of_a_String useClass;
		Solution345::Reverse_Vowels_of_a_String::Reverse_Vowels_of_a_String_Model getTestModel = useClass.GetTestData001();
		int result = useClass.decodeString(getTestModel.s);

		getTestModel = useClass.GetTestData002();
		result = useClass.decodeString(getTestModel.s);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 反轉元音字串
	/// </summary>
	class Reverse_Vowels_of_a_String
	{
#pragma region Model
	public:
		class Reverse_Vowels_of_a_String_Model
		{
		public:
			string s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///           Think：
		///        Runtime : 
		///   Memory Usage : 		
		/// <returns></returns>
		string reverseVowels(string s) {
			int leftIndex = 0;
			int rightIndex = s.size() - 1;

			while (leftIndex < rightIndex)
			{
				while (!(s[leftIndex] == 'a' || 
					     s[leftIndex] == 'A' || 
					     s[leftIndex] == 'e' || 
					     s[leftIndex] == 'E' ||
					     s[leftIndex] == 'I' ||
					     s[leftIndex] == 'i' ||
					     s[leftIndex] == 'O' ||
					     s[leftIndex] == 'o' ||
					     s[leftIndex] == 'U' ||
					     s[leftIndex] == 'u'
					  ))
				{
					leftIndex++;					
				}

				while (!(s[rightIndex] == 'a' ||
					s[rightIndex] == 'A' ||
					s[rightIndex] == 'e' ||
					s[rightIndex] == 'E' ||
					s[rightIndex] == 'I' ||
					s[rightIndex] == 'i' ||
					s[rightIndex] == 'O' ||
					s[rightIndex] == 'o' ||
					s[rightIndex] == 'U' ||
					s[rightIndex] == 'u'
					))
				{
					rightIndex--;
				}

				if (leftIndex < rightIndex)
				{
					auto temp = s[leftIndex];
					s[leftIndex] = s[rightIndex];
					s[rightIndex] = temp;
				}
			}
			return s;
		}


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Reverse_Vowels_of_a_String_Model GetTestData001(void)
		{
			Reverse_Vowels_of_a_String_Model result;
			result.s = "hello";
			return result;//expect:"holle"
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Reverse_Vowels_of_a_String_Model GetTestData002(void)
		{
			Reverse_Vowels_of_a_String_Model result;
			result.s = "leetcode";
			return result;//expect:"leotcede"
		};

#pragma endregion TestData
	};
}