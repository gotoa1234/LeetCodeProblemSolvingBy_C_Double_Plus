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
		///     thinking： N 皇后 - 主要難題在判斷一個皇后在 左上、上、右上、左、右、左下、下、右下 八方路徑上是否有存在值
		///               - 貪婪演算法 + 遞迴是一解 - 利用一張表紀錄皇后的落點，每模擬一步，然後遞迴走下一步，若可以將n個皇后放完棋盤
		///                 表示答案正確; 此時答案雖然正確，但還需要把n個皇后的走法在RollBack，走下一步棋，直到n*n 所有n皇后都走過一輪
		///                 才能確定所有解
		///                 利用3個檢核表，分別用 horizontalTable (解決左、右) ; rightToLeftSlashTable (右上-左下) ; 
		///                                       _leftToRightSlashTable (解決左上-右下)，其中上、下可以忽略，因為已經包含在這三張表中
		///                
		///       Runtime：   0 ms Beats   100 %
		/// Memory Usage ： 7.6 MB Beats 39.90 %
		/// </summary>	
		vector<vector<string>> _result;
		vector<string> _QueenRecordTable;
		vector<bool> _horizontalTable;
		vector<bool> _rightToLeftSlashTable;
		vector<bool> _leftToRightSlashTable;
		vector<vector<string>> solveNQueens(int n) {
	
			//1. 填充棋盤為預設值 EX: "...."
			string pendding(n, '.');
			_QueenRecordTable.resize(n, pendding);
			
			//2. 建立3張檢核表當 n = 4 時 水平軸為4個點，另外兩張表有7個點，true表示可通過檢核
			_horizontalTable.resize(n, true);
			_leftToRightSlashTable.resize(n * 2 - 1, true);
			_rightToLeftSlashTable.resize(n * 2 - 1, true);
			FindQueen(0, n);
			return _result;
		}

		/// <summary>
		/// 遞迴搜尋
		/// </summary>
		void FindQueen(int xAxis, int n) 
		{
			//Final : 最後一個皇后落點時為n 表示可以記錄 (n = 4 表示 0,1,2,3 個皇后都放了，所以會走到第4個索引)
			if (xAxis == n)
			{
				_result.push_back(_QueenRecordTable);
				return;
			}

			//3. 每個y軸都遍歷x落點，確保每行都至少有一個皇后有下到
			for (int yAxis = 0; yAxis < n; yAxis++) 
			{
				//4. 每次落子時確保可以下
				if (_horizontalTable[yAxis] && _leftToRightSlashTable[yAxis + xAxis] && _rightToLeftSlashTable[n - 1 + xAxis - yAxis] ) 
				{
					//5. 模擬下子，關閉對應檢核路徑
					_QueenRecordTable[yAxis][xAxis] = 'Q';
					_horizontalTable[yAxis] = false;
					_leftToRightSlashTable[yAxis + xAxis] = false;
					_rightToLeftSlashTable[n - 1 + xAxis - yAxis] = false;
					FindQueen(xAxis + 1, n);
					_QueenRecordTable[yAxis][xAxis] = '.';
					_horizontalTable[yAxis] = true;
					_leftToRightSlashTable[yAxis + xAxis] = true;
					_rightToLeftSlashTable[n - 1 + xAxis - yAxis] = true;
				}
			}
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
