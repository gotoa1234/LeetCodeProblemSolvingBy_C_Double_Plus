#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

namespace Solution225
{
#pragma region Paste to execute 
	/*
	#include "Easy\0225.Implement_Stack_using_Queues.cpp"
	using namespace Solution225;

	int main()
	{

		Solution225::Implement_Stack_using_Queues useClass;
		Solution225::Implement_Stack_using_Queues::Implement_Stack_using_Queues_Model getTestModel = useClass.GetTestData001();
		bool result = useClass.isAnagram(getTestModel.s, getTestModel.s);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ��{���|�u�ϥζJ�C
	/// </summary>
	class Implement_Stack_using_Queues
	{
#pragma region Model
	public:
		class Implement_Stack_using_Queues_Model
		{
		public:
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ��� : �D�حn�D��1�� queue<int> ��{Stack (���i��X)���ĪG�A�]�����Queue����Pop()��
		///                 �u�n�N��equeue<int> ����queue.size() - 1 ����Ƴ��i��push + Pop �A�M��̫�@���N�OStack�nPop����
		///       Runtime :  0 ms Beats 100 %
		///  Memory Usage :6.7 MB Beats 69.5 %
		/// </summary>
		class MyStack {
		public:
			queue<int> _queue;			
			MyStack() {				
			}

			void push(int x) {
				_queue.push(x);
			}

			int pop() {				
				for (int index = 0; index < _queue.size() - 1; index++)
				{
					_queue.push(_queue.front());
					_queue.pop();
				}
				auto topValue = _queue.front();
				_queue.pop();				
			    return topValue;
			}

			int top() {
				return _queue.back();
			}

			bool empty() {				
				return _queue.empty();
			}
		};
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Implement_Stack_using_Queues_Model GetTestData001(void)
		{
			/*
			
			Input ["MyStack", "push", "push", "top", "pop", "empty"] [[], [1], [2], [], [], []]
           Output [null, null, null, 2, 2, false]
Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
			
			*/
		};		

#pragma endregion TestData
	};
}