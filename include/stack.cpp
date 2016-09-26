#include "stack.h"

template <typename T>//копирование и выделение памяти 
auto mem_copy(size_t count_m, size_t array_size_m, const T * tmp)->T* {
	T *mass = new T[array_size_m];
	copy(tmp,tmp+count_m,mass);
	return mass; 
}

template<typename T>//пуст ли стэк или нет
inline auto stack<T>::empty()->bool { 
	if (this->count()) { return false; }
	else { return true; }
}

template <typename T>//освобождение памяти
inline stack<T>::~stack()
{
	delete[] array_;
}

template <typename T>//конструктор по умолчанию
inline stack<T>::stack() :count_(0),array_size_(0),array_(nullptr){};

template <typename T>//вставка элемента в стэк 
inline auto stack<T>::push(T const &val)->void {
	if (count_ == array_size_) {
			size_t size = array_size_ * 2+ (array_size_==0);
			T *tmp = mem_copy(count_,size,array_);
			delete[] array_;
			array_ = tmp;
			array_size_=size;

		}
		count_++;
		array_[count_-1] = val;
		
	
	}


template <typename T>//конструктор копирования
inline stack<T>::stack(const stack&tmp) :count_(tmp.count_), array_size_(tmp.array_size_), array_(mem_copy(tmp.count_, tmp.array_size_, tmp.array_)) {}

template <typename T>//перегрузка оператора присваивания 
inline auto stack<T>::operator=(const stack&tmp)->stack& {
	if (this != &tmp) {
		delete[] array_;
		count_ = tmp.count_;
		array_size_ = tmp.array_size_;
		array_ =mem_copy(tmp.count_, tmp.array_size_, tmp.array_);
	}
	return *this;
}

template <typename T>//возвращаем count_
inline auto stack<T>::count() const noexcept->size_t {
	return count_;
}

template <typename T>// уменьшение count_ 
inline auto stack<T>::pop()->T {
	if (count_ == 0) throw logic_error("Empty!");
	return --count_;
}

template <typename T>//удаление элемента
inline auto stack<T>::top() const->T&  {
	if (count_ == 0) throw logic_error("Empty!");
	return array_[count_];

}
