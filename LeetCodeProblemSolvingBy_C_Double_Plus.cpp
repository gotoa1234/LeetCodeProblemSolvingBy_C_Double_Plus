#include <unordered_map>
#include "Medium/0151.Reverse_Words_in_a_String.cpp"
using namespace Solution151;

int main()
{
    Solution151::Reverse_Words_in_a_String useClass;
    Solution151::Reverse_Words_in_a_String::Reverse_Words_in_a_String_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.reverseWords(getTestModel.s);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.reverseWords(getTestModel.s);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.reverseWords(getTestModel.s);
    return 0;
}