// liked list struct
typedef struct listNode {
    char * value;
    struct listNode * next;
} node;
//liked list functions
node * create(char * value);
int find(node * head, char * value);
node * insert(node * head, char * value);
void print(node * head);
void destroy(node * head);
node * delete(node * head, char * value);