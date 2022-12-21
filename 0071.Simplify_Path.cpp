#include <iostream>
#include <vector>
using namespace std;

namespace Solution71
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0071.Simplify_Path.cpp"
    using namespace Solution71;

    int main()
    {
        Solution71::Simplify_Path useClass;
        Solution71::Simplify_Path::Simplify_Path_Model getTestModel = useClass.GetTestData1();
        auto result1 = useClass.simplifyPath(getTestModel.path);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.simplifyPath(getTestModel.path);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.simplifyPath(getTestModel.path);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// ²�Ƹ��|
    /// </summary>
    class Simplify_Path
    {
#pragma region Model
    public:
        class Simplify_Path_Model
        {
        public:
            string path;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         ��� :
        ///               
        ///                
        ///      Runtime :
        /// Memory Usage :
        string simplifyPath(string path) {
            return {};
        }
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Simplify_Path_Model GetTestData001(void)
        {
            Simplify_Path_Model result;
            result.path = "/home/";
            return result;
            //Expect: /home
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Simplify_Path_Model GetTestData002(void)
        {
            Simplify_Path_Model result;
            result.path = "/../";
            return result;
            //Expect:"/"
        };

        /// <summary>
        /// ���ո��3
        /// </summary>   
        Simplify_Path_Model GetTestData003(void)
        {
            Simplify_Path_Model result;
            result.path = "/home//foo/";
            return result;
            //Expect:"/home/foo"
        };
#pragma endregion TestData
    };
}