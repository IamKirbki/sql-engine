#include <stdio.h>
#include <string.h>

#include "statements.h"

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement) {
    if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    } else if (strcmp(input_buffer->buffer, "select") == 0) {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    return PREPARE_UNRECOGNIZED_STATEMENT;    
}

void execute_statement(Statement* statement) {
    switch(statement->type) {
        case(STATEMENT_SELECT):
            printf("This is where the SELECT statement function wil go\n");
            break;
        case(STATEMENT_INSERT):
            printf("This is where the INSERT statement function wil go\n");
            break;
    }
}