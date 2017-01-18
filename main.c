#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#include "iopcdefine.h"
#include "iopcops_cfg_bdb.h"
#include "main.h"

unsigned long parse_paramegers(int argc, char** argv, char* cfg_file, char* cfg_key)
{
    unsigned long func = 0x0;
    int cmd_opt = 0;
    while(1) {
        cmd_opt = getopt(argc, argv, "f:k:alvts");

        if(cmd_opt == -1) {
            return func;
        }

        switch(cmd_opt) {
        case 'f': // cfg file
            strcpy(cfg_file, optarg);
        break;
        case 'a': // show all 
            func |= SHOW_ALL;
        break;
        }
    }

    return func;
}

static void show_usage()
{
    printf("-f: input cfg file\n");
    printf("-a: show all elements of file\n");
    printf("example : \n");
    printf("    utils -f /tmp/cfgs.db -a\n");
}

int main(int argc, char** argv)
{
    //uint8_t err_code = 0;
    uint8_t cfg_file[STR_LEN];
    unsigned long func = 0x0;
    int isError = 0;
    uint8_t cfg_key[STR_LEN];
//    uint8_t cfg_val[STR_LEN];

    if(argc < 2) {
        show_usage();
        return 1;
    }

    func = parse_paramegers(argc, argv, &cfg_file[0], &cfg_key[0]);

    switch(func) {
    case SHOW_ALL:
        GET_INSTANCE(ops_cfg_bdb)->show_all(cfg_file);
    break;
    }

    if(isError)
        printf("%s", ERROR_STRING);

    return 0;
}

