#include <iostream>
#include <vector>
using namespace std;

namespace Solution115
{
#pragma region Paste to execute 
	/*
	#include "Medium\0115.Distinct_Subsequences.cpp"
	using namespace Solution115;
	using namespace std;

	int main()
	{
		Solution115::Distinct_Subsequences useClass;
		Solution115::Distinct_Subsequences::Distinct_Subsequences_Model getTestModel = useClass.GetTestData001();
		useClass.flatten(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		useClass.flatten(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ���P���ǦC
	/// </summary>
	class Distinct_Subsequences
	{
#pragma region Model
	public:
		class Distinct_Subsequences_Model
		{
		public:
			string s;
			string t;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G�ݭn�Q�ΰʺA�W���ӸѦ����D�A�_�h�|�W��
		///       Runtime :  50 ms Beats  55.3 %
		///  Memory Usage :18.3 MB Beats 73.48 %
		/// </summary>
		int numDistinct(string s, string t) 
		{
			//1. �إߤ@��Dp �j�p�� (s+1 * t+1)
			vector<vector<long>> dp(t.size() + 1, vector<long>(s.size() + 1));
			//2. ��0�ƹw�]��1�K��p��
			for (int xAxis = 0; xAxis <= s.size(); xAxis++)
				dp[0][xAxis] = 1;
			
			//3-1. �ѲĤ@��1,1 �}�l���kx�b�M��(����t�M��s)
			for (int yAxis = 1; yAxis <= t.size(); yAxis++)
			{
				for (int xAxis = 1; xAxis <= s.size(); xAxis++)
				{
					//3-2. �C�Ӧ�m���ȬO => ��e�����䪺�p��� + (�W�����X�{�ۦP���r�����֭p��) 
					//���Y t[yAxis-1] != s[xAxis-1] ��0��ܤ��ۦP
				 	long tempValue = (t[yAxis - 1] == s[xAxis - 1] ? dp[yAxis - 1][xAxis - 1] : 0);
					dp[yAxis][xAxis] = dp[yAxis][xAxis - 1] + tempValue;
				}
			}
			return dp[t.size()][s.size()];
		}


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Distinct_Subsequences_Model GetTestData001(void)
		{
			Distinct_Subsequences_Model result;
			result.s = "rabbbit";
			result.t = "rabbit";
			return result;//expect:3
		}

		/// <summary>
		/// test 2
		/// </summary>   
		Distinct_Subsequences_Model GetTestData002(void)
		{
			Distinct_Subsequences_Model result;
			result.s = "babgbag";
			result.t = "bag";
			return result;//expect:5
		};

		/// <summary>
		/// test 3
		/// </summary>   
		Distinct_Subsequences_Model GetTestData003(void)
		{
			Distinct_Subsequences_Model result;
			result.s = "adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc";
			result.t = "bcddceeeebecbc";
			return result;//expect:
		};
		
	    /// <summary>
	    /// test 4
	    /// </summary>   
	    Distinct_Subsequences_Model GetTestData004(void)
		{
			Distinct_Subsequences_Model result;
			result.s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			result.t = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			return result;//expect:
		};

#pragma endregion TestData
	};
}
