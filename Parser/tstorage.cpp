#include "tstorage.h"
#include "Column.h"

TStorage::TStorage(){
  conn=NULL;
  resdb=NULL;
  name=NULL;
  user=NULL;
  host=NULL;
  password=NULL;
  socket=NULL;
  port=0;
  connect=false;
  conn=mysql_init(NULL);
  error=!(conn);
  num_fields = 0;
  num_rows = 0;
  row=NULL;
  if(error)
    PDEBUG("Error: can't create MySQL-descriptor\n");
  else{
    if(mysql_query(conn, "SET NAMES 'utf8'") != 0)
      PDEBUG("Error: can't set character set\n");
  }
}

TStorage::~TStorage() {
  if (!error)
    if(resdb)
      mysql_free_result(resdb);
    mysql_close(conn);
  if(name)
    delete [] name;
  if(user)
    delete [] user;
  if(host)
    delete [] host;
  if(password)
    delete [] password;
  if(socket)
    delete [] socket;
}

void TStorage::set(const char *name_,
                   const char *user_,
                   const char *host_,
                   const char *password_,
                   const char *socket_,
                   const uint port_){
  set_name(name_);
  set_user(user_);
  set_host(host_);
  set_password(password_);
  set_socket(socket_);
  port=port_;
}

void TStorage::set_name(const char *name_){
  if (name_&&name!=name_){
    if(name)
      delete [] name;
    name=new char[strlen(name_)+1]();
    strcpy(name,name_);
    PDEBUG("name base= %s",name);
  }
}

void TStorage::set_user(const char *user_){
  if (user_&&user!=user_){
    if(user)
      delete [] user;
    user=new char[strlen(user_)+1]();
    strcpy(user,user_);
    PDEBUG("user = %s",user);
  }
}

void TStorage::set_host(const char *host_){
  if (host_&&host!=host_){
    if(host)
      delete [] host;
    host=new char[strlen(host_)+1]();
    strcpy(host,host_);
    PDEBUG("host = %s",host);
  }
}

void TStorage::set_password(const char *password_){
  if (password_&&password!=password_){
    if(password)
      delete [] password;
    password=new char[strlen(password_)+1]();
    strcpy(password,password_);
    PDEBUG("password = %s", password);
  }
}

void TStorage::set_socket(const char *socket_){
  if (socket_&&socket!=socket_){
    if(socket)
      delete [] socket;
    socket=new char[strlen(socket_)+1]();
    strcpy(socket,socket_);
    PDEBUG("socket= %s",socket);
  }
}

void TStorage::set_port(const uint port_){
  port=port_;
  PDEBUG("port = %d",port);
}

bool TStorage::conect(){ 
  if(!error){
    error=!(mysql_real_connect(conn,
                               host,
                               user,
                               password,
                               name,
                               port,
                               socket,
                               0)
            );
  }
  if(error){
    PDEBUG("Error: %s\n", mysql_error(conn));
  }else{      
    PDEBUG("[connect MySQL]");
    connect=true;
  }
  return !error;
}

bool TStorage::set_query(const char * query){
  if(!error&&connect){
    error=!(query);
    mysql_query(conn, query);  
  }
  if(error){
    PDEBUG("Error: %s\n", mysql_error(conn));
    return false;
  }
  return restar_row();
}

MYSQL_FIELD* TStorage::field(const uint i){
  if(error||!connect||i>=num_fields)
      return NULL;
  return mysql_fetch_field_direct(resdb, i);
}

bool TStorage::next_row(){
  if(row){
      for (int i=0;i<num_fields;i++)
          delete [] row[i];
      delete [] row;
  }
  if(!error&&connect){
    row = mysql_fetch_row(resdb);
    return true;
  }
  if(!row){
      return false;
  }
  return false;
}

bool TStorage::restar_row(){
  num_fields = 0;
  num_rows = 0;
  if(resdb)
    mysql_free_result(resdb);
  if(!error&&connect){
    resdb = mysql_store_result(conn);
    error=!(resdb);
  }
  if(error){
    PDEBUG("Error: %s\n", mysql_error(conn));
    return false;
  }
  num_fields = mysql_num_fields(resdb);
  num_rows = mysql_num_rows(resdb);
  return true;
}

char* TStorage::get_sell(const uint i){
  char* Result=NULL;
  if(row&&i<num_fields){
    Result=new char[strlen(row[i])+1];
    strcpy(Result,row[i]);
  }else{
    PDEBUG("[error]");
  }
  return Result;
} 

int TStorage::fields(){
  return num_fields;
}

int TStorage::rows(){
    return num_rows;
}

char* TStorage::get_name(){
  return name;
}

char* Update_command::get(){
  //UPDATE `appDB`.`place` SET `place_weather`='20' WHERE `place_id`='6';
  if(!db_name.get_name()||
     !table_name.get_name()||
     !cell_write_name.get_name()||
     !cell_anchor_name.get_name()||
     !cell_write_id.get_name()||
     !cell_anchor_id.get_name())
    return NULL;
  char* Result;
  sprintf(Result,
          "%s '%s'.'%s' %s '%s'='%s' %s '%s'='%s'",
          "UPDATE", //команда MYSQL
          db_name.get_name(),
          table_name.get_name(),
          "SET", //команда MYSQL
          cell_write_name.get_name(),
          cell_write_id.get_name(),
          "WHERE", //команда MYSQL
          cell_anchor_name.get_name(),
          cell_anchor_id.get_name()
          );
  return Result;
}
