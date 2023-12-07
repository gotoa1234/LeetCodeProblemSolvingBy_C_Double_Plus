#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution58
{
#pragma region Paste to execute 
	/*
	#include "Easy\0058.Length_of_Last_Word.cpp"
	using namespace Solution58;
	using namespace std;

	int main()
	{
		Solution58::Length_of_Last_Word useClass;
		Solution58::Length_of_Last_Word::Length_of_Last_Word_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.lengthOfLastWord(getTestModel.s);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.lengthOfLastWord(getTestModel.s);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.lengthOfLastWord(getTestModel.s);
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 找出字串最後一個單詞的長度
	/// </summary>
	class Length_of_Last_Word
	{
#pragma region Model
	public:
		class Length_of_Last_Word_Model
		{
		public:
			string s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 題目說 '小寫字母' 與 '空白字元' 那從最後一個索引開始
		///                如果遇到第一個字元後，在遇到下個空白字元就是跳出的時候
		///       Runtime：  3 ms Beats 71.96 %
		/// Memory Usage ：6.5 MB Beats 89.60 %
		/// </summary>	
		int lengthOfLastWord(string s) {
			int result = 0;
			for (int index = s.size() - 1; 
				index >= 0 && !(s[index] == ' ' &&  result > 0);
				index--)
			{
				if (s[index] == ' ')
					continue;
				result++;
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Length_of_Last_Word_Model GetTestData001(void)
		{
			Length_of_Last_Word_Model result;
			result.s = "Hello World";
			return result;//except:  5
		};

		/// <summary>
		/// test data 2
		/// </summary>        
		Length_of_Last_Word_Model GetTestData002(void)
		{
			Length_of_Last_Word_Model result;
			result.s = "   fly me   to   the moon  ";
			return result;//except:  4
		};

		/// <summary>
		/// test data 3
		/// </summary>        
		Length_of_Last_Word_Model GetTestData003(void)
		{
			Length_of_Last_Word_Model result;
			result.s = "luffy is still joyboy";
			return result;//except:  6
		};
#pragma endregion TestData

	};
}
