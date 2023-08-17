#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

namespace Solution387
{
#pragma region Paste to execute 
	/*
	#include <vector>
	#include "Easy\0387.First_Unique_Character_in_a_String.cpp"
	using namespace Solution387;

	int main()
	{
		Solution387::First_Unique_Character_in_a_String useClass;
		Solution387::First_Unique_Character_in_a_String::First_Unique_Character_in_a_String_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.firstUniqChar(getTestModel.s);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.firstUniqChar(getTestModel.s);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.firstUniqChar(getTestModel.s);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 第一個字串中出現的唯一字元
	/// </summary>
	class First_Unique_Character_in_a_String
	{
#pragma region Model
	public:
		class First_Unique_Character_in_a_String_Model
		{
		public:
			string s;			
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          Think :建立一維陣列記錄所有字母數，然後再次遍歷字串，找出第一個出現次數為1的字母
		///        Runtime :  20 ms Beats 88.66 %
		///   Memory Usage :10.6 MB Beats 68.46 %
		/// <returns></returns>
		int firstUniqChar(string s) {
			vector<int> temp(26, 0);			
			for (int index = s.size() - 1; index >= 0; index--)
			{				
				temp[s[index] - 97]++;
			}			
			for (int index = 0; index < s.size(); index++)
			{		
				if (temp[s[index] - 97] == 1)
					return index;
			}
			return -1;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		First_Unique_Character_in_a_String_Model GetTestData001(void)
		{
			First_Unique_Character_in_a_String_Model result;
			result.s = "leetcode";			
			return result;//expect:0
		};

		/// <summary>
		/// test 2
		/// </summary>   
		First_Unique_Character_in_a_String_Model GetTestData002(void)
		{
			First_Unique_Character_in_a_String_Model result;
			result.s = "loveleetcode";
			return result;//expect:2
		};

		/// <summary>
		/// test 3
		/// </summary>   
		First_Unique_Character_in_a_String_Model GetTestData003(void)
		{
			First_Unique_Character_in_a_String_Model result;
			result.s = "aabb";	
			return result;//expect:-1
		};
#pragma endregion TestData
	};
}
