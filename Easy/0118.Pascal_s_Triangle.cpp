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
		auto result1 = useClass.generate(getTestModel.numRows);

		getTestModel = useClass.GetTestData002();
		auto result2 =useClass.generate(getTestModel.numRows);
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
		///          思路：利用帕斯卡三角的遞增性，頭、尾都是1，然後中間的值都是上一層的值的加總
		///       Runtime :  0 ms Beats 100 %
		///  Memory Usage :6.8 MB Beats 14.1 %
		/// </summary>
		vector<vector<int>> generate(int numRows) {
			numRows = numRows - 1;
			vector<vector<int>> result{};
			result.push_back({ 1 });
			for (int index = 1; index <= numRows; index++)
			{
				vector<int> arrayItem{};
				arrayItem.push_back(1);
				for (int loopCount = 1; loopCount < index; loopCount++)
				{
					arrayItem.push_back(result[index - 1][loopCount - 1] + result[index - 1][loopCount]);
				}
				arrayItem.push_back(1);
				result.push_back(arrayItem);
			}
			return result;
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
