#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution77
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0077.Combinations.cpp"
    using namespace Solution77;

    int main()
    {
        Solution77::Combinations useClass;
        Solution77::Combinations::Combinations_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.combine(getTestModel.n, getTestModel.k);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.combine(getTestModel.n, getTestModel.k);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ²Õ¦X
    /// </summary>
    class Combinations
    {
#pragma region Model
    public:
        class Combinations_Model
        {
        public:
            int n;
            int k;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         «ä¸ô ¡G
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>
        vector<vector<int>> combine(int n, int k) {
            return {};
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Combinations_Model GetTestData001(void)
        {
            Combinations_Model result;
            result.n = 4;
            result.k = 2;
            return result;//expect:  [[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Combinations_Model GetTestData002(void)
        {
            Combinations_Model result;
            result.n = 1;
            result.k = 1;
            return result;//expect:[[1]]
        };

#pragma endregion TestData
    };
}