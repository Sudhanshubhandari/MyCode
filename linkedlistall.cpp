#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;





	node* next;


	node(int data) {
		this->data = data;
		next = NULL;
	}
};



node* alternateMerge(node * root1, node* root2) {
	node*p3 = new node(root1->data);
	root1 = root1->next;
	node*temp = p3;
	while (root1 or root2)
	{
		if (root2)
		{
			temp->next = new node(root2->data);
			root2 = root2->next;
			temp = temp->next;
		}
		if (root1)
		{
			temp->next = new node(root1->data);
			root1 = root1->next;
			temp = temp->next;
		}
	}
	return p3;
}





void display(node * head)
{
	node*temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;

	}
}
void pushel(node*head, int data)
{
	node*n = new node (data);
	n->next = head;
	head = n;

}



node * middleelement(node*head)
{
	node*fast = head;
	node*slow = head;
	while (fast and fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;


}




node* sorted(node*head1, node*head2)
{
	node*p1 = head1;
	node*p2 = head2;
	node*dummy = new node(-1);
	node*p3 = dummy;
	while (p1 and p2) {
		if (p1->data > p2->data)
		{
			p3 ->next = p2;
			p2 = p2->next;
			p3 = p3->next;
		}
		else {
			p3->next = p1;
			p1 = p1->next;
			p3 = p3->next;
		}

	}
	while (p1) {
		p3->next = p1;
		p1 = p1->next;
		p3 = p3->next;
	}
	while (p2)
	{
		p3->next = p2;
		p2 = p2->next;
		p3 = p3->next;
	}
	return dummy->next;
}

void swap(node*h1)
{
	node*p1 = new node(p1->data);
	while (p1 != NULL)
	{
		swap(p1->next, p1->next->next);
		p1 = p1->next;
	}
	cout << p1;
}
node*removeh(node* head) {
	node*fast = head->next;
	node*slow = head;
	if ( !head->next) {
		return head;
	}
	else {
		while (fast && fast->next) {
			if (fast ->data > head->data) {
				slow = head->next;
				head->next = slow->next ;
				slow->next = NULL;
				delete slow;
				head = head->next
				       fast = fast->next;



			}
		}
	}

}


int main()
{


	node * r = new node(8);
	r->next = new node(2);
	r->next->next = new node(9);

	node * r2 = new node(5);





	removeh(r);

	display(r);


	return 0;
}



