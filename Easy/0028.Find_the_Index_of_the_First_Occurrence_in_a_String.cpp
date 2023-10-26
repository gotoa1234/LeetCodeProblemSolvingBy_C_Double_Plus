#include <iostream>
#include <vector>
using namespace std;

namespace Solution28
{
#pragma region Paste to execute 
	/*
	#include "Easy\0028.Find_the_Index_of_the_First_Occurrence_in_a_String.cpp"
	using namespace Solution28;
	using namespace std;

	int main()
	{
		Solution28::Find_the_Index_of_the_First_Occurrence_in_a_String useClass;
		Solution28::Find_the_Index_of_the_First_Occurrence_in_a_String::Find_the_Index_of_the_First_Occurrence_in_a_String_Model getTestModel = useClass.GetTestData001();
		int result = useClass.strStr(getTestModel.haystack, getTestModel.needle);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.strStr(getTestModel.haystack, getTestModel.needle);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 查找字符串中第一次出現的索引
	/// </summary>
	class Find_the_Index_of_the_First_Occurrence_in_a_String
	{
#pragma region Model
	public:
		class Find_the_Index_of_the_First_Occurrence_in_a_String_Model
		{
		public:
			string haystack;
			string needle;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         思路：		
		///      Runtime:   0 ms Beats 100 %
		///Memory Usage : 6.8 MB Beats 17.35 %
		/// </summary>
		int strStr(string haystack, string needle) {
			if (needle.size() == 0)
				return -1;

			int needleMax = needle.size() - 1;
			int moveIndex = 0;
			int result = -1;
			for (int index = 0; (index + needleMax) < haystack.size() && result == -1; index++)
			{
				result = index;
				for (moveIndex = 0;
					moveIndex <= (needleMax - moveIndex);
					moveIndex++)
				{
					if (haystack[index + moveIndex] != needle[moveIndex] ||
						haystack[index + needleMax - moveIndex] != needle[needleMax - moveIndex])
					{
						result = -1;
						break;
					}
				}
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Find_the_Index_of_the_First_Occurrence_in_a_String_Model GetTestData001(void)
		{
			Find_the_Index_of_the_First_Occurrence_in_a_String_Model result;
			result.haystack = "sadbutsad";
			result.needle = "sad";
			return result;//except: 0
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Find_the_Index_of_the_First_Occurrence_in_a_String_Model GetTestData002(void)
		{
			Find_the_Index_of_the_First_Occurrence_in_a_String_Model result;
			result.haystack = "leetcode";
			result.needle = "leeto";
			return result;//expect:-1  did not occur in "leetcode", so we return -1.
		};
#pragma endregion TestData

	};
}