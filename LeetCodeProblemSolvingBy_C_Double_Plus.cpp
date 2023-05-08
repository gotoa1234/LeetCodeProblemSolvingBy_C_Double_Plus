#include "Easy\0290.Word_Pattern.cpp"
using namespace Solution290;
using namespace std;


int main()
{
    Solution290::Word_Pattern useClass;
    Solution290::Word_Pattern::Word_Pattern_Model getTestModel = useClass.GetTestData001();
    auto result = useClass.wordPattern(getTestModel.pattern, getTestModel.s);

    return 0;
}