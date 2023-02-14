#include <iostream>
#include <vector>
using namespace std;

namespace Solution120
{
#pragma region Paste to execute 
	/*
	#include "Medium\0120.Triangle.cpp"
	using namespace Solution120;
	using namespace std;

	int main()
	{
		Solution120::Triangle useClass;
		Solution120::Triangle::Triangle_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.minimumTotal(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.minimumTotal(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ¤T¨¤§Î 
	/// </summary>
	class Triangle
	{
#pragma region Model
	public:
		class Triangle_Model
		{
		public:
			vector<vector<int>> triangle;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          «ä¸ô¡G
		///       Runtime :
		///  Memory Usage :
		/// </summary>
		int minimumTotal(vector<vector<int>>& triangle) {
			return { };
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Triangle_Model GetTestData001(void)
		{
			Triangle_Model result;
			result.triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

			return result;//expect:11
		}

		/// <summary>
		/// test 2
		/// </summary>   
		Triangle_Model GetTestData002(void)
		{
			Triangle_Model result;
			result.triangle = { {-10} };
			return result;//expect:-10
		};

#pragma endregion TestData
	};
}
