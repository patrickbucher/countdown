// time_str_to_seconds converts a time string, such as "1h15m59s" to an
// amount of seconds, e.g. 4559 for "1h15m59s".
int time_str_to_seconds(const char *);

// seconds_to_time_str converts the given number of seconds to a formatted time
// string, e.g. 3720 is converted to "1h2m3s".
char *seconds_to_time_str(int);
