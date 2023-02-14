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
	/// 不同的序列
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
		///          思路：
		///       Runtime :
		///  Memory Usage :
		/// </summary>
		int numDistinct(string s, string t) {
			return {};
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

#pragma endregion TestData
	};
}
