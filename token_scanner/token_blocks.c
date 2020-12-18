#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token_blocks.h"

token_blocks_struct *read_file(const char *filepath)
{
  //Allocate the token struct
  token_blocks_struct *token_list = malloc(sizeof(token_struct));
  if (token_list == NULL)
    return NULL;

  // Read the file
  int max_char_line = 200;

  FILE *sourcefile = fopen(filepath, "r");
  char read_buffer[max_char_line];

  token_struct *first_block = malloc(sizeof(token_struct));
  token_struct *current_block = first_block;
  void *end_of_file = NULL;
  token_list->first = first_block;

  for (;;)
  {
    end_of_file = fgets(read_buffer, max_char_line, sourcefile);
    if (end_of_file == NULL)
      break; // Reached EOF

    char* line = filter_and_allocate(read_buffer);
    //printf("%s\n", line);
    token_struct *next_block = malloc(sizeof(token_struct));
    current_block->next = next_block;
    next_block->token_char_seq = line;
    current_block = next_block;
  }

  return token_list;
}

// Takes the bytes in c and allocates a char* of its length, filering extra bytes.
// Important! This heap-allocates memory and surrenders memory ownership.
// Make sure to handle this!
static char *filter_and_allocate(const char *c)
{
  int len = 0;
  while (c[len] != 0)
  {
    len++;
  }
  //printf("%d\n", len);

  int bytesToRemove = 0;
  if(c[len - 1] == '\n')
    bytesToRemove++;
  if(c[len - 2] == '\r')
    bytesToRemove++;

  char *new_alloc = calloc(len, sizeof(char));
  memcpy(new_alloc, c, len - bytesToRemove * sizeof(char)); // Remove the last bytes if they're there
  return new_alloc;
}