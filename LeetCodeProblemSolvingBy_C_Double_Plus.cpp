#include "0002_Add_Two_Numbers.cpp"
using namespace Solution2;
using namespace std;



int main()
{

	Solution2::Add_Two_Numbers useClass;
	Solution2::Add_Two_Numbers::Add_Two_Numbers_Model getTestModel = useClass.GetTestData001();
	Solution2::Add_Two_Numbers::ListNode* result = useClass.addTwoNumbers(getTestModel.l1, getTestModel.l2);


	return 0;
}