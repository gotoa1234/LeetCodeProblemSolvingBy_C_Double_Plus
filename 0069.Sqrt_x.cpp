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
    /// ¥­¤è(x)
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
        ///         «ä¸ô ¡G
        ///      Runtime : 
        /// Memory Usage : 
        /// <returns></returns>
        int mySqrt(int x) {
            return {};
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