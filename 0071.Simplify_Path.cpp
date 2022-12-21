#include <vector>
#include <string>
#include <sstream> 
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
    /// 簡化路徑
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
        ///         思路 :
        ///      Runtime :
        /// Memory Usage :
        string simplifyPath(string path) {
            string result;
            istringstream iss(path);
            vector<string> stack;

            for (string dir; getline(iss, dir, '/');) {
                if (dir.empty() || dir == ".")
                    continue;
                if (dir == "..") {
                    if (!stack.empty())
                        stack.pop_back();
                }
                else {
                    stack.push_back(dir);
                }
            }

            for (const string& s : stack)
                result += "/" + s;

            return result.empty() ? "/" : result;
        }
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Simplify_Path_Model GetTestData001(void)
        {
            Simplify_Path_Model result;
            result.path = "/home/";
            return result;
            //Expect: /home
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Simplify_Path_Model GetTestData002(void)
        {
            Simplify_Path_Model result;
            result.path = "/../";
            return result;
            //Expect:"/"
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        Simplify_Path_Model GetTestData003(void)
        {
            Simplify_Path_Model result;
            result.path = "/home//foo/";
            return result;
            //Expect:"/home/foo"
        };

        /// <summary>
        /// 測試資料4
        /// </summary>   
        Simplify_Path_Model GetTestData004(void)
        {
            Simplify_Path_Model result;
            result.path = "/a/../../b/../c//.//";
            return result;
            //Expect:"/c"
        };

        /// <summary>
        /// 測試資料5
        /// </summary>   
        Simplify_Path_Model GetTestData005(void)
        {
            Simplify_Path_Model result;
            result.path = "/a//b////c/d//././/..";
            return result;
            //Expect:"/a/b/c"
        };

        /// <summary>
        /// 測試資料6
        /// </summary>   
        Simplify_Path_Model GetTestData006(void)
        {
            Simplify_Path_Model result;
            result.path = "/home////abc";
            return result;
            //Expect:"/home/abc"
        };

        /// <summary>
        /// 測試資料7
        /// </summary>   
        Simplify_Path_Model GetTestData007(void)
        {
            Simplify_Path_Model result;
            result.path = "/home//abc///aaa/..";
            return result;
            //Expect:"/home/abc"
        };

        /// <summary>
        /// 測試資料8
        /// </summary>   
        Simplify_Path_Model GetTestData008(void)
        {
            Simplify_Path_Model result;
            result.path = "/home//abc////aaa/../../..";
            return result;
            //Expect:"/home/abc/aaa"
        };
#pragma endregion TestData
    };
}