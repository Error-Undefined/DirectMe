#include<stdio.h>
#include<stdlib.h>

#include "token_blocks.h"

token_blocks_struct* read_file(const char* filepath)
{
  //Allocate the token struct
  token_blocks_struct* token_list = malloc(sizeof(token_struct));
  if(token_list == NULL)
    return 0x1;

  token_list->first = NULL;

  // Read the file
  int max_char_line = 200;

  FILE* sourcefile = fopen(filepath, "r");
  char* read_buffer = calloc(max_char_line, sizeof(char));

  fgets(read_buffer, max_char_line, sourcefile);

}