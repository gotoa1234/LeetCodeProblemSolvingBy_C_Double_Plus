#include "Easy\0448.Find_All_Numbers_Disappeared_in_an_Array.cpp"
using namespace Solution448;

int main()
{
	Solution448::Find_All_Numbers_Disappeared_in_an_Array useClass;
	Solution448::Find_All_Numbers_Disappeared_in_an_Array::Find_All_Numbers_Disappeared_in_an_Array_Model getTestModel = useClass.GetTestData001();
	auto result = useClass.findDisappearedNumbers(getTestModel.nums);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.findDisappearedNumbers(getTestModel.nums);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.findDisappearedNumbers(getTestModel.nums);
}