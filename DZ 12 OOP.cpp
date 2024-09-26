#include <iostream>
#include <set> // библиотека хранящая в себе реалитзацию бинарного дерева( класс set) нельзя хранить одинаковые элементы и нет подрядка добавления



template <typename ANY>
class BinaryTree {

private:
	struct Node {
		ANY value = ANY();
		Node* left = nullptr;
		Node* right = nullptr;

	};
	Node* root;



	void insert(ANY value, Node* node) { // узел 
		if (value < node->value) { //node->value число
			if (node->left == nullptr) { // 
				node->left = new Node; // создаем новый узел левая ветка
				node->left->value = value; // в новый узел вставляется значение
			}
			else { //если нет левой ветки мы создаем , аесли есть то дабвляем
				insert(value, node->left);
			}
			return;
		}
		if (value > node->value) {// node->value число
			if (node->right == nullptr) {
				node->right = new Node; // создаем новый узел правая ветка
				node->right->value = value;// в новый узел вставляется значение
			}
			else { // если нет правой ветки мы создаем , аесли есть то дабвляем
				insert(value, node->right);
			}
			return;
		}
	}

	void delete_node(Node* node) { // удаляет текущий узел и все узлы под ним(чтобы не было остатка и утечки данных)
		if (node != nullptr) {
			delete_node(node->left);
			delete_node(node->right);
			delete node;
		}
	}
	void print(Node* node) {
		if (node != nullptr) {
			print(node->left);
			std::cout << node->value << ' ';
			print(node->right);
		}
	}

public:

	BinaryTree() : root(nullptr) {} // конструктор  по умолч
	~BinaryTree() { // деструктор
		delete_node(root);
	}

	void insert(ANY value) { // добавить элемент
		if (root == nullptr) {
			root = new Node; // новый узел
			root->value = value;
			return;
		}
		insert(value, root);

	}

	void print() {
		print(root);
		std::cout << std::endl;
	}



	bool find(ANY value, Node* node) {
		if (node == nullptr) {
			return false;
		}

		if (value == node->value) {
			return true;
		}

		if (value < node->value) {
			return find(value, node->left);
		}
		else {
			return find(value, node->right);
		}
	}

	bool find(ANY value) {
		return find(value, root);
	}
};
int main() {
	setlocale(LC_ALL, "ru");


	//класс set
	/*
	std::set<int> set1;
	set1.insert(30);// добавить элемент
	set1.insert(50);
	set1.insert(20);
	set1.insert(40);
	set1.erase(40); // удалить элемент
	set1.insert(50); // не добавляется тк такой узел уже есть в коллекции (нет повтотрных элементов)


	std::cout << "Size: " << set1.size() << std::endl;

   //  for (std::set<int>::const_iterator it = set1.cbegin(); it != set1.cend(); ++it) любой порядок обработки элементов

	for (auto el : set1) //цикл forEach только получить элементы от начала до конца
		std::cout << el << ' ';
	std::cout << std::endl;
*/

	BinaryTree <int> bt;
	bt.insert(70);
	bt.insert(40);
	bt.insert(100);
	bt.insert(30);
	bt.insert(50);
	bt.insert(90);
	bt.insert(35);

	bt.print();

	return 0;
}
