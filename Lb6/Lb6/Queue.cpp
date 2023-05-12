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

class Queue
{
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void Enqueue(const Sklad& newData)
    {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = nullptr;

        if (IsEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void Dequeue()
    {
        if (IsEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
    }

    Sklad Front() const
    {
        if (IsEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            return Sklad();
        }

        return front->data;
    }

    bool IsEmpty() const
    {
        return front == nullptr;
    }

    void PrintInfo() const
    {
        if (IsEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        Node* current = front;
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
    Queue queue;

    // Добавление новых элементов в очередь
    Sklad item1 = { "Item1", 10.0f, 5, "kg" };
    queue.Enqueue(item1);

    Sklad item2 = { "Item2", 5.0f, 3, "units" };
    queue.Enqueue(item2);

    // Вывод информации о элементах в очереди
    queue.PrintInfo();

    // Удаление элемента из очереди
    queue.Dequeue();

    // Вывод информации о первом элементе в очереди
    Sklad frontItem = queue.Front();
    std::cout << "Front item:\n";
    std::cout << "Name: " << frontItem.name << "\n";
    std::cout << "Cost: " << frontItem.cost << "\n";
    std::cout << "Quantity: " << frontItem.quantity << "\n";
    std::cout << "Type of units: " << frontItem.type << "\n";

    return 0;
}