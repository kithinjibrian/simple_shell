#include "main.h"

Node *createNode(string data)
{
	Node *nnode = (Node *)malloc(sizeof(Node));
	if (nnode == NULL)
	{
		perror("Error memory allocation");
	}

	nnode->data = data;
	nnode->next = NULL;
	return nnode;
}

List *createList(void)
{
	List *list = (List *)malloc(sizeof(List));
	list->head = NULL;
	list->count = 0;
	return list;
}

void shift(List *list, string data)
{
	Node *nnode = createNode(data);
	if (list->head == NULL)
	{
		list->head = nnode;
	}
	else
	{
		Node *current = list->head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = nnode;
	}
	list->count++;
}

void printl(List *list)
{
	Node *current = list->head;
	printf("Linked List (%d elements): ", list->count);
	while (current != NULL)
	{
		printf("%s -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}