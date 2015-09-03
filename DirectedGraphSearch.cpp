#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct GraphNode {
	int num;
	vector<GraphNode *> next;
	GraphNode(int n): num(n) {}
};

class Graph {
	vector<GraphNode *> start;
	
	//use dfs to search the direction node.
	//if this node has been checked, return false.
	bool dfsSearch(GraphNode *subGraph, unordered_set<GraphNode *> &checked, int end){
		if(checked.find(subGraph) != checked.end()){
			return false;
		}
		if(subGraph->num == end){
			return true;
		}
		checked.insert(subGraph);
		for(int i = 0;i < subGraph->next.size();i ++){
			if(dfsSearch(subGraph->next[i], checked, end)){
				return true;
			}
		}
		return false;
	}
	
	GraphNode *findNodeByID(int num){
		for(int i = 0;i < start.size();i ++){
			if(start[i]->num == num){
				return start[i];
			}
		}
		return NULL;
	}
public:
	Graph(){
		start.push_back(new GraphNode(1));
	}
	
	void addNode(int num, vector<int> directions){
		GraphNode *input = new GraphNode(num);
		GraphNode *temp;
		for(int i = 0;i < directions.size();i ++){
			if((temp = findNodeByID(directions[i])) != NULL){
				input->next.push_back(temp);
			}
		}
		start.push_back(input);
	}
	
	bool GraphSearch(int from, int end){
		unordered_set<GraphNode *> checked;
		return dfsSearch(findNodeByID(from), checked, end);
	}
};

int main(){
	Graph a;
	vector<int> temp;
	temp.push_back(0);
	a.addNode(2, temp);
	cout<<a.GraphSearch(2,1)<<endl;
	return 0;
}