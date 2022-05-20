/* Построить двоичное дерево поиска из вводимой последовательности чисел,
 * располагая числа с учетом значения их суммы цифр.
 * Вывести дерево на экран. Определить все числа, кратные 2 и их количество.
 * Удалить из дерева эти числа. Вывести оставшиеся элементы дерева.
 * Реализовать подпрограмму добавления нового числа в список по желанию пользователя.
 * Вывести на экран всю необходимую информацию с комментариями.*/

#include <conio.h>
#include "tree.h"

void multTwo(node *root, int &count, int *arr) {
    if (root) {
        int n = root->val;
        if (n % 2 == 0) {
            std::cout << n << " ";
            *(arr + count) = n;
            count++;
        }
        if (root->left)
            multTwo(root->left, count, arr);
        if (root->right)
            multTwo(root->right, count, arr);
    }
}

int main() {
    int n;
    node *root = NULL;
    std::cout << "Input numbers:" << std::endl;
    while (scanf("%d", &n)) {
        root = add(root, n);
    }
    printTree(root);
    std::cout << "Numbers that are multiples of two:" << std::endl;
    int count = 0, *arr = new int[50];
    multTwo(root, count, arr);
    for (int i = 0; i < count; ++i) {
        root = deleteNode(root, *(arr + i));
    }
    std::cout << std::endl << "Amount: " << count << std::endl;
    std::cout << "Tree without this numbers:" << std::endl;
    printTree(root);
    getch();
    int k = 0;
    while (k != 4) {
        system("cls");
        std::cout << "Choose action:" << std::endl;
        std::cout << "1 - add new element" << std::endl;
        std::cout << "2 - delete element" << std::endl;
        std::cout << "3 - info" << std::endl;
        std::cout << "4 - exit" << std::endl;
        std::cin.ignore();
        std::cin >> k;
        switch (k) {
            case 1: {
                system("cls");
                int i;
                std::cout << "Enter a value: ";
                std::cin >> i;
                root = add(root, i);
                printTree(root);
                getch();
                break;
            }
            case 2: {
                system("cls");
                int i;
                std::cout << "Enter a value: ";
                std::cin >> i;
                root = deleteNode(root, i);
                printTree(root);
                getch();
                break;
            }
            case 3: {
                system("cls");
                printTree(root);
                std::cout << std::endl << "Size: " << size(root) << std::endl;
                std::cout << "Depth: " << depth(root) << std::endl;
                getch();
                break;
            }
        }
    }
    deleteTree(root);
    delete[] arr;
    return 0;
}
