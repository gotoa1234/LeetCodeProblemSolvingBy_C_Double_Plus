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
        ///         ��� :�Q��Stack�̷ӱ����_�N�r���J�A�̫�զ��һݪ����G
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 9.6 MB Beats 59.14 %
        string simplifyPath(string path) {
            string result{};
            vector<string> stack;
            istringstream strStream(path);

            //1. �H'/'�����ΡA�@�ӭӦr����X
            for (string item; getline(strStream, item, '/');)
            {
                //2-1. ���L������
                if (item.empty() || item == ".")
                    continue;
                
                //2-2. �Y��.. ��ܱ˱��誺push
                if (item == "..")
                {
                    if (!stack.empty())
                        stack.pop_back();
                }
                else//2-3. �_�h���O�N�Ӧr���J
                    stack.push_back(item);
            }

            //3.�զ��s�bStack���r��A�զ����G
            for (const string& item : stack)
				result += "/" + item;
            //4. �Y���ŦA�̷��D�N�A���'/'�B�z
            return result.empty() ? "/" : result;
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

        /// <summary>
        /// ���ո��4
        /// </summary>   
        Simplify_Path_Model GetTestData004(void)
        {
            Simplify_Path_Model result;
            result.path = "/a/../../b/../c//.//";
            return result;
            //Expect:"/c"
        };

        /// <summary>
        /// ���ո��5
        /// </summary>   
        Simplify_Path_Model GetTestData005(void)
        {
            Simplify_Path_Model result;
            result.path = "/a//b////c/d//././/..";
            return result;
            //Expect:"/a/b/c"
        };

        /// <summary>
        /// ���ո��6
        /// </summary>   
        Simplify_Path_Model GetTestData006(void)
        {
            Simplify_Path_Model result;
            result.path = "/home////abc";
            return result;
            //Expect:"/home/abc"
        };

        /// <summary>
        /// ���ո��7
        /// </summary>   
        Simplify_Path_Model GetTestData007(void)
        {
            Simplify_Path_Model result;
            result.path = "/home//abc///aaa/..";
            return result;
            //Expect:"/home/abc"
        };

        /// <summary>
        /// ���ո��8
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