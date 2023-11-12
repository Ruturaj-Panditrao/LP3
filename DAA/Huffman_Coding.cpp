#include <iostream>
#include <queue>
using namespace std;

// Custom Class Node for our Node Object
class minHeapNode
{   
    public :
    char data;
    int freq;
    minHeapNode*left;
    minHeapNode*right;

    // Parameterized Constructor to initialize the object with Given Data & Frequency
    minHeapNode(char c, int f)
    {
        data = c;
        freq = f;
        left = NULL;
        right = NULL;
    }

};

// Custom Comparator Function
class compare
{
    public:
    bool operator()(minHeapNode*a, minHeapNode*b)
    {
        return (a->freq > b->freq);
    }
};

// PrintCodes function to print Huffman Codes from the Huffman Tree
void printcodes(minHeapNode* root, string s)
{
    if(root==NULL) return;
    if(root->data!='$') 
    {
        // Print the Huffman Code for the Character
        cout<<root->data<<" : "<<s<<endl;
    }
    printcodes(root->left,s+"0"); // add 0 while left
    printcodes(root->right,s+"1"); // add 1 while right
}

void HuffmanCode(char data[],int freq[], int n)
{
    minHeapNode* left;
    minHeapNode* right;

    // Make Custom Nodes for Our Min Heap
    // And add all the Nodes to the MinHeap
    // Here we use a Prioirity Queue to implement a MinHeap

    priority_queue<minHeapNode*,vector<minHeapNode*>,compare>pq;
    // First Paramter minHeapNode* indicates the type of data inside the Prioirity Queue
    // Second Parameter vector<minHeapNode*> indicates the underlying data structure to be used in the Prioirity Queue
    // Third Parameter is the Custom Comparator Function

    for(int i=0; i<n; i++)
    {
        pq.push(new minHeapNode(data[i],freq[i]));
    }

    while(pq.size()!=1) // When size is 1, the remaining Node is the root of Huffman Tree
    {   
        // Extract Two Nodes with Lowest Frequency
        // Combine their frequencies to add a new Node 
        // The frequency of the new Node is the sum of their Frequencies
        // The Lesser frequency node becomes ->left of the New Node
        // The Higher frequency node becomes ->right of the New Node
        // In this way, we construct the Huffman Tree

        left = pq.top(); 
        pq.pop();
        right = pq.top();
        pq.pop();

        minHeapNode*temp = new minHeapNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        pq.push(temp);
    }

    printcodes(pq.top(),"");
}

int main()
{
    char data[] = {'a','b','c','d','e','f'};
    int freq[] = {5,9,12,13,16,45};
    // Input the Unique Characters and their corresponding frequencies

    cout<<"The Generated Huffman Codes are : "<<endl;
    HuffmanCode(data,freq,6);
}

//Complexity Analysis :
//Time complexity: O(nlogn) where n is the number of unique characters.
//If there are n nodes, extractMin() is called 2*(n – 1) times. 
//extractMin() takes O(logn) time as it calls minHeapify(). So, overall time complexity is O(nlogn).
//Space Complexity is O(n) 
//Where n is the number of Unique Characters
