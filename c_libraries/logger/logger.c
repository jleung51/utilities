// This C program provides a function to output formatted logs.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "logger.h"

// Change this to False to disable all output logging for this program.
_Bool PRINT_LOGS = true;

void logger_activate() {
  PRINT_LOGS = true;
}

void logger_deactivate() {
  PRINT_LOGS = false;
}

void logger_log(enum log_level l, char* str) {
  if (!PRINT_LOGS) {
    return;
  }

  char log_level_char[20];
  switch (l) {
    case DEBUG:
      strcpy(log_level_char, "DEBUG  ");
      break;
    case INFO:
      strcpy(log_level_char, "INFO   ");
      break;
    case SUCCESS:
      strcpy(log_level_char, "SUCCESS");
      break;
    case ERROR:
      strcpy(log_level_char, "ERROR  ");
      break;
  }

  time_t raw_time;
  time(&raw_time);
  char* time = asctime(localtime(&raw_time));
  for (int i = 0; i < strlen(time); ++i) {
    if (time[i] == '\n') {
      time[i] = '\0';
      break;
    }
  }

  printf("[ %s | %s ] %s\n", time, log_level_char, str);
}