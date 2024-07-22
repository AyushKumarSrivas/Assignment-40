deque

1. Inserts an element. And returns an iterator that points to the first of the newly inserted
elements.
2. Returns a reverse iterator which points to the last element of the deque (i.e., its
reverse beginning).
3. Returns a reverse iterator which points to the position before the beginning of the
deque (which is considered its reverse end).
4. Returns a constant iterator pointing to the first element of the container, that is, the
iterator cannot be used to modify, only traverse the deque.
5. Returns the maximum number of elements that a deque container can hold.
6. Assign values to the same or different deque container.
7. Return the first element and last element of the deque container.
8. Remove elements from a container from the specified position or range in deque.
9. Generate a permutation of first N natural numbers having count of unique adjacent
differences equal to K | Set 2 using a queue.
10. Check if given Strings can be made equal by inserting at most 1 String using deque.
11. How to get the first and last elements of Deque in c++?
12. Given a string S containing letters and ‘#‘. The ‘#” represents a backspace. The task
is to print the new string without ‘#‘. String after processing backspace characters
using deque
Examples:
Input : S = "abc#de#f#ghi#jklmn#op#"
Output : abdghjklmo
Input : S = "##iNeuron##Education##hub#"
Output : iNeurEducatihu
13. Segregate even and odd nodes in a Linked List using Deque.

Solution:-

1. #include <iostream>
#include <deque>

int main() {
    std::deque<int> dq = {1, 2, 3};
    auto it = dq.insert(dq.begin() + 1, 4);

    std::cout << "Deque elements after insertion: ";
    for (const auto& elem : dq) {
        std::cout << elem << " ";
    }
    std::cout << "\nIterator points to: " << *it << std::endl;

    return 0;
}

2. #include <iostream>
#include <deque>

int main() {
    std::deque<int> dq = {1, 2, 3};
    auto rit = dq.rbegin();

    std::cout << "Reverse beginning (last element) of deque: " << *rit << std::endl;

    return 0;
}

3. #include <iostream>
#include <deque>

int main() {
    std::deque<int> dq = {1, 2, 3};
    auto rit = dq.rend();

    std::cout << "Reverse end points to the position before the beginning of the deque." << std::endl;

    return 0;
}

4. #include <iostream>
#include <deque>

int main() {
    std::deque<int> dq = {1, 2, 3};
    std::deque<int>::const_iterator cit = dq.cbegin();

    std::cout << "Constant iterator points to the first element: " << *cit << std::endl;

    return 0;
}

5. #include <iostream>
#include <deque>

int main() {
    std::deque<int> dq;
    std::cout << "Maximum number of elements the deque can hold: " << dq.max_size() << std::endl;

    return 0;
}

6. #include <iostream>
#include <deque>

int main() {
    std::deque<int> dq1 = {1, 2, 3};
    std::deque<int> dq2;
    dq2.assign(dq1.begin(), dq1.end());

    std::cout << "Deque 2 elements: ";
    for (const auto& elem : dq2) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

7. #include <iostream>
#include <deque>

int main() {
    std::deque<int> dq = {1, 2, 3, 4, 5};

    std::cout << "First element: " << dq.front() << std::endl;
    std::cout << "Last element: " << dq.back() << std::endl;

    return 0;
}

8. #include <iostream>
#include <deque>

int main() {
    std::deque<int> dq = {1, 2, 3, 4, 5};

    // Remove element at position 2
    dq.erase(dq.begin() + 2);

    // Remove elements from position 1 to 3
    dq.erase(dq.begin() + 1, dq.begin() + 3);

    std::cout << "Deque elements after removal: ";
    for (const auto& elem : dq) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

9. #include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

std::deque<int> generatePermutation(int N, int K) {
    std::deque<int> dq;
    std::vector<int> numbers(N);
    std::iota(numbers.begin(), numbers.end(), 1);
    do {
        std::deque<int> temp(numbers.begin(), numbers.end());
        int unique_adj_diff = 0;
        for (int i = 1; i < N; ++i) {
            if (std::abs(temp[i] - temp[i-1]) != std::abs(temp[i-1] - temp[i-2])) {
                ++unique_adj_diff;
            }
        }
        if (unique_adj_diff == K) {
            dq = temp;
            break;
        }
    } while (std::next_permutation(numbers.begin(), numbers.end()));
    return dq;
}

int main() {
    int N = 5;
    int K = 4;
    std::deque<int> dq = generatePermutation(N, K);

    std::cout << "Generated permutation: ";
    for (const auto& elem : dq) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

10. #include <iostream>
#include <deque>
#include <string>

bool canBeMadeEqual(const std::string& str1, const std::string& str2) {
    std::deque<char> dq1(str1.begin(), str1.end());
    std::deque<char> dq2(str2.begin(), str2.end());

    while (!dq1.empty() && !dq2.empty() && dq1.front() == dq2.front()) {
        dq1.pop_front();
        dq2.pop_front();
    }
    while (!dq1.empty() && !dq2.empty() && dq1.back() == dq2.back()) {
        dq1.pop_back();
        dq2.pop_back();
    }
    return dq1.size() <= 1 && dq2.size() <= 1;
}

int main() {
    std::string str1 = "abc";
    std::string str2 = "abdc";

    if (canBeMadeEqual(str1, str2)) {
        std::cout << "Strings can be made equal by inserting at most 1 character." << std::endl;
    } else {
        std::cout << "Strings cannot be made equal by inserting at most 1 character." << std::endl;
    }

    return 0;
}

11. #include <iostream>
#include <deque>

int main() {
    std::deque<int> dq = {1, 2, 3, 4, 5};

    std::cout << "First element: " << dq.front() << std::endl;
    std::cout << "Last element: " << dq.back() << std::endl;

    return 0;
}

12. #include <iostream>
#include <deque>
#include <string>

std::string processBackspaces(const std::string& str) {
    std::deque<char> dq;
    for (char ch : str) {
        if (ch == '#') {
            if (!dq.empty()) {
                dq.pop_back();
            }
        } else {
            dq.push_back(ch);
        }
    }
    return std::string(dq.begin(), dq.end());
}

int main() {
    std::string str = "abc#de#f#ghi#jklmn#op#";
    std::string result = processBackspaces(str);

    std::cout << "Processed string: " << result << std::endl;

    return 0;
}

13. #include <iostream>
#include <deque>
#include <list>

void segregateEvenOdd(std::list<int>& lst) {
    std::deque<int> dq;
    for (const auto& elem : lst) {
        if (elem % 2 == 0) {
            dq.push_front(elem);
        } else {
            dq.push_back(elem);
        }
    }
    lst.assign(dq.begin(), dq.end());
}

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    segregateEvenOdd(lst);

    std::cout << "List after segregating even and odd nodes: ";
    for (const auto& elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
