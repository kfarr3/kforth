#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kforth.h"
#include "dictionary_1.h"

_kforth_context test_context;

int test_stack[1000];
int test_loop_stack[100];
char statement[200];

void main(void)
{
    int ret;

    printf("kforth %s\r\n", KFORTH_VERSION);
    printf("type 'bye' to exit\r\n");

    kforth_init_context(&test_context, test_stack, test_loop_stack, dictionary_1 );

    for(;;)
    {
        fgets(statement, 200, stdin);
        if ((statement[strlen(statement)-1]==0x0D)||(statement[strlen(statement)-1]==0x0A)) statement[strlen(statement)-1]='\0';
        if ((statement[strlen(statement)-1]==0x0D)||(statement[strlen(statement)-1]==0x0A)) statement[strlen(statement)-1]='\0';
        ret=kforth_execute_statement(&test_context, statement);
        if (ret!=0)
        {
            printf("Exiting with %d\r\n", ret);
            break;
        }
        else
        {
            printf("ok\r\n");
        }
    }

    printf("\r\nStack checks out %s\r\n", test_context.stack_ptr==test_context.stack?"GOOD":"BAD");
    
}

/***   End Of File   ***/

