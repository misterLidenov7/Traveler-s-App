#pragma once
#include <iostream>

template<class T>
class Vector {

private:
	T* elements;
	size_t size;
	size_t capacity;

private:
	void destroy();
	void copy(const Vector<T>&);
	void resize();

public:
	Vector();
	Vector(const Vector<T>&);
	~Vector();
	Vector<T>& operator=(const Vector<T>& other);

	size_t sizeGetter() const;
	size_t capacityGetter() const;
	T& operator[](const int) const;
	void pushBack(const T&);
	void setElement(size_t i, const T& x);
	T getElement(size_t i);

	template<class X>
	friend std::ostream& operator<<(std::ostream&, const Vector<X>&);
};

template<class T>
inline void Vector<T>::destroy()
{
	delete[] elements;
}

template<class T>
inline void Vector<T>::copy(const Vector<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	elements = new T[capacity];

	for (int i = 0; i < size; ++i) {
		elements[i] = other.elements[i];
	}
}

template<class T>
inline void Vector<T>::resize()
{
	capacity *= 2;

	T* newElems = new T[capacity];
	for (int i = 0; i < size; ++i) {
		newElems[i] = elements[i];
	}
	destroy();
	elements = newElems;
}

template<class T>
inline Vector<T>::Vector(){
	size = 0;
	capacity = 16;
	elements = new T[capacity];
}

template<class T>
inline Vector<T>::Vector(const Vector<T>& other)
{
	copy(other);
}

template<class T>
inline Vector<T>::~Vector()
{
	destroy();
}

template<class T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if(this != &other){
		destroy();
		copy(other);
	}
	return *this;
}

template<class T>
inline size_t Vector<T>::sizeGetter() const
{
	return size;
}

template<class T>
inline size_t Vector<T>::capacityGetter() const
{
	return capacity;
}

template<class T>
inline T& Vector<T>::operator[](const int i) const
{
	if (i >= 0 && i < size) {
		return elements[i];
	}
}

template<class T>
inline void Vector<T>::pushBack(const T& add)
{
	if (size + 1 >= capacity) {
		resize();
	}
	elements[size] = add;
	++size;
}

template<class T>
inline void Vector<T>::setElement(size_t i, const T& x)
{
	if (i >= 0 && i < size) {
		elements[i] = x;
	}
}

template<class T>
inline T Vector<T>::getElement(size_t i)
{
	if (i >= 0 && i < size) {
		return elements[i];
	}
}

template<class T>
inline std::ostream& operator<<(std::ostream& out, const Vector<T>& v)
{
	out << "{ ";
	for (int i = 0; i < v.size; ++i) {
		out << v.elements[i] << " ";
	}
	out << " }\n";

	return out;
}
