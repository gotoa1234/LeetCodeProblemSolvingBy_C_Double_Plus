#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

namespace Solution85
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0085.Maximal_Rectangle.cpp"
    using namespace Solution85;

    int main()
    {
        Solution85::Maximal_Rectangle useClass;
        Solution85::Maximal_Rectangle::Maximal_Rectangle_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.maximalRectangle(getTestModel.matrix);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.maximalRectangle(getTestModel.matrix);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ����Ϥ��̤j���x��
    /// </summary>
    class Maximal_Rectangle
    {
#pragma region Model
    public:
        class Maximal_Rectangle_Model
        {
        public:
            vector<vector<char>> matrix;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�Ѧ� 0084���p��覡�A���C�@�hY�b����1�ӭ��n���e�n�A���U�h�ɻݦA�֭p�e�@�h����
        ///                �Y���h���Ȭ�0�h�k0
        ///      Runtime :   51 ms Beats 79.23 %
        /// Memory Usage : 13.1 MB Beats 77.83 %
        /// </summary>
        /// <returns></returns>
        int maximalRectangle(vector<vector<char>>& matrix) {
            
            if (matrix.empty() || matrix[0].empty()) 
                return 0;
            int result = 0;
            int yAxisMax = matrix.size();
            int xAxisMax = matrix[0].size();
            int useDistance = 0;
            vector<int> height(xAxisMax + 1);
            //1. �C�h�p��
            for (int yAxis = 0; yAxis < yAxisMax; yAxis++) 
            {
                stack<int> stackContainer;
                for (int xAxis = 0; xAxis < xAxisMax + 1; xAxis++)
                {
                    //2. ���L�̫�@�Ӥ����A�̫�@�Ӥ����O�K�[��
                    if (xAxis < xAxisMax)
                    {
                        height[xAxis] = matrix[yAxis][xAxis] == '1' 
                                       ? height[xAxis] + 1 
                                       : 0;
                    }
                    //3. �P0084���p��覡
                    while (!stackContainer.empty() && 
                           height[stackContainer.top()] >= height[xAxis]
                        ) 
                    {
                        int cur = stackContainer.top(); 
                        stackContainer.pop();
                        int useDistance = stackContainer.empty() ? xAxis 
                                                    : (xAxis - stackContainer.top() - 1);
                        result = max(result, height[cur] * useDistance );
                    }
                    stackContainer.push(xAxis);
                }
            }
            return result;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Maximal_Rectangle_Model GetTestData001(void)
        {
            Maximal_Rectangle_Model result;
            result.matrix = { {'1', '0', '1', '0', '0'}, 
                              {'1', '0', '1', '1', '1'}, 
                              {'1', '1', '1', '1', '1'}, 
                              {'1', '0', '0', '1', '0'} };
            return result;//expect: 6
        };
        /// <summary>
        /// test 2
        /// </summary>   
        Maximal_Rectangle_Model GetTestData002(void)
        {
            Maximal_Rectangle_Model result;
			result.matrix = { { '0' } };
            return result;//expect:0
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Maximal_Rectangle_Model GetTestData003(void)
        {
            Maximal_Rectangle_Model result;
            result.matrix = {{ '1' }};
            return result;//expect:1
        };
#pragma endregion TestData
    };
}