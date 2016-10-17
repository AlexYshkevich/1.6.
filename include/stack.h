#include <iostream>
template <typename T>
class stack 
{
public:
	stack();/*noexcept*/
	stack(stack const &); /*strong*/
	auto count() const noexcept->size_t;/*noexcept*/
	auto push(T const &)->void;/*strong*/
	auto pop()->T;/*basic*/
	//auto top() const->T&;/*strong*/
	~stack(); 	/*noexcept*/
	auto operator=(const stack&tmp)->stack&;/*strong*/
	auto empty()->bool;/*noexcept*/
	private : 
	T * ptr_;
	size_t size_;
	size_t count_;

};
