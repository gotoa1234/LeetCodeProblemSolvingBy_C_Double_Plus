#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

namespace Solution221
{
#pragma region Paste to execute 
	/*
	#include "Medium\0221.Maximal_Square.cpp"
	using namespace Solution221;
	using namespace std;

	int main()
	{
		vector<vector<int>> result = {};
		Solution221::Maximal_Square useClass;
		Solution221::Maximal_Square::Maximal_Square_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.maximalSquare(getTestModel.matrix);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.maximalSquare(getTestModel.matrix);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.maximalSquare(getTestModel.matrix);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �̤j�x�}
	/// </summary>
	class Maximal_Square
	{
#pragma region Model
	public:
		class Maximal_Square_Model
		{
		public:
			vector<vector<char>> matrix;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking�GDP�D�A�q���w��matrix�̥k�U���}�l�A�çQ�Ψ��Vector<int> ����
		///               �C�@�C�⧹��A�֭p�ܤW�@�C�A�ŦX�﨤+�k+�U�����ߪ����p�U�~�i�֥[			
		///       Runtime�G  63 ms Beats 98.79 %
		/// Memory Usage �G18.7 MB Beats 95.40 %
		/// </summary>
		int maximalSquare(vector<vector<char>>& matrix) {
			int xAxisMax = matrix.size();
			int yAxisMax = matrix[0].size();
			vector<int> preVecs(yAxisMax + 1, 0);
			vector<int> currVecs(yAxisMax + 1, 0);
			int result = 0;
			//1. �̥k�U�}�l�p��
			for (int xAxis = xAxisMax - 1; xAxis >= 0; xAxis--) 
			{
				for (int yAxis = yAxisMax - 1; yAxis >= 0; yAxis--) 
				{				
					int right = currVecs[yAxis + 1];//�k�O�ݷ�e�C
					int down = preVecs[yAxis];//�U�O�ݫe�@�C
					int diagonal = preVecs[yAxis + 1];//�k�U�]�O�ݫe�@�C
					//2-1. �p�G�k+�U+�k�U(�﨤)�����ȡA��ܯx�}���ߡA�i��֭p
					if (matrix[xAxis][yAxis] == '1') 
					{
						
						currVecs[yAxis] = 1 + min(right, min(diagonal, down));
						result = max(result, currVecs[yAxis]);
					}//2-2. �p�G���O'1'�ɡA�����]��0
					else 
						currVecs[yAxis] = 0;					
				}
				preVecs = currVecs;
			}
			//3. �x�}n*n �ҥH�^�Ǭ�����
			return result * result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Maximal_Square_Model GetTestData001(void)
		{
			Maximal_Square_Model result;
			result.matrix = { {'1', '0', '1', '0', '0'}, 
				              {'1', '0', '1', '1', '1'}, 
				              {'1', '1', '1', '1', '1'}, 
				              {'1', '0', '0', '1', '0'} };
			return result;//except: 4
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Maximal_Square_Model GetTestData002(void)
		{
			Maximal_Square_Model result;
			result.matrix = { {'1', '0',},
							  {'1', '0',} };
			return result;//except: 1
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Maximal_Square_Model GetTestData003(void)
		{
			Maximal_Square_Model result;
			result.matrix = { {'0'} };
			return result;//except: 0
		};

		/// <summary>
		/// test data 4
		/// </summary>   
		Maximal_Square_Model GetTestData004(void)
		{
			Maximal_Square_Model result;
			result.matrix = { {'1','1','1','1','0'},
				              {'1','1','1','1','0'},
				              {'1','1','1','1','1'},
				              {'1','1','1','1','1'},
				              {'0','0','1','1','1'}};
			return result;//except: 16
		};

		/// <summary>
		/// test data 5
		/// </summary>   
		Maximal_Square_Model GetTestData005(void)
		{
			Maximal_Square_Model result;
			result.matrix = { {'0','0','0','1','0','1','1','1'},
				              {'0','1','1','0','0','1','0','1'},
				              {'1','0','1','1','1','1','0','1'},
				              {'0','0','0','1','0','0','0','0'},
				              {'0','0','1','0','0','0','1','0'},
				              {'1','1','1','0','0','1','1','1'},
				              {'1','0','0','1','1','0','0','1'},
				              {'0','1','0','0','1','1','0','0'},
				              {'1','0','0','1','0','0','0','0'} };
			return result;//except: 1
		};
#pragma endregion TestData

	};
}