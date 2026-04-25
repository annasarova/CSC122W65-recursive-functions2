#include <iostream>
using namespace std;

// Function 1: Recursive string length
int recursiveLength(const char* str) {
    // Base case
    if (*str == '\0')
        return 0;

    // Recursive case
    return 1 + recursiveLength(str + 1);
}

// Function 2: Generate all strings of length k
template <size_t N>
void generateStrings(char (&collection)[N], int k, string current = "") {
    // Base case: if current string is length k
    if (current.length() == k) {
        cout << current << endl;
        return;
    }

    // Recursive case: try each character
    for (int i = 0; i < N; i++) {
        generateStrings(collection, k, current + collection[i]);
    }
}

int main() {
    // ---- Test recursive string length ----
    const char str[] = "hello";
    cout << "String: " << str << endl;
    cout << "Length (recursive): " << recursiveLength(str) << endl;

    cout << endl;

    // ---- Test generate strings ----
    // ---- First test ----
    char collection1[] = {'a', 'b'};
    int k1 = 3;
    cout << "All strings of length " << k1 << ":\n";
    generateStrings(collection1, k1);

    cout << endl;

    // ---- Second test ----
    char collection2[] = {'a', 'b', 'c', 'd'};
    int k2 = 1;
    cout << "All strings of length " << k2 << ":\n";
    generateStrings(collection2, k2);

    return 0;
}