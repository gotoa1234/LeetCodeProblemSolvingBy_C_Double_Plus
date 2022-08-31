#include <iostream>
#include <vector>
using namespace std;

namespace Solution1046
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "1046.Last_Stone_Weight.cpp"
    using namespace Solution1046;

    int main()
    {
        Solution1046::Last_Stone_Weight useClass;
        Solution1046::Last_Stone_Weight::Last_Stone_Weight_Model getTestModel = useClass.GetTestData001();
        string result = useClass.getHint(getTestModel.secret, getTestModel.guess);

        getTestModel = useClass.GetTestData002();
        result = useClass.getHint(getTestModel.secret, getTestModel.guess);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �̫᪺���Y���q
    /// </summary>
    class Last_Stone_Weight
    {
#pragma region Model
    public:
        class Last_Stone_Weight_Model
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
        Last_Stone_Weight_Model GetTestData001(void)
        {
            Last_Stone_Weight_Model result;
            vector<int> input = { 2, 7, 4, 1, 8, 1 };
            result.stones = input;
            return result; 
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Last_Stone_Weight_Model GetTestData002(void)
        {
            Last_Stone_Weight_Model result;
            vector<int> input = { 1 };
            result.stones = input;
            return result;

        };

#pragma endregion TestData
    };
}