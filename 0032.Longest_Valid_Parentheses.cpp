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
		///     thinking�G �̷��D�N�u�|��( �P ) �A�]���u����() �i�H�t��A�ҥH�i�H���ⳡ���d��
		///                1. �q�r��̥���}�l���k 2.�q�r��̥k��}�l���� �̫�ݭ��Ӱt����ת��N�O���T
		///      Runtime�G   0 ms Beats   100 %
		///Memory Usage �G 6.9 MB Beats 81.57 %
		/// </summary>
		int longestValidParentheses(string s) {
			int left = 0, right = 0, maxlen = 0;
			//1. ��X�ѥ��ܥk�i�t�諸�A��
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
			//2. ��X�ѥk�ܥ��i�t�諸�A��
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
			//�^�ǳ̪������G
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