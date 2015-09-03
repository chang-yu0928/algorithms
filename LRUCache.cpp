#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int key, value;
    Node *prev, *next;
    Node(int k, int v): key(k), value(v), prev(NULL), next(NULL) {}
};
class LRUCache{
    Node *head, *tail;
    unordered_map<int, Node *> cache;
    int maxNum, num;
public:
    LRUCache(int capacity) {
    	head = NULL; tail = NULL;
        maxNum = capacity;
        num = 0;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
        	//cout<<key<<endl;
            Node *temp = cache[key];
            if(head == temp) {
                if(temp->next == NULL) {
                    return temp->value;
                } else {
                    Node *newHead = temp->next;
                    newHead->prev = NULL;
                    tail->next = temp;
                    temp->prev = tail;
                    tail = temp;
                    head = newHead;
                }
            } else {
                if(temp == tail) {
                    return temp->value;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp->next = NULL;
                    tail->next = temp;
                    temp->prev = tail;
                    tail = temp;
                }
            }
            return temp->value;
        }
        return -1;
    }
    
    void set(int key, int value) {
    	if(cache.find(key) != cache.end()) {
    		cache[key]->value = value;
    		get(key);
    		return;
    	}
        if(maxNum == num) {
        	//cout<<"OK"<<endl;
            Node *temp = head;
            head = head->next;
            if(head != NULL) {
            	head->prev = NULL;
            }
            cache.erase(temp->key);
            //cout<<endl<<key<<":"<<temp->key<<endl;
            delete temp;
        } else {
            num ++;
        }
        if(head == NULL) {
            head = new Node(key, value);
            cache[key] = head;
            tail = head;
        } else {
        	//cout<<"OK2"<<endl;
            Node *newNode = new Node(key, value);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            cache[key] = newNode;
        }
    }
};

int main() {
	LRUCache c(10);
	c.set(10,13);c.set(3,17);c.set(6,11);c.set(10,5);c.set(9,10);
	cout<<c.get(13)<<",";
	c.set(2,19);
	cout<<c.get(2)<<","<<c.get(3)<<",";
	c.set(5,25);
	cout<<c.get(8)<<",";
	c.set(9,22);c.set(5,5);c.set(1,30);
	cout<<c.get(11)<<",";
	c.set(9,12);
	cout<<c.get(7)<<","<<c.get(5)<<","<<c.get(8)<<","<<c.get(9)<<",";
	c.set(4,30);c.set(9,3);
	cout<<c.get(9)<<","<<c.get(10)<<","<<c.get(10)<<",";
	c.set(6,14);c.set(3,1);
	cout<<c.get(3)<<",";
	c.set(10,11);
	cout<<c.get(8)<<",";
	c.set(2,14);
	cout<<c.get(1)<<","<<c.get(5)<<","<<c.get(4)<<",";
	c.set(11,4);c.set(12,24);c.set(5,18);
	cout<<c.get(13)<<",";
	c.set(7,23);
	cout<<c.get(8)<<","<<c.get(12)<<",";
	c.set(3,27);c.set(2,12);
	cout<<c.get(5)<<",";
	c.set(2,9);c.set(13,4);c.set(8,18);c.set(1,7);
	cout<<c.get(6)<<",";
	c.set(9,29);c.set(8,21);
	cout<<c.get(5)<<",";
	c.set(6,30);c.set(1,12);
	cout<<c.get(10)<<",";
	c.set(4,15);c.set(7,22);c.set(11,26);c.set(8,17);c.set(9,29);
	cout<<c.get(5)<<",";
	c.set(3,4);c.set(11,30);
	cout<<c.get(12)<<",";
	c.set(4,29);
	cout<<c.get(3)<<","<<c.get(9)<<","<<c.get(6)<<",";
	c.set(3,4);
	cout<<c.get(1)<<","<<c.get(10)<<",";
	c.set(3,29);c.set(10,28);c.set(1,20);c.set(11,13);
	cout<<c.get(3)<<",";
	c.set(3,12);c.set(3,8);c.set(10,9);c.set(3,26);
	cout<<c.get(8)<<","<<c.get(7)<<","<<c.get(5)<<",";
	c.set(13,17);c.set(2,27);c.set(11,15);
	cout<<c.get(12)<<",";
	c.set(9,19);c.set(2,15);c.set(3,16);
	cout<<c.get(1)<<",";
	c.set(12,17);c.set(9,1);c.set(6,19);
	cout<<c.get(4)<<","<<c.get(5)<<","<<c.get(5)<<",";
	c.set(8,1);c.set(11,7);c.set(5,2);c.set(9,28);
	cout<<c.get(1)<<endl;
	c.set(2,2);c.set(7,4);c.set(4,22);c.set(7,24);c.set(9,26);c.set(13,28);c.set(11,26);
	/*LRUCache c(2);
	cout<<c.get(2)<<",";
	c.set(2,6);
	cout<<c.get(1)<<",";
	c.set(1,5);c.set(1,2);
	cout<<c.get(1)<<","<<c.get(2)<<endl;*/
	/*LRUCache c(1);
	c.set(2,1);
	cout<<c.get(2)<<",";
	c.set(3,2);
	cout<<c.get(2)<<","<<c.get(3)<<endl;
	*/
	/*LRUCache c(3);
	c.set(1,1);
	c.set(2,2);
	c.set(3,3);
	c.set(4,4);
	cout<<c.get(4)<<","<<c.get(3)<<","<<c.get(2)<<","<<c.get(1);
	c.set(5,5);
	cout<<c.get(1)<<","<<c.get(2)<<","<<c.get(3)<<","<<c.get(4)<<","<<c.get(5)<<endl;*/
	return 0;
}