#include "Medium\0109.Convert_Sorted_List_to_Binary_Search_Tree.cpp"
using namespace Solution109;
using namespace std;

int main()
{
    Solution109::Convert_Sorted_List_to_Binary_Search_Tree useClass;
    Solution109::Convert_Sorted_List_to_Binary_Search_Tree::Convert_Sorted_List_to_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
    Convert_Sorted_List_to_Binary_Search_Tree::TreeNode* result = useClass.sortedListToBST(getTestModel.head);

}