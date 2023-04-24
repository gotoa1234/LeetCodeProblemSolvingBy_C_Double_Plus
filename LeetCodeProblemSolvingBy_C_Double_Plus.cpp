#include "Easy\0242.Valid_Anagram.cpp"
using namespace Solution242;

int main()
{

	Solution242::Valid_Anagram useClass;
	Solution242::Valid_Anagram::Valid_Anagram_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.isAnagram(getTestModel.s, getTestModel.s);
}