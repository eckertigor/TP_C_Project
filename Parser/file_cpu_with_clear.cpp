#include "file_cpu_with_clear.h"

File_CPU_with_clear::~File_CPU_with_clear() {
  if(remove(name_file)){
    PDEBUG("[delete file: %s]",name_file);
    delete [] name_file;
  }
}

bool File_CPU_with_clear::change_file(const char*_name_file){
  close();
  if (name_file!=NULL&&remove(name_file)){
    PDEBUG("[delete file: %s]",name_file);
    delete [] name_file;
  }
  name_file=new char[strlen(_name_file)+1];
  strcpy(name_file,_name_file);
  PDEBUG(name_file);
  return (name_file!=NULL);
}
