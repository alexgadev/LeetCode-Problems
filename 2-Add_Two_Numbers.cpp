#include <iostream>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int div = 0; 
        ListNode* result = new ListNode();
        ListNode* temp = result;
        while(l1 || l2){
            int i1 = 0; int i2 = 0;
            if(l1){
                i1 = l1->val;
                l1 = l1->next;
            }

            if(l2){
                i2 = l2->val;
                l2 = l2->next;
            }

            int current = div + i1 + i2;
            std::cout << div << ", " << i1 << ", " << i2 << std::endl;
            temp->val = current % 10;
            temp->next = new ListNode();
            
            div = current / 10;
            if(l1 == nullptr && l2 == nullptr){
                if(div != 0){
                    temp->next->val = div;
                    temp->next->next = nullptr;
                }
                else{
                    temp->next = nullptr;
                }
            }
            temp = temp->next;
        }
        return result;
    }
};

int main(){
    Solution sol = Solution();

    ListNode* l1 = new ListNode(9);
    ListNode* l2 = new ListNode(1, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))))))))));

    ListNode* result = sol.addTwoNumbers(l1, l2);

    std::cout << "[";
    while(result != nullptr){
        if(result->next == nullptr){
            std::cout << result->val;
        }
        else{
            std::cout << result->val << ",";
        }
        result = result->next;
    }
    std::cout << "]" << std::endl;
}