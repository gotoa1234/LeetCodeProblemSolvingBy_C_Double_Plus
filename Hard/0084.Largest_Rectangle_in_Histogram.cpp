#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

namespace Solution84
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0084.Largest_Rectangle_in_Histogram.cpp"
    using namespace Solution84;

    int main()
    {
        Solution84::Largest_Rectangle_in_Histogram useClass;
        Solution84::Largest_Rectangle_in_Histogram::Largest_Rectangle_in_Histogram_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.largestRectangleArea(getTestModel.heights);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.largestRectangleArea(getTestModel.heights);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ����Ϥ��̤j���x��
    /// </summary>
    class Largest_Rectangle_in_Histogram
    {
#pragma region Model
    public:
        class Largest_Rectangle_in_Histogram_Model
        {
        public:
            vector<int> heights;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G��X�p��(��e�����קC��e�@�Ӱ��׮ɡA�W�@�Ӱ��׬��p��)
        ///                �åB�A�X�{�p�ȫe�إߤ@��Stack�N�C�����D�p�Ȫ��ƭȩ�J
        ///                ��Ĳ�o�p�Ȯɶi��H�U�y�{:
        ///                1. �q���|�̧Ǩ��X�ȡA�Y���e�Ȱ��h���X
        ///                2. ���X�����|�� * �Z�� => �O���U�̤j�ȡA�Y��e�@���j��ܥX�{�̤j���x��       
        ///      Runtime :  233 ms Beats 68.19 %
        /// Memory Usage : 75.3 MB Beats 91.84 %
        /// </summary>
        /// <returns></returns>
        int largestRectangleArea(vector<int>& heights) {
            int result = 0;
            int useDistance = 0;
            int current = 0;
            stack<int> stackContainer{};
            heights.push_back(0);
            for (int index = 0; index < heights.size(); index++)
            {
                while (!stackContainer.empty() &&
                    heights[stackContainer.top()] >= heights[index])
                {
                    current = stackContainer.top();
                    stackContainer.pop();
                    useDistance = stackContainer.empty() ? index 
                                                         : index - stackContainer.top() - 1;
                    result = max(result, heights[current] * useDistance);
                }
                stackContainer.push(index);
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
        Largest_Rectangle_in_Histogram_Model GetTestData001(void)
        {
            Largest_Rectangle_in_Histogram_Model result;
            result.heights = { 2, 1, 5, 6, 2, 3 };
            return result;//expect: 10
        };
        /// <summary>
        /// test 2
        /// </summary>   
        Largest_Rectangle_in_Histogram_Model GetTestData002(void)
        {
            Largest_Rectangle_in_Histogram_Model result;
            result.heights = { 2, 4 };
            return result;//expect:4
        };
#pragma endregion TestData
    };
}