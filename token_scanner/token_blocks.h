typedef struct token_blocks token_blocks_struct;

// A single linked list of token blocks.
struct token_blocks
{
  token_struct* first;
};

typedef struct token token_struct;
struct token
{
  char* token_char_seq;
  token_struct* next;
};

token_blocks_struct* read_file();