#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "log_debug.h"
#include "file_cpu_with_clear.h"

#ifndef PARS_SEACH_H
#define PARS_SEACH_H

class pars_seach: public File_CPU_with_clear{
public:
  pars_seach();
  virtual ~pars_seach();
  char* get_data();
  char* weed_by_tag(const char*,const char*);
private:
//  int read_site(const char*);
  bool resize();
  char *buffer_str;
  uint max_buffer;
};

#endif // PARS_SEACH_H
