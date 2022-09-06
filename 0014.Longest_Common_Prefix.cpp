#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution14
{
#pragma region Paste to execute 
	/*
	#include "0014.Longest_Common_Prefix.cpp"
    using namespace Solution14;
    using namespace std;
    
    int main()
    {
    	Solution14::Longest_Common_Prefix useClass;
    	Solution14::Longest_Common_Prefix::Longest_Common_Prefix_Model getTestModel = useClass.GetTestData001();
    	string result = useClass.longestCommonPrefix(getTestModel.strs);
    
    	getTestModel = useClass.GetTestData002();
    	result = useClass.longestCommonPrefix(getTestModel.strs);
    
    	return 0;
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 最長共用前綴
	/// </summary>
	class Longest_Common_Prefix
	{
#pragma region Model
	public:
		class Longest_Common_Prefix_Model
		{
		public:
			vector<string> strs;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：利用C++的Sort排序，第一個必定是最小長度，然後對頭尾兩個字串比對char，若都相同則記錄，當不相同時跳出
		///      Runtime :   3 ms, faster than 92.55% of C++ online submissions for Longest Common Prefix.
		/// Memory Usage : 9.2 MB,   less than 83.20% of C++ online submissions for Longest Common Prefix.
		/// </summary>
		string longestCommonPrefix(vector<string>& strs) {
			string result = "";
			short index = 0;
			sort(strs.begin(), strs.end());
			short minLength = strs[0].size();
			for (index = 0; index < strs[0].size(); index++)
			{
				if (strs[0][index] != strs[strs.size() - 1][index])
				{
					break;
				}
				result.push_back(strs[strs.size() - 1][index]);
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Longest_Common_Prefix_Model GetTestData001(void)
		{
			Longest_Common_Prefix_Model result;
			result.strs = { "flo","flsw","floght" };
			return result;//except: "fl"
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Longest_Common_Prefix_Model GetTestData002(void)
		{
			Longest_Common_Prefix_Model result;
			result.strs = { "dog","racecar","car" };
			return result;//expect: ""
		};
#pragma endregion TestData
	};
}