#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution69
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0069.Sqrt_x.cpp"
    using namespace Solution69;

    int main()
    {
        Solution69::Sqrt_x useClass;
        Solution69::Sqrt_x::Sqrt_x_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.mySqrt(getTestModel.x);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.mySqrt(getTestModel.x);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.mySqrt(getTestModel.x);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 平方(x)
    /// </summary>
    class Sqrt_x
    {
#pragma region Model
    public:
        class Sqrt_x_Model
        {
        public:
            int x;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：利用牛根法求值，可參考維基百科 https://zh.wikipedia.org/zh-tw/%E7%89%9B%E9%A1%BF%E6%B3%95
        ///      Runtime : 3 ms Beats 77.26 %
        /// Memory Usage : 6 MB Beats 27.94 %
        /// <returns></returns>
        int mySqrt(int x) {
            long ApproximateValue = x;
            while (ApproximateValue * ApproximateValue > x)
            {
                ApproximateValue = (ApproximateValue + x / ApproximateValue) / 2;
            }
            return ApproximateValue;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Sqrt_x_Model GetTestData001(void)
        {
            Sqrt_x_Model result;
            result.x = 4;
            return result;//2
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Sqrt_x_Model GetTestData002(void)
        {
            Sqrt_x_Model result;
            result.x = 8;
            return result;//2
        };
#pragma endregion TestData
    };
}