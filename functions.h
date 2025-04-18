#include "stack.h"
#include <unistd.h>

//saved in the user's home directory
#define FILENAME ".stack.dat"
#define BASHRC ".bashrc"

void spit_command(Stack *st);
void anchor(Stack *st);
void display_anchors(Stack *st);
void delete_anchor(Stack *st);
void display_current(Stack *st);
void switch_anchor(Stack *st,int index);
void update_alias(Stack *st);








