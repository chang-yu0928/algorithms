//Firstly store all characters into a int array(because it is char so I can just use
//them as index, so hash map is not needed.). This process cost O(n) time complexity 
//and O(1) space complexity. By the way, n means the number of characters
//Secondly, I create a heap to store all alphabets. And get result by pop.
//The insertion time complexity is O(n) and the get result process cost O(klogn)
//time complexity. The space complexity for this method is O(n). By the way,
//n means the number of alphabets.

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

//create a struct contains the alphabets. 
struct Element {
	char alphabet;
	int frequency;
	Element(char al, int fre): alphabet(al), frequency(fre) {}
};

//struct for my own comparison for priority queue.
struct Compare {
	bool operator() (Element a, Element b) {
		return a.frequency < b.frequency;
	}
};

//read file and store whatever in the file into a container for processing.
void readFile(string fileAdd, char *container) {
	fstream readInFile;
	
	readInFile.open(fileAdd);
	
	while(true)
	{
		char alpha;
		readInFile >> alpha;
		if(readInFile.eof()) break;
		container[alpha] += 1;
	}
}

//main method to find and print out all top K alphabets.
void printTopK(char *container, int k) {
	priority_queue<Element, vector<Element>, Compare> heap;
	for(int i = 0;i < 256;i ++) {
		//filter out all char except alphabets.
		if((i >= 65 && i <= 90) || (i >= 97 && i <= 122)) {
			Element temp(i, container[i]);
			heap.push(temp);
		}
	}
	//run k times to get top k.
	for(int i = 0;i < k;i ++) {
		Element temp = heap.top();
		heap.pop();
		cout<<temp.alphabet<<"-"<<temp.frequency<<endl;
	}
}

int main() {
	char container[256];

	//initialize the container.
	for(int i = 0;i < 256;i ++) {
		container[i] = 0;
	}
	readFile("test.txt", container);
		
	printTopK(container, 3);
	return 0;
}