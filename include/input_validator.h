#ifndef INPUT_VALIDATOR
#define INPUT_VALIDATOR

#include <regex.h>

void validate_flags(int quantity_of_arguments, char *arguments[]); 

void validate_argument_quantity(int quantity_of_arguments);

void validate_flag_argument(int quantity_of_arguments, char *arguments[]);

void validate_inspect_flag_argument(int quantity_of_arguments, char *arguments[]);

void generate_pid_validation_regex(regex_t *pid_regex);

#endif
