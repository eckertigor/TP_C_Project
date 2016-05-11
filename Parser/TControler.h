#include "log_debug.h"
#include "download_layout.h"
#include "pars_seach.h"
#include "tstorage.h"
#include "Column.h"

#ifndef TCONTROLER_H
#define TCONTROLER_H

typedef enum {
  db_url,
  db_teg,
  db_begin,
  db_end,
  db_place        
}read_t;

class TControler{
public:
  TControler();
  virtual ~TControler();
  void set_obj(TStorage *db_);
  //void set_obj(download_layout *dl_);
  //void set_obj(pars_seach *ps_);  
  bool read_sql(const char* table_,const int cell_,read_t);
  bool set_write_sql(const char* table_,const int cell_);
  int parse();
private:
  pars_seach ps;
  download_layout dl;
  TStorage* db;
  Column* url_list;
  Column* id_url_tag;
  Column* place_id;
  Column* tag_begin;
  Column* tag_end;
  Update_command write;
  bool set_table_cell(const char* table_,const int cell_);
  Column* buffer(const char* table_,const int cell_);
  int check();
};

#endif /* TCONTROLER_H */

