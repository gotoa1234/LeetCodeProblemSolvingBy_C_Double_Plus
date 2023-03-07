#include <unordered_map>
#include "Hard/0127.Word_Ladder.cpp"
using namespace Solution127;

int main()
{
    Solution127::Word_Ladder useClass;
    Solution127::Word_Ladder::Word_Ladder_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.ladderLength(getTestModel.beginWord, getTestModel.endWord, getTestModel.wordList);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.ladderLength(getTestModel.beginWord, getTestModel.endWord, getTestModel.wordList);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.ladderLength(getTestModel.beginWord, getTestModel.endWord, getTestModel.wordList);
    return 0;
}