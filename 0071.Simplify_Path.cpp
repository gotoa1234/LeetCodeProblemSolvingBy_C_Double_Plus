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
        ///         思路 :利用Stack依照條件不斷將字串放入，最後組成所需的結果
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 9.6 MB Beats 59.14 %
        string simplifyPath(string path) {
            string result{};
            vector<string> stack;
            istringstream strStream(path);

            //1. 以'/'為切割，一個個字串取出
            for (string item; getline(strStream, item, '/');)
            {
                //2-1. 跳過的條件
                if (item.empty() || item == ".")
                    continue;
                
                //2-2. 若為.. 表示捨棄剛剛的push
                if (item == "..")
                {
                    if (!stack.empty())
                        stack.pop_back();
                }
                else//2-3. 否則都是將該字串放入
                    stack.push_back(item);
            }

            //3.組成存在Stack的字串，組成結果
            for (const string& item : stack)
				result += "/" + item;
            //4. 若為空再依照題意，放個'/'處理
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