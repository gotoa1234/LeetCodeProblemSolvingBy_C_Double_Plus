#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution66
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Easy\0066.Plus_One.cpp"       
    using namespace Solution66;

    int main()
    {
        Solution66::Plus_One useClass;
        Solution66::Plus_One::Plus_One_Model getTestModel = useClass.GetTestData001();
        int result = useClass.plusOne(getTestModel.digits);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.plusOne(getTestModel.digits);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.plusOne(getTestModel.digits);

        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 
    /// </summary>
    class Plus_One
    {
#pragma region Model
    public:
        class Plus_One_Model
        {
        public:
            vector<int> digits;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         隔 盢程ま竚计+1 礛眖程┕玡璝秈玥
        ///                程铬璝临Τ秈玥程玡 Insert掸础秈
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 8.7 MB Beats 85.40 %
        /// <returns></returns>
        vector<int> plusOne(vector<int>& digits) {
            int carry = 0;
            int currentValue = 0;
            digits[digits.size() - 1] += 1;
            for (int index = digits.size() - 1; index >= 0; index--)
            {
                currentValue = (digits[index] + carry);
                digits[index] = currentValue % 10;
                carry = currentValue / 10;
                if (carry == 0)
                    break;
            }
            if (carry > 0)
                digits.insert(digits.begin(), carry);
            return digits;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Plus_One_Model GetTestData001(void)
        {
            Plus_One_Model result;
            result.digits =  { 1,2,3 };
            return result;//expected = [1,2,4]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Plus_One_Model GetTestData002(void)
        {
            Plus_One_Model result;
            result.digits = { 1,2,3 };
            return result;//expected = [4,3,2,2]
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Plus_One_Model GetTestData003(void)
        {
            Plus_One_Model result;
            result.digits = { 9 };
            return result;//expected = [1, 0]
        };

#pragma endregion TestData
    };
}