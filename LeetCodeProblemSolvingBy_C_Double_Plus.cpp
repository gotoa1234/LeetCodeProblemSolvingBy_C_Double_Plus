#include "Easy\0541.Reverse_String_II.cpp"
using namespace Solution541;

int main()
{
	Solution541::Reverse_String_II useClass;
	Solution541::Reverse_String_II::Reverse_String_II_Model getTestModel = useClass.GetTestData001();
	auto result = useClass.reverseStr(getTestModel.s, getTestModel.k);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.reverseStr(getTestModel.s, getTestModel.k);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.reverseStr(getTestModel.s, getTestModel.k);
}