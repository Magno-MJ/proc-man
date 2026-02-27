#include <stdio.h>
#include "message_presenter.h"

void present_commands_message() {
  printf("Example of usage: proc-man --[flag]\n");
  printf("Available flags:\n");
  printf("--h [help]: Shows the available commands with it's descriptions\n");
  printf("--l [list]: List all running processes\n");
  printf("--i PID [inspect]: Shows a detailed description about some running process with the requested PID\n");
  printf("--w [watch]: Watch all processes running with it's respective details\n");
}

void present_invalid_pid_message() {
  printf("Invalid PID. Please send a correct PID to inspect the respective process\n");
};
