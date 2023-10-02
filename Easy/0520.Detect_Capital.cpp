#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution520
{
#pragma region Paste to execute 
	/*
	#include "Easy\0520.Detect_Capital.cpp"
	using namespace Solution520;

	int main()
	{
		Solution520::Detect_Capital useClass;
		Solution520::Detect_Capital::Detect_Capital_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.convertToBase7(getTestModel.num);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.convertToBase7(getTestModel.num);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 偵測大寫 (判斷是否用使用符合基本的英文單詞拼寫)
	/// </summary>
	class Detect_Capital
	{
#pragma region Model
	public:
		class Detect_Capital_Model
		{
		public:
			string word;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 遵循以下三個規則
		/// 1. All letters in this word are capitals, like "USA".
	    /// 2. All letters in this word are not capitals, like "leetcode".
		/// 3. Only the first letter in this word is capital, like "Google".
		///       Runtime :   0 ms Beats 100 %
		///  Memory Usage :	6.4 MB Beats 25.33 %
		/// </summary>
		bool detectCapitalUse(string word) {
			if (word[0] >= 'A' && word[0] <= 'Z')
			{
				if (word[1] >= 'a' && word[1] <= 'z')
				{
					for (int index = 2; index < word.size(); index++)
					{
						if (word[index] >= 'a' && word[index] <= 'z')						
							continue;						
						else						
							return false;						
					}
				}
				else if (word[1] >= 'A' && word[1] <= 'Z')
				{
					for (int index = 2; index < word.size(); index++)
					{
						if (word[index] >= 'A' && word[index] <= 'Z')
							continue;
						else
							return false;
					}
				}
			}
			else if (word[0] >= 'a' && word[0] <= 'z')
			{
				for (int index = 1; index < word.size(); index++)
				{
					if (word[index] >= 'a' && word[index] <= 'z')
						continue;
					else
						return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Detect_Capital_Model GetTestData001(void)
		{
			Detect_Capital_Model result;
			result.word = "USA";
			return result;//expect : true
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Detect_Capital_Model GetTestData002(void)
		{
			Detect_Capital_Model result;
			result.word = "FlaG";
			return result;//expect : false
		};
#pragma endregion TestData
	};
}