#include "Medium\0114.Flatten_Binary_Tree_to_Linked_List.cpp"
using namespace Solution114;
using namespace std;

int main()
{
	Solution114::Flatten_Binary_Tree_to_Linked_List useClass;
	Solution114::Flatten_Binary_Tree_to_Linked_List::Flatten_Binary_Tree_to_Linked_List_Model getTestModel = useClass.GetTestData001();
	useClass.flatten(getTestModel.root);

	getTestModel = useClass.GetTestData002();
	useClass.flatten(getTestModel.root);
}