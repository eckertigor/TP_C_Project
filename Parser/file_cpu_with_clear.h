#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "log_debug.h"
#include "file_cpu.h"

#ifndef FILE_CPU_WITH_CLEAR_H
#define FILE_CPU_WITH_CLEAR_H

class File_CPU_with_clear:public File_CPU{
public:
  virtual ~File_CPU_with_clear();
  bool change_file(const char*_name_file="TEMP");
};

#endif // FILE_CPU_WITH_CLEAR_H
