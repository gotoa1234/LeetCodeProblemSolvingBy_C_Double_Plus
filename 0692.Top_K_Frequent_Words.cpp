#include <iostream>
#include <vector>
using namespace std;

namespace Solution692
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "692.Top_K_Frequent_Words.cpp"
    using namespace Solution692;

    int main()
    {
        Solution692::Top_K_Frequent_Words useClass;
        Solution692::Top_K_Frequent_Words::Top_K_Frequent_Words_Model getTestModel = useClass.GetTestData001();
        string result = useClass.getHint(getTestModel.secret, getTestModel.guess);

        getTestModel = useClass.GetTestData002();
        result = useClass.getHint(getTestModel.secret, getTestModel.guess);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �ƦW�̰�(TOP) K �`�ε�
    /// </summary>
    class Top_K_Frequent_Words
    {
#pragma region Model
    public:
        class Top_K_Frequent_Words_Model
        {
        public:
            vector<int> stones;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///            ����G
        ///                  
        ///         Runtime:
        ///   Memory Usage :
        ///Time complexity :
        /// <returns></returns>
        int lastStoneWeight(vector<int>& stones)
        {
            return 0;
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��2
        /// </summary>        
        Top_K_Frequent_Words_Model GetTestData001(void)
        {
            Top_K_Frequent_Words_Model result;
            vector<int> input = { 2, 7, 4, 1, 8, 1 };
            result.stones = input;
            return result;
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Top_K_Frequent_Words_Model GetTestData002(void)
        {
            Top_K_Frequent_Words_Model result;
            vector<int> input = { 1 };
            result.stones = input;
            return result;

        };

#pragma endregion TestData
    };
}