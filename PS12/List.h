#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "ListNode.h"

namespace cs52 {

	class List {
	public:
		List();
		~List();
	/// Implement these!
		void concatenate(const List& B);
		void insertith(const int& data, const size_t& i);
		void removeDups(); 

		bool isEmpty() const;
		int  size() const;
		void makeEmpty();
		void insert(const int& data);
		void remove(const int& data);


		friend std::ostream& operator << (std::ostream& outs, const List& l);
		friend std::ostream& operator << (std::ostream& outs, const List* l);
	private:
		ListNode* head;
		int listSize;

		std::ostream& printList(std::ostream& outs) const;

		void append(const int& data);
	};

}
#endif