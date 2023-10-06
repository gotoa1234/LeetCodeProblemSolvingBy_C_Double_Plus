#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution566
{
#pragma region Paste to execute 
	/*
	#include "Easy\0566.Reshape_the_Matrix.cpp"
	using namespace Solution566;

	int main()
	{
		Solution566::Reshape_the_Matrix useClass;
		Solution566::Reshape_the_Matrix::Reshape_the_Matrix_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.matrixReshape(getTestModel.mat, getTestModel.r, getTestModel.c);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.matrixReshape(getTestModel.mat, getTestModel.r, getTestModel.c);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// Array 切割
	/// </summary>
	class Reshape_the_Matrix
	{
#pragma region Model
		public:
		class Reshape_the_Matrix_Model
		{
			public:
			vector<vector<int>> mat;
			int r;
			int c;
		};
#pragma endregion Model

#pragma region Main
		public:
		/// <summary>
		///          思路 :轉置矩陣，如果r*c 不等於當前的mat的m * n 回傳mat否則，轉成r * c 矩陣		
		///                在For回圈中盡量避免用判斷式，否則有很大機會效能不好。
		///       Runtime :   8 ms Beats 70.5 %
		///  Memory Usage :11.2 MB Beats 22.40 %
		/// </summary>
		vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
		{
			if (mat.size() * mat[0].size() != r * c)
				return mat;

			vector<vector<int>> result(r, vector<int>(c , 0));			
			for (int xAxis = 0; xAxis < mat.size(); xAxis++)
			{
				for (int yAxis = 0; yAxis < mat[0].size(); yAxis++)
				{					
					result[(xAxis * mat[0].size() + yAxis) / c][(xAxis * mat[0].size() + yAxis) % c] = mat[xAxis][yAxis];
				}
			}			
			return result;
		}
#pragma endregion Main

#pragma region TestData
		public:
		/// <summary>
		/// test 1
		/// </summary>        
		Reshape_the_Matrix_Model GetTestData001(void)
		{
			Reshape_the_Matrix_Model result; 
            result.mat = { {1, 2}, { 3,4} };
			result.r = 1;
			result.c = 4;
			return result;//expect : {1,2,3,4}
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Reshape_the_Matrix_Model GetTestData002(void)
		{
			Reshape_the_Matrix_Model result;
			result.mat = { {1, 2}, { 3,4} };
			result.r = 2;
			result.c = 4;
			return result;//expect : { {1, 2}, { 3,4} };
		};

#pragma endregion TestData
	};
}