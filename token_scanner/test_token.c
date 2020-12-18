#include <stdlib.h>
#include<stdio.h>

#include"token_blocks.h"

int main(int argc, char** argv)
{ 
  token_blocks_struct* token_list = read_file("test_tokens.dm");  
  token_struct* token = token_list->first;
  while (token->next != NULL)
  {
    token = token->next;
    printf("%s\n",token->token_char_seq);
  }
  

}