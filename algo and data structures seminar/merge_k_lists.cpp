#include<bits/stdc++.h>
using namespace std;


typedef struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> s;
        ListNode* aux = NULL;
        ListNode* sol = NULL;



        while(lists.size() > 0) {
            for(int i = 0; i < lists.size(); i++) {
                if(lists[i] != NULL) {
                    s.insert(lists[i]->val);
                    lists[i] = lists[i]->next;
                }

                if(lists[i] == NULL) {
                    lists.erase(lists.begin() + i);
                    i--;
                }
            }

            for(int i = 0; i < s.size(); i++) {
                aux = new ListNode(*s.begin());
                if(sol == NULL)
                    sol = aux;
                aux = aux->next;
                s.erase(s.begin());
            }

        }

        return sol;
    }

int main() {
    vector<ListNode*> v;
    v.push_back(new ListNode(1));
    ListNode* node = mergeKLists(v);

    cout << node->val;
}
