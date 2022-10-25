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
		///     thinking： 依照題意只會有( 與 ) ，因此只有當() 或(()) 可以配對，所以可以分兩部分查找
		///                1. 從字串最左邊開始往右 2.從字串最右邊開始往左 最後看哪個配對長度長就是正確
		///      Runtime：   0 ms Beats   100 %
		///Memory Usage ： 6.9 MB Beats 81.57 %
		/// </summary>
		int longestValidParentheses(string s) {
			int left = 0; 
			int right = 0;
			int maxLength = 0;
			for (int index = 0; index < s.size(); index++)
			{
				if (s[index] == '(')
					left++;
				else
					right++;
				
				if (left == right)
				{
					maxLength = max(maxLength, left * 2);
				}
				else if (right > left)
				{
					left = right = 0;
				}
			}
			left = 0;
			 right = 0;
			for (int index = s.size() - 1; index >= 0; index--)
			{
				if (s[index] == ')')
					right++;
				else
					left++;

				if (right == left)
				{
					maxLength = max(maxLength, right * 2);
				}
				else if (left > right )
				{
					left = right = 0;
				}
			}
			return maxLength;
		}

		/// <summary>
		/// 動態規劃解法 thinking: 每次以前面兩個結果是否為 () 做為解
		/// ※ (()) 為4 需要考慮
		///      Runtime：   9 ms Beats 49.95 %
		///Memory Usage ： 7.3 MB Beats 41.63 %
		/// </summary>
		/// <returns></returns>
		int longestValidParentheses_DpSolve(string s) {
			int result = 0;
			vector<int> dp(s.size() + 1);
			int lastIndex = 0;//上個索引
			int indexBeforeLast = 0;//上上個索引
			for (int index = 1; index <= s.size(); index++)
			{
				lastIndex = index - 1;
				//如果上個DP有找到值，則在本次需要找出包覆的狀況 EX: (()) 現在在index = 5 需要對lastindex = 3 與 indexBeforeLast = 1 做檢查
				indexBeforeLast = index - 2 - dp[lastIndex];
				if (indexBeforeLast < 0)
					dp[index] = 0;
				else if (s[indexBeforeLast] == '(' && s[lastIndex] == ')')
				{
					dp[index] = dp[indexBeforeLast] + dp[lastIndex] + 2;
					result = max(result, dp[index]);
				}
				else
				{
					dp[index] = 0;
				}
			}
			return result;
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
			result.s = "()()()()";
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

		Longest_Valid_Parentheses_Model GetTestData004(void)
		{
			Longest_Valid_Parentheses_Model result;
			result.s = "()(())";
			return result;//except: 6
		};
#pragma endregion TestData

	};
}