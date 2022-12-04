int mx_atoimod(const char *str, int len) {
    if (str == 0)
        return -1;
    int result = 0;
    for (int a = 0; a < len ; a++) {
        if ((str[a] >= 48) && (str[a] <= 57)) {
            result *= 10;
            if (result % 10 != 0) {
                return -1;
            }
            result += (int)str[a] - 48;
        }
        else {
            return -1;
        }
    }
    return result;
}



