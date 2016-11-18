#include "Var.h"
#include "common.h"
#ifndef VAR_CPP
#define VAR_CPP

template<typename T>
VAR<T>::VAR(){}

template<typename T>
string VAR<T>::getName() {
	return name;
}

template<typename T>
T VAR<T>::getValue() {
    return value;
}

template<typename T>
bool VAR<T>::locked() {
	return isLocked;
}

template<typename T>
void VAR<T>::setLock() {
	isLocked = true;
}

template<typename T>
void VAR<T>::unLock() {
	isLocked = false;
}

template<typename T>
VAR<T>::~VAR(){}

#endif