#define STATEMENTS_H

#include <stdint.h>
#include "io.h"

#define COLUM_USERNAME_SIZE 32
#define COLUM_EMAIL_SIZE 255

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT,
    PREPARE_SYNTAX_ERROR
} PrepareResult;

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

typedef struct {
    uint32_t id;
    char username[COLUM_USERNAME_SIZE];
    char email[COLUM_EMAIL_SIZE];
} Row;

typedef struct {
    StatementType type;
    Row row_to_insert;
} Statement;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
void execute_statement(Statement* statement);

