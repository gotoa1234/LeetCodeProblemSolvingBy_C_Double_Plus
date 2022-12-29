#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution54
{
#pragma region Paste to execute 
	/*
	#include "0054.Spiral_Matrix.cpp"
	using namespace Solution54;
	using namespace std;

	int main()
	{
		Solution54::Spiral_Matrix useClass;
		Solution54::Spiral_Matrix::Spiral_Matrix_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.spiralOrder(getTestModel.matrix);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.spiralOrder(getTestModel.matrix);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.spiralOrder(getTestModel.matrix);

		getTestModel = useClass.GetTestData004();
		auto result4 = useClass.spiralOrder(getTestModel.matrix);

		getTestModel = useClass.GetTestData005();
		auto result5 = useClass.spiralOrder(getTestModel.matrix);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 螺旋矩陣
	/// </summary>
	class Spiral_Matrix
	{
#pragma region Model
	public:
		class Spiral_Matrix_Model
		{
		public:
			vector<vector<int>> matrix;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 依照題意，準備四個方位的array 當觸發轉向時使用該方位的 x, y 係數，走的步數正好為 row * col 
		///                螺旋走法，可參考代碼
		///       Runtime：  0 ms Beats   100 %
		/// Memory Usage ：6.7 MB Beats 99.76 %
		/// </summary>	
		vector<int> spiralOrder(vector<vector<int>>& matrix) {
			//1. 準備4個方位： 右 -> 下 -> 左 -> 上
			int move[4][2] = {
				{0 , 1},
				{1 , 0},
				{0 , -1},
				{-1 , 0}
			};
			//2. y軸、x軸每次走的步數
			int yStep = matrix.size();
			int xStep = matrix[0].size();
			//3. 總步數，累計走完可以跳出
			int totalStep = yStep * xStep;
			yStep -= 1;//※ x軸先動，故y軸會少走一步
			int directionStepCount = 0;//紀錄方向走的次數，如果該方向可走次數用完 要換方向
			int direction = 0;//預設往右 (x軸)
			int yAxisNextMove = 0;//下一步y軸
			int xAxisNextMove = 0;//下一步x軸
			
			vector<int> result{};
			while (totalStep > 0)
			{
				//4. 走一步
				result.push_back(matrix[yAxisNextMove][xAxisNextMove]);
				totalStep--;
				directionStepCount++;

				//5. 判斷是否該方向走盡，走盡要換方向
				if (
					(direction == 0 || direction == 2) && 
					xStep > 0
					)
				{
					if (directionStepCount % xStep == 0)
					{
						direction = (direction + 1) % 4;
						directionStepCount = 0;
						xStep -= 1;//下一次的x軸必須少走一步
					}
				}
				else if(
					(direction == 1 || direction == 3) &&
					yStep > 0
					)
				{
					if (directionStepCount % yStep == 0)
					{
						direction = (direction + 1) % 4;
						directionStepCount = 0;
						yStep -= 1;//下一次的y軸必須少走一步
					}
				}
				//6. 依照5.得到的方向得出下一步路徑
				yAxisNextMove += move[direction][0];
				xAxisNextMove += move[direction][1];
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Spiral_Matrix_Model GetTestData001(void)
		{
			Spiral_Matrix_Model result;
			result.matrix = { 
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};
			return result;//except: { 1, 2, 3, 6, 9, 8, 7, 4, 5}
		};

		/// <summary>
		/// test data 2
		/// </summary>        
		Spiral_Matrix_Model GetTestData002(void)
		{
			Spiral_Matrix_Model result;
			result.matrix = {
				{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12}
			};
			return result;//except: {1,2,3,4,8,12,11,10,9,5,6,7}
		};

		/// <summary>
		/// test data 3
		/// </summary>        
		Spiral_Matrix_Model GetTestData003(void)
		{
			Spiral_Matrix_Model result;
			result.matrix = {
				{1},
				{2}, 
				{3}
			};
			return result;//except: {1,2,3}
		};

		/// <summary>
		/// test data 4
		/// </summary>        
		Spiral_Matrix_Model GetTestData004(void)
		{
			Spiral_Matrix_Model result;
			result.matrix = {
				{1,2,3}
			};
			return result;//except: {1,2,3}
		};


		/// <summary>
		/// test data 5
		/// </summary>        
		Spiral_Matrix_Model GetTestData005(void)
		{
			Spiral_Matrix_Model result;
			result.matrix = {
				{1}
			};
			return result;//except: {1}
		};



#pragma endregion TestData

	};
}
