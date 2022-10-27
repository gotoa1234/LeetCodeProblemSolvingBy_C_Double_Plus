#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution43
{
#pragma region Paste to execute 
	/*
	#include "0043.Multiply_Strings.cpp"
	using namespace Solution43;
	using namespace std;

	int main()
	{
		int result = 0;
		Solution43::Multiply_Strings useClass;
		Solution43::Multiply_Strings::Multiply_Strings_Model getTestModel = useClass.GetTestData001();
		result = useClass.trap(getTestModel.height);

		getTestModel = useClass.GetTestData002();
		result = useClass.trap(getTestModel.height);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ¦r¦ê¬Û­¼
	/// </summary>
	class Multiply_Strings
	{
#pragma region Model
	public:
		class Multiply_Strings_Model
		{
		public:
			string num1;
			string num2;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking¡G 
		///       Runtime¡G
		/// Memory Usage ¡G
		/// </summary>	
		string multiply(string num1, string num2) {
			return "";
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Multiply_Strings_Model GetTestData001(void)
		{
			Multiply_Strings_Model result;
			result.num1 = "2";
			result.num1 = "3";
			return result;//except: "6"
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Multiply_Strings_Model GetTestData002(void)
		{
			Multiply_Strings_Model result;
			result.num1 = "123";
			result.num1 = "456";

			return result;//except: 56088
		};
#pragma endregion TestData

	};
}
