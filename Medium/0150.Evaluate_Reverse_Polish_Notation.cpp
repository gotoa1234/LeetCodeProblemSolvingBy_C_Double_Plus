#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution150
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0150.Evaluate_Reverse_Polish_Notation.cpp"
    using namespace Solution150;

    int main()
    {
        Solution150::Evaluate_Reverse_Polish_Notation useClass;
        Solution150::Evaluate_Reverse_Polish_Notation::Evaluate_Reverse_Polish_Notation_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.evalRPN(getTestModel.head);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.evalRPN(getTestModel.head);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.evalRPN(getTestModel.head);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 評估反向波蘭表示法
    /// </summary>
    class Evaluate_Reverse_Polish_Notation
    {
#pragma region Model
    public:
        class Evaluate_Reverse_Polish_Notation_Model
        {
        public:
            vector<string> tokens;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路： 
        ///      Runtime： 
        /// Memory Usage： 
        /// </summary>
        /// <returns></returns>
    public:
        int evalRPN(vector<string>& tokens) {
            return {};
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Evaluate_Reverse_Polish_Notation_Model GetTestData001(void)
        {
            Evaluate_Reverse_Polish_Notation_Model result;
            result.tokens = {"2", "1", "+", "3", "9"};
            return result;//expect:9
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Evaluate_Reverse_Polish_Notation_Model GetTestData002(void)
        {
            Evaluate_Reverse_Polish_Notation_Model result;
            result.tokens = { "4","13","5","/","+" };
            return result;//expect: [ 4 + (13 /5)] =  6
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Evaluate_Reverse_Polish_Notation_Model GetTestData003(void)
        {
            Evaluate_Reverse_Polish_Notation_Model result;
            result.tokens = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
            return result;//expect: 22
        };
#pragma endregion TestData
    };
}