#pragma once

template <typename T, T value>
struct TypeDefVal {
	T val = value;

	TypeDefVal() {};
	TypeDefVal(T value) : val(value) {}
	operator T() const { return val; }
	TypeDefVal<T, value> &operator =(const TypeDefVal<T, value> &typeDefVal) { return *this = typeDefVal; }
	T &operator =(T value) { return this->val = value; }
};