#include <bits/stdc++.h>
using namespace std;

// Node structure for Huffman tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};

// Custom comparator for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Generate Huffman codes recursively
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;

    if (!root->left && !root->right)
        huffmanCode[root->ch] = code;

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Encode input string
string encode(const string& text, unordered_map<char, string>& huffmanCode) {
    string encoded = "";
    for (char ch : text)
        encoded += huffmanCode[ch];
    return encoded;
}

// Decode the encoded string
string decode(Node* root, const string& encoded) {
    string decoded = "";
    Node* curr = root;
    for (char bit : encoded) {
        curr = (bit == '0') ? curr->left : curr->right;
        if (!curr->left && !curr->right) {
            decoded += curr->ch;
            curr = root;
        }
    }
    return decoded;
}

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    // Step 1: Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text)
        freq[ch]++;

    // Step 2: Create a min-heap (priority queue)
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    // Step 3: Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    Node* root = pq.top();

    // Step 4: Generate Huffman Codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    cout << "\nHuffman Codes:\n";
    for (auto pair : huffmanCode)
        cout << pair.first << " : " << pair.second << "\n";

    // Step 5: Encode
    string encoded = encode(text, huffmanCode);
    cout << "\nEncoded string:\n" << encoded << "\n";

    // Step 6: Decode
    string decoded = decode(root, encoded);
    cout << "\nDecoded string:\n" << decoded << "\n";

    return 0;
}