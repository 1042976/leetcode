/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //T-O(nlogn), S-O(n)
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     vector<ListNode*> arr;
    //     for(int i = 0; i < lists.size(); ++i){
    //         ListNode* cur = lists[i];
    //         while(cur != nullptr){
    //             arr.emplace_back(cur);
    //             cur = cur->next;
    //         }
    //     }
    //     if(arr.empty()){
    //         return nullptr;
    //     }
    //     sort(arr.begin(), arr.end(), [](const ListNode* a, const ListNode* b)->bool{
    //        return a->val < b->val; 
    //     });
    //     for(int i = 0; i < (int)arr.size()-1; ++i){
    //         arr[i]->next = arr[i+1];
    //     }
    //     arr.back()->next = nullptr;
    //     return arr[0];
    // }
    
    //T-O(Nlogk) S-O(k)
    // ListNode* mergeKLists(vector<ListNode*>& lists){
    //     auto compare = [](const ListNode* a, const ListNode* b){
    //         return a->val > b->val;
    //     };
    //    priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> Q(compare);
    //     for(int i = 0; i < lists.size(); ++i){
    //         if(lists[i] != nullptr){
    //             Q.push(lists[i]);
    //         }
    //     }
    //     if(Q.empty()){
    //         return nullptr;
    //     }
    //     ListNode* head = Q.top();
    //     Q.pop();
    //     if(head->next != nullptr){
    //         Q.push(head->next);
    //     }
    //     ListNode* cur = head;
    //     while(!Q.empty()){
    //         cur->next = Q.top();
    //         Q.pop();
    //         cur = cur->next;
    //         if(cur->next != nullptr){
    //             Q.push(cur->next);
    //         }
    //     }
    //     return head;
    // }
    
    //T-O(Nlogk), S-O(1)
    ListNode* mergeKLists(vector<ListNode*>& lists){
        int interval = 1;
        while(lists.size() > 1 && interval < lists.size()){
            int i = 0;
            while(i+interval < lists.size()){
                mergeList(lists[i], lists[i+interval]);
                i += 2*interval;
            }
            interval *= 2;
        }
        if(lists.empty() || lists[0] == nullptr){
            return nullptr;
        }
        return lists[0];
    }
    
    void mergeList(ListNode* &head1, ListNode* &head2){
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        ListNode *cur1 = head1, *cur2 = head2;
        while(cur1 != nullptr && cur2 != nullptr){
            if(cur1->val <= cur2->val){
                cur->next = cur1;
                cur1 = cur1->next;
            }else{
                cur->next = cur2;
                cur2 = cur1;
                cur1 = cur->next->next;
               // cur2 = cur2->next;
            }
            cur = cur->next;
        }
        if(cur1 != nullptr){
            cur->next = cur1;
        }
        if(cur2 != nullptr){
            cur->next = cur2;
        }
        head1 = head->next;
        delete head;
    }
    
};
