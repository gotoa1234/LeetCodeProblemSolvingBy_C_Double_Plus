#include <unordered_map>
#include "0079.Word_Search.cpp"
using namespace Solution79;

int main()
{
    Solution79::Word_Search useClass;
    Solution79::Word_Search::Word_Search_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.exist(getTestModel.board, getTestModel.word);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.exist(getTestModel.board, getTestModel.word);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.exist(getTestModel.board, getTestModel.word);
    return 0;
}