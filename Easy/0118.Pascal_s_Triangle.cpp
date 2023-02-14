#include <iostream>
#include <vector>
using namespace std;

namespace Solution118
{
#pragma region Paste to execute 
	/*
	#include "Easy\0118.Pascal_s_Triangle.cpp"
	using namespace Solution118;
	using namespace std;

	int main()
	{
		Solution118::Pascal_s_Triangle useClass;
		Solution118::Pascal_s_Triangle::Pascal_s_Triangle_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.generate(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		auto result2 =useClass.generate(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 帕斯卡三角
	/// </summary>
	class Pascal_s_Triangle
	{
#pragma region Model
	public:
		class Pascal_s_Triangle_Model
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
		vector<vector<int>> generate(int numRows) {
			return {};
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Pascal_s_Triangle_Model GetTestData001(void)
		{
			Pascal_s_Triangle_Model result;
			result.numRows = 5;
			
			return result;//expect:[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
		}

		/// <summary>
		/// test 2
		/// </summary>   
		Pascal_s_Triangle_Model GetTestData002(void)
		{
			Pascal_s_Triangle_Model result;
			result.numRows = 1;
			return result;//expect:[[1]]
		};

#pragma endregion TestData
	};
}
