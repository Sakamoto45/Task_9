#pragma once
#include <string>
#include <iostream>
// #include <sstream>
// #include <fstream>
#include <iomanip>

using namespace std;

class node {
public:
    char c;
    node* left; //tree
    node* right; //tree
    node* next; //stack

    node(char _c) {
        c = _c;
        left = NULL;
        right = NULL;
        next = NULL;

    }

    int solve() {

        int l, r;
        if (left != NULL) {
            l = left->solve();
            if (l == -1) return -1;
        }
        if (right != NULL) {
            r = right->solve();
            if (r == -1) return -1;
        }
        switch (c) {
        case '+': return l || r;
        case '*': return l && r;
        case '!': return !l;
        case '0': return 0;
        case '1': return 1;
        default: return -1;
        }
    }

    void print(int n) {
        if (left != NULL) left->print(n + 1);
        cout << setw(n * 2) << c << endl;
        if (right != NULL) right->print(n + 1);
    }


};

class stack {
public:

    node* head;

    stack() {
        head = NULL;

    }

    bool is_empty() {
        return head == NULL;
    }

    void push(char _c) {
        node* temp = new node(_c);
        if (head == NULL) {
            head = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
    }

    char pop() {
        if (head != NULL) {
            node* temp = head;
            head = head->next;
            return temp->c;
        }
        else {
            return '?';
        }
    }

    char top() {
        if (head != NULL) {
            return head->c;
        }
        else {
            return '?';
        }
    }

};

node* build(string pre, int* n) {
    node* temp = new node(pre[*n]);
    cout << pre[*n] << endl;
    if (pre[*n] == '+' || pre[*n] == '*') {
        *n = *n + 1;
        temp->left = build(pre, n);
        temp->right = build(pre, n);
    }
    else if (pre[*n] == '!') {
        *n = *n + 1;
        temp->left = build(pre, n);
    }
    else {
        *n = *n + 1;
    }
    return temp;
}
