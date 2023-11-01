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
	/// �d��r�Ŧꤤ�Ĥ@���X�{������
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
		///         ����G����XPMT(Partial Match Table)�A�M��Q��KMP�t��k��X�l�r�� 
		///               �ɶ������� O(m + n)
		///      Runtime:  0 ms Beats 100 %
		///Memory Usage :6.8 MB Beats 8.67 %
		/// </summary>
		int strStr(string haystack, string needle) {
			//Inner Method �G PMT
			//1. �qPMT ���oPattern �����YIndex
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

			//Main Method �G KMP
			//2. ���oPMT
		    auto pmt = GetPartialMatchTable(needle);	
			int index = 0, matchCount = 0;
			//3. �}�l���pattern �P ��J�r��
			while (index < haystack.size()) {
				//4-1. �ۦP�ֶi+1
				if (needle[matchCount] == haystack[index]) {
					index++;
					matchCount++;
				}
				else
				{
					//4-2. �Y�����P�ɡA�BmatchCount=0 ���ީ��e���
					if (matchCount == 0)
						index++;
					else//4-3. �_�hmatchCount�s�b�A��PMT���Y��󤧫e����m���
						matchCount = pmt[matchCount - 1];
				}
				//5. �Y�����׬ۦP�ɡA�h�i�H��X���ަ�m
				if (matchCount == needle.size())
					return index - matchCount;
			}
			return -1;
		}

		/// <summary>
		/// �ɤO�j�M�k O((m-n+1) * n)
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
		/// ���ո��1
		/// </summary>        
		Find_the_Index_of_the_First_Occurrence_in_a_String_Model GetTestData001(void)
		{
			Find_the_Index_of_the_First_Occurrence_in_a_String_Model result;
			result.haystack = "sadbutsad";
			result.needle = "sad";
			return result;//except: 0
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Find_the_Index_of_the_First_Occurrence_in_a_String_Model GetTestData002(void)
		{
			Find_the_Index_of_the_First_Occurrence_in_a_String_Model result;
			result.haystack = "leetcode";
			result.needle = "leeto";
			return result;//expect:-1  did not occur in "leetcode", so we return -1.
		};

		/// <summary>
		/// ���ո��3
		/// </summary>   
		Find_the_Index_of_the_First_Occurrence_in_a_String_Model GetTestData003(void)
		{
			Find_the_Index_of_the_First_Occurrence_in_a_String_Model result;
			result.haystack = "ABABDABACDABABCABAB";
			result.needle = "ABABCABAB";
			return result;//expect:10
		};

		/// <summary>
		/// ���ո��4
		/// </summary>   
		Find_the_Index_of_the_First_Occurrence_in_a_String_Model GetTestData004(void)
		{
			Find_the_Index_of_the_First_Occurrence_in_a_String_Model result;
			result.haystack = "mississippi";
			result.needle = "issip";
			return result;//expect:4
		};

		/// <summary>
		/// ���ո��5
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