#include <iostream>
using namespace std;

namespace Solution392
{
#pragma region Paste to execute 
	/*
	#include "Easy\392.Is_Subsequence.cpp"
	using namespace Solution392;
	using namespace std;

	Solution392::Is_Subsequence useClass;
	Solution392::Is_Subsequence::Is_Subsequence_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.runningSum(getTestModel.nums);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 是否子字串
	/// </summary>
	class Is_Subsequence
	{
#pragma region Model
	public:
		class Is_Subsequence_Model
		{
		public:
			string s;
			string t;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 字串t 必定大於s字串，因此t遍歷，每次用t[0]字元做比對，比對到則移除t[0]，直到t為空表示true，其他狀況都是false
		///       Runtime :   0 ms, faster than 100.00% of C++ online submissions for Is Subsequence.
		///  Memory Usage : 6.4 MB,   less than 69.65 % of C++ online submissions for Is Subsequence.
		/// </summary>
		bool isSubsequence(string s, string t) {
			//遍歷
			for (int index = 0; index < t.size(); index++)
			{
				if (s[0] == t.at(index))//首個字元比對，存在則移除
				{
					s.erase(s.begin());
					if (s.empty())
						break;
				}
			}
			//s全比對到為True 
			return s.empty() ? true : false;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Is_Subsequence_Model GetTestData001(void)
		{
			Is_Subsequence_Model result;
			result.s = "abc";
			result.t = "ahbgdc";
			return result;
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Is_Subsequence_Model GetTestData002(void)
		{
			Is_Subsequence_Model result;
			result.s = "axc";
			result.t = "ahbgdc";
			return result;
		};
#pragma endregion TestData
	};
}