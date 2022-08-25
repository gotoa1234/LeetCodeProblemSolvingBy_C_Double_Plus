#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution200
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0200.Number_of_Islands.cpp"
    using namespace Solution200;
    
    int main()
    {
        Solution200::Number_of_Islands useClass;
        Solution200::Number_of_Islands::Number_of_Islands_Model getTestModel = useClass.GetTestData2();
        int result = useClass.numIslands(getTestModel.grid);
    
        getTestModel = useClass.GetTestData002();
        result = useClass.numIslands(getTestModel.grid);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �q���ƶq
    /// </summary>
    class Number_of_Islands
    {
#pragma region Model
    public:
        class Number_of_Islands_Model
        {
        public:
            vector<vector<char>> grid;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         ��� : �M���G���}�C�C�Ӥ����A�C��ݨ�'1'�ɡA�}�l��dfs�����A�p�G����'1' �[1 �åB�аO��x��ܨ��L�C
        ///      Runtime:    42 ms, faster than 81.30% of C++ online submissions for Number of Islands.
        /// Memory Usage : 12.2 MB,   less than 97.02% of C++ online submissions for Number of Islands.
        int numIslands(vector<vector<char>>& grid) {
            int count = 0;
            int x = grid.size();
            int y = grid[0].size();
            for (int xIndex = 0; xIndex < x; xIndex++)
            {
                for (int yIndex = 0; yIndex < y; yIndex++)
                {
                    if (grid[xIndex][yIndex] == '1')
                    {
                        island(grid, xIndex, yIndex, x, y);
                        count += 1;
                    }
                }
            }
            return count;
        }
    private:
        void island(vector<vector<char>>& grid, int i, int j, int r, int c) {
            if (i >= r || i < 0 || j >= c || j < 0 || grid[i][j] != '1')
                return;
            //�аO���L
            grid[i][j] = 'x';
            island(grid, i + 1, j, r, c);
            island(grid, i - 1, j, r, c);
            island(grid, i, j + 1, r, c);
            island(grid, i, j - 1, r, c);
        };
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Number_of_Islands_Model GetTestData001(void)
        {
            Number_of_Islands_Model result;
			vector<vector<char>> input =
			{
				{'1', '1', '1', '1', '0'},
				{'1', '1', '0', '1', '0'},
				{'1', '1', '0', '0', '0'},
				{'0', '0', '0', '0', '0'}
			};
            result.grid = input;
            return result;
            //Expect: 1
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Number_of_Islands_Model GetTestData002(void)
		{
			Number_of_Islands_Model result;
			vector<vector<char>> input =
			{
				{'1','1','0','0','0'},
                {'1','1','0','0','0'},
                {'0','0','1','0','0'},
                {'0','0','0','1','1'}
			};
			return result;
            //Expect:3
		};
#pragma endregion TestData
    };
}