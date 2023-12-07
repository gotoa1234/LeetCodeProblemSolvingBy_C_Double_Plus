#include <iostream>
using namespace std;

namespace Solution392
{
#pragma region Paste to execute 
	/*
	#include "Easy\392.Is_Subsequence.cpp"
	using namespace Solution392;
	using namespace std;

	Solution392::Is_Subsequence useClass;
	Solution392::Is_Subsequence::Is_Subsequence_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.runningSum(getTestModel.nums);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �O�_�l�r��
	/// </summary>
	class Is_Subsequence
	{
#pragma region Model
	public:
		class Is_Subsequence_Model
		{
		public:
			string s;
			string t;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ��� : �r��t ���w�j��s�r��A�]��t�M���A�C����t[0]�r�������A����h����t[0]�A����t���Ū��true�A��L���p���Ofalse
		///       Runtime :   0 ms, faster than 100.00% of C++ online submissions for Is Subsequence.
		///  Memory Usage : 6.4 MB,   less than 69.65 % of C++ online submissions for Is Subsequence.
		/// </summary>
		bool isSubsequence(string s, string t) {
			//�M��
			for (int index = 0; index < t.size(); index++)
			{
				if (s[0] == t.at(index))//���Ӧr�����A�s�b�h����
				{
					s.erase(s.begin());
					if (s.empty())
						break;
				}
			}
			//s�����쬰True 
			return s.empty() ? true : false;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Is_Subsequence_Model GetTestData001(void)
		{
			Is_Subsequence_Model result;
			result.s = "abc";
			result.t = "ahbgdc";
			return result;
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Is_Subsequence_Model GetTestData002(void)
		{
			Is_Subsequence_Model result;
			result.s = "axc";
			result.t = "ahbgdc";
			return result;
		};
#pragma endregion TestData
	};
}