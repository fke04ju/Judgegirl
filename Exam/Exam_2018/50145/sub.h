typedef struct Node
{
    char c;
    struct Node *next;
}Node;
void substring(Node* text, Node* pattern);
void subsequence(Node* text, Node* pattern);
