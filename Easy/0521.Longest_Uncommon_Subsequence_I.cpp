#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution521
{
#pragma region Paste to execute 
	/*
	#include "Easy\0521.Longest_Uncommon_Subsequence_I.cpp"
	using namespace Solution521;

	int main()
	{
		Solution521::Longest_Uncommon_Subsequence_I useClass;
		Solution521::Longest_Uncommon_Subsequence_I::Longest_Uncommon_Subsequence_I_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.checkPerfectNumber(getTestModel.num);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.checkPerfectNumber(getTestModel.num);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �̱`���`�����l�ǦC1
	/// </summary>
	class Longest_Uncommon_Subsequence_I
	{
#pragma region Model
	public:
		class Longest_Uncommon_Subsequence_I_Model
		{
		public:
			string a;
			string b;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ��� : �@�ˮɬ�-1�A���@�ˮɧ�X�̪����r�ꬰ��Ӧr��t���̪�������
		///       Runtime :   0 ms Beats   100 %
		///  Memory Usage :	6.5 MB Beats 12.24 %
		/// </summary>
		int findLUSlength(string a, string b) {
			return a == b ? -1 
				          : max(a.size(), b.size());
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Longest_Uncommon_Subsequence_I_Model GetTestData001(void)
		{
			Longest_Uncommon_Subsequence_I_Model result;
			result.a = "aba";
			result.b = "cdc";
			return result;//expect : 3
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Longest_Uncommon_Subsequence_I_Model GetTestData002(void)
		{
			Longest_Uncommon_Subsequence_I_Model result;
			result.a = "aaa";
			result.b = "bbb";
			return result;//expect : 3
		};

		/// <summary>
		/// test 3
		/// </summary>   
		Longest_Uncommon_Subsequence_I_Model GetTestData003(void)
		{
			Longest_Uncommon_Subsequence_I_Model result;
			result.a = "aaa";
			result.b = "aaa";
			return result;//expect : 0
		};
#pragma endregion TestData
	};
}