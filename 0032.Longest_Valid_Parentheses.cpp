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
	/// ���ҳ̪��A��
	/// ���夣���D�A���D�n��X�̱`���A������
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
		///     thinking�G �̷��D�N�u�|��( �P ) �A�]���u����() ��(()) �i�H�t��A�ҥH�i�H���ⳡ���d��
		///                1. �q�r��̥���}�l���k 2.�q�r��̥k��}�l���� �̫�ݭ��Ӱt����ת��N�O���T
		///      Runtime�G   0 ms Beats   100 %
		///Memory Usage �G 6.9 MB Beats 81.57 %
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
		/// �ʺA�W���Ѫk thinking: �C���H�e����ӵ��G�O�_�� () ������
		/// �� (()) ��4 �ݭn�Ҽ{
		///      Runtime�G   9 ms Beats 49.95 %
		///Memory Usage �G 7.3 MB Beats 41.63 %
		/// </summary>
		/// <returns></returns>
		int longestValidParentheses_DpSolve(string s) {
			int result = 0;
			vector<int> dp(s.size() + 1);
			int lastIndex = 0;//�W�ӯ���
			int indexBeforeLast = 0;//�W�W�ӯ���
			for (int index = 1; index <= s.size(); index++)
			{
				lastIndex = index - 1;
				//�p�G�W��DP�����ȡA�h�b�����ݭn��X�]�Ъ����p EX: (()) �{�b�bindex = 5 �ݭn��lastindex = 3 �P indexBeforeLast = 1 ���ˬd
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