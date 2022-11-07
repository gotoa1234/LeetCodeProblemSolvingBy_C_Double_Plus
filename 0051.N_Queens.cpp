#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution51
{
#pragma region Paste to execute 
	/*
	#include "0051.N_Queens.cpp"
	using namespace Solution51;
	using namespace std;

	int main()
	{

		Solution51::N_Queens useClass;
		Solution51::N_Queens::N_Queens_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.solveNQueens(getTestModel.n);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.solveNQueens(getTestModel.n);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// n 皇后
	/// </summary>
	class N_Queens
	{
#pragma region Model
	public:
		class N_Queens_Model
		{
		public:
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 
		///                
		///                
		///       Runtime：
		/// Memory Usage ：
		/// </summary>	
		vector<vector<bool>> _recordQueen{};
		vector<vector<string>> _result{};
		unordered_map<string, bool> _hashTable{};
		int _totalQueenCount = 0;
		vector<vector<string>> solveNQueens(int n) {

			if (n == 1)
				return { {"Q"} };

			//Inital
			for (int yAxis = 0; yAxis < n; yAxis++)
			{
				vector<bool> newItem{};
				for (int xAxis = 0; xAxis < n; xAxis++)
				{
					newItem.push_back(false);
				}
				_recordQueen.push_back(newItem);
			}

			for (int indexX = 0; indexX < n && _totalQueenCount != n; indexX++)
			{
				for (int indexY = 0; indexY < n && _totalQueenCount != n; indexY++)
				{
					FindSolveNQueens(indexX, indexY, n);					
				}
			}

			return _result;
		}

		bool FindSolveNQueens(int yAxis, int xAxis, int n)
		{
			if (_totalQueenCount == n)
			{
				vector<string> newItem{};
				string key = "";
				//Output
				for (int y = 0; y< n; y++)
				{
					string sss = {};
					for (int x = 0; x < n; x++)
					{
						sss.push_back(_recordQueen[y][x] == true ? 'Q' : '.');						
						key.push_back(_recordQueen[y][x] == true ? 'Q' : '.');
					}
					newItem.push_back(sss);
				}
				if (_hashTable.find(key) == _hashTable.end())
				{
					_hashTable[key] = true;
					_result.push_back(newItem);
				}
				return false;
			}

			//Check 左上
			for (int yCheckAxis = yAxis - 1, xCheckAxis = xAxis - 1; yCheckAxis >= 0 && xCheckAxis >= 0; yCheckAxis--, xCheckAxis--)
			{
				if (_recordQueen[yCheckAxis][xCheckAxis] && !(yAxis == yCheckAxis && xAxis == xCheckAxis))
					return false;
			}
			//Check 上
			for (int yCheckAxis = yAxis - 1; yCheckAxis >= 0; yCheckAxis--)
			{
				if (_recordQueen[yCheckAxis][xAxis] && !(yAxis == yCheckAxis))
					return false;
			}
			//Check 右上
			for (int yCheckAxis = yAxis - 1, xCheckAxis = xAxis + 1; yCheckAxis >= 0 && xCheckAxis < n; yCheckAxis--, xCheckAxis++)
			{
				if (_recordQueen[yCheckAxis][xCheckAxis] && !(yAxis == yCheckAxis && xAxis == xCheckAxis))
					return false;
			}
			
			//Check 左
			for (int xCheckAxis = xAxis - 1; xCheckAxis >= 0; xCheckAxis--)
			{
				if (_recordQueen[yAxis][xCheckAxis] && !(xAxis == xCheckAxis))
					return false;
			}
			//Check 右
			for (int xCheckAxis = xAxis + 1; xCheckAxis < n; xCheckAxis++)
			{
				if (_recordQueen[yAxis][xCheckAxis] && !(xAxis == xCheckAxis))
					return false;
			}
			//Check 左下
			for (int yCheckAxis = yAxis + 1, xCheckAxis = xAxis - 1; yCheckAxis < n && xCheckAxis >= 0; yCheckAxis++, xCheckAxis--)
			{
				if (_recordQueen[yCheckAxis][xCheckAxis] && !(yAxis == yCheckAxis && xAxis == xCheckAxis))
					return false;
			}
			//Check 下 
			for (int yCheckAxis = yAxis + 1; yCheckAxis < n; yCheckAxis++)
			{
				if (_recordQueen[yCheckAxis][xAxis] && !(yAxis == yCheckAxis) )
					return false;
			}
			//Check 右下 
			for (int yCheckAxis = yAxis + 1 , xCheckAxis = xAxis + 1; yCheckAxis < n && xCheckAxis < n; yCheckAxis++, xCheckAxis++)
			{
				if (_recordQueen[yCheckAxis][xCheckAxis] && !(yAxis == yCheckAxis && xAxis == xCheckAxis))
					return false;
			}

			
			int nextX = xAxis + 1 < n ? xAxis + 1 : 0;
			int nextY = nextX == 0 ? yAxis + 1 : yAxis;
			while (nextY < n && _totalQueenCount != n && nextX < n)
			{
				_recordQueen[yAxis][xAxis] = true;
				_totalQueenCount++;
				if (FindSolveNQueens(nextY, nextX, n) == false)
				{
					_recordQueen[yAxis][xAxis] = false;
					_totalQueenCount--;
				}
				nextX = nextX + 1 < n ? nextX + 1 : 0;
				nextY = nextX == 0 ? nextY + 1 : nextY;
			}
			return false;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		N_Queens_Model GetTestData001(void)
		{
			N_Queens_Model result;
			result.n = 4;
			return result;//except: [[".Q..", "...Q", "Q...", "..Q."], ["..Q.", "Q...", "...Q", ".Q.."]]
		};

		/// <summary>
		/// test data 2
		/// </summary>        
		N_Queens_Model GetTestData002(void)
		{
			N_Queens_Model result;
			result.n = 1;
			return result;//except: {"Q"}
		};
#pragma endregion TestData

	};
}
