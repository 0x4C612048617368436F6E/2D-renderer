#pragma once
#include"../header/common.hpp"
#ifndef DEBUGGING
#define DEBUGGING
#endif  // !DEBUGGING

#ifndef TURNWARNINGTOERROR
#define TURNWARNINGTOERROR
#endif

#if defined(DEBUGGING)
template <typename T>
void LOGINFO(T args...){
  std::cout << "[LOGINFO] " << args << std::endl;
 }

#if !defined(TURNWARNINGTOERROR)
  template <typename T>
void LOGWARNING(T args...) {
   std::cout << "[LOGWARNING] " << args << std::endl;
 }
#endif

template <typename T>
 void LOGWARNING(T args...) {
   std::cout << "[LOGWARNING] " << args << std::endl;
  exit(EXIT_FAILURE);
 }

template <typename T>
void LOGERROR(T args...) {
   std::cout << "[LOGERROR] " << args << std::endl;
 }
#endif