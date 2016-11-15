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
VAR<T>::~VAR(){}

#endif