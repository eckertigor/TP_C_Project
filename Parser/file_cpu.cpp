#include "file_cpu.h"
File_CPU::File_CPU() {
  bufer_file=NULL;
  name_file=NULL;
  atr=NULL;
  change_file();
  PDEBUG(name_file);
}

File_CPU::~File_CPU() {
  PDEBUG(name_file);
  close();
  if (name_file!=NULL)
    delete [] name_file;
}

FILE* File_CPU::get_file(){
  if (bufer_file)
    PDEBUG("[get file]");
  else
    PDEBUG("[not file]");
  return bufer_file;
}

char* File_CPU::get_fname(){
  PDEBUG(name_file);
  return name_file;
}

bool File_CPU::change_file(const char*_name_file){
  close();
  if (name_file!=NULL){
    delete [] name_file;
  }
  name_file=new char[strlen(_name_file)+1];
  strcpy(name_file,_name_file);
  PDEBUG(name_file);
  return (name_file!=NULL);
}

bool File_CPU::close(){
  if(bufer_file==NULL){
    PDEBUG("return false");
    return false;
  }
  if (fclose(bufer_file)){
    PDEBUG("[close]");
  }
  if (atr!=NULL){
    PDEBUG("[clear label]");
    delete [] atr;
    atr=NULL;
  }
  PDEBUG("return true");
  return (bufer_file=NULL); //не опечатка присваиваем и возращаем true
}

int File_CPU::check(const char* _atr){
  PDEBUG(_atr);
  if (_atr==NULL){
    PDEBUG("[error]: not file name");
    return -1;
  }
  if (atr!=NULL)
    return (strcmp(atr,_atr)==0)?0:1;
  else{
    atr=new char[strlen(_atr)+1];
    strcpy(atr,_atr);
  }
  bufer_file=fopen(name_file,atr);
  if(bufer_file!=NULL){
    PDEBUG("[open file: %s], [label] = \"%s\"",name_file,atr);
    return 0;
  }
  return -1;
}

bool File_CPU::open(const char* _atr){
  for(int i=check(_atr);i!=0;i=check(_atr)){
    if (i>0) {
      PDEBUG("[close]");
      close();
    }
    if (i<0) {
      PDEBUG("[error] - not open file");
      return false;
    }
  }
  return true;
}

int File_CPU::get_char(){
  if (!bufer_file)
    return EOF;
  return fgetc(bufer_file);
}
