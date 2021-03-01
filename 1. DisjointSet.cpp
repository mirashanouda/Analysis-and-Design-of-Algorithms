#include <iostream>
#include <unordered_map>
using namespace std;

class DisjointSet {
public:

    unordered_map<int, int> parent;
    unordered_map<int, int> rank; //a counter for the number of elements
    int cycle;

    DisjointSet() {
        cycle = 0;
    }
    ~DisjointSet(){}


    //perform makeset operation
    void MakeSet(const vector<int>& universe) { //const: to not make any changes in the value; &: to avoid making copies of the values like the passing by value
        
        //initializing all the elements 
        for (int i : universe) {
            parent[i] = i; //can be: = -1
            rank[i] = 1;   //intializing all the elements with 1 rank

            //we can make the rank by putting the parent as -(the number of elements) 
        }
    }

    int Find(int k) {
        //if k is a root
        if (parent[k] == k)
            return k; //----------------------------------------------
        //recure for the parent untill we find the root
        return Find(parent[k]); 
    }

    void Union(int a, int b) {

        //---------the improvement----------------
        int a_parent = Find(a);
        int b_parent = Find(b);

        if (a_parent == b_parent) {
            cycle++;
            return; //the same parent
        }
            

        if (rank[a] > rank[b]) {
            parent[Find(b)] = Find(a);
            rank[a] = rank[a] + rank[b];
        }
        else {//if a < b or a == b
            parent[Find(a)] = Find(b);
            rank[a] = rank[a] + rank[b];
        }
    }

    void printSet(DisjointSet ds) {

        for (int i = 0; i < ds.parent.size(); i++)
            cout << ds.parent[i] << " ";
        cout << endl;
    }
};

struct Edge {
    int src, dest;
};

class Graph {
public:
    //adjacency list of the sources and destination
    vector<vector<int>> adjList;

    //Graph constructor 
    Graph(const DisjointSet& disSet) {

        //resize the adjlist with n
        adjList.resize(disSet.parent.size());

        //construct the gragh
        for (int i = 0; i < disSet.parent.size(); i++) {
            //insert at the end
            adjList[i].push_back(disSet.parent.at(i));
        }
    }

    bool detectCycle(DisjointSet ds) {
        if (ds.cycle > 0)
            return true;
        else
            return false;
    }

    ~Graph() {
    }
};



int main() {

    cout << "---------Example 1------------" << endl;

    //universe of elements 
    vector<int> universe = { 1,2,3,4};



    DisjointSet ds1;

    ds1.MakeSet(universe);
    
    ds1.Union(0, 1);
    ds1.Union(0, 2);
    ds1.Union(1, 3);
    ds1.Union(1, 4);
    ds1.Union(3, 4);

    ds1.printSet(ds1);
    Graph a(ds1);
    if (a.detectCycle(ds1))
        cout << "It has a cycle" << endl;
    else
        cout << "It doesn't have a cycle" << endl;

    cout << endl<< endl << "---------Example 2------------" << endl;
    DisjointSet ds2;

    ds2.MakeSet(universe);
    ds2.Union(0, 1);
    ds2.Union(0, 2);
    ds2.Union(1, 3);
    ds2.Union(1, 4);  
    ds2.printSet(ds2);
    
    Graph b(ds2);
    if (b.detectCycle(ds2))
        cout << "It has a cycle" << endl << endl;
    else
        cout << "It doesn't have a cycle" << endl << endl;

    system("pause");
    return 0;
}