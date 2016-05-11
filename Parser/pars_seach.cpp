#include "pars_seach.h"

pars_seach::pars_seach() {
  max_buffer=128;
  buffer_str=new char[max_buffer]();
}

pars_seach::~pars_seach() {
  if (buffer_str)
    delete [] buffer_str;
  buffer_str=NULL;
}
/*
int pars_seach::read_site(const char* tag){
  FILE* data=get_file();
  char s=fgetc(data);
  return 0;
}
*/

char* pars_seach::weed_by_tag(const char* tag_begin,const char* tag_end){
  memset(buffer_str,0,max_buffer);
  if (check("r")!=0){
    PDEBUG("[error]");
    strcpy(buffer_str,"[error]");
    close();
    return buffer_str;
  }
  bool error=false;
  uint i=0;
  int s;
  char ch=0;
  while(!error){
    s=get_char();
    ch=char(s);
    if (s==EOF){
      error=true;
      break;
    }
    if (tag_begin[i]==ch){
      i++;
      if (tag_begin[i]=='\0')
        break;
    }else
      i=0;
  }
  i=0;
  uint j=0;
  while(!error){
    s=get_char();
    ch=char(s);
    if (s==EOF){
      error=true;
      break;
    }
    if (tag_end[i]==ch){
      i++;
      if (tag_end[i]=='\0')
      break;
    }else{
      i=0;
      buffer_str[j]=ch;
      if(j==max_buffer)
        resize();
      j++;
    }
  }
  if (error){
    memset(buffer_str,0,max_buffer);
    PDEBUG("[error] EOF");
    strcpy(buffer_str,"EOF");
    close();
    return buffer_str;
  }
  return buffer_str;
}

bool pars_seach::resize(){
  char*_buffer_str=buffer_str;
  uint _max_buffer=max_buffer;
  max_buffer*=2;
  buffer_str=new char[max_buffer]();
  if (!buffer_str){
    buffer_str=_buffer_str;
    max_buffer=_max_buffer;
    return false;
  }
  strcpy(buffer_str,_buffer_str);
  delete [] _buffer_str;
  return true;
}
