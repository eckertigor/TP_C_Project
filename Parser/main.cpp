/*
 * Qt Creator 3.5.1 (opensource)
 *
 * In file conf progect:
 * LIBS += -lcurl -Lpath-to-the-mysql-library -lmysqlclient -lz
 */

#include <cstdio>
#include <cstdlib>
#include <string>
#include <time.h>

#include "log_debug.h"
#include "download_layout.h"
#include "pars_seach.h"
#include "tstorage.h"

char* start_session();//вызывается один раз для записи в лог файл время старта программы

//appDB.sql поля для парсера
typedef enum {
  url_place_id,
  url_parser,
  url_tag_id
}weather_url_now;
typedef enum {
  tag_id,
  tag_begin,
  tag_end
}tag_pars;
//appDB.sql основная таблица с погодой
typedef enum {
  place_id,
  place_name,
  place_weather,
  place_activity
}place;


int main()
{
  PDEBUG(start_session());
    pars_seach buffer;
  if (!buffer.open("w")) return 0;
  download_layout pars_obj;
  pars_obj.get_http_doc("https://pogoda.yandex.ru/ramenskoe/details",buffer.get_file());
  buffer.open("r");
  //на этапе отладки необходимо переделать
  char tem[2][128];
  memset(tem[0],0,128);
  memset(tem[1],0,128);
  //
  if (buffer.check("r")==0){
    strcpy(tem[0],buffer.weed_by_tag("after\">","</div>"));
  }
  if (buffer.check("r")==0){
    strcpy(tem[1],buffer.weed_by_tag("after\">","</div>"));
  }
  /*
  TStorage bd;
  bd.set("appDB","root","localhost","DontSmoke030291",NULL,3306);
  bd.conect();
  bd.set_query("SELECT * FROM weather_url_now");
  */
  PDEBUG("Succesfuly!");
  getchar();
  return 0;
}

char* start_session(){
  time_t t = time(NULL);
  tm* aTm = localtime(&t);
  return asctime(aTm);
}
