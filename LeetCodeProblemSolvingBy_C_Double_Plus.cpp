#include <unordered_map>
#include "0075.Sort_Colors.cpp"
using namespace Solution75;

int main()
{
    Solution75::Sort_Colors useClass;
    Solution75::Sort_Colors::Sort_Colors_Model getTestModel = useClass.GetTestData001();
    useClass.sortColors(getTestModel.nums);

    getTestModel = useClass.GetTestData002();
    useClass.sortColors(getTestModel.nums);

    return 0;
}