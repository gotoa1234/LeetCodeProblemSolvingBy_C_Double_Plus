#include <unordered_map>
#include "Medium/0130.Surrounded_Regions.cpp"
using namespace Solution130;

int main()
{
    Solution130::Surrounded_Regions useClass;
    Solution130::Surrounded_Regions::Surrounded_Regions_Model getTestModel = useClass.GetTestData001();
    useClass.solve(getTestModel.board);

    getTestModel = useClass.GetTestData002();
    useClass.solve(getTestModel.board);
    return 0;
}