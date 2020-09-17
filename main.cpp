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
	Node* head;//头节点  

public:
	StudList();
	void CreateList();//创建链表  
	void Display();//显示链表  
	int getlen();//获取链表长度  
//  bool isEmpty();//判断链表是否为空  
//  bool Find(const int n);//在链表中查找某个值  
//  Node* GetNode(int i);//返回第i个节点  
	Node* GetHead();

	void averGrade(Node* node);	//求平均成绩 
	void pushBack(); //尾部添加一个学生 
	void Insert(); //在第i个位置插入一个学生 
	int Delete();  //删除一个个学生 
	int Modif();  //修改一个个学生 的信息 
	void sort(); //根据输入的参数决定使用某门课程成绩排序 
	void sortM();
	void sortE();
	void sortP();
	void sortAver();//平均成绩排序 
	int select();//查询
	void CountNot();//查询某一门学科不及格的人数和成绩单 
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
	cout << "共有:" << len << "条数据"<<endl;
	while (len--) {
		cout << "  学号：" << cur->num;
		cout << "  姓名：" << cur->name;
		cout << "  高数：" << cur->Math;
		cout << "  英语：" << cur->English;
		cout << "  物理：" << cur->Physics;
		cout << "  平均成绩：" << cur->average << endl;
		cur = cur->next;
	}
}

//建立一个空表 
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
	cout << "输入学号：" << endl;
	cin >> p->num;
	while (t) {
		if (t->num == p->num) {
			cout << "已存在该学号！" << endl;
			return;
		}
		t = t->next;
	}
	cout << "输入姓名：" << endl;
	cin >> p->name;
	cout << "输入高数成绩：" << endl;
	cin >> p->Math;
	cout << "输入英语成绩：" << endl;
	cin >> p->English;
	cout << "输入物理成绩：" << endl;
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

//获取单链表长度 
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

//插入一个节点 
void StudList::Insert() {
	int i, len;
	cout << "输入要插入学生的位置(不能插入到第一个学生前和超过最后一个学生之后，即n>1，n<=len)：";
	cin >> i;
	len = getlen();
	if (i <= 2 || i > len) {

	}
	Node* cur, * t, * pr, * newNode;
	if (head == NULL || head->num == 0) {
		cout << "当前表为空！" << endl;
		StudList();
		return;
	}
	cur = head;
	pr = head;
	i -= 1;		//这里的i根据情况来定，如果i表示的下标则不需要，表示位数则需要对i-1; 
	while (cur && i--) {
		pr = cur;
		cur = cur->next;
	}
	newNode = new Node();
	t = head;
	cout << "输入插入学生的学号：" << endl;
	cin >> newNode->num;
	while (t) {					//判断是否从在已有学号 
		if (t->num == newNode->num) {
			cout << "已存在该学号!" << endl;
			return;
		}
		t = t->next;
	}
	cout << "输入姓名：" << endl;
	cin >> newNode->name;
	cout << "输入高数成绩：" << endl;
	cin >> newNode->Math;
	cout << "输入英语成绩：" << endl;
	cin >> newNode->English;
	cout << "输入物理成绩：" << endl;
	cin >> newNode->Physics;
	averGrade(newNode);

	pr->next = newNode;
	newNode->next = cur;

}
//查询
int StudList::select() {				//n表示学号 
	int n;
	Node* cur, * pr;
	cur = head;
	pr = head;
	cout << "输入要查询学生的学号：";
	cin >> n;
	bool flag = false;
	while (cur) {
		if (cur->num == n) {
			cout << "  学号：" << cur->num;
			cout << "  姓名：" << cur->name;
			cout << "  高数：" << cur->Math;
			cout << "  英语：" << cur->English;
			cout << "  物理：" << cur->Physics;
			cout << "  平均成绩：" << cur->average << endl;
			flag = true;
		}
		pr = cur;
		cur = cur->next;
	}
	if (!flag) {
		cout << "没有查到该学号" << endl;
		return 1;
	}

}
//删除 
int StudList::Delete() {				//n表示学号 
	int n;
	Node* cur, * pr;
	cur = head;
	pr = head;
	cout << "输入要删除学生的学号：";
	cin >> n;
	while (cur) {
		if (cur->num == n) {
			if (cur == head) {			//如果删除的是头节点，直接令头节点为头节点的下一节点 
				head = head->next;
				return 1;
			}
			pr->next = cur->next;
			return 1; 					//若删除的是最后一个节点则不能使用 cur->next->next,前边已经 cur = cur->next;不许操作 
		}
		pr = cur;
		cur = cur->next;
	}
	cout << "没有查到要删除的学号" << endl;
	return -1;
}

//修改指定学号学生的信息 
int StudList::Modif() {			//n为学号 
	int a, n;
	Node* cur;
	cur = head;
	cout << "输入要修改学生的学号：";
	cin >> n;
	while (cur) {
		if (cur->num == n) {
			cout << "1.修改姓名" << endl;
			cout << "2.修改数学成绩" << endl;
			cout << "3.修改英语成绩" << endl;
			cout << "4.修改物理成绩" << endl;
			cout << "请输入要修改的项目(输入其它不做修改)：";
			cin >> a;
			switch (a) {
			case 1:
				cout << "请输入修改姓名：";
				cin >> cur->name;
				return 1;
			case 2:
				cout << "请输入修改的数学成绩：";
				cin >> cur->Math;
				return 1;
			case 3:
				cout << "请输入修改的英语成绩：";
				cin >> cur->English;
				return 1;
			case 4:
				cout << "请输入修改的物理成绩：";
				cin >> cur->Physics;
				return 1;
			default:
				cout << "退出修改" << endl;
				return 1;
			}
		}
		cur = cur->next;
	}
	return -1;
}

void swapNode(Node* a, Node* b) {			//交换两节点的信息 
	int temp;
	char c;
	float ft;

	temp = a->num;
	a->num = b->num;
	b->num = temp;

	//姓名交换 
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

void StudList::sortM() {			//按数学成绩排序 
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

void StudList::sortE() {			//按英语成绩排序 
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

void StudList::sortP() {				//按物理成绩排序 
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
		cout << "学号：" << cur->num << " 姓名：" << cur->name << "  数学成绩：" << cur->Math << "  英语成绩：" << cur->English
			<< "  物理成绩：" << cur->Physics << "  平均成绩：" << cur->average << " 名次：" << rank << endl;
		if (cur->next && cur->average == cur->next->average) {
			cur = cur->next;
			continue;
		}
		rank++;
		cur = cur->next;
	}
}

//按成绩排序 
void StudList::sort() {
	int m;
	cout << "1.按数学成绩排序。" << endl;
	cout << "2.按英语成绩排序。" << endl;
	cout << "3.按物理成绩排序。" << endl;
	cout << " 选择某一门排序方式：";
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
			cout << "学号：" << cur->num << " 姓名：" << cur->name << " 成绩：" << cur->Math << endl;
			n++;
		}
		cur = cur->next;
	}
	cout << "共计数学不及格人数：" << n << endl;
	return n;
}

int StudList::CountNotE() {
	int n = 0;
	Node* cur;
	cur = head;
	while (cur) {
		if (cur->English < 60) {
			cout << "学号：" << cur->num << " 姓名：" << cur->name << " 成绩：" << cur->English << endl;
			n++;
		}
		cur = cur->next;
	}
	cout << "共计英语不及格人数：" << n << endl;
	return n;
}


int StudList::CountNotP() {
	int n = 0;
	Node* cur;
	cur = head;
	while (cur) {
		if (cur->Physics < 60) {
			cout << "学号：" << cur->num << " 姓名：" << cur->name << " 成绩：" << cur->Physics << endl;
			n++;
		}
		cur = cur->next;
	}
	cout << "共计物理不及格人数：" << n << endl;
	return n;
}

//统计不及格成绩名单 
void StudList::CountNot() {
	int m;
	cout << "1.统计数学成绩不及格名单。" << endl;
	cout << "2.统计英语成绩不及格名单。" << endl;
	cout << "3.统计物理成绩不及格名单。" << endl;
	cout << "输入选择方式：";
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

//菜单 
void menu(StudList* list) {
	int a;
	//cout << "************************************" << endl;
	cout << "欢迎使用石家庄铁道大学学生成绩表管理系统" << endl;
	//cout << "************************************" << endl;
	while (1) {
		system("pause");
		system("cls");
		cout << "--------------------------------" << endl;
		cout << "---1.添加一个学生成绩        ---" << endl;
		cout << "---2.删除一个学生成绩        ---" << endl;
		cout << "---3.修改一个学生成绩        ---" << endl;
		cout << "---4.显示学生成绩表          ---" << endl;
		cout << "---5.按某一课成绩排序        ---" << endl;
		cout << "---6.统计某一课成绩不及格人数---" << endl;
		cout << "---7.平均成绩排名            ---" << endl;
		cout << "---8.查询学生成绩            ---"<< endl;
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

//保存文件 
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
	cout << "保存成功！" << endl;
}

//读文件 
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
	cout << "读取成功！" << endl;
}
