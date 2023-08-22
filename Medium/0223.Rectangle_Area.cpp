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
	/// ¯x°}°Ï°ì
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
		///     thinking¡G		
		///       Runtime¡G
		/// Memory Usage ¡G
		/// </summary>
		int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
			
			auto aArea = CaculationArea(ax1, ay1, ax2, ay2);
			auto bArea = CaculationArea(bx1, by1, bx2, by2);
			auto overlapArea = aArea >= bArea ? FindOverlapArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2)
				                              : FindOverlapArea(bx1, by1, bx2, by2, ax1, ay1, ax2, ay2);
			auto result =  aArea + bArea - overlapArea;
			return result;
		}

		int FindOverlapArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
		{
			int result = 0;
			int aXAxisLeft = ax1 < ax2 ? ax1 : ax2;
			int aXAxisRight = ax1 < ax2 ? ax2 : ax1;
			int aYAxisTop = ay1 < ay2 ? ay1 : ay2;
			int aYAxisDown = ay1 < ay2 ? ay2 : ay1;

			int bXAxisLeft = bx1 < bx2 ? bx1 : bx2;
			int bXAxisRight = bx1 < bx2 ? bx2 : bx1;
			int bYAxisTop = by1 < by2 ? by1 : by2;
			int bYAxisDown = by1 < by2 ? by2 : by1;
		
			bool isXOverLap = (aXAxisLeft <= bXAxisLeft && bXAxisLeft <= aXAxisRight) || (aXAxisLeft <= bXAxisRight && bXAxisRight <= aXAxisRight);
			bool isYOverLap = (aYAxisTop <= bYAxisTop && bYAxisTop <= aYAxisDown) || (aYAxisTop <= bYAxisDown && bYAxisDown <= aYAxisDown);
			
			if (isXOverLap && isYOverLap)
			{
				int aXLeft = aXAxisLeft < bXAxisLeft ? bXAxisLeft : aXAxisLeft;
				int bYTop = bYAxisTop < aYAxisTop? aYAxisTop : bYAxisTop;
				int aXRight = bXAxisRight < aXAxisRight ? bXAxisRight : aXAxisRight;
				int bYDown = aYAxisDown < bYAxisDown ? bYAxisDown : aYAxisDown;
				result = CaculationArea(aXLeft, bYTop, aXRight, bYDown);
			}
			return result;
		}

		int CaculationArea(int x1, int y1, int x2, int y2)
		{
			int height = abs(y1 - y2);
			int wedth = abs(x1 - x2);
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


#pragma endregion TestData

	};
}