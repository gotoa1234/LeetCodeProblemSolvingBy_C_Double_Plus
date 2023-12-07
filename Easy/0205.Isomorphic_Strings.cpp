#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution205
{
#pragma region Paste to execute 
	/*
	#include "Easy\0205.Isomorphic_Strings.cpp"
    using namespace Solution205;
    using namespace std;

	Solution205::Isomorphic_Strings useClass;
	Solution205::Isomorphic_Strings::Isomorphic_Strings_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.isIsomorphic(getTestModel.s, getTestModel.s);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �P�c�y�r�� (��Ӧr��C�Ӧr�����c�O�_�ۦP�A�۷����ıK�X)
	/// </summary>
	class Isomorphic_Strings
	{
#pragma region Model
	public:
		class Isomorphic_Strings_Model
		{
		public:
			string s;
			string t;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ��� : �����ˮ� => ��Ӧr���������� => �w�s�b�������h���
		///       Runtime :   4 ms, faster than 91.45% of C++ online submissions for Isomorphic Strings.
		///  Memory Usage : 6.9 MB,   less than 74.74% of C++ online submissions for Isomorphic Strings.
		/// </summary>
		bool isIsomorphic(string s, string t) {
			//�ˮ֪���
			if (s.size() != t.size())
				return false;
			//���Hash��������
			unordered_map<int, int> sHashTable;
			unordered_map<int, int> tHashTable;
			for (int index = 0; index < s.size(); index++)
			{
				//���䥼�o�{���r���N�إ�
				if (sHashTable.find(s[index]) == sHashTable.end() &&
				    tHashTable.find(t[index]) == tHashTable.end()
					)
				{
					sHashTable[s[index]] = t[index];
				    tHashTable[t[index]] = s[index];
					continue;
				}
				
				//�w�s�b�r���ɶi���ˮ�
				if (sHashTable[s[index]] != t[index] ||
					tHashTable[t[index]] != s[index])
				{
					return false;
				}
			}
			return true;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Isomorphic_Strings_Model GetTestData001(void)
		{
			Isomorphic_Strings_Model result;
			result.s = "badc";
			result.t = "baba";
			return result;
		};
		/// <summary>
		/// ���ո��2
		/// </summary>   
		Isomorphic_Strings_Model GetTestData002(void)
		{
			Isomorphic_Strings_Model result;
			result.s = "foo";
			result.t = "bar";
			return result;
		};

		/// <summary>
		/// ���ո��3
		/// </summary>   
		Isomorphic_Strings_Model GetTestData003(void)
		{
			Isomorphic_Strings_Model result;
			result.s = "paper";
			result.t = "title";
			return result;
		};
#pragma endregion TestData
	};
}