# Simple Logging System for C
## Overview
This project provides a simple logging library written in C. It allows logging messages of various types (debug, info, warning, error) to a specified stream (file or standard output). The library also supports setting different log levels to control the verbosity of the log output.

## Customizing the Logging
- **Setting the Log Stream**:
  By default, logs are written to `stderr` for warnings and errors, and `stdout` for debug and info messages. You can change the log stream by calling `log_set_stream(FILE *stream)` with a valid `FILE*`.

- **Setting the Log Level**:
  The log level controls the minimum severity of messages that will be logged. By default, it is set to `LOG_WRN`. You can change it using `log_set_level(log_type type)`.

## License
This project is licensed under the MIT License.
