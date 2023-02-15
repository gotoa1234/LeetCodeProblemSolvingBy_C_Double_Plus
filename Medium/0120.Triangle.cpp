#include <iostream>
#include <vector>
using namespace std;

namespace Solution120
{
#pragma region Paste to execute 
	/*
	#include "Medium\0120.Triangle.cpp"
	using namespace Solution120;
	using namespace std;

	int main()
	{
		Solution120::Triangle useClass;
		Solution120::Triangle::Triangle_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.minimumTotal(getTestModel.triangle);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.minimumTotal(getTestModel.triangle);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �T���� 
	/// </summary>
	class Triangle
	{
#pragma region Model
	public:
		class Triangle_Model
		{
		public:
			vector<vector<int>> triangle;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G �̨θѬO�ʺA�W��DP �A�w���L�������b���ư���A
		///                 ���D�حn�D�̦h�ϥ�Space O(n)�A�]���Q�γ̫�T���γ̤@�h�}�l�p��A�̫�dp[0] �N�O�̲׸�
		///       Runtime :   0 ms Beats 100 %
		///  Memory Usage : 8.6 MB Beats 95.11 %
		///����    �T���μh��Array   
		/// 0   |   2
		/// 1   |   3 4
		/// 2   |   6 5 7
		/// 3   |   4 1 8 3
		/// 
		/// �B�J: 4 1  8  3   -> ��l�� �ɥγ̫�@�h
		///     : 7 1  8  3   -> ���h[2][0] = 6  -> 6�P[3][0] �� 6�P[3][1] �p�������G7 (6+1)
		///     : 7 6  8  3   -> ���h[2][1] = 5  -> 5�P[3][1] �� 5�P[3][2] �p�������G6 (5+1)
		///     : 7 6  10 3   -> ���h[2][2] = 7  -> 7�P[3][2] �� 7�P[3][3] �p�������G10(7+3)
		///     ----------
		///     : 9 6  10 3   -> ���h[1][0] = 3  -> 3�P[3][0] �� 3�P[3][1] �p�������G9 (3+6)
		///     : 9 10 10 3   -> ���h[1][1] = 4  -> 4�P[3][1] �� 4�P[3][2] �p�������G10(4+6)
		///     ----------
		///     : 11 10 10 3  -> ���h[1][0] = 2  -> 2�P[3][0] �� 2�P[3][1] �p�������G11(2+9)
		/// </summary>
		int minimumTotal(vector<vector<int>>& triangle) 
		{	
			//1. �ɥ��D�ؤT���Ϊ��̫�@�C�A��DP�p��s�񪺦�m
			vector<int> dp(triangle.back());
			for (int index = (int)triangle.size() - 2; index >= 0; index--) 
			{
				//2. �Q��Dp�̫�@�h�A�P�e�@�h�[�`���idp���A�M��A���W�@�h���ƭp��
				for (int innerIndex = 0; innerIndex <= index; innerIndex++) 
				{
					dp[innerIndex] = min(dp[innerIndex], dp[innerIndex + 1]) + triangle[index][innerIndex];
				}
			}
			//3. �̲ת��֥[�̤p�ȴN�Odp[0]
			return dp[0];		
		}

		// [���~] �H�U�O���j���� - ���w�W��
		int minimumTotal_Recursive(vector<vector<int>>& triangle)
		{

			auto getResult = FindValue_Recursive(0, 0, triangle);
			return getResult;
		}
		int FindValue_Recursive(int rowIndex, int currentDepth, vector<vector<int>>& triangle)
		{
			if (currentDepth >= triangle.size() ||
				rowIndex >= triangle[currentDepth].size())
			{
				return 0;
			}
			int leftTotal = FindValue_Recursive(rowIndex, currentDepth + 1, triangle);
			int rightTotal = FindValue_Recursive(rowIndex + 1, currentDepth + 1, triangle);
			return triangle[currentDepth][rowIndex] + min(leftTotal, rightTotal);
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Triangle_Model GetTestData001(void)
		{
			Triangle_Model result;
			result.triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
			return result;//expect:11
		}

		/// <summary>
		/// test 2
		/// </summary>   
		Triangle_Model GetTestData002(void)
		{
			Triangle_Model result;
			result.triangle = { {-10} };
			return result;//expect:-10
		};

#pragma endregion TestData
	};
}
