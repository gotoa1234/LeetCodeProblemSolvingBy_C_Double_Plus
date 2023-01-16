#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

namespace Solution97
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0097.Interleaving_String.cpp"
    using namespace Solution97;

    int main()
    {
        Solution97::Interleaving_String useClass;
        Solution97::Interleaving_String::Interleaving_String_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.isInterleave(getTestModel.s1,getTestModel.s2,getTestModel.s3);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.isInterleave(getTestModel.s1,getTestModel.s2,getTestModel.s3);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.isInterleave(getTestModel.s1,getTestModel.s2,getTestModel.s3);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ¥æÂ´¦r²Å¦ê
    /// </summary>
    class Interleaving_String
    {
#pragma region Model
    public:
        class Interleaving_String_Model
        {
        public:
             string s1; 
             string s2; 
             string s3;
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
        bool isInterleave(string s1, string s2, string s3) {
             return {};
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Interleaving_String_Model GetTestData001(void)
        {
            Interleaving_String_Model result;
            result.s1 = "aabcc";
            result.s2 = "dbbca";
            result.s3 = "aadbbcbcac";
            return result;//expect: true
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Interleaving_String_Model GetTestData002(void)
        {
          Interleaving_String_Model result;
            result.s1 = "aabcc";
            result.s2 = "dbbca";
            result.s3 = "aadbbbaccc";
            return result;//expect: false
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Interleaving_String_Model GetTestData003(void)
        {
           Interleaving_String_Model result;
            result.s1 = "";
            result.s2 = "";
            result.s3 = "";
            return result;//expect: true
        };
#pragma endregion TestData
    };
}