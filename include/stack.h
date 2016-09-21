#include <iostream>
using namespace std;

template <typename T>
class stack
{
public:
	stack();/*noexcept*/
	stack(const stack&); /*strong*/
	auto count() const noexcept->size_t;/*noexcept*/
	auto push(T const &)->void;/*strong*/
	auto pop()->T;/*strong*/
	auto top() const->T&;/*strong*/
	~stack(); 	/*noexcept*/
	auto operator=(const stack&tmp)->stack&;/*strong*/
	auto empty()->bool;	/*noexcept*/
private:
	T * array_;
	size_t array_size_;
	size_t count_;
};
