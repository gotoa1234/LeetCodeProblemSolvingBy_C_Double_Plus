#include "Easy\0412.Fizz_Buzz.cpp"
using namespace Solution412;

int main()
{

	Solution412::Fizz_Buzz useClass;
	Solution412::Fizz_Buzz::Fizz_Buzz_Model getTestModel = useClass.GetTestData001();
	auto result = useClass.fizzBuzz(getTestModel.n);

	getTestModel = useClass.GetTestData002();
	result = useClass.fizzBuzz(getTestModel.n);

	getTestModel = useClass.GetTestData003();
	result = useClass.fizzBuzz(getTestModel.n);
}