#include <curl/curl.h>

#include "log_debug.h"

#ifndef DOWNLOAD_LAYOUT_H
#define DOWNLOAD_LAYOUT_H

class download_layout {
public:
  download_layout();
  virtual ~download_layout();
  bool get_http_doc(const char* url_adress,FILE* data);
private:
  CURL* curl;
  CURLcode res;
  static size_t write_data(char* ptr, size_t size, size_t nmemb, FILE* data);
  bool error;
};
#endif // DOWNLOAD_LAYOUT_H
