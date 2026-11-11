#include <stdio.h>
#include <stdbool.h>

#include "cli/io.h"
#include "cli/meta_commands.h"
#include "cli/statements.h"

int main(void) {
    InputBuffer* input_buffer = new_input_buffer();
    
    while(true) {
        print_prompt();
        read_input(input_buffer);

        if(input_buffer->buffer[0] == '.') {
            switch(do_meta_command(input_buffer)) {
                case(META_COMMAND_SUCCESS):
                    break;
                case(META_COMMAND_UNRECOGNIZED_COMMAND):
                    printf("Command unrecognised\n");
                    break;
            }
            continue;
        }

        Statement statement;
        switch(prepare_statement(input_buffer, &statement)){
            case(PREPARE_SUCCESS):
                break;
            case(PREPARE_UNRECOGNIZED_STATEMENT):
                printf("Unrecognised command\n");
                continue;
        }


        execute_statement(&statement);
        printf("Executed.\n");
    }
}
