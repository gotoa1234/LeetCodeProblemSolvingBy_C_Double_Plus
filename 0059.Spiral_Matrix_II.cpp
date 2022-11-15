#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution59
{
#pragma region Paste to execute 
	/*
	#include "0059.Spiral_Matrix_II.cpp"
	using namespace Solution59;
	using namespace std;

	int main()
	{
		Solution59::Spiral_Matrix_II useClass;
		Solution59::Spiral_Matrix_II::Spiral_Matrix_II_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.generateMatrix(getTestModel.s);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.generateMatrix(getTestModel.s);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.generateMatrix(getTestModel.s);
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 螺旋矩陣 II
	/// </summary>
	class Spiral_Matrix_II
	{
#pragma region Model
	public:
		class Spiral_Matrix_II_Model
		{
		public:
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 利用特性，先建立n*n 的2D陣列
		///                上 走N步 -> 右 走N-1步 -> 下 走N-1 步 -> 左 走N-2步 .....直到 n*n 的步數走完	
		///       Runtime：  0 ms Beats 100 %
		/// Memory Usage ：6.5 MB Beats 63.18 %
		/// </summary>	
		vector<vector<int>> generateMatrix(int n) {
			//1. 準備方位 上 -> 右 -> 下 -> 左
			int move[4][2] = {
				{0, 1},
				{1, 0},
				{0, -1},
				{-1, 0}
			};
			
			//2. 初始化結果
			vector<vector<int>> result(n, vector<int>(n));
			int currentMoveMaxStep = n;
			int currentDirectorMaxStep = currentMoveMaxStep;
			int useMove = 0;//由上開始
			int maxStep = n * n;
			int moveX = 0;
			int moveY = 0;
			for (int stepValue = 1; stepValue <= maxStep; stepValue++)
			{
				result[moveY][moveX] = stepValue;
				currentDirectorMaxStep--;
				if (currentDirectorMaxStep == 0)
				{
					if (useMove == 0 || useMove == 2)
					{
						currentMoveMaxStep--;
					}
					currentDirectorMaxStep = currentMoveMaxStep;
					useMove = (useMove + 1) % 4;
				}
				moveY += move[useMove][0];
				moveX += move[useMove][1];
			}
			return { result };
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Spiral_Matrix_II_Model GetTestData001(void)
		{
			Spiral_Matrix_II_Model result;
			result.n = 3;
			return result;//except: [[1,2,3],[8,9,4],[7,6,5]] 
		};

		/// <summary>
		/// test data 2
		/// </summary>        
		Spiral_Matrix_II_Model GetTestData002(void)
		{
			Spiral_Matrix_II_Model result;
			result.n = 1;
			return result;//except:  [[1]]
		};
#pragma endregion TestData

	};
}
