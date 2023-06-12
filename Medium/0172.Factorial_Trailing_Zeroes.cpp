#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution172
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0172.Factorial_Trailing_Zeroes.cpp"
    using namespace Solution172;

    int main()
    {
        Solution172::Factorial_Trailing_Zeroes useClass;
        Solution172::Factorial_Trailing_Zeroes::Factorial_Trailing_Zeroes_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.trailingZeroes(getTestModel.n);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.trailingZeroes(getTestModel.n);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 
    /// </summary>
    class Factorial_Trailing_Zeroes
    {
#pragma region Model
    public:
        class Factorial_Trailing_Zeroes_Model
        {
        public:
            int n;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路：利用5的特性，找出尾隨0的個數
        ///                4!=> 24
        ///                5!=> 120  
        ///               10!=> 3628800 
        ///               實際上在10的時候 10 / 5 = 2 所以2
        ///      Runtime：  0 ms Beats   100 %
        /// Memory Usage：5.8 MB Beats 93.38 %
        /// </summary>
        /// <returns></returns>
    public:
        int trailingZeroes(int n) {
            if (n < 5)
                return 0;
            int result = 0;
            while (n > 0)
            {
                result += (n / 5);
                n = n / 5;
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
        Factorial_Trailing_Zeroes_Model GetTestData001(void)
        {
            Factorial_Trailing_Zeroes_Model result;
            result.n = 3;
            return result;//expect: 0
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Factorial_Trailing_Zeroes_Model GetTestData002(void)
        {
            Factorial_Trailing_Zeroes_Model result;
            result.n = 5;
            return result;//expect: 1
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Factorial_Trailing_Zeroes_Model GetTestData003(void)
        {
            Factorial_Trailing_Zeroes_Model result;
            result.n = 0;
            return result;//expect: 0
        };

#pragma endregion TestData
    };
}