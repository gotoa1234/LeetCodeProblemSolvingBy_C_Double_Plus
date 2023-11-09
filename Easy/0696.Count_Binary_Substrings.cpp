#include <iostream>
#include <vector>
using namespace std;

namespace Solution696
{
#pragma region Paste to execute 
	/*
	#include "Easy\0696.Count_Binary_Substrings.cpp"
	using namespace Solution696;
	using namespace std;

	int main()
	{
		Solution696::Count_Binary_Substrings useClass;
		Solution696::Count_Binary_Substrings::Count_Binary_Substrings_Model getTestModel = useClass.GetTestData001();
		int result = useClass.countBinarySubstrings(getTestModel.s);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.countBinarySubstrings(getTestModel.s);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.countBinarySubstrings(getTestModel.s);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 統計二進制子字符串
	/// </summary>
	class Count_Binary_Substrings
	{
#pragma region Model
	public:
		class Count_Binary_Substrings_Model
		{
		public:
			string s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         思路：題目要求輸入一個字串，裡面的子字串中要同時"包含0與1" 的字元的子字串有多少個
		///               此法為解化後的解，可以先參考 countBinarySubstrings_Solve2
		///      Runtime：  16 ms Beats 93.14 %
		/// Memory Usage：10.8 MB Beats 49.77 %
		/// </summary>
		int countBinarySubstrings(string s) {
			int result = 0;
			int prevMatch = 0;
			int currentMatch = 0;

			for (int index = 0, currentMatch = 1; index < s.length() - 1; index++)
			{				
				if (s[index] == s[index + 1])
					currentMatch++;
				else
				{
					result += min(prevMatch, currentMatch);
					prevMatch = currentMatch;
					currentMatch = 1;
				}
			}
			return result + min(prevMatch, currentMatch);
		}

		/// <summary>
		///         思路：這是一個很好理解的作法，先遍歷一次將每個連續的字元做群集，然後再遍歷一次加總所有的數值	
		///      Runtime：  22 ms Beats 46.88 %
		/// Memory Usage：14.4 MB Beats 10.25 %
		/// </summary>
		int countBinarySubstrings_Solve2(string s) {
			//建立一個群組個數
			vector<int> groups{};
			int addcount = 0;
			for (int index = 0; index < s.size();)
			{		
				addcount = 0;
				int innerIndex = 0;
				for (innerIndex = index;innerIndex < s.size(); innerIndex++)
				{
					if (s[index] == s[innerIndex])
						addcount++;
					else					
						break;
				}
				index = innerIndex;
				groups.push_back(addcount);
			}

			//必定是0的連續數與1的連續數做比對，取兩兩小的，例如 110 就是1個 1100 就會是2個
			//※必須同時出現0與1 才成立
			int result = 0;
			for (int index = 1; index < groups.size(); index++)
			{
				result += min(groups[index - 1], groups[index]);
			}
			return result;
		}


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Count_Binary_Substrings_Model GetTestData001(void)
		{
			Count_Binary_Substrings_Model result;
			result.s = "00110011";			
			return result;//except: 6
			//會有子字串 : "0","00","001","0011","1","11","110","1100","100","1001"
			//有包含0與1 : "001","0011","110","1100","100","1001" 一共6個

		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Count_Binary_Substrings_Model GetTestData002(void)
		{
			Count_Binary_Substrings_Model result;
			result.s = "10101";
			return result;//expect:4
		    //會有子字串 : "","00","001","0011","1","11","110","1100","100","1001"
			//有包含0與1 : "001","0011","110","1100","100","1001" 一共6個
		};


		/// <summary>
		/// 測試資料3
		/// </summary>   
		Count_Binary_Substrings_Model GetTestData003(void)
		{
			Count_Binary_Substrings_Model result;
			result.s = "000111000111";
			return result;//expect:9
		};



#pragma endregion TestData

	};
}