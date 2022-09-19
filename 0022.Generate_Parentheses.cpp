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
	/// ���ͦX�z���A���}�C 
	/// ���X�z�O���������_�W�A�� : () 
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
		///         ����G�Ҽ{�H�U2�ӯS�ʡA�Q�λ��j��X�Ҧ��զ����i��
		///         1. '(' �P ')' �����۹���
		///         2. �̥��䥲�w '(' �̥k�䥲�w ')' 
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
			//�S��1 ��( �P �k) �۹����A�åB�κɡA��ܥi�H�O��
			if (left == 0 && right == 0)
			{
				result.push_back(joinStr);
				return;
			}

			//�S��2 ��( �û��|���@���b��; �k) �û��@���b)
			if (left > 0)
				Recursive(left - 1, right, joinStr + '(', result);
			if( right > left)
				Recursive(left , right - 1, joinStr + ')', result);
		}
		
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Generate_Parentheses_Model GetTestData001(void)
		{
			Generate_Parentheses_Model result;
			result.n = 3;
			return result;//except:["((()))","(()())","(())()","()(())","()()()"]
		};

		/// <summary>
		/// ���ո��2
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