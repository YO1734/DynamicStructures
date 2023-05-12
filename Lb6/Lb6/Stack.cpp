#include <iostream>
#include <string>

struct Sklad
{
    std::string name;
    float cost;
    int quantity;
    std::string type;
};

struct Node
{
    Sklad data;
    Node* next;
};

class Stack
{
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void Push(const Sklad& newData)
    {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = top;
        top = newNode;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    Sklad Top() const
    {
        if (IsEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
            return Sklad();
        }

        return top->data;
    }

    bool IsEmpty() const
    {
        return top == nullptr;
    }

    void PrintInfo() const
    {
        if (IsEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        Node* current = top;
        while (current != nullptr)
        {
            std::cout << "Name: " << current->data.name << "\n";
            std::cout << "Cost: " << current->data.cost << "\n";
            std::cout << "Quantity: " << current->data.quantity << "\n";
            std::cout << "Type of units: " << current->data.type << "\n\n";
            current = current->next;
        }
    }
};

int main()
{
    Stack stack;

    // Добавление новых элементов в стек
    Sklad item1 = { "Item1", 10.0f, 5, "kg" };
    stack.Push(item1);

    Sklad item2 = { "Item2", 5.0f, 3, "units" };
    stack.Push(item2);

    // Вывод информации о элементах в стеке
    stack.PrintInfo();

    // Удаление элемента из стека
    stack.Pop();

    // Вывод информации о элементе на вершине стека
    Sklad topItem = stack.Top();
    std::cout << "Top item:\n";
    std::cout << "Name: " << topItem.name << "\n";
    std::cout << "Cost: " << topItem.cost << "\n";
    std::cout << "Quantity: " << topItem.quantity << "\n";
    std::cout << "Type of units: " << topItem.type << "\n";

    return 0;
}