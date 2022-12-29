#include <iostream>
#include <stack>
#include <string>
using namespace std;

namespace Solution394
{
#pragma region Paste to execute 
	/*
	#include <vector>
	#include "0394.Decode_String.cpp"
	using namespace Solution394;

	int main()
	{
		Solution394::Decode_String useClass;
		Solution394::Decode_String::Decode_String_Model getTestModel = useClass.GetTestData001();
		int result = useClass.decodeString(getTestModel.s);

		getTestModel = useClass.GetTestData002();
		result = useClass.decodeString(getTestModel.s);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �ѽX�r�Ŧ�
	/// </summary>
	class Decode_String
	{
#pragma region Model
	public:
		class Decode_String_Model
		{
		public:
			string s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///            ����G�M���A�Q��2�Ӱ��|�N�Ʀr�B�r�����ֿn�C�b�J�� '[' �ɱN�ثe���L���Ʀr�B�r����i���|��
		///                 ���쨫��']' ���X�Ʀr���|�A�N�r�꭫�Ʋ֥[�A���ƫe���B�J�C�̫��X���G�C
		///        Runtime :   0 ms, faster than 100.00% of C++ online submissions for Decode String.
		///   Memory Usage : 6.5 MB,   less than  77.13% of C++ online submissions for Decode String.
		///Time complexity : O(N)
		/// <returns></returns>
		string decodeString(string s) {
			stack<string> digitStack, alphaStack;//�]�w�Ʀr�B�r�����|
			string digitStr = "";//�Ʀr�������r��A�~�����2��H�W�Ʀr
			string resultStr = "";//���G�r��

			for (int index = 0; index < s.size(); index++)
			{
				if (isdigit(s[index])) //�Ʀr
					digitStr += s[index];
				else if (isalpha(s[index]))//�r��
					resultStr += s[index];
				else if (s[index] == '[') //�J�� [ �n�N�ֿn����i���|
				{
					digitStack.push(digitStr);
					alphaStack.push(resultStr);
					digitStr.clear();
					resultStr.clear();
				}
				else
				{
					//2. �J�� ] �ɧ�̪� �Ʀr���X�A�åB�N��e�r�꭫�Ʋ֥[
					if (s[index] == ']')
					{
						int digit = stoi(digitStack.top());
						digitStack.pop();
						string newResult = "";
						for (int repeatTime = 0; repeatTime < digit; repeatTime++)
						{
							newResult += resultStr;
						}
						resultStr = newResult;
					}
					//3. �Y�Ʀr�Ǧ��r�����X�֥[
					resultStr = alphaStack.top() + resultStr;
					alphaStack.pop();
				}
			}
			return resultStr;
		}


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��2
		/// </summary>        
		Decode_String_Model GetTestData001(void)
		{
			Decode_String_Model result;
			result.s = "3[a]22[bc]";
			return result;//expect:"aaabcbc"
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Decode_String_Model GetTestData002(void)
		{
			Decode_String_Model result;
			result.s = "3[a2[c]]";
			return result;//expect:"accaccacc"
		};

#pragma endregion TestData
	};
}