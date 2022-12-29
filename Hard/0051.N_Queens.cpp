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
	/// n �ӦZ
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
		///     thinking�G N �ӦZ - �D�n���D�b�P�_�@�ӬӦZ�b ���W�B�W�B�k�W�B���B�k�B���U�B�U�B�k�U �K����|�W�O�_���s�b��
		///               - �g���t��k + ���j�O�@�� - �Q�Τ@�i������ӦZ�����I�A�C�����@�B�A�M�Ỽ�j���U�@�B�A�Y�i�H�Nn�ӬӦZ�񧹴ѽL
		///                 ��ܵ��ץ��T; ���ɵ������M���T�A���ٻݭn��n�ӬӦZ�����k�bRollBack�A���U�@�B�ѡA����n*n �Ҧ�n�ӦZ�����L�@��
		///                 �~��T�w�Ҧ���
		///                 �Q��3���ˮ֪�A���O�� horizontalTable (�ѨM���B�k) ; rightToLeftSlashTable (�k�W-���U) ; 
		///                                       _leftToRightSlashTable (�ѨM���W-�k�U)�A�䤤�W�B�U�i�H�����A�]���w�g�]�t�b�o�T�i��
		///                
		///       Runtime�G   0 ms Beats   100 %
		/// Memory Usage �G 7.6 MB Beats 39.90 %
		/// </summary>	
		vector<vector<string>> _result;
		vector<string> _QueenRecordTable;
		vector<bool> _horizontalTable;
		vector<bool> _rightToLeftSlashTable;
		vector<bool> _leftToRightSlashTable;
		vector<vector<string>> solveNQueens(int n) {
	
			//1. ��R�ѽL���w�]�� EX: "...."
			string pendding(n, '.');
			_QueenRecordTable.resize(n, pendding);
			
			//2. �إ�3�i�ˮ֪�� n = 4 �� �����b��4���I�A�t�~��i��7���I�Atrue��ܥi�q�L�ˮ�
			_horizontalTable.resize(n, true);
			_leftToRightSlashTable.resize(n * 2 - 1, true);
			_rightToLeftSlashTable.resize(n * 2 - 1, true);
			FindQueen(0, n);
			return _result;
		}

		/// <summary>
		/// ���j�j�M
		/// </summary>
		void FindQueen(int xAxis, int n) 
		{
			//Final : �̫�@�ӬӦZ���I�ɬ�n ��ܥi�H�O�� (n = 4 ��� 0,1,2,3 �ӬӦZ����F�A�ҥH�|�����4�ӯ���)
			if (xAxis == n)
			{
				_result.push_back(_QueenRecordTable);
				return;
			}

			//3. �C��y�b���M��x���I�A�T�O�C�泣�ܤ֦��@�ӬӦZ���U��
			for (int yAxis = 0; yAxis < n; yAxis++) 
			{
				//4. �C�����l�ɽT�O�i�H�U
				if (_horizontalTable[yAxis] && _leftToRightSlashTable[yAxis + xAxis] && _rightToLeftSlashTable[n - 1 + xAxis - yAxis] ) 
				{
					//5. �����U�l�A���������ˮָ��|
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
