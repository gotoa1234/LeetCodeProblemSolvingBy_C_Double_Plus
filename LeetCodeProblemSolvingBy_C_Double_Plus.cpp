#include <unordered_map>
#include "0509.Fibonacci_Number.cpp"
using namespace Solution509;

int main()
{
    Solution509::Fibonacci_Number useClass;
    Solution509::Fibonacci_Number::Fibonacci_Number_Model getTestModel = useClass.GetTestData001();
    int result = useClass.fib(getTestModel.n);
    result = useClass.fib(6);
    getTestModel = useClass.GetTestData002();
    result = useClass.fib(getTestModel.n);

    getTestModel = useClass.GetTestData003();
    result = useClass.fib(getTestModel.n);
    return 0;
}