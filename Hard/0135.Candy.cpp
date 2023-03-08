#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution135
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0135.Candy.cpp"
    using namespace Solution135;

    int main()
    {
        Solution135::Candy useClass;
        Solution135::Candy::Candy_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.candy(getTestModel.ratings);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.candy(getTestModel.ratings);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ¿}ªG
    /// </summary>
    class Candy
    {
#pragma region Model
    public:
        class Candy_Model
        {
        public:
            vector<int> ratings;
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
        int candy(vector<int>& ratings) {
            return {};
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Candy_Model GetTestData001(void)
        {
            Candy_Model result;
            result.ratings = { 1, 0, 2 };
            return result;//expect: 5
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Candy_Model GetTestData002(void)
        {
            Candy_Model result;
            result.ratings = { 1, 2, 2 };
            return result;//expect: 4
        };

        
#pragma endregion TestData
    };
}