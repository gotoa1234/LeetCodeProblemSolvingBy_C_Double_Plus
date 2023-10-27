#include "Easy\0028.Find_the_Index_of_the_First_Occurrence_in_a_String.cpp"
using namespace Solution28;
using namespace std;

int main()
{
	Solution28::Find_the_Index_of_the_First_Occurrence_in_a_String useClass;
	Solution28::Find_the_Index_of_the_First_Occurrence_in_a_String::Find_the_Index_of_the_First_Occurrence_in_a_String_Model getTestModel = useClass.GetTestData001();
	int result = useClass.strStr(getTestModel.haystack, getTestModel.needle);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.strStr(getTestModel.haystack, getTestModel.needle);


	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.strStr(getTestModel.haystack, getTestModel.needle);
	return 0;
}