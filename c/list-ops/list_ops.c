#include "list_ops.h"
#include <string.h>

#define ERROR 0

static list_t *new_empty_list(size_t length){
  list_t *nList = malloc(sizeof(list_t) + length*sizeof(list_element_t));
  if (!nList) return ERROR;
  nList->length = length;
  return nList;
}

list_t *new_list(size_t length, list_element_t elements[]){
  list_t *nList = malloc(sizeof(list_t) + length*sizeof(list_element_t));
  if (!nList) return ERROR; 

  nList->length = length;

  memcpy(nList->elements, elements, length * sizeof(list_element_t));

  return nList;
}

list_t *append_list(list_t *list1, list_t *list2){
  if (!list1 || !list2) return ERROR;
  
  int length = list1->length + list2->length;
  list_t *nList = malloc(sizeof(list_t) + length*sizeof(list_element_t));

  nList->length = length;

  memcpy(nList->elements, list1->elements, 
         list1->length * sizeof(list_element_t));
  memcpy(nList->elements + list1->length, list2->elements, 
         list2->length * sizeof(list_element_t));

  return nList;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)){
  if (!list || !filter) return ERROR;

  list_t *nList = new_empty_list(list->length);

  size_t j = 0;
  for (size_t i = 0; i < list->length; i++){
    if (filter(list->elements[i]))
     nList->elements[j++] = list->elements[i];
  }

  nList = realloc(nList, sizeof(list_t) + j*(sizeof(list_element_t)));
  nList->length = j;
  
  return nList;
}

size_t length_list(list_t *list){
  if (!list) return ERROR;
  
  return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)){
  if (!list || !map) return ERROR;

  list_t *nList = new_empty_list(list->length);

  for (size_t i = 0; i < list->length; i++){
    nList->elements[i] = map(list->elements[i]);
  }
  
  return nList;
}

list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)){
  if (!list || !foldl) return ERROR;
  list_element_t res = initial;

  for (size_t i = 0; i < list->length; i++){
    res = foldl(list->elements[i], res);
  }

  return res;

}

list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)){
  if (!list || !foldr) return ERROR;

  list_element_t res = initial;

  for (size_t i = list->length; i > 0; i--){
    res = foldr(list->elements[i-1], res);
  }

  return res;
}

list_t *reverse_list(list_t *list){
  list_t *nList = new_empty_list(list->length);

  size_t j = 0;

  for (size_t i = list->length; i > 0; i--){
    nList->elements[j++] = list->elements[i - 1];
  }
  
  return nList;
}

void delete_list(list_t *list){
  if (!list) return;

  free(list);
}
