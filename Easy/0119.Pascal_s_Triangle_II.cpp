#include <iostream>
#include <vector>
using namespace std;

namespace Solution119
{
#pragma region Paste to execute 
	/*
	#include "Easy\0119.Pascal_s_Triangle_II.cpp"
	using namespace Solution119;
	using namespace std;

	int main()
	{
		Solution119::Pascal_s_Triangle_II useClass;
		Solution119::Pascal_s_Triangle_II::Pascal_s_Triangle_II_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.generate(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.generate(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 帕斯卡三角 II
	/// </summary>
	class Pascal_s_Triangle_II
	{
#pragma region Model
	public:
		class Pascal_s_Triangle_II_Model
		{
		public:
			int numRows;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：
		///       Runtime :
		///  Memory Usage :
		/// </summary>
		vector<int> getRow(int rowIndex) {
			return {};
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Pascal_s_Triangle_II_Model GetTestData001(void)
		{
			Pascal_s_Triangle_II_Model result;
			result.numRows = 3;

			return result;//expect:[1,3,3,1]
		}

		/// <summary>
		/// test 2
		/// </summary>   
		Pascal_s_Triangle_II_Model GetTestData002(void)
		{
			Pascal_s_Triangle_II_Model result;
			result.numRows = 0;
			return result;//expect:[[1]]
		};

		/// <summary>
		/// test 3
		/// </summary>   
		Pascal_s_Triangle_II_Model GetTestData003(void)
		{
			Pascal_s_Triangle_II_Model result;
			result.numRows = 1;
			return result;//expect:[[1,1]]
		};

#pragma endregion TestData
	};
}
