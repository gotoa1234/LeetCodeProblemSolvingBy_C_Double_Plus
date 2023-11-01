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
    
    
    	getTestModel = useClass.GetTestData003();
    	auto result3 = useClass.strStr(getTestModel.haystack, getTestModel.needle);
    
    	getTestModel = useClass.GetTestData004();
    	auto result4 = useClass.strStr(getTestModel.haystack, getTestModel.needle);
    
    	getTestModel = useClass.GetTestData005();
    	auto result5 = useClass.strStr(getTestModel.haystack, getTestModel.needle);
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
		///         思路：先找出PMT(Partial Match Table)，然後利用KMP演算法找出子字串 
		///               時間複雜度 O(m + n)
		///      Runtime:  0 ms Beats 100 %
		///Memory Usage :6.8 MB Beats 8.67 %
		/// </summary>
		int strStr(string haystack, string needle) {
			//Inner Method ： PMT
			//1. 從PMT 取得Pattern 的關係Index
			auto GetPartialMatchTable = [](string pattern) {
				vector<int> pmtResult(pattern.size(), 0);
				int findIndex = 0;
				for (int index = 1; index < pattern.size();)
				{
					if (pattern[index] == pattern[findIndex]) {
						pmtResult[index] = findIndex + 1;
						findIndex++;
						index++;
					}
					else {
						if (findIndex == 0) {
							pmtResult[index] = 0;
							index++;
						}
						else findIndex = pmtResult[findIndex - 1];
					}
				}
				return pmtResult;
			};

			//Main Method ： KMP
			//2. 取得PMT
		    auto pmt = GetPartialMatchTable(needle);	
			int index = 0, matchCount = 0;
			//3. 開始比對pattern 與 輸入字串
			while (index < haystack.size()) {
				//4-1. 相同累進+1
				if (needle[matchCount] == haystack[index]) {
					index++;
					matchCount++;
				}
				else
				{
					//4-2. 若有不同時，且matchCount=0 索引往前比對
					if (matchCount == 0)
						index++;
					else//4-3. 否則matchCount存在，往PMT關係表更之前的位置比對
						matchCount = pmt[matchCount - 1];
				}
				//5. 若找到長度相同時，則可以輸出索引位置
				if (matchCount == needle.size())
					return index - matchCount;
			}
			return -1;
		}

		/// <summary>
		/// 暴力搜尋法 O((m-n+1) * n)
		/// </summary>		
		///      Runtime:   0 ms Beats 100 %
		///Memory Usage : 6.8 MB Beats 17.35 %
		int strStr_ForceSovle(string haystack, string needle) {
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

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Find_the_Index_of_the_First_Occurrence_in_a_String_Model GetTestData003(void)
		{
			Find_the_Index_of_the_First_Occurrence_in_a_String_Model result;
			result.haystack = "ABABDABACDABABCABAB";
			result.needle = "ABABCABAB";
			return result;//expect:10
		};

		/// <summary>
		/// 測試資料4
		/// </summary>   
		Find_the_Index_of_the_First_Occurrence_in_a_String_Model GetTestData004(void)
		{
			Find_the_Index_of_the_First_Occurrence_in_a_String_Model result;
			result.haystack = "mississippi";
			result.needle = "issip";
			return result;//expect:4
		};

		/// <summary>
		/// 測試資料5
		/// </summary>   
		Find_the_Index_of_the_First_Occurrence_in_a_String_Model GetTestData005(void)
		{
			Find_the_Index_of_the_First_Occurrence_in_a_String_Model result;
			result.haystack = "aabaaabaaac";
			result.needle = "aabaaac";
			return result;//expect:4
		};
		
#pragma endregion TestData

	};
}