#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITER " \t\r\n\a"
#define BUFFER_SIZE 1024
#define true 1
#define false 0

typedef char *string;
typedef int bool;
typedef void (*Builtin)(string *);

typedef struct BuiltinCmds
{
	string cmd;
	Builtin fn;
} BuiltinCmds;

extern char *environ;

void loop(int argc, string argv[]);
string _getline(void);
string *split(int *num_commands, string line, string delimeter);
int run(string *args);
int execute(string *args);

string location(char *command);

void (*builtins(string cmd))(string *);
void ss_exit(string *args);

#endif