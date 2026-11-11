#ifndef META_COMMANDS_H
#define META_COMMANDS_H

#include "io.h"

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

MetaCommandResult do_meta_command(InputBuffer* input_buffer);

#endif
