#include "stack.h"
#include <unistd.h>
#include "../misc/misc.h"

//saved in the user's home directory
#define FILENAME "stack.dat"
#define BASHRC ".bashrc"

void spit_command(Stack *st);
void anchor(Stack *st,char *stackfile);
void display_anchors(Stack *st,char *stackfile);
void delete_anchor(Stack *st,char *stackfile);
void display_current(Stack *st);
void switch_anchor(Stack *st,int index,char *stackfile,Mem *mem);
void update_alias(Stack *st,char *stackfile, Mem *mem);








