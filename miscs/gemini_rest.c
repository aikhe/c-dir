#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/curl/curl.h"

/* Dynamic memory struct for response (keeps full response if you need it) */
struct Memory {
  char *response;
  size_t size;
};

/* Write callback: prints received data immediately and also appends to Memory
 */
size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
  size_t total = size * nmemb;
  struct Memory *mem = (struct Memory *)userdata;

  /* 1) Print chunk immediately so user sees streaming output */
  fwrite(ptr, size, nmemb, stdout);
  fflush(stdout);

  /* 2) Append to dynamic buffer so we still have the full response later */
  char *temp = realloc(mem->response, mem->size + total + 1);
  if (!temp) {
    fprintf(stderr, "\nFailed to realloc memory\n");
    return 0; /* returning 0 tells libcurl to abort */
  }
  mem->response = temp;
  memcpy(mem->response + mem->size, ptr, total);
  mem->size += total;
  mem->response[mem->size] = '\0';

  return total;
}

int main(void) {
  CURL *curl;
  CURLcode res;

  const char *api_key = getenv("GEMINI_API_KEY");
  if (!api_key) {
    fprintf(stderr, "GEMINI_API_KEY environment variable not set.\n");
    return 1;
  }

  struct Memory mem = {malloc(1), 0};
  if (!mem.response) {
    fprintf(stderr, "Failed to allocate memory\n");
    return 1;
  }

  const char *json_data =
      "{"
      "  \"contents\": ["
      "    {"
      "      \"parts\": ["
      "        {\"text\": \"Explain how annoying namias yaps one short "
      "sentence in genz. please roast him really bad\"}"
      "      ]"
      "    }"
      "  ]"
      "}";

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
  if (curl) {
    struct curl_slist *headers = NULL;
    char auth_header[512];

    snprintf(auth_header, sizeof(auth_header), "x-goog-api-key: %s", api_key);

    headers = curl_slist_append(headers, auth_header);
    headers = curl_slist_append(headers, "Content-Type: application/json");

    /* Optional: reduce internal buffering to get data to you faster */
    curl_easy_setopt(curl, CURLOPT_BUFFERSIZE, 10240L); /* 10KB buffer */

    /* Useful timeouts to avoid hanging indefinitely */
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L); /* connection timeout */
    /* Do NOT set an overall CURLOPT_TIMEOUT if you expect the stream to be open
       for long. If you want an overall limit, set CURLOPT_TIMEOUT to a large
       value. */

    /* TCP_NODELAY can reduce latency for small data */
    curl_easy_setopt(curl, CURLOPT_TCP_NODELAY, 1L);

    curl_easy_setopt(curl, CURLOPT_URL,
                     "https://generativelanguage.googleapis.com/v1beta/models/"
                     "gemini-2.5-flash:generateContent");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    /* Use POSTFIELDS for a simple request body; for large bodies consider read
     * callback */
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(json_data));

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&mem);

    /* --- INSECURE: disable SSL certificate verification (for testing only) ---
     */
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

    /* Perform request */
    printf("=== Streaming response start ===\n");
    fflush(stdout);

    res = curl_easy_perform(curl);

    /* Print trailing newline in case stream didn't end with one */
    printf("\n=== Streaming response end ===\n");

    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    } else {
      /* Optionally inspect the full response stored in mem.response */
      /* printf("\nFull response:\n%s\n", mem.response); */
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
  } else {
    fprintf(stderr, "Failed to init curl\n");
  }

  free(mem.response);
  curl_global_cleanup();
  return 0;
}
