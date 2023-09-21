#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define DELIMITER " \t\r\n\a"
#define BUFFER_SIZE 1024
#define true 1
#define false 0

typedef char *string;
typedef int bool;
typedef void (*Builtin)(string *);

typedef struct Node
{
	string data;
	struct Node *next;
} Node;

typedef struct List
{
	Node *head;
	int count;
} List;

typedef struct BuiltinCmds
{
	string cmd;
	Builtin fn;
} BuiltinCmds;

extern char **environ;
extern List history;

void print(int fd, string str);

void prompt(void);

Node *createNode(string data);
List *createList(void);
void shift(List *list, string data);
void printl(List *list);

void loop(int argc, string argv[]);
void nonterminal(string line, string argv[]);
string _getline(void);
string *split(string line, string delimeter);
void handle(string *args, string argv[]);
int run(string *args, string argv[]);
int execute(string *args, string argv[]);

string location(char *command);

void (*builtins(string cmd))(string *);
void ss_exit(string *args);
void ss_env(string *args);
void ss_clear(string *args);
void ss_setenv(string *args);

string one(string name, string arg);

int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
string _strstr(const char *haystack, const char *needle);
int _strncmp(const char *str1, const char *str2, size_t n);
string _strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
string _strncat(char *dest, const char *src, size_t n);
char *_strchr(const char *str, char character);
string _strtok(char *str, const char *delim);
char *_strdup(const char *str);

#endif