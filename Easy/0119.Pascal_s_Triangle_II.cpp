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
		auto result1 = useClass.getRow(getTestModel.rowIndex);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.getRow(getTestModel.rowIndex);
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
			int rowIndex;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路： 與118.邏輯相同，但要移除2維陣列，並利用本次的結果計算於下一次，才能加快速度
		///       Runtime :   0 ms Beats 100 %
		///  Memory Usage : 6.3 MB Beats 81.35 %
		/// </summary>
		vector<int> getRow(int rowIndex) {
			vector<int> result{};
			//1. 遍歷每層
			for (int index = 0; index <= rowIndex; index++)
			{
				//2. 每進新的一層加入帕斯卡的首位數1在最前端
				result.insert(result.begin(), 1);
				//3. 每次加總都只累計中間的值，完成帕斯卡累進
				for (int loopCount = 1; loopCount < index; loopCount++)				
					result[loopCount] = result[loopCount] + result[loopCount + 1];
			}
			return result;
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
			result.rowIndex = 3;

			return result;//expect:[1,3,3,1]
		}

		/// <summary>
		/// test 2
		/// </summary>   
		Pascal_s_Triangle_II_Model GetTestData002(void)
		{
			Pascal_s_Triangle_II_Model result;
			result.rowIndex = 0;
			return result;//expect:[[1]]
		};

		/// <summary>
		/// test 3
		/// </summary>   
		Pascal_s_Triangle_II_Model GetTestData003(void)
		{
			Pascal_s_Triangle_II_Model result;
			result.rowIndex = 1;
			return result;//expect:[[1,1]]
		};

#pragma endregion TestData
	};
}
