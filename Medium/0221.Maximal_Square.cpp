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
	/// ³Ì¤j¯x°}
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
		///     thinking¡G		
		///       Runtime¡G
		/// Memory Usage ¡G
		/// </summary>
		int maximalSquare(vector<vector<char>>& matrix) {
			auto maxSquareValue = 0;
			for (int xAxis = 0; xAxis < matrix.size(); xAxis++)
			{
				for (int yAxis = 0; yAxis < matrix[xAxis].size(); yAxis++)
				{
					if (matrix[xAxis][yAxis] == 1)
					{
						auto getLevel = ExtendedExploration(xAxis, yAxis, 1, xAxis + 1, yAxis + 1, matrix);
						maxSquareValue = max(maxSquareValue, getLevel);
					}
				}
			}
			return maxSquareValue;
		}

		int ExtendedExploration(int origineX, int origineY, int level, int xAxisMax, int yAxisMax, vector<vector<char>>& matrix)
		{						
			if (xAxisMax >= matrix.size() || yAxisMax >= matrix[origineX].size())
				return level;

			bool isSquare = true;					
			for (int xAxis = origineX + level, yAxis = origineY; yAxis < yAxisMax; yAxis++)
			{
				if (matrix[xAxis][yAxis] == 0)
				{
					isSquare = false;
					break;
				}
			}
			if(isSquare)
		    for (int xAxis = origineX, yAxis = origineY + level; xAxis < xAxisMax; xAxis++)
			{				
				if (matrix[xAxis][yAxis] == 0)
				{
					isSquare = false;
					break;
				}
			}
			if (isSquare)
			{
				level++;
				level = ExtendedExploration(origineX, origineY, level, xAxisMax + level, yAxisMax + level, matrix);
			}
			return level;
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
#pragma endregion TestData

	};
}