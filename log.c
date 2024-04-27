#include "log.h"

#include <stdarg.h>
#include <string.h>

static FILE *log_fstream = NULL;
static log_type log_level = LOG_WRN;

const char *LOG_TYP_STR[] = {"DBG", "INF", "WRN", "ERR", "NON"};

void log_set_stream(FILE *stream)
{
    log_fstream = stream;
}

void log_set_level(log_type type)
{
    log_level = type;
}

void log_msg(log_type type, const char *format_str, ...)
{
    if (type < log_level)
        return;

    if (!log_fstream)
    {
        if (type >= LOG_WRN)
            log_fstream = stderr;
        else
            log_fstream = stdout;
    }

    char frmt[LOG_MAX_LEN + 2] = {0};
    char out_str[LOG_MAX_LEN + 2] = {0};
    strcat(frmt, LOG_TYP_STR[type]);
    strcat(frmt, ": ");
    strncat(frmt, format_str, (LOG_MAX_LEN - 5));
    va_list args;
    va_start(args, format_str);
    vsnprintf(out_str, LOG_MAX_LEN + 1, frmt, args);
    // printf("LOG_MAX_LEN: %d, following log line length: %zu\n", LOG_MAX_LEN, strlen(out_str));
    strcat(out_str, "\n");
    fputs(out_str, log_fstream);
    va_end(args);
}
