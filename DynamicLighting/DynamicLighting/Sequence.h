#pragma once
class Sequence
{
private:
	struct Node
	{
	public:
		Node() {};
		Node(Colour _value)
		{
			value = _value;
		};
		~Node() {};

		Node* previous;
		Node* next;
		Colour value;
	};
public:
	Sequence() {}
	Sequence(uint16_t _size)
	{
		for (uint16_t i = 0; i < _size; i++)
		{
			head = Insert(new Node(), Colour());
		}
	}
	~Sequence() {};

	Node* Insert(Node* _node, Colour _value)
	{
		if (_node == nullptr)
			return Create(_value, _node);
		_node->next = Insert(_node->next, _value);
		return _node;
	}
	Node* Create(Colour _value, Node* _node = NULL)
	{
		Node* newNode = new Node(_value);
		newNode->next = _node;
		return newNode;
	}

	Node* root = NULL;
	Node* head = NULL;
	Node* current = NULL;
	uint16_t count = 0;
	//uint16_t location = 0;
};