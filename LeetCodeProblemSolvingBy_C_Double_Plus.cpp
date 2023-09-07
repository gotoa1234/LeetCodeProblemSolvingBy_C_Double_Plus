#include "Easy\0455.Assign_Cookies.cpp"
using namespace Solution455;

int main()
{
	Solution455::Assign_Cookies useClass;
	Solution455::Assign_Cookies::Assign_Cookies_Model getTestModel = useClass.GetTestData001();
	auto result = useClass.findContentChildren(getTestModel.g, getTestModel.s);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.findContentChildren(getTestModel.g, getTestModel.s);
}