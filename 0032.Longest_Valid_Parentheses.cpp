#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution32
{
#pragma region Paste to execute 
	/*
	#include "0032.Longest_Valid_Parentheses.cpp"
	using namespace Solution32;
	using namespace std;

	int main()
	{
	Solution32::Longest_Valid_Parentheses useClass;
	Solution32::Longest_Valid_Parentheses::Longest_Valid_Parentheses_Model getTestModel = useClass.GetTestData001();
	int result = useClass.longestValidParentheses(getTestModel.s);

	getTestModel = useClass.GetTestData002();
	result = useClass.longestValidParentheses(getTestModel.s);

	getTestModel = useClass.GetTestData003();
	result = useClass.longestValidParentheses(getTestModel.s);
	return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 驗證最長括號
	/// ※文不對題，此題要找出最常的括號長度
	/// </summary>
	class Longest_Valid_Parentheses
	{
#pragma region Model
	public:
		class Longest_Valid_Parentheses_Model
		{
		public:
			string s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 依照題意只會有( 與 ) ，因此只有當() 可以配對，所以可以分兩部分查找
		///                1. 從字串最左邊開始往右 2.從字串最右邊開始往左 最後看哪個配對長度長就是正確
		///      Runtime：   0 ms Beats   100 %
		///Memory Usage ： 6.9 MB Beats 81.57 %
		/// </summary>
		int longestValidParentheses(string s) {
			int left = 0, right = 0, maxlen = 0;
			//1. 找出由左至右可配對的括號
			for (int index = 0; index < s.size(); index++)
			{
				if (s[index] == '(')
					left++;
				else
					right++;

				if (left == right)
					maxlen = max(maxlen, left * 2);
				else if (right > left)
				{
					right = left = 0;
				}
			}
			left = 0, right = 0;
			//2. 找出由右至左可配對的括號
			for (int index = s.size() - 1; 0 <= index; index--)
			{
				if (s[index] == '(')
					left++;
				else
					right++;
				if (left == right)
					maxlen = max(maxlen, right * 2);
				else if (left > right)
				{
					right = left = 0;
				}
			}
			//回傳最長的結果
			return maxlen;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Longest_Valid_Parentheses_Model GetTestData001(void)
		{
			Longest_Valid_Parentheses_Model result;
			result.s = "(()";
			return result;//except: 2
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Longest_Valid_Parentheses_Model GetTestData002(void)
		{
			Longest_Valid_Parentheses_Model result;
			result.s = ")()())";
			return result;//except: 4
		};

		/// <summary>
		/// test data 3
		/// </summary>   
		Longest_Valid_Parentheses_Model GetTestData003(void)
		{
			Longest_Valid_Parentheses_Model result;
			result.s = "";
			return result;//except: 0
		};
#pragma endregion TestData

	};
}