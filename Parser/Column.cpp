/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Column.cpp
 * Author: alexandr
 * 
 * Created on 10 мая 2016 г., 21:45
 */

#include <string.h>

#include "Column.h"

Tname::Tname(){
  name=NULL;
}

Tname::~Tname(){
  rename(NULL);
}

void Tname::rename(const char* _name){
  if(name){
    delete [] name;
    name=NULL;
  }
  if(_name){
    name=new char[strlen(_name)+1];
    strcpy(name,_name);
  }
}

char* Tname::get_name(){
  return name;
}

Column::Column() {
  data=NULL;
  max=0;
  set_max(1);
}

/*
Column::Column(const Column& orig) {
}
 */

Column::~Column() {
  data_clear();
}

void Column::data_clear(){
  for(uint i=0;i<max;i++){
    if(data[i])
      delete [] data[i];
  }
  if(data)
    delete[] data;
  data=NULL;
}

char* &Column::operator [](const uint i){
  if(i<max)
    return data[i];
  return data[0];
}

void Column::set_max(uint _max){
  if(max=_max)
    return;
  char**_data=new char*[_max]();
  int m=_max;
  if(m>max)
      m=max;
  for(int i=0; i<m;i++){
    _data[i]=data[i];
    data[i]=NULL;
  }
  data_clear();
  data=_data;
  _data=NULL;
  max=_max;
}

uint Column::get_max(){
  return max;
}