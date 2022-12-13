#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution73
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0073.Set_Matrix_Zeroes.cpp"
    using namespace Solution73;

    int main()
    {
        Solution73::Set_Matrix_Zeroes useClass;
        Solution73::Set_Matrix_Zeroes::Set_Matrix_Zeroes_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.setZeroes(getTestModel.matrix);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.setZeroes(getTestModel.matrix);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �]�m�x�}�s�I
    /// </summary>
    class Set_Matrix_Zeroes
    {
#pragma region Model
    public:
        class Set_Matrix_Zeroes_Model
        {
        public:
            vector<vector<int>> matrix;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�D�حn�D Space O(1) �A�Q�έ�x�}���Ĥ@��P�Ĥ@�C�@�������аO�ΡA�Q�ΥH�U�B�J����
        ///               1. �]�Ĥ@�C�A�����O�_��0
        ///               2. �]�Ĥ@��A�����O�_��0
        ///               3. �q[1,1] �}�l�M�ҨC�Ӥ��� (���]�Ĥ@�C�B�Ĥ@�檺����)�A�Y��0�h�N��������C�аO��0
        ///               4. �]�Ĥ@�C�A�Ĥ@��Y��0�������N��C�]��0
        ///               5. �Y1 , 2�B�J����0�h��C�B��г]��0
        ///      Runtime :   22 ms Beats 72.80 %
        /// Memory Usage : 13.1 MB Beats 82.96 %
        /// </summary>
        /// <returns></returns>
        void setZeroes_sovel(vector<vector<int>>& matrix)
        {
            int yAxisMax = matrix.size();
            int xAxisMax = matrix[0].size();
            int xAxisContains_zero = 1;
            for (int yAxis = 0; yAxis < yAxisMax; yAxis++)
            {
                if (matrix[yAxis][0] == 0)
                    xAxisContains_zero = 0;
                for (int xAxis = 1; xAxis < xAxisMax; xAxis++)
                {
                    if (matrix[yAxis][xAxis] == 0)
                    {
                        matrix[yAxis][0] = matrix[0][xAxis] = 0;
                    }
                }
            }

            for (int yAxis = yAxisMax - 1; yAxis >= 0; yAxis--)
            {
                for (int xAxis = xAxisMax - 1; xAxis >= 1; xAxis--)
                {
                    if (matrix[yAxis][0] == 0 || matrix[0][xAxis] == 0)
                    {
                        matrix[yAxis][xAxis] = 0;
                    }
                }
                if (xAxisContains_zero == 0)
                    matrix[yAxis][0] = 0;
            }
            return;
        }

        /// <summary>
        /// �Ѫk��Space: O(1) ���覡 - ���į�ܮt�A�]���j��Q�βv�ӧC
        /// </summary>
        void setZeroes_solve2(vector<vector<int>>& matrix) {
            bool yAxisContainsZero = false;
            bool xAxisContainsZero = false;

            //1. ��X�Ĥ@��O�_��0
            for (int yAxis = 0; yAxis < matrix.size(); yAxis++)
            {
                if (matrix[yAxis][0] == 0)
                {
                    yAxisContainsZero = true;
                    break;
                }
            }

            //2. ��X�Ĥ@�C�O�_��0
            for (int xAxis = 0; xAxis < matrix[0].size(); xAxis++)
            {
                if (matrix[0][xAxis] == 0)
                {
                    xAxisContainsZero = true;
                    break;
                }
            }

            //3. ��X���������аO�X�O�_��0 (�Q�βĤ@�C�B�Ĥ@��)
            for(int yAxis = 0; yAxis < matrix.size(); yAxis++)
            {
                for (int xAxis = 0; xAxis < matrix[0].size(); xAxis++)
                {
                    if (matrix[yAxis][xAxis] == 0)
                    {
                        matrix[yAxis][0] = 0;
                        matrix[0][xAxis] = 0;
                    }
                }
            }

            //4. �B�z�аO���Ĥ@��B�C�Y��0�h���B��C�]��0
            for (int yAxis = 1; yAxis < matrix.size(); yAxis++)
            {
                if (matrix[yAxis][0] == 0)
                {
                   for(int xAxis = 1 ;xAxis < matrix[yAxis].size(); xAxis++)
                   {
                       matrix[yAxis][xAxis] = 0;
                   }
                }
            }
            for (int xAxis = 1; xAxis < matrix[0].size(); xAxis++)
            {
                if (matrix[0][xAxis] == 0)
                {
                    for (int yAxis = 1; yAxis < matrix.size(); yAxis++)
                    {
                        matrix[yAxis][xAxis] = 0;
                    }
                }
            }

            //5. �Ĥ@��B�C��0�h���B�C�]0
            if (yAxisContainsZero)
            {
                for (int yAxis = 0; yAxis < matrix.size(); yAxis++)
                {
                    matrix[yAxis][0] = 0;
                }
            }
            if (xAxisContainsZero)
            {
                for (int xAxis = 0; xAxis < matrix[0].size(); xAxis++)
                {
                    matrix[0][xAxis] = 0;
                }
            }
        }

        /// <summary>
        /// �Ѫk��Space: O(n*m) ���覡 - �D�D�حn�D���Ѫk
        /// </summary>
        void setZeros_solve3(vector<vector<int>>& matrix)
        {
            vector<tuple<int, int>> points;
            for (int yAxis = 0; yAxis < matrix.size(); yAxis++)
            {
                for (int xAxis = 0; xAxis < matrix[yAxis].size(); xAxis++)
                {
                    if (matrix[yAxis][xAxis] == 0)
                    {
                        tuple<int, int> point = make_tuple(yAxis, xAxis);
                        points.push_back(point);
                        points.insert(points.begin(), point);
                    }
                }
            }

            for (auto point : points)
            {
                int yAxisAnchor = get<0>(point);
                int xAxisAnchor = get<1>(point);
                for (int xAxis = 0; xAxis < matrix[yAxisAnchor].size(); xAxis++)
                {
                    matrix[yAxisAnchor][xAxis] = 0;
                }

                for (int yAxis = 0; yAxis < matrix.size(); yAxis++)
                {
                    matrix[yAxis][xAxisAnchor] = 0;
                }
            }
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Set_Matrix_Zeroes_Model GetTestData001(void)
        {
            Set_Matrix_Zeroes_Model result;
			result.matrix = { {1,1,1},
                              {1,0,1},
                              {1,1,1} };
            return result;//expect: [[1, 0, 1], [0, 0, 0], [1, 0, 1]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Set_Matrix_Zeroes_Model GetTestData002(void)
        {
            Set_Matrix_Zeroes_Model result;
            result.matrix = { {0, 1, 2, 0},
                              {3, 4, 5, 2},
                              {1, 3, 1, 5} 
            };
            return result;//expect: [[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]]
        };
#pragma endregion TestData
    };
}