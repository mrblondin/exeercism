#include "binary_search_tree.h"
#include <assert.h>
#include <stdlib.h>

static node_t * create_node(int val){
  node_t * node = calloc(1, sizeof(node_t));
  node->data = val;
  node->left = node->right = NULL;
  return node;
}

static node_t * insert_in_tree(int val, node_t *tree){
  if (!tree) return create_node(val);

  if (val > tree->data)
    tree->right = insert_in_tree(val, tree->right);
  else
    tree->left = insert_in_tree(val, tree->left);

  return tree;
}

static void tree_sorted(node_t *node, int *arr, size_t *i){
  if (node){
    tree_sorted(node->left, arr, i);
    arr[*i] = node->data;
    *i += 1;
    tree_sorted(node->right, arr, i);
  }
}

static size_t len_tree(node_t *node){
  if (!node)
    return 0;

  return 1 + len_tree(node->left) + len_tree(node->right);
}

node_t *build_tree(int *tree_data, size_t tree_data_len){
  assert(tree_data && tree_data_len);

  node_t * tree = create_node(tree_data[0]);

  for (size_t index = 1; index < tree_data_len; index++)
    insert_in_tree(tree_data[index], tree);

  return tree;
}

void free_tree(node_t *tree){
  if (!tree) 
    return;

  free_tree(tree->left);
  free_tree(tree->right);

  free(tree);
}

int *sorted_data(node_t *tree){
  if (!tree) return ERROR;
  
  int *sorted = calloc(len_tree(tree), sizeof(int));
  size_t i = 0;
  tree_sorted(tree, sorted, &i);
  return sorted;
}

