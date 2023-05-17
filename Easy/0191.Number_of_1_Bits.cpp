#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution191
{
#pragma region Paste to execute 
    /*
#include "Easy/0191.Number_of_1_Bits.cpp"
using namespace Solution191;
using namespace std;

int main()
{
        Solution191::Number_of_1_Bits useClass;
        Solution191::Number_of_1_Bits::Number_of_1_Bits_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.hammingWeight(getTestModel.n);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.hammingWeight(getTestModel.n);
        return 0;
}
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 1 bit 數量
    /// </summary>
    class Number_of_1_Bits
    {
#pragma region Model
    public:
        class Number_of_1_Bits_Model
        {
        public:
            uint32_t n;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：利用邏輯閘AND的特性與二進制右位移，直到輸入數為0前不斷判斷。
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 6.1 MB Beats 33.31 %
        /// </summary>
        /// <returns></returns>        
        int hammingWeight(uint32_t n) {
            int count = 0;
            while (n > 0)
            {
                count += (n & 1);                    
                n = n >> 1;
            }
            return count;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Number_of_1_Bits_Model GetTestData001(void)
        {
            Number_of_1_Bits_Model result;
            result.n = 0b00000000000000000000000000001011;
            return result;//expect: 3
        };  

        /// <summary>
        /// test 2
        /// </summary>   
        Number_of_1_Bits_Model GetTestData002(void)
        {
            Number_of_1_Bits_Model result;
            result.n = 0b00000000000000000000000010000000;
            return result;//expect:  1
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Number_of_1_Bits_Model GetTestData003(void)
        {
            Number_of_1_Bits_Model result;
            result.n = 0b11111111111111111111111111111101;
            return result;//expect:  31
        };
#pragma endregion TestData
    };
}