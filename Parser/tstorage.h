#include <mysql/my_global.h>
#include <mysql/mysql.h>
#include <mysql/errmsg.h>
#include <mysql/mysqld_error.h>
#include "log_debug.h"
#include "Column.h"

#ifndef TSTORAGE_H
#define TSTORAGE_H

class TStorage {
public:
  TStorage();
  virtual ~TStorage();
  void set(const char *name_,
           const char *user_,
           const char *host_,
           const char *password_,
           const char *socket_,
           const uint port_);
  void set_name(const char *name_);
  void set_user(const char *user_);
  void set_host(const char *host_);
  void set_password(const char *password_);
  void set_socket(const char *socket_);
  void set_port(const uint port_);
  bool conect();
  bool set_query(const char * query);
  char* get_name();
  bool restar_row();
  bool next_row();
  MYSQL_FIELD *field(const uint);
  char* get_sell(const uint);
  int rows();
  int fields();
private:
  MYSQL *conn;
  MYSQL_RES *resdb;
  MYSQL_ROW row;
  char *host;
  char *name;
  char *user;
  char *password;
  char *socket;
  uint port;
  bool error;
  bool connect;
  int num_fields; //количество полей
  int num_rows;   //количество строк
};


class Update_command{
public:
  Tname db_name;
  Tname table_name;
  Tname cell_write_name; //куда записываем
  Tname cell_anchor_name; //по какому столбцу ищем строку пивязки
  Tname cell_write_id;
  Tname cell_anchor_id;
  char* get();
};
#endif // TSTORAGE_H
