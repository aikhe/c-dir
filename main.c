#include "include/curl/curl.h"

#include <ActiveDS.h>
#include <stdio.h>

// Callback to write data received from server
size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
  return fwrite(ptr, size, nmemb, stdout); // print to console
}

int main(void) {
  CURL *curl;
  CURLcode res;

  // Initialize curl
  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
  if (curl) {
    // Set URL
    curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");

    // Set callback to handle data
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    // Specify CA bundle for SSL verification (download cacert.pem from
    // https://curl.se/docs/caextract.html)
    curl_easy_setopt(curl, CURLOPT_CAINFO, "cacert-2025-09-09.pem");

    // Perform the request
    res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    }

    // Cleanup
    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();
  return 0;
}
