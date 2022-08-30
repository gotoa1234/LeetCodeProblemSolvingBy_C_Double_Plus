#include <vector>
#include <string>
#include "0394.Decode_String.cpp"
using namespace Solution394;

int main()
{
    Solution394::Decode_String useClass;
    Solution394::Decode_String::Decode_String_Model getTestModel = useClass.GetTestData001();
    string result = useClass.decodeString("3[ad4[cs]]");


    getTestModel = useClass.GetTestData002();
    result = useClass.decodeString(getTestModel.s);
    return 0;
}