#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MyNode {
    struct MyNode *children[26];
    int value; 
    char text[7]; 
    char more_value_text[7]; 
} MyNode;


typedef struct {
    char text[7]; 
    int value;
} MyWord;


MyNode *makeNode() {
    MyNode *node = (MyNode *)malloc(sizeof(MyNode));
    node->value = -1;
    node->more_value_text[0] = '\0';
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insertMyTrie(MyNode *root, char *text, int value) {
    MyNode *node = root;
    char *start = text; 

    while (*text) {
        if (!node->children[*text - 'A']) {
            node->children[*text - 'A'] = makeNode();
        }
        node = node->children[*text - 'A'];

        if (node->value== -1 || value> node->value|| (value== node->value&& strcmp(start, node->more_value_text) < 0)) {
            strcpy(node->more_value_text, start);
            node->value= value;
        }
        text++;
    }
}

MyNode *searchMyTrie(MyNode *root, char *prefix) {
    MyNode *node = root;
    while (*prefix && node) {
        node = node->children[*prefix - 'A'];
        prefix++;
    }
    return node;
}

int calculateMinTyping(MyNode *root, char **novel, int m) {
    int typing_count = 0;

    for (int i = 0; i < m; i++) {
        char *word = novel[i];
        int len = strlen(word);
        int j = 0;
        int found = 0;
        MyNode *node = root;

        while (j < len && node) {
            
            node = node->children[word[j] - 'A'];
            if (node && strcmp(node->more_value_text, word) == 0) {
                if (j +1 < len) { 
                    typing_count += (j + 1) + 1; 
                    found=1;
                }
                else {
                    typing_count += len; 
                    found = 1;
                }
                
                
                break;
            }
            
            j++;
        }
        if (!found) {
            typing_count += len; 
        }

        if(i<m-1) {
            typing_count++;
        } 

    }

    return typing_count;
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    MyNode *root = makeNode();
    MyWord *dictionary = (MyWord *)malloc(n * sizeof(MyWord));
    for (int i = 0; i < n; i++) {
        scanf("%s %d", dictionary[i].text, &dictionary[i].value);
        insertMyTrie(root, dictionary[i].text, dictionary[i].value);
    }

    char **novel = (char **)malloc(m * sizeof(char *));
    for (int i = 0; i < m; i++) {
        novel[i] = (char *)malloc(7 * sizeof(char));
        scanf("%s",novel[i]);
    }

    int min = calculateMinTyping(root, novel, m);
    printf("%d\n", min);

    for (int i = 0; i < m; i++) {
        free(novel[i]);
    }
    free(novel);
    free(dictionary);

    return 0;
}
