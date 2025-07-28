//Úloha 1: Evidence studentů
// Vytvořte strukturu Student, která bude obsahovat následující údaje:
// jméno studenta, věk studenta a průměrnou známku studenta
//

#include <stdlib.h>
#include <string.h>

int is_name_valid(const char* name) {
    return (name != NULL && strlen(name) > 0 && strlen(name) < 50 && name[0] != '\0');
}

int is_age_valid(const char* s, int* age) {
    if (s == NULL || strlen(s) == 0) return 0;
    *age = atoi(s); // convert to int
    return (*age >= 0 && *age <= 120);
}

int is_gpa_valid(const char* s, float* avg) {
    if (s == NULL || strlen(s) == 0) return 0;
    *avg = atof(s); // convert to float
    return (*avg >= 1.0f && *avg <= 5.0f);
}

void main(void) {



}