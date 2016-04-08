/**
 *       Filename:  main.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  04/06/2016 19:41:24
 *       Compiler:  gcc
 *         Author:  Apacal (apacal.cn), apacalzqz@gmail.com
 *        Company:  tencent
 */
#include "../global.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* retListNode = new ListNode(0);
        ListNode* node = retListNode, *prevNode = retListNode;
        int carry = 0,  val;
        while (l1 != NULL || l2 != NULL) {
            val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = val / 10;
            node->val = val < 10 ? val : val % 10;
            node->next = new ListNode(0);
            prevNode = node;
            node = node->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }

        if (carry != 0) {
            node->val = carry;
        } else if (node->val == 0) {
            prevNode->next = NULL;
            delete node;
        }

        return retListNode;
    }
};




void free(ListNode * root) {
    ListNode* next = root;
    while( next != NULL) {
        next = next->next;
        delete root;
        root = next;
    }
}

void print(ListNode * root) {
    cout << "ListNode content[";
    while(root != NULL) {
        cout << root->val;
        if (root->next != NULL) {
            cout << ", ";
        }
        root = root->next;
    }
    cout << "]\n";
}



int main() {
    int numCount, solutionCount = 0, num;
    ListNode *l1, *l2, *tmp;
    Solution solution;
    while(cin >> numCount) {

        if (solutionCount % 2 == 0) {
            cin >> num;
            l1 = new ListNode(num);
            tmp = l1;
            for(int i = 1; i < numCount; i++) {
                cin >> num;
                tmp->next = new ListNode(num);
                tmp = tmp->next;
            }
        } else {
            cin >> num;
            l2 = new ListNode(num);
            tmp = l2;
            for(int i = 1; i < numCount; i++) {
                cin >> num;
                tmp->next = new ListNode(num);
                tmp = tmp->next;
            }

            print(l1);
            print(l2);


            ListNode* retNode = solution.addTwoNumbers(l1, l2);

            print(retNode);
            free(retNode);

            free(l1);
            free(l2);

        }
        solutionCount++;

    }
    return 0;
}
