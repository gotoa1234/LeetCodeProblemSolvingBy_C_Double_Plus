#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

namespace Solution20
{
#pragma region Paste to execute 
	/*
	#include "Easy\0020.Valid_Parentheses.cpp"
	using namespace Solution20;
	using namespace std;

	int main()
	{
		Solution20::Valid_Parentheses useClass;
		Solution20::Valid_Parentheses::Valid_Parentheses_Model getTestModel = useClass.GetTestData001();
		bool result = useClass.isValid(getTestModel.s);

		getTestModel = useClass.GetTestData002();
		result = useClass.isValid(getTestModel.s);

		getTestModel = useClass.GetTestData003();
		result = useClass.isValid(getTestModel.s);

	    getTestModel = useClass.GetTestData004();
		result = useClass.isValid(getTestModel.s);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ���ĬA��
	/// �����Ī��A�� => characters '(', ')', '{', '}', '[' , ']' 
	/// </summary>
	class Valid_Parentheses
	{
#pragma region Model
	public:
		class Valid_Parentheses_Model
		{
		public:
			string s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G�Q��Stack �A�åB�w�� ( , { , [ ��J���|���A�J�� ) , } , ] �P��e���|�̤W�����A���P�_�O�_���@��
		///                ���q�L�T�{��A�̫�Y���|�����Ū�ܥ��T
		///       Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
		/// Memory Usage : 6.2 MB, less than  79.97% of C++ online submissions for Valid Parentheses.
		/// </summary>
		bool isValid(string s) {
			
			//1. �ư�������~������
			if (s.size() < 2 || s[0] == ')' || s[0] == '}' || s[0] == ']')
				return false;

			stack<char> stackContiner;
			for (int index = 0; index < s.size(); index++)
			{
				//2. ��J���|����
				if (s[index] == '(' || s[index] == '[' || s[index] == '{')
					stackContiner.push(s[index]);
				else if (s[index] == ')' || s[index] == ']' || s[index] == '}')
				{
					//���X�ȨӤ��O�_�@��
					if (stackContiner.empty())
						return false;
					else if (
						(s[index] == ')' && stackContiner.top() != '(') ||
						(s[index] == '}' && stackContiner.top() != '{') ||
						(s[index] == ']' && stackContiner.top() != '[')
						) {
						return false;
					}
					stackContiner.pop();
				}
			}
			return stackContiner.empty() ? true : false ;
		}

		bool isValidSolve2(string s) {
			stack<char> stackContiner;
			unordered_map<char, char> hashMap;
			hashMap['('] = '(';
			hashMap[')'] = ')';
			hashMap['{'] = '{';
			hashMap['}'] = '}';
			hashMap['['] = '[';
			hashMap[']'] = ']';

			for (int index = 0; index < s.size(); index++)
			{
				if (hashMap.find(s[index]) != hashMap.end())
				{
					if (hashMap[s[index]] == '(' ||
						hashMap[s[index]] == '{' ||
						hashMap[s[index]] == '[')
					{
						stackContiner.push(s[index]);
					}
					else
					{
						if (!stackContiner.empty())
						{
							if (
								(s[index] == ')' && stackContiner.top() != '(') ||
								(s[index] == '}' && stackContiner.top() != '{') ||
								(s[index] == ']' && stackContiner.top() != '[')
								)
								return false;
							stackContiner.pop();
						}
						else
							return false;
					}
				}
			}
			return stackContiner.empty() ? true : false;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Valid_Parentheses_Model GetTestData001(void)
		{
			Valid_Parentheses_Model result;
			result.s = "()";
			return result;//except: true
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Valid_Parentheses_Model GetTestData002(void)
		{
			Valid_Parentheses_Model result;
			result.s = "()[]{}";
			return result;//expect: true
		};

		/// <summary>
		/// ���ո��3
		/// </summary>   
		Valid_Parentheses_Model GetTestData003(void)
		{
			Valid_Parentheses_Model result;
			result.s = "(]";
			return result;//expect: false
		
		};

		/// <summary>
		/// ���ո��4
		/// </summary>
		Valid_Parentheses_Model GetTestData004(void)
		{
			Valid_Parentheses_Model result;
			result.s = "([)]";
			return result;//expect: false
		};
#pragma endregion TestData

	};
}