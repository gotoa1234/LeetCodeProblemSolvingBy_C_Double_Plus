#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution75
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0075.Sort_Colors.cpp"
    using namespace Solution75;

    int main()
    {
        Solution75::Sort_Colors useClass;
        Solution75::Sort_Colors::Sort_Colors_Model getTestModel = useClass.GetTestData001();
        useClass.sortColors(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        useClass.sortColors(getTestModel.nums);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ·j´M2ºû¯x°}
    /// </summary>
    class Sort_Colors
    {
#pragma region Model
    public:
        class Sort_Colors_Model
        {
        public:
            vector<int> nums;
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
        void sortColors(vector<int>& nums) {
            
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Sort_Colors_Model GetTestData001(void)
        {
            Sort_Colors_Model result;
            result.nums = { 2, 0, 2, 1, 1, 0 };
            return result;//expect: [0, 0, 1, 1, 2, 2]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Sort_Colors_Model GetTestData002(void)
        {
            Sort_Colors_Model result;
            result.nums = { 2, 0, 1 };
            return result;//expect: [0, 1, 2]
        };
#pragma endregion TestData
    };
}