#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "mylib.h"
#include "htable.h"

static const char *HELP_TEXT = 
    "Usage: asgn [options] dict_file\n"
    " options:\n"
    "  -r\t\tUse a robust chaining method.\n"
    "  -s table-size\tUse table-size as the size of the hash table.\n"
    "  -p\t\tPrint the hash table.\n"
    "  -i\t\tPrint information about how long things took and number of"
    " unknown words found.\n"
    "  -h\t\tPrint a help message.\n";

int main(int argc, char **argv) {
    char word[256];
    char option;
    const char *optstring = "r-s:pih";
    
    htable dict;        
    FILE *dict_file;
    int use_robust_chaining = 0;
    int size = 3877;
    int print_hash_table = 0;
    int print_info = 0;
    
    while ((option = getopt(argc, argv, optstring)) != EOF) {
        switch (option) {
            case 'r':
                use_robust_chaining = 1;
                break;
            case 's':
                size = *optarg;
                break;
            case 'p':
                print_hash_table = 1;
                break;
            case 'i':
                print_info = 1;
                break;
            case 'h':
                /* Drop through to default case for option h. */
            default:
                fprintf(stderr,"%s\n", HELP_TEXT);
                exit(EXIT_SUCCESS);
        }
    }

    /* Dicitionary file name will be at end of args list after getopt. */
    dict_file = fopen(argv[argc - 1], "r");

    /* Start reading first file, which will serve as the dictionary. */
    htable h = htable_new(size, use_robust_chaining);
    while (getword(word, sizeof word, dict_file) != EOF) {
        htable_insert(h, word);
    }

    htable_free(h);

    return EXIT_SUCCESS;
}