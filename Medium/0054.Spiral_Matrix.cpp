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
	/// ���ۯx�}
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
		///     thinking�G �̷��D�N�A�ǳƥ|�Ӥ�쪺array ��Ĳ�o��V�ɨϥθӤ�쪺 x, y �Y�ơA�����B�ƥ��n�� row * col 
		///                ���ۨ��k�A�i�ѦҥN�X
		///       Runtime�G  0 ms Beats   100 %
		/// Memory Usage �G6.7 MB Beats 99.76 %
		/// </summary>	
		vector<int> spiralOrder(vector<vector<int>>& matrix) {
			//1. �ǳ�4�Ӥ��G �k -> �U -> �� -> �W
			int move[4][2] = {
				{0 , 1},
				{1 , 0},
				{0 , -1},
				{-1 , 0}
			};
			//2. y�b�Bx�b�C�������B��
			int yStep = matrix.size();
			int xStep = matrix[0].size();
			//3. �`�B�ơA�֭p�����i�H���X
			int totalStep = yStep * xStep;
			yStep -= 1;//�� x�b���ʡA�Gy�b�|�֨��@�B
			int directionStepCount = 0;//������V�������ơA�p�G�Ӥ�V�i�����ƥΧ� �n����V
			int direction = 0;//�w�]���k (x�b)
			int yAxisNextMove = 0;//�U�@�By�b
			int xAxisNextMove = 0;//�U�@�Bx�b
			
			vector<int> result{};
			while (totalStep > 0)
			{
				//4. ���@�B
				result.push_back(matrix[yAxisNextMove][xAxisNextMove]);
				totalStep--;
				directionStepCount++;

				//5. �P�_�O�_�Ӥ�V���ɡA���ɭn����V
				if (
					(direction == 0 || direction == 2) && 
					xStep > 0
					)
				{
					if (directionStepCount % xStep == 0)
					{
						direction = (direction + 1) % 4;
						directionStepCount = 0;
						xStep -= 1;//�U�@����x�b�����֨��@�B
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
						yStep -= 1;//�U�@����y�b�����֨��@�B
					}
				}
				//6. �̷�5.�o�쪺��V�o�X�U�@�B���|
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
