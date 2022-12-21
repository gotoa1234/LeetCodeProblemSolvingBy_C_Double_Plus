#include <vector>
#include "0071.Simplify_Path.cpp"
using namespace Solution71;

int main()
{
    Solution71::Simplify_Path useClass;
    Solution71::Simplify_Path::Simplify_Path_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.simplifyPath(getTestModel.path);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.simplifyPath(getTestModel.path);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.simplifyPath(getTestModel.path);

    getTestModel = useClass.GetTestData004();
    auto result4 = useClass.simplifyPath(getTestModel.path);

    getTestModel = useClass.GetTestData005();
    auto result5 = useClass.simplifyPath(getTestModel.path);

    getTestModel = useClass.GetTestData006();
    auto result6 = useClass.simplifyPath(getTestModel.path);

    getTestModel = useClass.GetTestData007();
    auto result7 = useClass.simplifyPath(getTestModel.path);

    getTestModel = useClass.GetTestData008();
    auto result8 = useClass.simplifyPath(getTestModel.path);
    return 0;
}