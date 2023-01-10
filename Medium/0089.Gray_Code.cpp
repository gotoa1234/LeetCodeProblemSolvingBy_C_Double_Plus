#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

namespace Solution89
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0089.Gray_Code.cpp"
    using namespace Solution89;
    
    int main()
    {
        Solution89::Gray_Code useClass;
        Solution89::Gray_Code::Gray_Code_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.grayCode(getTestModel.n);
    
        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.grayCode(getTestModel.n);
    
        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.grayCode(getTestModel.n);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 格雷碼
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
        ///         思路 ：建立基底N=1 的狀況，然後用迴圈的方式，將規律的數值做累計
        ///      Runtime :  3 ms Beats 99.44 %
        /// Memory Usage : 12 MB Beats 75.55 %
        /// </summary>
        /// <returns></returns>
        vector<int> grayCode(int n)
        {
            vector<int> result{ };
            result.push_back(0);
            result.push_back(1);
            for (int input = 2; input <= n; input++)
            {
                int max = pow(2, input);
                int useValue = pow(2, input - 1);
                int startIndex = result.size() - 1;
                for (int index = startIndex; index >= 0; index--)
                {
                    result.push_back(useValue + result[index]);
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

        /// <summary>
        /// test 3
        /// </summary>   
        Gray_Code_Model GetTestData003(void)
        {
            Gray_Code_Model result;
            result.n = 4;
            return result;//expect: 
        };
#pragma endregion TestData
    };
}