//Your task is to sort a given string. Each word in the string will contain a single number.
//This number is the position the word should have in the result.

//Note: Numbers can be from 1 to 9. So 1 will be the first word (not 0).

//If the input string is empty, return an empty string.
//The words in the input String will only contain valid consecutive numbers.

//Examples:
//"is2 Thi1s T4est 3a", "Thi1s is2 3a T4est"
//"4of Fo1r pe6ople g3ood th5e the2", "Fo1r the2 g3ood 4of th5e pe6ople"
//"d4o dru7nken sh2all w5ith s8ailor wha1t 3we a6", "wha1t sh2all 3we d4o w5ith a6 dru7nken s8ailor"
//"", ""
//"3 6 4 2 8 7 5 1 9", "1 2 3 4 5 6 7 8 9")

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Pro strdup a free


char *order_words (char *ordered, const char *words)
{
    if (words == NULL || *words == '\0') {
        *ordered = '\0';
        return ordered;
    }

    char *word_array[9];
    for (int i = 0; i < 9; i++) {
        word_array[i] = NULL;
    }

    char *mutable_words = strdup(words);
    char *token = strtok(mutable_words, " ");
    while (token != NULL) {
        int position = -1;
        for (int i = 0; token[i] != '\0'; i++) {
            if (token[i] >= '1' && token[i] <= '9') {
                position = token[i] - '1';
                break;
            }
        }
        if (position != -1) {
            word_array[position] = token;
        }
        token = strtok(NULL, " ");
    }

    *ordered = '\0';
    int first_word_added = 0;
    for (int i = 0; i < 9; i++) {
        if (word_array[i] != NULL) {
            if (first_word_added) {
                strcat(ordered, " ");
            }
            strcat(ordered, word_array[i]);
            first_word_added = 1;
        }
    }

    free(mutable_words);
    return ordered;
}

int main() {
    // Definujeme pole pro uložení seřazeného řetězce.
    // Velikost by měla být dostatečná (max. délka vstupního řetězce + 1 pro '\0').
    // Použijeme dostatečně velkou, abychom pokryli příklady.
    char ordered_string[256]; // Maximální délka pro výsledný řetězec

    // --- Příklad 1 ---
    const char *test1_input = "is2 Thi1s T4est 3a";
    printf("Vstup: \"%s\"\n", test1_input);
    order_words(ordered_string, test1_input);
    printf("Výstup: \"%s\"\n", ordered_string);
    printf("Očekáváno: \"Thi1s is2 3a T4est\"\n");
    printf("---\n");

    // --- Příklad 2 ---
    const char *test2_input = "4of Fo1r pe6ople g3ood th5e the2";
    printf("Vstup: \"%s\"\n", test2_input);
    order_words(ordered_string, test2_input);
    printf("Výstup: \"%s\"\n", ordered_string);
    printf("Očekáváno: \"Fo1r the2 g3ood 4of th5e pe6ople\"\n");
    printf("---\n");

    // --- Příklad 3 (prázdný vstup) ---
    const char *test3_input = "";
    printf("Vstup: \"%s\"\n", test3_input);
    order_words(ordered_string, test3_input);
    printf("Výstup: \"%s\"\n", ordered_string);
    printf("Očekáváno: \"\"\n");
    printf("---\n");

    // --- Další testovací případ (pouze jedno slovo) ---
    const char *test4_input = "Wo1rd";
    printf("Vstup: \"%s\"\n", test4_input);
    order_words(ordered_string, test4_input);
    printf("Výstup: \"%s\"\n", ordered_string);
    printf("Očekáváno: \"Wo1rd\"\n");
    printf("---\n");

    return 0; // Vše proběhlo v pořádku
}
