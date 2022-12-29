#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution44
{
#pragma region Paste to execute 
	/*
	#include "0044.Wildcard_Matching.cpp"
	using namespace Solution44;
	using namespace std;

	int main()
	{
		bool result = false;
		Solution44::Wildcard_Matching useClass;
		Solution44::Wildcard_Matching::Wildcard_Matching_Model getTestModel = useClass.GetTestData001();
		result = useClass.isMatch(getTestModel.s, getTestModel.p);

		getTestModel = useClass.GetTestData002();
		result = useClass.isMatch(getTestModel.s, getTestModel.p);

		getTestModel = useClass.GetTestData003();
		result = useClass.isMatch(getTestModel.s, getTestModel.p);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �U�Φr���t��
	/// </summary>
	class Wildcard_Matching
	{
#pragma region Model
	public:
		class Wildcard_Matching_Model
		{
		public:
			string s;
			string p;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking�G ���q�޿�A 1. ���U�Φr���e�A�Y1v1�����~�h��^false 
		///                               2. ���U�Φr����As���_���e�Ap�B�b*�r����p���ޤW�A�u���AĲ�I���2�ӥH�᪺* �~��sp�r��������
		///       Runtime�G  3 ms Beats 99.78 %
		/// Memory Usage �G6.6 MB Beats 95.62 %
		/// </summary>	
		bool isMatch(string s, string p) {
			int pIndex = 0;
			for (int sIndex = 0, pWildcardIndex = -1, sWildcardIndex = -1;
				sIndex < s.size();
				)
			{
				//1. ��X�U�Φr��
				if(pIndex < p.size() &&
				   p[pIndex] == '*')
				{
					pWildcardIndex = pIndex;
					sWildcardIndex = sIndex;
					pIndex++;
					continue;
				}
				
				//2-1. ��X1v1 ������
				if (pIndex < p.size() &&
					(p[pIndex] == s[sIndex] || p[pIndex] == '?')
					)
				{
					pIndex++;
					sIndex++;
				}
				else if (sWildcardIndex != -1)//2-2 �U�Φr�����X�{�L��Ĳ�o
				{
					sIndex = sWildcardIndex + 1;
					pIndex = pWildcardIndex + 1;
					sWildcardIndex++;
				}
				else
					return false;//2-3 �u�|�b�SĲ�o��* �B 1v1�����ɨ�o
			}
			
			//3. �p�Gp �٦��Ѿl���r���A���w�ݭn* �_�h���������~
			while (pIndex < p.size())
			{
				if (p[pIndex] != '*')
					return false;
				pIndex++;
			}
			return true;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Wildcard_Matching_Model GetTestData001(void)
		{
			Wildcard_Matching_Model result;
			result.s = "aa";
			result.p = "a";
			return result;//except: false
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Wildcard_Matching_Model GetTestData002(void)
		{
			Wildcard_Matching_Model result;
			result.s = "aa";
			result.p = "*";

			return result;//except: true
		};

		/// <summary>
		/// test data 3
		/// </summary>   
		Wildcard_Matching_Model GetTestData003(void)
		{
			Wildcard_Matching_Model result;
			result.s = "cb";
			result.p = "?a";

			return result;//except: false
		};

		/// <summary>
		/// test data 4
		/// </summary>   
		Wildcard_Matching_Model GetTestData004(void)
		{
			Wildcard_Matching_Model result;
			result.s = "abcde";
			result.p = "*fz?j";

			return result;//except: false
		};

		/// <summary>
		/// test data 5
		/// </summary>   
		Wildcard_Matching_Model GetTestData005(void)
		{
			Wildcard_Matching_Model result;
			result.s = "mississippi";
			result.p = "m??*ss*?i*pi";
			return result;//except: false
		};
#pragma endregion TestData
	};
}
