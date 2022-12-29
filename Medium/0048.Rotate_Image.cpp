#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution48
{
#pragma region Paste to execute 
	/*
	#include "0048.Rotate_Image.cpp"
	using namespace Solution48;
	using namespace std;

	int main()
	{

		Solution48::Rotate_Image useClass;
		Solution48::Rotate_Image::Rotate_Image_Model getTestModel = useClass.GetTestData001();
		useClass.rotate(getTestModel.matrix);

		getTestModel = useClass.GetTestData002();
		useClass.rotate(getTestModel.matrix);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ����Ϲ�
	/// </summary>
	class Rotate_Image
	{
#pragma region Model
	public:
		class Rotate_Image_Model
		{
		public:
			vector<vector<int>> matrix;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking�G ���󭭨� �Ŷ��ϥ�:O(1)�A�u���\��쥻���x�}�A�ҥH�o�D�����[��O
		///                1, 2, 3       7, 4 ,1                                            1, 4, 7
		///                4, 5, 6   =>  8, 5, 2   => �i�Q��[x][y] �﨤�ﴫ�覡�ARevese =>  2, 5, 8
		///                7, 8, 9       9, 6, 3                                            3, 6, 9
		///                ��l���     �ؼе��G                                           �w�B�z
		///       Runtime�G3ms Beats 70.96%
		/// Memory Usage �G7MB Beats 92.85%
		/// </summary>	
		void rotate(vector<vector<int>>& matrix) {
			int tempValue = 0;
			for (int yAxis = 0; yAxis < matrix.size(); yAxis++)
			{
				for (int xAxis = yAxis + 1; xAxis < matrix.size(); xAxis++)
				{
					tempValue = matrix[yAxis][xAxis];
					matrix[yAxis][xAxis] = matrix[xAxis][yAxis];
					matrix[xAxis][yAxis] = tempValue;
				}
				reverse(matrix[yAxis].begin(), matrix[yAxis].end());
			}
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Rotate_Image_Model GetTestData001(void)
		{
			Rotate_Image_Model result;
			result.matrix = { {1, 2, 3},{4, 5, 6 },{7, 8, 9 }};
			return result;//except: {{7,4,1},{8,5,2},{9,6,3}}
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Rotate_Image_Model GetTestData002(void)
		{
			Rotate_Image_Model result;
			result.matrix = { {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16} };
			return result;//except:{{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}}
		};

#pragma endregion TestData

	};
}
