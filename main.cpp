#include<iostream>
#include<string.h> 
#include <fstream>
#include"stdlib.h"
using namespace std;
class Node {
public:
	int num;
	char name[20];
	float Math;
	float English;
	float Physics;
	float average;
	Node* next;
};
class StudList
{
private:
	Node* head;//ͷ�ڵ�  

public:
	StudList();
	void CreateList();//��������  
	void Display();//��ʾ����  
	int getlen();//��ȡ������  
//  bool isEmpty();//�ж������Ƿ�Ϊ��  
//  bool Find(const int n);//�������в���ĳ��ֵ  
//  Node* GetNode(int i);//���ص�i���ڵ�  
	Node* GetHead();

	void averGrade(Node* node);	//��ƽ���ɼ� 
	void pushBack(); //β�����һ��ѧ�� 
	void Insert(); //�ڵ�i��λ�ò���һ��ѧ�� 
	int Delete();  //ɾ��һ����ѧ�� 
	int Modif();  //�޸�һ����ѧ�� ����Ϣ 
	void sort(); //��������Ĳ�������ʹ��ĳ�ſγ̳ɼ����� 
	void sortM();
	void sortE();
	void sortP();
	void sortAver();//ƽ���ɼ����� 
	int select();//��ѯ
	void CountNot();//��ѯĳһ��ѧ�Ʋ�����������ͳɼ��� 
	int CountNotM();
	int CountNotE();
	int CountNotP();
};

void menu(StudList* list);
void Save(StudList* list);
void Read(StudList* list);

int main() {

	StudList list;
	list.CreateList();
	menu(&list);
	return 0;
}

StudList::StudList()
{
	head = new Node();
	head->next = NULL;
}

void StudList::Display() {
	Node* cur = head;
	int len = getlen();
	cout << "����:" << len << "������"<<endl;
	while (len--) {
		cout << "  ѧ�ţ�" << cur->num;
		cout << "  ������" << cur->name;
		cout << "  ������" << cur->Math;
		cout << "  Ӣ�" << cur->English;
		cout << "  ����" << cur->Physics;
		cout << "  ƽ���ɼ���" << cur->average << endl;
		cur = cur->next;
	}
}

//����һ���ձ� 
void StudList::CreateList()
{
	head->num = 0;
}

Node* StudList::GetHead() {
	return head;
}

void StudList::pushBack() {
	Node* cur, * p, * t;
	if (!head) {
		head = new Node();
	}
	cur = head;
	p = new Node();
	t = head;

	while (cur->next) {
		cur = cur->next;
	}
	cout << "����ѧ�ţ�" << endl;
	cin >> p->num;
	while (t) {
		if (t->num == p->num) {
			cout << "�Ѵ��ڸ�ѧ�ţ�" << endl;
			return;
		}
		t = t->next;
	}
	cout << "����������" << endl;
	cin >> p->name;
	cout << "��������ɼ���" << endl;
	cin >> p->Math;
	cout << "����Ӣ��ɼ���" << endl;
	cin >> p->English;
	cout << "��������ɼ���" << endl;
	cin >> p->Physics;
	averGrade(p);
	if (head->num == 0) {
		head = p;
		return;
	}
	cur->next = p;
	p->next = NULL;
}


void StudList::averGrade(Node* node) {
	node->average = (node->English + node->Math + node->Physics) / 3;
}

//��ȡ�������� 
int StudList::getlen() {
	int n = 0;
	Node* cur;
	cur = head;
	while (cur) {
		n++;
		cur = cur->next;
	}
	return n;
}

//����һ���ڵ� 
void StudList::Insert() {
	int i, len;
	cout << "����Ҫ����ѧ����λ��(���ܲ��뵽��һ��ѧ��ǰ�ͳ������һ��ѧ��֮�󣬼�n>1��n<=len)��";
	cin >> i;
	len = getlen();
	if (i <= 2 || i > len) {

	}
	Node* cur, * t, * pr, * newNode;
	if (head == NULL || head->num == 0) {
		cout << "��ǰ��Ϊ�գ�" << endl;
		StudList();
		return;
	}
	cur = head;
	pr = head;
	i -= 1;		//�����i����������������i��ʾ���±�����Ҫ����ʾλ������Ҫ��i-1; 
	while (cur && i--) {
		pr = cur;
		cur = cur->next;
	}
	newNode = new Node();
	t = head;
	cout << "�������ѧ����ѧ�ţ�" << endl;
	cin >> newNode->num;
	while (t) {					//�ж��Ƿ��������ѧ�� 
		if (t->num == newNode->num) {
			cout << "�Ѵ��ڸ�ѧ��!" << endl;
			return;
		}
		t = t->next;
	}
	cout << "����������" << endl;
	cin >> newNode->name;
	cout << "��������ɼ���" << endl;
	cin >> newNode->Math;
	cout << "����Ӣ��ɼ���" << endl;
	cin >> newNode->English;
	cout << "��������ɼ���" << endl;
	cin >> newNode->Physics;
	averGrade(newNode);

	pr->next = newNode;
	newNode->next = cur;

}
//��ѯ
int StudList::select() {				//n��ʾѧ�� 
	int n;
	Node* cur, * pr;
	cur = head;
	pr = head;
	cout << "����Ҫ��ѯѧ����ѧ�ţ�";
	cin >> n;
	bool flag = false;
	while (cur) {
		if (cur->num == n) {
			cout << "  ѧ�ţ�" << cur->num;
			cout << "  ������" << cur->name;
			cout << "  ������" << cur->Math;
			cout << "  Ӣ�" << cur->English;
			cout << "  ����" << cur->Physics;
			cout << "  ƽ���ɼ���" << cur->average << endl;
			flag = true;
		}
		pr = cur;
		cur = cur->next;
	}
	if (!flag) {
		cout << "û�в鵽��ѧ��" << endl;
		return 1;
	}

}
//ɾ�� 
int StudList::Delete() {				//n��ʾѧ�� 
	int n;
	Node* cur, * pr;
	cur = head;
	pr = head;
	cout << "����Ҫɾ��ѧ����ѧ�ţ�";
	cin >> n;
	while (cur) {
		if (cur->num == n) {
			if (cur == head) {			//���ɾ������ͷ�ڵ㣬ֱ����ͷ�ڵ�Ϊͷ�ڵ����һ�ڵ� 
				head = head->next;
				return 1;
			}
			pr->next = cur->next;
			return 1; 					//��ɾ���������һ���ڵ�����ʹ�� cur->next->next,ǰ���Ѿ� cur = cur->next;������� 
		}
		pr = cur;
		cur = cur->next;
	}
	cout << "û�в鵽Ҫɾ����ѧ��" << endl;
	return -1;
}

//�޸�ָ��ѧ��ѧ������Ϣ 
int StudList::Modif() {			//nΪѧ�� 
	int a, n;
	Node* cur;
	cur = head;
	cout << "����Ҫ�޸�ѧ����ѧ�ţ�";
	cin >> n;
	while (cur) {
		if (cur->num == n) {
			cout << "1.�޸�����" << endl;
			cout << "2.�޸���ѧ�ɼ�" << endl;
			cout << "3.�޸�Ӣ��ɼ�" << endl;
			cout << "4.�޸�����ɼ�" << endl;
			cout << "������Ҫ�޸ĵ���Ŀ(�������������޸�)��";
			cin >> a;
			switch (a) {
			case 1:
				cout << "�������޸�������";
				cin >> cur->name;
				return 1;
			case 2:
				cout << "�������޸ĵ���ѧ�ɼ���";
				cin >> cur->Math;
				return 1;
			case 3:
				cout << "�������޸ĵ�Ӣ��ɼ���";
				cin >> cur->English;
				return 1;
			case 4:
				cout << "�������޸ĵ�����ɼ���";
				cin >> cur->Physics;
				return 1;
			default:
				cout << "�˳��޸�" << endl;
				return 1;
			}
		}
		cur = cur->next;
	}
	return -1;
}

void swapNode(Node* a, Node* b) {			//�������ڵ����Ϣ 
	int temp;
	char c;
	float ft;

	temp = a->num;
	a->num = b->num;
	b->num = temp;

	//�������� 
	for (int i = 0; i < 20; i++) {
		c = a->name[i];
		a->name[i] = b->name[i];
		b->name[i] = c;
	}

	ft = a->Math;
	a->Math = b->Math;
	b->Math = ft;

	ft = a->English;
	a->English = b->English;
	b->English = ft;

	ft = a->Physics;
	a->Physics = b->Physics;
	b->Physics = ft;

	ft = a->average;
	a->average = b->average;
	b->average = ft;
}

void StudList::sortM() {			//����ѧ�ɼ����� 
	int len, inlen;
	Node* cur;
	len = getlen();
	while (--len) {
		inlen = len;
		cur = head;
		while (inlen--) {
			if (cur->Math < cur->next->Math) {
				swapNode(cur, cur->next);
			}
			cur = cur->next;
		}
	}
}

void StudList::sortE() {			//��Ӣ��ɼ����� 
	int len, inlen;
	Node* cur;
	cur = head;
	len = getlen();
	while (--len) {
		inlen = len;
		cur = head;
		while (cur && inlen--) {
			if (cur->English < cur->next->English) {
				swapNode(cur, cur->next);
			}
			cur = cur->next;
		}
	}
}

void StudList::sortP() {				//������ɼ����� 
	int len, inlen;
	Node* cur;
	cur = head;
	len = getlen();
	while (--len) {
		inlen = len;
		cur = head;
		while (cur && inlen--) {
			if (cur->Physics < cur->next->Physics) {
				swapNode(cur, cur->next);
			}
			cur = cur->next;
		}
	}
}

void StudList::sortAver() {
	int len, inlen, rank = 1;
	Node* cur;
	cur = head;
	len = getlen();
	while (--len) {
		inlen = len;
		cur = head;
		while (cur && inlen--) {
			if (cur->average < cur->next->average) {
				swapNode(cur, cur->next);
			}
			cur = cur->next;
		}
	}
	cur = head;
	while (cur) {
		cout << "ѧ�ţ�" << cur->num << " ������" << cur->name << "  ��ѧ�ɼ���" << cur->Math << "  Ӣ��ɼ���" << cur->English
			<< "  ����ɼ���" << cur->Physics << "  ƽ���ɼ���" << cur->average << " ���Σ�" << rank << endl;
		if (cur->next && cur->average == cur->next->average) {
			cur = cur->next;
			continue;
		}
		rank++;
		cur = cur->next;
	}
}

//���ɼ����� 
void StudList::sort() {
	int m;
	cout << "1.����ѧ�ɼ�����" << endl;
	cout << "2.��Ӣ��ɼ�����" << endl;
	cout << "3.������ɼ�����" << endl;
	cout << " ѡ��ĳһ������ʽ��";
	cin >> m;
	switch (m) {
	case 1:
		sortM();
		break;
	case 2:
		sortE();
		break;
	case 3:
		sortP();
		break;
	default:
		break;
	}
}

int StudList::CountNotM() {
	int n = 0;
	Node* cur;
	cur = head;
	while (cur) {
		if (cur->Math < 60) {
			cout << "ѧ�ţ�" << cur->num << " ������" << cur->name << " �ɼ���" << cur->Math << endl;
			n++;
		}
		cur = cur->next;
	}
	cout << "������ѧ������������" << n << endl;
	return n;
}

int StudList::CountNotE() {
	int n = 0;
	Node* cur;
	cur = head;
	while (cur) {
		if (cur->English < 60) {
			cout << "ѧ�ţ�" << cur->num << " ������" << cur->name << " �ɼ���" << cur->English << endl;
			n++;
		}
		cur = cur->next;
	}
	cout << "����Ӣ�ﲻ����������" << n << endl;
	return n;
}


int StudList::CountNotP() {
	int n = 0;
	Node* cur;
	cur = head;
	while (cur) {
		if (cur->Physics < 60) {
			cout << "ѧ�ţ�" << cur->num << " ������" << cur->name << " �ɼ���" << cur->Physics << endl;
			n++;
		}
		cur = cur->next;
	}
	cout << "������������������" << n << endl;
	return n;
}

//ͳ�Ʋ�����ɼ����� 
void StudList::CountNot() {
	int m;
	cout << "1.ͳ����ѧ�ɼ�������������" << endl;
	cout << "2.ͳ��Ӣ��ɼ�������������" << endl;
	cout << "3.ͳ������ɼ�������������" << endl;
	cout << "����ѡ��ʽ��";
	cin >> m;
	switch (m) {
	case 1:
		CountNotM();
		break;
	case 2:
		CountNotE();
		break;
	case 3:
		CountNotP();
		break;
	default:
		break;
	}
}

//�˵� 
void menu(StudList* list) {
	int a;
	//cout << "************************************" << endl;
	cout << "��ӭʹ��ʯ��ׯ������ѧѧ���ɼ������ϵͳ" << endl;
	//cout << "************************************" << endl;
	while (1) {
		system("pause");
		system("cls");
		cout << "--------------------------------" << endl;
		cout << "---1.���һ��ѧ���ɼ�        ---" << endl;
		cout << "---2.ɾ��һ��ѧ���ɼ�        ---" << endl;
		cout << "---3.�޸�һ��ѧ���ɼ�        ---" << endl;
		cout << "---4.��ʾѧ���ɼ���          ---" << endl;
		cout << "---5.��ĳһ�γɼ�����        ---" << endl;
		cout << "---6.ͳ��ĳһ�γɼ�����������---" << endl;
		cout << "---7.ƽ���ɼ�����            ---" << endl;
		cout << "---8.��ѯѧ���ɼ�            ---"<< endl;
		cout << "--------------------------------" << endl;
		cin >> a;
		switch (a) {
		case 1:
			list->pushBack();
			break;

		case 2:
			list->Display();
			list->Delete();
			list->Display();
			break;

		case 3:
			list->Display();
			list->Modif();
			list->Display();
			break;

		/*case 4:
			list->Display();
			list->Insert();
			list->Display();
			break;*/
		case 4:
			list->Display();
			break;

		case 5:
			list->sort();
			list->Display();
			break;

		case 6:
			list->CountNot();
			break;

		case 7:
			list->sortAver();
			break;
		case 8:
			list->Display();
			list->select();
			break;
		default:
			Save(list);
			return;

		}
	}
}

//�����ļ� 
void Save(StudList* list)
{
	Node* p;
	ofstream outfile;
	p = list->GetHead();

	outfile.open("Stud_data.dat", ios::binary);
	if (!outfile) {
		cerr << "open error!" << endl;
		return;
	}
	while (p) {
		outfile.write((char*)p, sizeof(Node));
		p = p->next;
	}
	outfile.close();
	cout << "����ɹ���" << endl;
}

//���ļ� 
void Read(StudList* list)
{
	Node* p, * q, * h;
	ifstream infile;
	list->CreateList();
	p = list->GetHead();
	infile.open("Stud_data.dat", ios::binary);
	if (!infile)
	{
		cerr << "open error!" << endl;
		return;
	}
	while (!infile.eof()) {
		infile.read((char*)p, sizeof(Node));
		q = new Node();
		p->next = q;
		p = q;
	}
	h = list->GetHead();
	while (h->next->num) {
		h = h->next;
	}
	h->next = NULL;
	infile.close();
	cout << "��ȡ�ɹ���" << endl;
}
