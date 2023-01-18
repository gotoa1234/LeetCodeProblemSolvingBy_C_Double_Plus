#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

namespace Solution91
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0091.Decode_Ways.cpp"
    using namespace Solution91;

    int main()
    {
        Solution91::Decode_Ways useClass;
        Solution91::Decode_Ways::Decode_Ways_Model getTestModel = useClass.GetTestData001();
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
    /// 解碼方式
    /// </summary>
    class Decode_Ways
    {
#pragma region Model
    public:
        class Decode_Ways_Model
        {
        public:
            string s;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：
        ///      Runtime :
        /// Memory Usage :
        /// </summary>
        /// <returns></returns>
        int numDecodings(string s) {
            
            if (s.empty() || s[0] == '0') 
                return 0;
            int totalCount = 1, lastCount = 1;
            //1. 遍歷每個字元
            for (int index = 1; index < s.size(); ++index)
            {
                //2-1. 為0時視為不可能組成
                if (s[index] == '0') 
                    totalCount = 0;

                //3-1. 1X ~ 26 之間(A~Z) 視為可組成
                if (  s[index - 1] == '1' || 
                     (s[index - 1] == '2' && s[index] <= '6')
                   ) 
                {
                    totalCount = totalCount + lastCount;
                    lastCount = totalCount - lastCount;
                }
                else //3-2. 最後一種可能是獨立數值
                {
                    lastCount = totalCount;
                }
            }
            return totalCount;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Decode_Ways_Model GetTestData001(void)
        {
            Decode_Ways_Model result;
            result.s = "12";
            return result;//expect: 2
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Decode_Ways_Model GetTestData002(void)
        {
            Decode_Ways_Model result;
            result.s = "2212451026";
            return result;//expect: 3  Re:226
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Decode_Ways_Model GetTestData003(void)
        {
            Decode_Ways_Model result;
            result.s = "06";
            return result;//expect: 0
        };

        /// <summary>
       /// test 4
       /// </summary>   
        Decode_Ways_Model GetTestData003(void)
        {
            Decode_Ways_Model result;
            result.s = "2222";
            return result;//expect: 5
        };
#pragma endregion TestData
    };
}