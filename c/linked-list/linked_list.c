#include "linked_list.h"
#include <stdlib.h>

#define ERROR 0

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

struct list *list_create(void){
  struct list *main_list = malloc(sizeof(struct list));
  main_list->first = NULL;
  main_list->last = NULL;
  return main_list;
}

size_t list_count(const struct list *list){
  if (!list) return ERROR;

  size_t length = 0;

  struct list_node *node = list->first;

  while(node){
    node = node->next;
    length++;
  }

  return length;
}

void list_push(struct list *list, ll_data_t item_data){
  if (!list)
    return;

  struct list_node *node = malloc(sizeof(struct list_node));
  node->next = NULL;
  node->prev = list->last;
  node->data = item_data;

  list->last = node;

  // check if the list was empty
  if (!list->first)
    list->first = node;

  // if previous node != NULL, point it to this new node
  if (node->prev)
    node->prev->next = node;
}

ll_data_t list_pop(struct list *list){
  if (!list)
    return ERROR;

  struct list_node *node = list->last;
  ll_data_t data = node->data;
  list->last = node->prev;

  // check if it is the only node
  if (!list->last){
    list->first = NULL;
  } else{
    node->prev->next = NULL;
  }

  free(node);

  return data;
}

void list_unshift(struct list *list, ll_data_t item_data){
  if (!list)
    return;

  struct list_node *node = malloc(sizeof(struct list_node));
  node->prev = NULL;
  node->next = list->first;
  node->data = item_data;

  list->first = node;

  // check if the list was empty
  if (!list->last)
    list->last = node;

  // if next node != NULL, point it to this new node
  if (node->next)
    node->next->prev = node;
}

ll_data_t list_shift(struct list *list){
  if (!list)
    return ERROR;

  struct list_node *node = list->first;
  ll_data_t data = node->data;
  list->first = node->next;

  // check if it is the only node
  if (!list->first){
    list->last = NULL;
  } else{
    node->next->prev = NULL;
  }

  free(node);

  return data;
}

void list_delete(struct list *list, ll_data_t data){
  if (!list) return;

  struct list_node *node = list->first;

  while(node){
    if (node->data == data){
      if (node == list->first)
        list->first = node->next;
      else 
        node->prev->next = node->next;
      if (node == list->last) 
        list->last = node->prev;
      else
        node->next->prev = node->prev;
      free(node);
      return;
    }

    node = node->next;
  }
}

void list_destroy(struct list *list){
  struct list_node * node = list->first;
  struct list_node * next;
  while (node){
    next = node->next;
    free(node);
    node = next;
  }

  free(list);
}
