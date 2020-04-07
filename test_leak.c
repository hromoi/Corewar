#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "regex.h"
# define PATTERN_CHECK "^==[0-9]{4,6}==[    ]*definitely lost: .*$"
# define PATTERN_OK_OR_KO "^==[0-9]{4,6}==[    ]*definitely lost: 0.*$"

int parse_check(char *line, char *pattern)
{
    int         err;
    regex_t     reg1;
    regmatch_t  pm;

    err = regcomp(&reg1, pattern, REG_EXTENDED);
    if (err != 0)
    {
        regfree(&reg1);
        printf("error with regex in file interpretation.c\n");
        return (0);
    }
    if (!regexec(&reg1, line, 0, &pm, 0))
    {
        regfree(&reg1);
        return (1);
    }
    regfree(&reg1);
    return (0);
}

int main(void){
    int fd;
    char *line;

    line = NULL;
    if ((fd = open("check_leak", O_RDONLY)) < 0){
        printf("файл не check_leak не обнаружен\n");
        return (0);
    }
    while (get_next_line(fd, &line) > 0){
        if (parse_check(line, PATTERN_CHECK)){
            if (parse_check(line, PATTERN_OK_OR_KO)){
                printf("[OK] - leak\n");
                return (1);
            }
            else {
                printf("[KO] - leak\n");
                // printf("%s\n", line);
                printf("%s \n", (ft_strchr(line, ':') + 2));
                return (0);
            }
        }
    }
    return (0);
}