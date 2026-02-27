#include <stdlib.h>
#include <regex.h>
#include "input_validator.h"
#include "message_presenter.h"

void validate_flags(int quantity_of_arguments, char *arguments[]) {
  validate_argument_quantity(quantity_of_arguments);
 
  validate_flag_argument(quantity_of_arguments, arguments);
}


void validate_argument_quantity(int quantity_of_arguments) {
  const int required_quantity_of_arguments = 2;

  if (quantity_of_arguments < required_quantity_of_arguments) {
    present_commands_message();
    
    exit(EXIT_FAILURE);
  }
}


void validate_flag_argument(int quantity_of_arguments, char *arguments[]) {
  const int flag_argument_position = 1;
  
  const char inspect_flag_argument[] = "--i";

  const bool inspect_flag_was_sent = arguments[flag_argument_position] == inspect_flag_argument;

  if (inspect_flag_was_sent) {
     validate_inspect_flag_argument(quantity_of_arguments, arguments); 
  }
  
  const char available_flags[][3] = {"--h", "--l", "--w"};
}


void validate_inspect_flag_argument(int quantity_of_arguments, char *arguments[]) {
  const int quantity_of_arguments_for_inspect = 3;
    
  const bool pid_argument_is_missing = quantity_of_arguments < quantity_of_arguments_for_inspect;

  if (pid_argument_is_missing) {
    present_commands_message();

    exit(EXIT_FAILURE);
  }
  
  regex_t pid_regex_pattern;

  generate_pid_validation_regex(&pid_regex_pattern);
  
  const int pid_argument_position = 2;

  const char *pid_argument = arguments[pid_argument_position];

  const int number_of_subexpressions_to_match = 0;
  regmatch_t *matched_subexpressions_offset_list = NULL;
  const int regex_line_matching_default_behavior = 0;

  const int regex_matching_result = regexec(
      &pid_regex_pattern, 
      pid_argument, 
      number_of_subexpressions_to_match, 
      matched_subexpressions_offset_list, 
      regex_line_matching_default_behavior
  );

  regfree(&pid_regex_pattern);

  const bool pid_not_matches_with_pattern = regex_matching_result != 0;
    
  if (pid_not_matches_with_pattern) {
    present_invalid_pid_message();

    exit(EXIT_FAILURE);
  }
}


void generate_pid_validation_regex(regex_t *pid_regex) {
  const char pid_regex_pattern[] = "[0-9]+";
  
  const int regex_interpretation_type = REG_EXTENDED;

  regcomp(pid_regex, pid_regex_pattern, regex_interpretation_type);
}
