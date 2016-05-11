#include <cstdio>
#include <cstdlib>

#ifndef COLUMN_H
#define COLUMN_H

class Tname{
public:
  Tname();
  virtual ~Tname();
  void rename(const char* _name);
  char* get_name();
private:
  char *name;  
};

class Column {
public:
  Column();
  //Column(const Column& orig);
  virtual ~Column();
  void data_clear();
  void set_max(uint _max);
  uint get_max();
  char* &operator [] (const uint i);
  Tname name;
  Tname table_name;
  Tname db_name;
private:
  char** data;
  uint max;
};

#endif /* COLUMN_H */

