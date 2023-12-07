#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution205
{
#pragma region Paste to execute 
	/*
	#include "Easy\0205.Isomorphic_Strings.cpp"
    using namespace Solution205;
    using namespace std;

	Solution205::Isomorphic_Strings useClass;
	Solution205::Isomorphic_Strings::Isomorphic_Strings_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.isIsomorphic(getTestModel.s, getTestModel.s);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 同構造字串 (兩個字串每個字元結構是否相同，相當於凱薩密碼)
	/// </summary>
	class Isomorphic_Strings
	{
#pragma region Model
	public:
		class Isomorphic_Strings_Model
		{
		public:
			string s;
			string t;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 長度檢核 => 兩個字元對應紀錄 => 已存在紀錄中則比對
		///       Runtime :   4 ms, faster than 91.45% of C++ online submissions for Isomorphic Strings.
		///  Memory Usage : 6.9 MB,   less than 74.74% of C++ online submissions for Isomorphic Strings.
		/// </summary>
		bool isIsomorphic(string s, string t) {
			//檢核長度
			if (s.size() != t.size())
				return false;
			//兩個Hash紀錄對應
			unordered_map<int, int> sHashTable;
			unordered_map<int, int> tHashTable;
			for (int index = 0; index < s.size(); index++)
			{
				//兩邊未發現的字元就建立
				if (sHashTable.find(s[index]) == sHashTable.end() &&
				    tHashTable.find(t[index]) == tHashTable.end()
					)
				{
					sHashTable[s[index]] = t[index];
				    tHashTable[t[index]] = s[index];
					continue;
				}
				
				//已存在字元時進行檢核
				if (sHashTable[s[index]] != t[index] ||
					tHashTable[t[index]] != s[index])
				{
					return false;
				}
			}
			return true;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Isomorphic_Strings_Model GetTestData001(void)
		{
			Isomorphic_Strings_Model result;
			result.s = "badc";
			result.t = "baba";
			return result;
		};
		/// <summary>
		/// 測試資料2
		/// </summary>   
		Isomorphic_Strings_Model GetTestData002(void)
		{
			Isomorphic_Strings_Model result;
			result.s = "foo";
			result.t = "bar";
			return result;
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Isomorphic_Strings_Model GetTestData003(void)
		{
			Isomorphic_Strings_Model result;
			result.s = "paper";
			result.t = "title";
			return result;
		};
#pragma endregion TestData
	};
}