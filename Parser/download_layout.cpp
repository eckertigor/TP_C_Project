#include "download_layout.h"
download_layout::download_layout(){
  curl=curl_easy_init();
  error=(curl==NULL);
  if(!error)
    PDEBUG("[conect]");
  else
    PDEBUG("[error] not curl");
}

download_layout::~download_layout(){
  if(!error)
    curl_easy_cleanup(curl);
}

bool download_layout::get_http_doc(const char* url_adress,FILE* data){
  PDEBUG(url_adress);
  if(!error){
    curl_easy_setopt(curl,CURLOPT_URL,url_adress);
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
    curl_easy_setopt(curl,CURLOPT_WRITEDATA,data);
    res=curl_easy_perform(curl);
    if (res==CURLE_OK){
      PDEBUG("Succesfuly");
      return true;
    }
  }
  PDEBUG("[error]");
  return false;
}

size_t download_layout::write_data(char* ptr, size_t size, size_t nmemb, FILE* data){
  return fwrite(ptr,size,nmemb,data);
}

