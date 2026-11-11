#include <stdlib.h>
#include <string.h>

#include "meta_commands.h"

MetaCommandResult do_meta_command(InputBuffer* input_buffer) {
    if(strcmp(input_buffer->buffer, ".exit") == 0) {
        close_input_buffer(input_buffer);
        exit(EXIT_SUCCESS);
    } else {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}
