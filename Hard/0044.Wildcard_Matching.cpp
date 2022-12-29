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
	/// 萬用字元配對
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
		///     thinking： 拆成兩段邏輯， 1. 找到萬用字元前，若1v1比對錯誤則返回false 
		///                               2. 找到萬用字元後，s不斷往前，p處在*字元的p索引上，只有再觸碰到第2個以後的* 才更新p字元的索引
		///       Runtime：  3 ms Beats 99.78 %
		/// Memory Usage ：6.6 MB Beats 95.62 %
		/// </summary>	
		bool isMatch(string s, string p) {
			int pIndex = 0;
			for (int sIndex = 0, pWildcardIndex = -1, sWildcardIndex = -1;
				sIndex < s.size();
				)
			{
				//1. 找出萬用字元
				if(pIndex < p.size() &&
				   p[pIndex] == '*')
				{
					pWildcardIndex = pIndex;
					sWildcardIndex = sIndex;
					pIndex++;
					continue;
				}
				
				//2-1. 找出1v1 完整比對
				if (pIndex < p.size() &&
					(p[pIndex] == s[sIndex] || p[pIndex] == '?')
					)
				{
					pIndex++;
					sIndex++;
				}
				else if (sWildcardIndex != -1)//2-2 萬用字元有出現過時觸發
				{
					sIndex = sWildcardIndex + 1;
					pIndex = pWildcardIndex + 1;
					sWildcardIndex++;
				}
				else
					return false;//2-3 只會在沒觸發到* 且 1v1比對錯時到這
			}
			
			//3. 如果p 還有剩餘的字元，必定需要* 否則都視為錯誤
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
