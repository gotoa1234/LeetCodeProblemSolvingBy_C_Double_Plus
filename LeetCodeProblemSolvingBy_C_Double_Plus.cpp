#include <unordered_map>
#include "Easy/0168.Excel_Sheet_Column_Title.cpp"
using namespace Solution168;

int main()
{
    Solution168::Excel_Sheet_Column_Title useClass;
    Solution168::Excel_Sheet_Column_Title::Excel_Sheet_Column_Title_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.convertToTitle(getTestModel.columnNumber);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.convertToTitle(getTestModel.columnNumber);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.convertToTitle(getTestModel.columnNumber);
    return 0;
}