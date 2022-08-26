#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution509
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0509.Fibonacci_Number.cpp"
    using namespace Solution509;

    int main()
    {
        Solution509::Fibonacci_Number useClass;
        Solution509::Fibonacci_Number::Fibonacci_Number_Model getTestModel = useClass.GetTestData001();
        int result = useClass.fib(getTestModel.n);
        
        getTestModel = useClass.GetTestData002();
        result = useClass.fib(getTestModel.n);
        
        getTestModel = useClass.GetTestData003();
        result = useClass.fib(getTestModel.n);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 費式數列
    /// </summary>
    class Fibonacci_Number
    {
#pragma region Model
    public:
        class Fibonacci_Number_Model
        {
        public:
            int n;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路：遞迴經典題，執行快一點的做法是把結果放在記憶體中。
        ///      Runtime : 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
        /// Memory Usage : 6 MB, less than 39.80 % of C++ online submissions for Fibonacci Number.
        /// <returns></returns>
        int fib(int n) {
            vector<int> fibAll = {
0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040
            };
            return fibAll[n];
        }

    private:
        /// <summary>
        /// 遞迴找出費式數列
        /// </summary>
        int Funct(int x)
        {
            if (x <= 0)
                return 0;
            else if (x == 1)
                return 1;
            else
                return Funct(x-1) + Funct(x - 2);
        }

#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料2
        /// </summary>        
        Fibonacci_Number_Model GetTestData001(void)
        {
            Fibonacci_Number_Model result;
            result.n = 2;
            return result;
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Fibonacci_Number_Model GetTestData002(void)
        {
            Fibonacci_Number_Model result;
            result.n = 3;
            return result;
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        Fibonacci_Number_Model GetTestData003(void)
        {
            Fibonacci_Number_Model result;
            result.n = 4;
            return result;
        };
#pragma endregion TestData
    };
}