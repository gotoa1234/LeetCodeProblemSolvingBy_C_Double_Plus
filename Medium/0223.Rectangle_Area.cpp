#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

namespace Solution223
{
#pragma region Paste to execute 
	/*
	#include "Medium\0223.Rectangle_Area.cpp"
	using namespace Solution223;
	using namespace std;

	int main()
	{
		vector<vector<int>> result = {};
		Solution223::Rectangle_Area useClass;
		Solution223::Rectangle_Area::Rectangle_Area_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.computeArea(getTestModel.ax1, getTestModel.ay1, getTestModel.ax2, getTestModel.ay2, getTestModel.bx1, getTestModel.by1, getTestModel.bx2, getTestModel.by2);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.computeArea(getTestModel.ax1, getTestModel.ay1, getTestModel.ax2, getTestModel.ay2, getTestModel.bx1, getTestModel.by1, getTestModel.bx2, getTestModel.by2);

		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 矩陣區域
	/// </summary>
	class Rectangle_Area
	{
#pragma region Model
	public:
		class Rectangle_Area_Model
		{
		public:
			int ax1;
			int ay1; 
			int ax2; 
			int ay2; 
			int bx1; 
			int by1;
			int bx2;
			int by2;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking：將兩個矩形相加後，再減去重疊的地方，關鍵在如何找出重疊的方法
		///       Runtime：0 ms Beats 100.0 %
		/// Memory Usage ：6 MB Beats 14.83 %
		/// </summary>
		int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

			auto aArea = CaculationArea(ax1, ay1, ax2, ay2);
			auto bArea = CaculationArea(bx1, by1, bx2, by2);
			auto overlapArea = FindOverlapArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
			auto result = aArea + bArea - overlapArea;
			return result;
		}

		int FindOverlapArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
		{
			int result = 0;
			int aXLeft = max(ax1, bx1);
			int aXRight = min(ax2, bx2);
			int bYTop = min(ay2, by2);
			int bYDown = max(ay1, by1);
			//這邊是判斷重疊，如果左邊的x,y 有其中大於右邊的x,y 必定不重疊，回傳0
			result = aXLeft > aXRight || bYDown > bYTop ? 0
			                                            : CaculationArea(aXLeft, bYDown, aXRight, bYTop);
			return result;
		}

		int CaculationArea(int x1, int y1, int x2, int y2)
		{
			int height = y2 - y1;
			int wedth = x2 - x1;
			return height * wedth;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Rectangle_Area_Model GetTestData001(void)
		{
			Rectangle_Area_Model result;
			result.ax1 = -3;
			result.ay1 = 0; 
			result.ax2 = 3; 
			result.ay2 = 4; 
			result.bx1 = 0; 
			result.by1 = -1;
			result.bx2 = 9;
			result.by2 = 2;
			return result;//except: 4
		};

		/// <summary>
		/// test data 2
		/// </summary>        
		Rectangle_Area_Model GetTestData002(void)
		{
			Rectangle_Area_Model result;
			result.ax1 = -2;
			result.ay1 = -2; 
			result.ax2 = 2; 
			result.ay2 = 2; 
			result.bx1 = 3; 
			result.by1 = 3;
			result.bx2 = 4;
			result.by2 = 4;
			return result;//except: 24
		};
#pragma endregion TestData

	};
}