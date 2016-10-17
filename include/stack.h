#include <iostream>
 template<typename T>
 class allocator
 {
 protected:
 	allocator(size_t size = 0);
 	~allocator();
 	auto swap(allocator& other)->void;
 	allocator(allocator const&) = delete;
 	auto operator=(allocator const&)->allocator& = delete;
 	T * ptr_;
 	size_t size_;
 	size_t count_;
 };
 
 template <typename T>// конструктор аллокатора
 inline allocator<T>::allocator(size_t size) : ptr_(static_cast<T *>(size == 0 ? nullptr : operator new(size * sizeof(T)))), size_(0), count_(size) {
 };
 
 template <typename T>//деструктор аллокатора
 inline allocator<T>::~allocator() {
 delete ptr_;
 };
 
 template <typename T>//swap allocator
 inline auto allocator<T>::swap(allocator& other)->void {
	std::swap(ptr_, other.ptr_);
 	std::swap(size_, other.size_);
 	std::swap(count_, other.count_);
 };
