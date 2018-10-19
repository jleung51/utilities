// This C program provides a function to output formatted logs.

#ifndef LOGGER_H
#define LOGGER_H

enum log_level {
  DEBUG,
  INFO,
  SUCCESS,
  ERROR
};

// This function activates the logger until deactivated.
// All log calls will be successful.
void logger_activate();

// This function deactivates the logger until reactivated.
// All log calls will do nothing.
void logger_deactivate();

// This function outputs a formatted log message if logging is activated.
// Parameters:
//   l - Severity of the log message.
//   str - Message to be logged.
void logger_log(enum log_level l, char* str);

#endif