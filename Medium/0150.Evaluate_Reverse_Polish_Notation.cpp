#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
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
        auto result1 = useClass.evalRPN(getTestModel.tokens);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.evalRPN(getTestModel.tokens);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.evalRPN(getTestModel.tokens);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �����ϦV�i����ܪk
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
        ///         ����G �Q�ΰ��|���S�ʡA�J��B��Ÿ��ɱN��e�̪񪺨�ӼƭȨ��X�ӹB��A�M��A��^���|�A����Ҧ���Vector<string> �������e
        ///      Runtime�G    4 ms Beats 96.21 %
        /// Memory Usage�G 11.9 MB Beats 89.33 %
        /// </summary>
        /// <returns></returns>
    public:
        int evalRPN(vector<string>& tokens) 
        {
            stack<int> stackContiner;
            int tempValue = 0;
            int caculationA = 0;
            int caculationB = 0;
            //1. �M���C�Ӧr��
            for (const auto& token : tokens) 
            {
                //2-1. �Ӧr��D�B��l�N��i���|(���w�ƭ�)
                if (token == "+")
                {
                    caculationB = stackContiner.top(); stackContiner.pop();
                    caculationA = stackContiner.top(); stackContiner.pop();
                    tempValue = caculationA + caculationB;
                }
                else if (token == "-")
                {
                    caculationB = stackContiner.top(); stackContiner.pop();
                    caculationA = stackContiner.top(); stackContiner.pop();
                    tempValue = caculationA - caculationB;
                }
                else if (token == "*")
                {
                    caculationB = stackContiner.top(); stackContiner.pop();
                    caculationA = stackContiner.top(); stackContiner.pop();
                    tempValue = caculationA * caculationB;
                }
                else if (token == "/")
                {
                    caculationB = stackContiner.top(); stackContiner.pop();
                    caculationA = stackContiner.top(); stackContiner.pop();
                    tempValue = caculationA / caculationB;
                }
                else
                {
                    //2-2. �ƭȪ�����J���|
                    stackContiner.push(stoi(token));
                    continue;
                }

                //3. �D�ƭȡA��ܦ����L�B��A�N�p�⵲�G��J���|
                stackContiner.push(tempValue);
            }
            return stackContiner.top();            
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
            result.tokens = {"2", "1", "+", "3", "*"};
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