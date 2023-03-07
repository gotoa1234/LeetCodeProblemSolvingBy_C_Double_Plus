#include <unordered_map>
#include "Hard/0126.Word_Ladder_II.cpp"
using namespace Solution126;

int main()
{
    Solution126::Word_Ladder_II useClass;
    Solution126::Word_Ladder_II::Word_Ladder_II_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.findLadders(getTestModel.beginWord, getTestModel.endWord, getTestModel.wordList);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.findLadders(getTestModel.beginWord, getTestModel.endWord, getTestModel.wordList);

    /*getTestModel = useClass.GetTestData003();
    auto result3 = useClass.findLadders(getTestModel.beginWord, getTestModel.endWord, getTestModel.wordList);*/
    return 0;
}