#pragma once
#include"../header/common.hpp"
#define DEBUGGING
#if defined(DEBUGGING)
template <typename T>
void LOGINFO(T args...){
  std::cout << "[LOGINFO] " << args << std::endl;
 }

template <typename T>
void LOGWARNING(T args...) {
   std::cout << "[LOGWARNING] " << args << std::endl;
 }

template <typename T>
void LOGERROR(T args...) {
   std::cout << "[LOGERROR] " << args << std::endl;
 }
#endif