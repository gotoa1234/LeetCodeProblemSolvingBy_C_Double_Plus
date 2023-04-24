#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution242
{
#pragma region Paste to execute 
	/*
    #include "Easy\0242.Valid_Anagram.cpp"
    using namespace Solution242;
    
    int main()
    {
    
    	Solution242::Valid_Anagram useClass;
    	Solution242::Valid_Anagram::Valid_Anagram_Model getTestModel = useClass.GetTestData001();
    	bool result = useClass.isAnagram(getTestModel.s, getTestModel.s);
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 有效的字謎
	/// </summary>
	class Valid_Anagram
	{
#pragma region Model
	public:
		class Valid_Anagram_Model
		{
		public:
			string s;
			string t;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 這邊是包含可分辨Unicode字元的寫法，如果不考慮unicode直接用vector<int>效能會提升很多
		///      加分問題 : Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
		///                 包含其他字元的解法。
		///       Runtime :   8 ms Beats 75.50 %
		///  Memory Usage : 7.4 MB Beats 60.39 %
		/// </summary>
		bool isAnagram(string s, string t) {
			if (s.size() != t.size())
				return false;			
			unordered_map<char, int> recordHashTable{};
			//1. 紀錄每個字元的筆數，t的都減，s的都加
			for (int index = 0; index < s.size(); index++)
			{
				recordHashTable[s[index]]++;
				recordHashTable[t[index]]--;
			}
			//最後所有元素都必須為0才適合法的
			for (auto item : recordHashTable)
			{
				if (item.second != 0)
					return false;
			}
			return true;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Valid_Anagram_Model GetTestData001(void)
		{
			Valid_Anagram_Model result;
			result.s = "anagram";
			result.t = "nagaram";
			return result;//expect : true
		};
		/// <summary>
		/// 測試資料2
		/// </summary>   
		Valid_Anagram_Model GetTestData002(void)
		{
			Valid_Anagram_Model result;
			result.s = "rat";
			result.t = "car";
			return result;//expect : false
		};
#pragma endregion TestData
	};
}