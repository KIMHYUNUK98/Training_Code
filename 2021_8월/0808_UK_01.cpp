#include <iostream>

using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
};
Node *node;

void preorder(Node *R) {
    cout << R->data;
    if(R->left)
        preorder(R->left);
    if(R->right)
        preorder(R->right);
}

void inorder(Node *R){
    if(R->left)
        inorder(R->left);
    cout << R->data;
    if(R->right)
        inorder(R->right);
}

void postorder(Node *R) {
    if(R->left)
        postorder(R->left);
    if(R->right)
        postorder(R->right);
        cout << R->data;
}

int main() {
    int num;
    int root_index;
    char root, lnode, rnode;
    cin >> num;

    // 동적할당
    node = (Node*)malloc(sizeof(Node)* num);

    for(int i = 0 ; i < num ; i++) {
        cin >> root >> lnode >> rnode;
        root_index = root - 'A';

        node[root_index].data = root;

        // left node 추가하기
        if(lnode == '.') {
            node[root_index].left = NULL;
        }
        else {
            // 값만 할당해주는 게 아니라 해당 문자의 주소를 할당해준다.
            node[root_index].left = &node[lnode - 'A'];
        }

        // right node 추가하기
        if(rnode == '.') {
            node[root_index].right = NULL;
        }
        else {
            node[root_index].right = &node[rnode - 'A'];
        }
    }

    // 출력
    preorder(&node[0]);
    cout << "\n";
    inorder(&node[0]);
    cout << "\n";
    postorder(&node[0]);

    free(node);
}