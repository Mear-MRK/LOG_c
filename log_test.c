#include "log.h"

int main()
{
    float f = 123.45678911f;
    log_msg(LOG_INF, "inf 1");
    log_msg(LOG_WRN, "wrn 1: %8.2f", f);
    log_set_level(LOG_INF);
    log_msg(LOG_INF, "inf 2");
    log_msg(LOG_ERR, "err 1: ldfweuroiwcjalk laksdjlksjdf %10.7f lasdjflksldjfks %10.7f sssdfsafd %10.7f sfsaflsjdflskdjf %10.7f",
            f, f, f, f);
    return 0;
}