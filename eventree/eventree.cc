#include <vector>
#include <iostream>
using namespace std;

int countEvenSubtrees(vector<vector<int>> &tree, int currentNode, vector<bool> &isVisited, int &evenSubtrees){
	isVisited[currentNode] = true;
	int numDescendants = 0;
	for (int i = 0 ; i < tree[currentNode].size(); i++) {
		int nextNode = tree[currentNode][i];
		if (!isVisited[nextNode]) {
			int temp = countEvenSubtrees(tree, nextNode, isVisited, evenSubtrees);
			numDescendants += temp;
		}
	}
	if (numDescendants  % 2 != 0){ //if odd # of children, increment # of even subtrees
		evenSubtrees++;
	}
	return numDescendants+1; //number of descendants plus current node
}
int main(){

    //uncomment different trees for testing

	// Expected Output: 1
	/*
	vector<vector<int>> tree{
		{1,2}, //0
		{3},   //1
		{},    //2
		{}};   //3
	*/
	// Expected Output: 6
	
	vector<vector<int>> tree{
		{1, 2},   //0
		{3,4,5},      //1
		{6,7},   //2
		{8,9}, //3
		{10},      //4
		{11},      //5
		{},      //6
		{12},     //7
		{13},     //8
		{},     //9
		{},     //10
		{},     //11
		{},     //12
		{}};    //13
	
	// Expected output: 2
	/*
	vector<vector<int>> tree{
		{1, 2},   //0
		{},      //1
		{3,4},   //2
		{5,6,7}, //3
		{},      //4
		{},      //5
		{},      //6
		{}};    //7
	*/
	vector<bool> isVisited(tree.size(), false);
	int evenSubtrees = 0;
	int numDescendants = countEvenSubtrees(tree, 0, isVisited, evenSubtrees);
	if (numDescendants % 2 ==0){
		evenSubtrees--;
	}
	cout << "Edges to be removed: " << evenSubtrees << endl;
	return 0;
}
