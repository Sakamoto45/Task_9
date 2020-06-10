#include "tree_stack.hpp"




int main() {
    string inf;
    getline (cin,inf);
    cout << inf << endl;
    string pre = ""; 
    stack* opn = new stack();
    
    
    for (int i = inf.length() - 1; i >= 0; i--) {

        if (inf[i] == '+' || inf[i] == '*' || inf[i] == ')') {

            while (!opn->is_empty() && ((int)inf[i] > (int)opn->top()) && opn->top() != ')') {
                
				pre = opn->pop() + pre;
			}	
			opn->push(inf[i]);

        } else if (inf[i] == '(') {


			while (opn->top() != ')') {

				pre = opn->pop() + pre;
			}
            
			opn->pop();
            
		} else if (inf[i] == ' '){

        } else {
            
            pre = inf[i] + pre;
        }
    }

    while (!opn->is_empty()) {
        pre = opn->pop() + pre;
	}
    cout << pre << endl;

    int n = 0;
    node* Tree = build(pre, &n);
    cout << "(" << Tree->left->c << ")" << endl;

    Tree->print(0);

    cout << endl << Tree->solve() << endl;

    return 0;
}