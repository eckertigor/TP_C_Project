
#include "TControler.h"

TControler::TControler() {
  ps;
  dl;
  db=NULL;
  url_list=NULL;
  id_url_tag=NULL;
  cell_place=0;
  tag_begin=NULL;
  tag_end=NULL;
  url_elm_max=0;
  tag_begin_max=0;
  tag_end_max=0;
  id_tag_max=0;
}

TControler::~TControler() {
  ps.~pars_seach();
  dl.~download_layout();
  url_clear();
  id_url_tag_clear();
  tag_begin_clear();
  tag_end_clear();
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
    int max=db->rows();
      char** buffer_str=buffer(cell_);
    switch(i){
      case db_url:
        url_clear();
        url_list=buffer_str;
        url_elm_max=max;
        return true;
      case db_teg:
        id_url_tag_clear();
        id_url_tag=new int[max]();
        for(int j=0;j<max;j++)
          id_url_tag[j]=atoi(buffer_str[j]);
        id_tag_max=max;
        return true;
      case db_begin:
        tag_begin_clear();
        tag_begin=buffer_str;
        tag_begin_max=max;
        return true;
      case db_end:
        tag_end_clear();
        tag_end=buffer_str;
        tag_end_max=max;
        return true;
    }
    if(buffer_str){
      for(int j=0;j<max;j++){
        if(buffer_str[j])
          delete [] buffer_str[j];
      }
      delete [] buffer_str;
    }
  }
  return false;
}

char** TControler::buffer(const int cell_){
  char** Result=new char*[db->rows()]();
  for (int i=0;i<db->rows();i++){
    Result[i]=db->get_sell(cell_);
  }
  return Result;
}

void TControler::url_clear(){
  for(int i=0;i<url_elm_max;i++){
    if(url_list[i])
      delete [] url_list[i];
  }
  if(url_list)
    delete [] url_list;
  url_list=NULL;
  url_elm_max=0;
}

void TControler::id_url_tag_clear(){
  if(id_url_tag)
    delete [] id_url_tag;
  id_url_tag=NULL;
  id_tag_max=0;
}

void TControler::tag_begin_clear(){
  for(int i=0;i<tag_begin_max;i++){
    if(tag_begin[i])
      delete [] tag_begin[i];
  }
  if(tag_begin)
    delete [] tag_begin;
  tag_begin=NULL;
  tag_begin_max=0;
}

void TControler::tag_end_clear(){
  for(int i=0;i<tag_end_max;i++){
    if(tag_end[i])
      delete [] tag_end[i];
  }
  if(tag_end)
    delete [] tag_end;
  tag_end=NULL;
  tag_end_max=0;
}

bool TControler::set_write_sql(const char* table_, const int cell_){
   if(set_table_cell(table_, cell_)){
     cell_place=cell_;
     return true;  
   }
    return false;
}

int TControler::parse(){
  int error=check();
  if (error)
    return error;  
  for (int i=0;i<url_elm_max;i++){
    if(dl.get_http_doc(url_list[i],ps.get_file())){
      ps.weed_by_tag(tag_begin[id_url_tag[i]],
                     tag_end[id_url_tag[i]]
         );
    }
  }  
}

int TControler::check(){
    if(url_elm_max!=id_tag_max){
      PDEBUG("url_elm_max!=id_tag_max");
      return -1;
    }
    if(tag_end_max!=tag_begin_max){
      PDEBUG("tag_end_max!=tag_begin_max");
      return -1;
    }
    if(!tag_begin){
      PDEBUG("!tag_begin");
      return -2;
    }
    if(!tag_end){
      PDEBUG("!tag_end");
      return -2;
    }
    if(!url_list){
      PDEBUG("!url_list");
      return -2;
    }
    if(!id_url_tag){
      PDEBUG("!id_url_tag");
      return -2;
    }
    return 0;
}
