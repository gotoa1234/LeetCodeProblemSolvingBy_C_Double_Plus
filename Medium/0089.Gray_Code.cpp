#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution89
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0089.Gray_Code.cpp"
    using namespace Solution89;

    int main()
    {
        Solution89::Gray_Code useClass;
        Solution89::Gray_Code::Gray_Code_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.grayCode(getTestModel.n, getTestModel.s2);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.grayCode(getTestModel.n, getTestModel.s2);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.grayCode(getTestModel.n, getTestModel.s2);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ®æ¹p½X
    /// </summary>
    class Gray_Code
    {
#pragma region Model
    public:
        class Gray_Code_Model
        {
        public:
            int n;            
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
        vector<int> grayCode(int n) {
            return {};
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Gray_Code_Model GetTestData001(void)
        {
            Gray_Code_Model result;
            result.n = 2;            
            return result;//expect: [0, 1, 3, 2]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Gray_Code_Model GetTestData002(void)
        {
            Gray_Code_Model result;
            result.n = 1;
            return result;//expect: [0, 1]
        };
#pragma endregion TestData
    };
}