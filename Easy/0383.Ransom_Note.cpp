#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

namespace Solution383
{
#pragma region Paste to execute 
	/*
	#include <vector>
	#include "Easy\0383.Ransom_Note.cpp"
	using namespace Solution383;

	int main()
	{
		Solution383::Ransom_Note useClass;
		Solution383::Ransom_Note::Ransom_Note_Model getTestModel = useClass.GetTestData001();
		int result = useClass.isPerfectSquare(getTestModel.num);

		getTestModel = useClass.GetTestData002();
		result = useClass.isPerfectSquare(getTestModel.num);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 勒索信
	/// </summary>
	class Ransom_Note
	{
#pragma region Model
	public:
		class Ransom_Note_Model
		{
		public:
			string ransomNote;
			string magazine;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          Think :利用HashTable 紀錄雜誌的字母，然後遍歷勒索信的字母，如果沒有或用盡字母，表示False
		///        Runtime : 12 ms Beats 82.67 %
		///   Memory Usage :8.8 MB Beats 64.32 %
		/// <returns></returns>
		bool canConstruct(string ransomNote, string magazine) 
		{
			unordered_map<char, int> hashTable;
			for (int index = 0; index < magazine.size(); index++)
			{
				hashTable[magazine[index]]++;
			}

			for (int index = 0; index < ransomNote.size(); index++)
			{
				if (hashTable.find(ransomNote[index]) == hashTable.end())
				{
					return false;
				}
				else if(hashTable[ransomNote[index]] <= 0)
				{
					return false;
				}
				hashTable[ransomNote[index]]--;
			}
			return true;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Ransom_Note_Model GetTestData001(void)
		{
			Ransom_Note_Model result;
			result.ransomNote = "a";
			result.magazine = "b";
			return result;//expect:false
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Ransom_Note_Model GetTestData002(void)
		{
			Ransom_Note_Model result;
			result.ransomNote = "aa";
			result.magazine = "ab";
			return result;//expect:false
		};
		
		/// <summary>
		/// test 3
		/// </summary>   
		Ransom_Note_Model GetTestData003(void)
		{
			Ransom_Note_Model result;
			result.ransomNote = "aa";
			result.magazine = "aab";
			return result;//expect:true
		};

		/// <summary>
		/// test 4
		/// </summary>   
		Ransom_Note_Model GetTestData004(void)
		{
			Ransom_Note_Model result;
			result.ransomNote = "aa";
			result.magazine = "aba";
			return result;//expect:true
		};

#pragma endregion TestData
	};
}
