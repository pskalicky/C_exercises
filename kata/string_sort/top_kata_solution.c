//first

#include <string.h>
char* order_words (char* ordered, const char* const words) {
    const char* const orderedOrigin = ordered;
    char tmp[100];
    for (char i = '1'; i <= '9'; ++i) {
        const char* s = strchr(words, i);
        if (s == NULL) break;
        while (*(s - 1) != ' ' && s != words) --s;
        unsigned ti;
        for (ti = 0; *s && *s != ' '; ++ti, ++s) tmp[ti] = *s;
        tmp[ti] = 0;
        strcpy(ordered, tmp);
        while (*(++ordered));
        *(ordered++) = ' ';
    }
    *(ordered - (ordered != orderedOrigin)) = 0;
    return (char*)orderedOrigin;
}


//second

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int pos(char *w) { for (; isalpha(*w); w++) {;} return *w - '0'; }

char *order_words (char *ordered, const char *words)
{
    char *w[10] = {0}, *cpy = calloc(strlen(words) + 1, 1), n = 0;

    for (char *tok = strtok(strcpy(cpy, words), " "); tok; tok = strtok(NULL, " "), n++) w[pos(tok)] = tok;

    *ordered = 0;
    for (int i = 1; i < 10; i++) if (w[i]) strcat(ordered, w[i]), strcat(ordered, --n ? " " : "");

    return free(cpy), ordered;
}