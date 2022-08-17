#include <iostream>
#include <vector>
using namespace std;

namespace Solution205
{
#pragma region Paste to execute 
	/*
	#include "205.Isomorphic_Strings.cpp"
	using namespace Solution205;
	using namespace std;

	Solution205::.Isomorphic_Strings useClass;
	Solution205::.Isomorphic_Strings::.Isomorphic_Strings_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.runningSum(getTestModel.nums);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 同構造字串
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
		///          思路：
		///      Runtime : 
		/// Memory Usage : 
		/// </summary>
		bool isIsomorphic(string s, string t) {
			return true;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Isomorphic_Strings_Model GetTestData001(void)
		{
			Isomorphic_Strings_Model result;
			result.s = "egg";
			result.t = "add";
			return result;
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Isomorphic_Strings_Model GetTestData002(void)
		{
			Isomorphic_Strings_Model result;
			result.s = "foo";
			result.t = "bar";
			return result;
		};

		/// <summary>
		/// 測試資料3
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