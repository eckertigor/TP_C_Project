#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "log_debug.h"

#ifndef FILE_CPU_H
#define FILE_CPU_H

class File_CPU_with_clear;

class File_CPU {
public:
  File_CPU();
  virtual ~File_CPU();
  FILE* get_file();   //получить объект файла
  char* get_fname();
  int get_char();
  bool change_file(const char*_name_file="TEMP"); //сменить имя файла
  bool open(const char*);
  bool close(); //закрыть файл
  int check(const char*);
  friend File_CPU_with_clear;
private:
  FILE* bufer_file;
  char* name_file;
  char* atr;
};

#endif // FILE_CPU_H
