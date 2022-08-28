#include <vector>
#include "0424.Longest_Repeating_Character_Replacement.cpp"
using namespace Solution424;

int main()
{
    Solution424::Longest_Repeating_Character_Replacement useClass;
    Solution424::Longest_Repeating_Character_Replacement::Longest_Repeating_Character_Replacement_Model getTestModel = useClass.GetTestData001();
    int result = useClass.characterReplacement(getTestModel.s, getTestModel.k);

    getTestModel = useClass.GetTestData002();
    result = useClass.characterReplacement(getTestModel.s, getTestModel.k);
    return 0;
}