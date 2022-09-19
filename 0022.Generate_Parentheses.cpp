#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution22
{
#pragma region Paste to execute 
	/*
	#include "0022.Generate_Parentheses.cpp"
	using namespace Solution22;
	using namespace std;

	int main()
	{
		Solution22::Generate_Parentheses useClass;
		Solution22::Generate_Parentheses::Generate_Parentheses_Model getTestModel = useClass.GetTestData001();
		vector<string> result = useClass.generateParenthesis(getTestModel.n);

		getTestModel = useClass.GetTestData002();
		result = useClass.generateParenthesis(getTestModel.n);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 產生合理的括號陣列 
	/// ※合理是指有對應起訖括號 : () 
	/// </summary>
	class Generate_Parentheses
	{
#pragma region Model
	public:
		class Generate_Parentheses_Model
		{
		public:
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         思路：考慮以下2個特性，利用遞迴找出所有組成的可能
		///         1. '(' 與 ')' 必須相對應
		///         2. 最左邊必定 '(' 最右邊必定 ')' 
		///     Runtime :    3 ms, faster than 87.69% of C++ online submissions for Generate Parentheses.
		///Memory Usage : 13.6 MB,   less than 59.89% of C++ online submissions for Generate Parentheses.
		/// </summary>
		vector<string> generateParenthesis(int n)
		{
			vector<string> result;
			string combinateStr;
			Recursive(n, n, combinateStr, result);
			return result;
		}

		void Recursive(int left, int right, string joinStr, vector<string>& result)
		{
			//特性1 左( 與 右) 相對應，並且用盡，表示可以記錄
			if (left == 0 && right == 0)
			{
				result.push_back(joinStr);
				return;
			}

			//特性2 左( 永遠會有一筆在左; 右) 永遠一筆在)
			if (left > 0)
				Recursive(left - 1, right, joinStr + '(', result);
			if( right > left)
				Recursive(left , right - 1, joinStr + ')', result);
		}
		
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Generate_Parentheses_Model GetTestData001(void)
		{
			Generate_Parentheses_Model result;
			result.n = 3;
			return result;//except:["((()))","(()())","(())()","()(())","()()()"]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Generate_Parentheses_Model GetTestData002(void)
		{
			Generate_Parentheses_Model result;
			result.n = 1;
			return result;//expect:["()"]
		};
#pragma endregion TestData

	};
}