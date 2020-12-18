typedef struct token_blocks token_blocks_struct;
typedef struct token token_struct;

// A single linked list of token blocks.
struct token_blocks
{
  token_struct* first;
};

struct token
{
  char* token_char_seq;
  token_struct* next;
};

token_blocks_struct* read_file(const char* filepath);

static char *filter_and_allocate(const char *c);