#include "0022.Generate_Parentheses.cpp"
using namespace Solution22;
using namespace std;

int main()
{
	Solution22::Generate_Parentheses useClass;
	Solution22::Generate_Parentheses::Generate_Parentheses_Model getTestModel = useClass.GetTestData001();
	vector<string> result = useClass.generateParenthesis(getTestModel.n);

	getTestModel = useClass.GetTestData002();
	result = useClass.generateParenthesis(getTestModel.n);

	return 0;
}