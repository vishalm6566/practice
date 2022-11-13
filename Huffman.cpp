#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
    char data;
    int freq;

    MinHeapNode *left, *right;

    MinHeapNode(char d, int f)
    {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

//Compare is a function which helps user to decide the priority according to which element should be arranged in the queue
struct cmp
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};
void printCodes(struct MinHeapNode *root, string str)
{
    if(!root)
        return;

    if(root->data != '$')
        cout<<root->data<<" : "<<str<<endl;

    printCodes(root->left, str+"0");
    printCodes(root->right, str+"1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, cmp> minheap;

    for(int i=0; i<size; i++)
    {
        minheap.push(new MinHeapNode(data[i], freq[i]));
    }

    while(minheap.size() != 1)
    {
        left = minheap.top();
        minheap.pop();

        right = minheap.top();
        minheap.pop();

        struct MinHeapNode *temp = new MinHeapNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;

        minheap.push(temp);
    }
    printCodes(minheap.top(), " ");
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] = {10, 5, 2, 14, 15};

    int size = 5;
    HuffmanCodes(arr, freq, size);

    return 0;
}