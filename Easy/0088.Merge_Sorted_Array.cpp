#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution88
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0088.Scramble_String.cpp"
    using namespace Solution88;

    int main()
    {
        Solution88::Scramble_String useClass;
        Solution88::Scramble_String::Scramble_String_Model getTestModel = useClass.GetTestData001();
        useClass.isScramble(getTestModel.num1, getTestModel.m, getTestModel.num2, getTestModel.n);

        getTestModel = useClass.GetTestData002();
        useClass.isScramble(getTestModel.num1, getTestModel.m, getTestModel.num2, getTestModel.n );

        getTestModel = useClass.GetTestData003();
        seClass.isScramble(getTestModel.num1, getTestModel.m, getTestModel.num2, getTestModel.n );
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 合併排序數組
    /// </summary>
    class Scramble_String
    {
#pragma region Model
    public:
        class Scramble_String_Model
        {
        public:
            vector<int> nums1;
            int m;
            vector<int> nums2;
            int n;
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
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Scramble_String_Model GetTestData001(void)
        {
            Scramble_String_Model result;
            result.nums1 = { 1,2,3,0,0,0 };
            result.m = 3;
            result.nums2 = { 2,5,6 };
            result.n = 3;
            return result;//expect: [1,2,2,3,5,6]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Scramble_String_Model GetTestData002(void)
        {
            Scramble_String_Model result;
            result.nums1 = { 1};
            result.m = 1;
            result.nums2 = {  };
            result.n = 0;
            return result;//expect: [1]
        };

        /// <summary>
        /// test 3
        /// </summary>
        Scramble_String_Model GetTestData003(void)
        {
            Scramble_String_Model result;
            result.nums1 = {  };
            result.m = 0;
            result.nums2 = { 1 };
            result.n = 1;
            return result;//expect: [1]
        };
#pragma endregion TestData
    };
}