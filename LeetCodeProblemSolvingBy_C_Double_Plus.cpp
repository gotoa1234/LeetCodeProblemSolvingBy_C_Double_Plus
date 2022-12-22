#include <vector>
#include "0072.Edit_Distance.cpp"
using namespace Solution72;

int main()
{
    Solution72::Edit_Distance useClass;
    Solution72::Edit_Distance::Edit_Distance_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.minDistance(getTestModel.word1, getTestModel.word2);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.minDistance(getTestModel.word1, getTestModel.word2);

    return 0;
}