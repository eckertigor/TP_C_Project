
#include "TControler.h"

TControler::TControler() {
  ps;
  dl;
  db=NULL;
  url_list=NULL;
  id_url_tag=NULL;
  tag_begin=NULL;
  tag_end=NULL;
}

TControler::~TControler(){
  ps.~pars_seach();
  dl.~download_layout();
  if(url_list)
    delete url_list;
  if(id_url_tag)
    delete id_url_tag;
  if(tag_begin)
    delete tag_begin;
  if(tag_end)
    delete tag_end;
  if(place_id)
    delete place_id;    
}

void TControler::set_obj(TStorage *db_){
  db=db_;
}
/*
void TControler::set_obj(download_layout *dl_){
  dl=dl_;
}
*//*
void TControler::set_obj(pars_seach *ps_){
  ps=ps_;
} 
*/
bool TControler::set_table_cell(const char* table_, const int cell_){
  if(!db||!db->set_query(table_)||cell_>=db->fields()) 
    return false;
  return true;
}

bool TControler::read_sql(const char* table_, const int cell_, read_t i){
  if(set_table_cell(table_, cell_)){
    switch(i){
      case db_url:
          if(url_list)
            delete url_list;
          url_list=buffer(table_,cell_);
        return true;
      case db_teg:
        if(id_url_tag)
          delete id_url_tag;
        id_url_tag=buffer(table_,cell_);
        return true;
      case db_begin:
        if(tag_begin)
          delete tag_begin;
        tag_begin=buffer(table_,cell_);
        return true;
      case db_end:
        if(tag_end)
          delete tag_end;
        tag_end=buffer(table_,cell_);
        return true;
      case db_place:
        if(place_id)
          delete place_id;
        place_id=buffer(table_,cell_);
        return true;
    }
  }
  return false;
}

Column* TControler::buffer(const char* table_,const int cell_){
  Column* Result=new Column();
  Result->db_name.rename(db->get_name());
  Result->table_name.rename(table_);
  Result->name.rename(db->field(cell_)->name);
  Result->set_max(db->rows());
  for (int i=0;i<db->rows();i++){
    //почему так не понимаю
    strcpy(Result->operator [](i),db->get_sell(cell_));
  }
  return Result;
}

bool TControler::set_write_sql(const char* table_, const int cell_){
  //Примеры команды изменения данных в ячейку
  //UPDATE `appDB`.`weather_url_now` SET `url_tag_id`='1' WHERE `url_place_id`='7';
  //UPDATE `appDB`.`place` SET `place_weather`='20' WHERE `place_id`='6';
  //необходим маленький класс собирающий команду изменения некто лямда функция
}

int TControler::parse(){
  int error=check();
  if (error)
    return error;  
  for (int i=0,j=0;i<url_list->get_max();i++){
    if(dl.get_http_doc(url_list->operator [](i),ps.get_file())){
      j=atoi(id_url_tag->operator [](i));
      ps.weed_by_tag(tag_begin->operator [](i),
                     tag_end->operator [](i)
         );
    }
  }  
}

int TControler::check(){
    //позже допишем
    return 0;
}