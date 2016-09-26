#include "stack.h"

template <typename T>
inline stack<T>::~stack()
{
	delete[] array_;
}

template <typename T>
inline stack<T>::stack() :count_(0),array_size_(0),array_(nullptr){};

template <typename T>
inline auto stack<T>::push(T const &val)->void {
	if (array_ == nullptr) {
		array_ = new T[1];
		array_[0] = val;
		count_++; array_size_++;
	}
	else {
		if (count_ == array_size_) {
			T *tmp = array_;
			array_size_ *= 2;
			array_ = new T[array_size_];
			std::copy(tmp,tmp+count_,array_);
			delete[] tmp;
		}
		array_[count_] = val;
		count_++;
	}
}
template <typename T>
inline stack<T>::stack(const stack&tmp):count_(tmp.count_),array_size_(tmp.array_size_),array_(new T[tmp.array_size_]) {
	array_ = new T[array_size_];
	copy(tmp.array_, tmp.array_ + count_, array_);
}

template <typename T>
inline auto stack<T>::operator=(const stack&tmp)->stack& {
	if (this != &tmp) {
		delete[] array_;
		count_ = tmp.count_;
		array_size_ = tmp.array_size_;
		array_ = new T[array_size_];
		copy(tmp.array_, tmp.array_ + count_, array_);
	}
	return *this;
}

template <typename T>
inline auto stack<T>::print()->void {
	for (size_t i(0); i < count_; i++) cout << array_[i] << endl; 
}

template <typename T>
inline auto stack<T>::count() const noexcept->size_t {
	return count_;
}

template<typename T>
inline auto stack<T>::pop() -> T {
if (count_ == 0) {
throw std::range_error("Empty stack");
}
return array_[--count_];
}
