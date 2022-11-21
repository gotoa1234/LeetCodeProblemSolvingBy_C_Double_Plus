#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution64
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0064.Minimum_Path_Sum.cpp"
    using namespace Solution64;

    int main()
    {
        Solution64::Minimum_Path_Sum useClass;
        Solution64::Minimum_Path_Sum::Minimum_Path_Sum_Model getTestModel = useClass.GetTestData001();
        int result = useClass.minPathSum(getTestModel.grid);

        getTestModel = useClass.GetTestData002();
        result = useClass.minPathSum(getTestModel.grid);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �̤p�[�`���|
    /// </summary>
    class Minimum_Path_Sum
    {
#pragma region Model
    public:
        class Minimum_Path_Sum_Model
        {
        public:
            vector<vector<int>> grid;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G������DP���覡�A�v�B�N���e�D�X���̤p�Ȩ��X�A����̫�@�Ӯy�Ь��̤p�֭p���|��
        ///      Runtime :   7 ms Beats 97.41 %
        /// Memory Usage : 9.6 MB Beats 98.80 %
        /// <returns></returns>
        int minPathSum(vector<vector<int>>& grid) {

            //1. �ư���0�����p
			if (grid[0].empty() || grid.empty())
				return 0;

            //2. �Ѯy��0,0 �}�l�A�N�W�U�ȥ[�J���e���y�Ф�
			for (int yAxis = 0; yAxis < grid.size(); yAxis++)
			{
				for (int xAxis = 0; xAxis < grid[0].size(); xAxis++)
				{
                    //2-1. �_�I���κ�
					if (yAxis == 0 && xAxis == 0)
						continue;

                    //2-2. �W�U�ȨD�X�A���p��(�D�جO�̤p���|)
					int upValue = yAxis == 0 ? INT_MAX : grid[yAxis - 1][xAxis];
					int downValue = xAxis == 0 ? INT_MAX : grid[yAxis][xAxis - 1];
					grid[yAxis][xAxis] += min(upValue, downValue);
				}
			}
            //3. �̫�@�Ӯy���I�N�O�ثe����֭p�̤p�����|��
			return grid[grid.size() - 1][grid[0].size() - 1];
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Minimum_Path_Sum_Model GetTestData001(void)
        {
            Minimum_Path_Sum_Model result;
			result.grid = { {1, 3, 1},{1, 5, 1},{4, 2, 1} };
            return result;//expected = 7
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Minimum_Path_Sum_Model GetTestData002(void)
        {
            Minimum_Path_Sum_Model result;
            result.grid = { {1, 2, 3},{4, 5, 6}};
            return result;//expected = 12
        };

#pragma endregion TestData
    };
}