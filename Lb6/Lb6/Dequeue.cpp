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
    Node* prev;
    Node* next;
};

class Deque
{
private:
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    void EnqueueFront(const Sklad& newData)
    {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->prev = nullptr;
        newNode->next = front;

        if (IsEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            front->prev = newNode;
            front = newNode;
        }
    }

    void EnqueueRear(const Sklad& newData)
    {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->prev = rear;
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

    void DequeueFront()
    {
        if (IsEmpty())
        {
            std::cout << "Deque is empty." << std::endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front != nullptr)
        {
            front->prev = nullptr;
        }
        else
        {
            rear = nullptr;
        }

        delete temp;
    }

    void DequeueRear()
    {
        if (IsEmpty())
        {
            std::cout << "Deque is empty." << std::endl;
            return;
        }

        Node* temp = rear;
        rear = rear->prev;

        if (rear != nullptr)
        {
            rear->next = nullptr;
        }
        else
        {
            front = nullptr;
        }

        delete temp;
    }

    Sklad Front() const
    {
        if (IsEmpty())
        {
            std::cout << "Deque is empty." << std::endl;
            return Sklad();
        }

        return front->data;
    }

    Sklad Rear() const
    {
        if (IsEmpty())
        {
            std::cout << "Deque is empty." << std::endl;
            return Sklad();
        }

        return rear->data;
    }

    bool IsEmpty() const
    {
        return front == nullptr;
    }

    void PrintInfo() const
    {
        if (IsEmpty())
        {
            std::cout << "Deque is empty." << std::endl;
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
    Deque deque;

    // Добавление новых элементов в двустороннюю очередь
    Sklad item1 = { "Item1", 10.0f, 5, "kg" };
    deque.EnqueueFront(item1);

    Sklad item2 = { "Item2", 5.0f, 3, "units" };
    deque.EnqueueRear(item2);

    // Вывод информации о элементах в двусторонней очереди
    deque.PrintInfo();

    // Удаление элементов из двусторонней очереди
    deque.DequeueFront();
    deque.DequeueRear();

    // Вывод информации о первом и последнем элементах в двусторонней очереди
    Sklad frontItem = deque.Front();
    std::cout << "Front item:\n";
    std::cout << "Name: " << frontItem.name << "\n";
    std::cout << "Cost: " << frontItem.cost << "\n";
    std::cout << "Quantity: " << frontItem.quantity << "\n";
    std::cout << "Type of units: " << frontItem.type << "\n";

    Sklad rearItem = deque.Rear();
    std::cout << "Rear item:\n";
    std::cout << "Name: " << rearItem.name << "\n";
    std::cout << "Cost: " << rearItem.cost << "\n";
    std::cout << "Quantity: " << rearItem.quantity << "\n";
    std::cout << "Type of units: " << rearItem.type << "\n";

    return 0;
}