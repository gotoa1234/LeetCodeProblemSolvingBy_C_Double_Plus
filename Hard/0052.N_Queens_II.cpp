#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

namespace Solution52
{
#pragma region Paste to execute 
	/*
	#include "0052.N_Queens_II.cpp"
	using namespace Solution52;
	using namespace std;

	int main()
	{

		Solution52::N_Queens_II useClass;
		Solution52::N_Queens_II::N_Queens_II_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.totalNQueens(getTestModel.n);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.totalNQueens(getTestModel.n);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// n 皇后-求解數
	/// </summary>
	class N_Queens_II
	{
#pragma region Model
	public:
		class N_Queens_II_Model
		{
		public:
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking：同0051. 解法，但此題只需回傳數量，所以不用記錄棋盤圖
		///       Runtime：  0 ms Beats   100 %
		/// Memory Usage ：5.8 MB Beats 97.47 %
		/// </summary>	
		int _totalResult = 0;		
		vector<bool> _checkHor;
		vector<bool> _checkLeftUpToRightDown;
		vector<bool> _checkRightUpToLeftDown;
		int totalNQueens(int n) {
			_checkHor.resize(n, true);
			_checkLeftUpToRightDown.resize(n * 2 - 1, true);
			_checkRightUpToLeftDown.resize(n * 2 - 1, true);
			FindQueen(0, n);
			return _totalResult;
		}

		void FindQueen(int xAxis, int& n)
		{
			if (xAxis == n)
			{
				_totalResult++;
				return;
			}
			for (int yAxis = 0; yAxis < n; yAxis++)
			{
				if (_checkHor[yAxis] && _checkLeftUpToRightDown[xAxis + yAxis] && _checkRightUpToLeftDown[n - 1 + xAxis - yAxis])
				{
					_checkHor[yAxis] = false; 
					_checkLeftUpToRightDown[xAxis + yAxis] = false;
					_checkRightUpToLeftDown[n - 1 + xAxis - yAxis] = false;
					FindQueen(xAxis + 1, n);
					_checkHor[yAxis] = true;
					_checkLeftUpToRightDown[xAxis + yAxis] = true;
					_checkRightUpToLeftDown[n - 1 + xAxis - yAxis] = true;
				}
			}
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		N_Queens_II_Model GetTestData001(void)
		{
			N_Queens_II_Model result;
			result.n = 4;
			return result;//except: 2
		};

		/// <summary>
		/// test data 2
		/// </summary>        
		N_Queens_II_Model GetTestData002(void)
		{
			N_Queens_II_Model result;
			result.n = 1;
			return result;//except:1
		};
#pragma endregion TestData

	};
}
