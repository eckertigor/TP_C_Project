#include "log_debug.h"
#define MAX 1024
void realdprintf(int line, const char *func, char const *fmt ...){ 
  char *mes=NULL;
  mes=new char[MAX];
  sprintf(mes,fmt);
  FILE *LOG=fopen("log.txt","a+");
  fprintf(LOG,"%d - %s : %s\n",line,func,mes);
  delete [] mes;
  fclose(LOG);
}
