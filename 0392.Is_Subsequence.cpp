#include <iostream>
#include <vector>
using namespace std;

namespace Solution392
{
#pragma region Paste to execute 
	/*
	#include "392.Is_Subsequence.cpp"
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
		///          思路：
		///      Runtime : 
		/// Memory Usage : 
		/// </summary>
		bool isSubsequence(string s, string t) {
			for (int index = 0; index < t.size(); index++)
			{
				if (s[0] == t.at(index))
				{
					s.erase(s.begin());
					if (s.empty())
						break;
				}
			}
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