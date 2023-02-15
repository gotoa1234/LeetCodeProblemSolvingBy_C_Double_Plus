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
	/// 三角形 
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
		///          思路： 最佳解是動態規劃DP ，已走過的路不在重複執行，
		///                 ※題目要求最多使用Space O(n)，因此利用最後三角形最一層開始計算，最後dp[0] 就是最終解
		///       Runtime :   0 ms Beats 100 %
		///  Memory Usage : 8.6 MB Beats 95.11 %
		///索引    三角形層數Array   
		/// 0   |   2
		/// 1   |   3 4
		/// 2   |   6 5 7
		/// 3   |   4 1 8 3
		/// 
		/// 步驟: 4 1  8  3   -> 原始值 借用最後一層
		///     : 7 1  8  3   -> 階層[2][0] = 6  -> 6與[3][0] 或 6與[3][1] 小的為結果7 (6+1)
		///     : 7 6  8  3   -> 階層[2][1] = 5  -> 5與[3][1] 或 5與[3][2] 小的為結果6 (5+1)
		///     : 7 6  10 3   -> 階層[2][2] = 7  -> 7與[3][2] 或 7與[3][3] 小的為結果10(7+3)
		///     ----------
		///     : 9 6  10 3   -> 階層[1][0] = 3  -> 3與[3][0] 或 3與[3][1] 小的為結果9 (3+6)
		///     : 9 10 10 3   -> 階層[1][1] = 4  -> 4與[3][1] 或 4與[3][2] 小的為結果10(4+6)
		///     ----------
		///     : 11 10 10 3  -> 階層[1][0] = 2  -> 2與[3][0] 或 2與[3][1] 小的為結果11(2+9)
		/// </summary>
		int minimumTotal(vector<vector<int>>& triangle) 
		{	
			//1. 借用題目三角形的最後一列，當做DP計算存放的位置
			vector<int> dp(triangle.back());
			for (int index = (int)triangle.size() - 2; index >= 0; index--) 
			{
				//2. 利用Dp最後一層，與前一層加總後放進dp中，然後再往上一層重複計算
				for (int innerIndex = 0; innerIndex <= index; innerIndex++) 
				{
					dp[innerIndex] = min(dp[innerIndex], dp[innerIndex + 1]) + triangle[index][innerIndex];
				}
			}
			//3. 最終的累加最小值就是dp[0]
			return dp[0];		
		}

		// [錯誤] 以下是遞迴版本 - 必定超時
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
