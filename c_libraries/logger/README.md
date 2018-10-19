# Logger

C file which provides a function to output formatted logs.

## Setup

add the library to the destination directory and compile `logger.c` alongside 

## Usage

Run `logger_log(foo, "text")` where `foo` is the log level.

The following log levels are currently supported:
* DEBUG
* INFO
* SUCCESS
* ERROR

### Configuration

To disable all logging output, use the command `logger_deactivate()`, and re-enable logging output with the command `logger_activate()`.

Output is formatted like so:
```
[Thu Oct 18 18:44:30 2018 | DEBUG   ] Message sent.
```
