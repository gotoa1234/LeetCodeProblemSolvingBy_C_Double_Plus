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
		result = useClass.multiply(getTestModel.num1, getTestModel.num2);

		getTestModel = useClass.GetTestData002();
		result = useClass.multiply(getTestModel.num1, getTestModel.num2);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ¦r¦ê¬Û­¼
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
		///     thinking¡G           
		///       Runtime¡G
		/// Memory Usage ¡G
		/// </summary>	
		bool isMatch(string s, string p) {
			return false;
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
			result.s = "2";
			result.p = "3";
			return result;//except: "6"
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Wildcard_Matching_Model GetTestData002(void)
		{
			Wildcard_Matching_Model result;
			result.s = "123";
			result.p = "456";

			return result;//except: 56088
		};
#pragma endregion TestData

	};
}
