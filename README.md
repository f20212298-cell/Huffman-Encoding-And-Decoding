Huffman Coding and Decoding (C++)
📖 Overview

This project implements Huffman Coding, a lossless data compression algorithm that assigns shorter binary codes to more frequent characters and longer codes to less frequent ones.
It includes both encoding and decoding functionalities for any given input string.

⚙️ Features

Builds Huffman Tree based on character frequency

Generates optimal binary Huffman codes

Encodes and decodes user-input strings

Displays Huffman code mappings for each character

Works with any ASCII input

🧠 How Huffman Coding Works

Frequency Calculation – Count the occurrences of each character in the input.

Tree Construction – Build a binary tree where low-frequency nodes are deeper.

Code Assignment – Assign 0 for left edges and 1 for right edges recursively.

Encoding – Replace each character in the input with its corresponding Huffman code.

Decoding – Traverse the Huffman tree using the encoded bits to reconstruct the original string.
