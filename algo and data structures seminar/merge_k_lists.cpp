#include<bits/stdc++.h>
#define in f
#define out cout
using namespace std;

ifstream f("date.in");

typedef struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset< pair<int, int> >  s;
        ListNode* beginning = NULL;
        ListNode* node = NULL;

        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                s.insert(make_pair(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        }

        while(!s.empty()) {
            int index = s.begin()->second;

            if(node == NULL) {
                node = new ListNode(s.begin()->first);
            } else {
                node->next = new ListNode(s.begin()->first);
                node = node->next;
            }

            if(beginning == NULL)
                beginning = node;

            s.erase(s.begin());

            while(lists[index] != NULL) {
                s.insert(make_pair(lists[index]->val, index));
                lists[index] = lists[index]->next;
            }
        }

        return beginning;
}

void printList(ListNode* node) {
    while(node != NULL) {
        out << node->val << " ";
        node = node->next;
    }

    out << "\n";
}

int main() {

    int k, n, x;
    vector<ListNode*> v;
    in >> k;

    for(int i = 1; i <= k; i++) {
        in >> n;

        ListNode* node = NULL;
        ListNode* beginning = NULL;
        for(int j = 1; j <= n; j++) {
            in >> x;
            if(node == NULL)
                node = new ListNode(x);
            else {
                node->next = new ListNode(x);
                node = node->next;
            }

            if(beginning == NULL)
                beginning = node;

        }

        v.push_back(beginning);
    }


    for(int i = 0; i < v.size(); i++) {
        printList(v[i]);
    }

    ListNode* ans = mergeKLists(v);
    printList(ans);

    return 0;
}
