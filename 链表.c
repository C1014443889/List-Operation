#include<stdio.h>

//ʵ���������ɾ�Ĳ�

//��������ڵ�
typedef struct list
{
	int value;
	struct list* next;
}List;


//����n���ڵ������
List* CreateList(int n)
{
	List* head, * node, * end;//ͷβ�ڵ㣬��ͨ�ڵ�
	head = (List*)malloc(sizeof(List));//�����ַ
	if (head == NULL)//�Ƿ����ɹ�
	{
		printf("malloc fair!\n");
	}
	end = head;//��ʼ��

	for (int i = 1; i <= n; i++)
	{
		node = (List*)malloc(sizeof(List));
		scanf_s("%d", &node->value);//�����������ֵ��value
		end->next = node;
		end = node;
	}

	end->next = NULL;
	return head;
}


//��ӡ����(ע�⣺��ͷ�ڵ����һ���ڵ㿪ʼ��ӡ��
void PrintList(List* head)
{
	List* p = head;
	while (p->next!= NULL)
	{
		p = p->next;
		printf("%d->", p->value);
	}
	puts("\n");
}

//�޸������N���ڵ��ֵ
void ChangNode(List* head,int n)
{
	List* q = head;
	int i = 0;
	while (q != NULL && i < n)//�����������n���ڵ�
	{
		q = q->next;
		i++;
	}
	if (q != NULL)
	{
		puts("����Ҫ�޸ĵ�ֵ��");
		scanf_s("%d",&q->value);
	}
	else
	{
		puts("�ڵ㲻���ڣ�");
	}
}

//ɾ�������n���ڵ�
void deleteNode(List* head,int n)
{
	List *q = head,*p=NULL;//ע��ָ���ʼ��
	int i = 0;
	while (q != NULL && i < n)//��������
	{
		p = q;//����ǰһ���ڵ�
		q = q->next;
		i++;
	}
	if (q != NULL)//��n���ڵ����
	{
		p->next = q->next;
		free(q);//ע��ɾ��
	}
	else
	{
		puts("�ڵ㲻���ڣ�");
	}
}

//ɾ��ֵΪdata������ڵ�
void deleteData(List* head, int val)
{
	List* q = head, * p = NULL;
	while (q->next != NULL)
	{
		p = q;//���浱ǰ�ڵ��ǰһ���ڵ��ָ��
		q = q->next;//��ǰ�ڵ��ָ��
		if (q->value == val)
		{
			//ע��������һ������ͨ�ڵ㣬һ����β�ڵ�
			if (q->next == NULL)
			{
				p->next = NULL;
				free(q);
			}
			else
			{
				p->next = q->next;
				free(q);
			}
			return;
		}
	}

	printf("û��Ҫɾ���Ľڵ㣡");
}

//�ڵ�n���ڵ�������
void insertNode(List* head,int n)
{
	List *q = head,*p=NULL;
	int i = 0;
	while (i < n && q != NULL)
	{
		q = q->next;
		i++;
	}
	if (q != NULL)
	{
		p = (List*)malloc(sizeof(List));
		puts("����Ҫ�����ֵ��");
		scanf_s("%d",&p->value);
		p->next = q->next;//����
		q->next = p;
	}
	else
	{
		puts("�ڵ㲻���ڣ�");
	}
}

//����ֵΪm�Ľڵ�
void searchNodeValue(List* head,int m)
{
	List* q = head;
	while (q != NULL)
	{
		if (q->value == m)
		{
			puts("�ýڵ����!\n");
			return;
		}
		q = q->next;
	}
	puts("�ڵ㲻���ڣ�");
}

//���ҵ�m���ڵ�
void searchNode(List* head, int m)
{
	List* q = head;
	int i = 0;
	while (i < m && q != NULL)
	{
		q = q->next;
		i++;
	}
	if (q != NULL)
	{
		printf("%d", q->value);
	}
	else
	{
		printf("�ڵ㲻����");
	}
}


//��������򣨿�������Ϊ�ջ���ֻ��һ���ڵ�����,��һ���ڵ���ͷ������һ���ڵ㣩
List* reverseList(List* head)
{
	List* q = head->next;//��һ���ڵ�
	List* p2 = q->next;//�ڶ����ڵ�

	if (q == NULL || p2 == NULL)//����Ϊ�ջ���ֻ��һ���ڵ�
	{
		printf("����Ҫ����");
		return NULL;
	}

	q->next = NULL;//��һ���ڵ�ָ���

	List* p3 = NULL;//�м�ָ��
	while (p2 != NULL)//�ӵڶ����ڵ㿪ʼ����
	{
		p3 = p2;//p3���浱ǰ�ڵ�
		p2 = p2->next;//���½ڵ�p2
		p3->next = q;//��������
		q = p3;//����q,������ 
	}

	head = q;//�µ�ͷ���
	return head;
}

//����Ŀ���
List* copyList(List* head)
{
	List* p = head;
	List* p1 = p->next;//ԭ����ĵ�һ���ڵ�

	List *tail,*newHead,*node;
	newHead = (List*)malloc(sizeof(List));//�������ͷ
	tail = newHead;

	while (p1 != NULL)//����ԭ����
	{
		node = (List*)malloc(sizeof(List));
		node->value = p1->value;//��ֵ
		tail->next = node;//����

		tail = node;//�ƶ�������
		p1 = p1->next;//�ƶ�ԭ����
	}

	tail->next = NULL;//ע��
	return newHead;
}

int main(void)
{
	int n = 5;//�ڵ�ĸ���
	List *head= CreateList(n);//��������
	//PrintList(head);//��ӡ����

	//ChangNode(head,5);//�޸������е�5���ڵ��ֵ
	//PrintList(head);

	//deleteNode(head, 3);//ɾ���ڵ�
	//PrintList(head);

	//searchNode(head,6);//����ֵΪ2�Ľڵ�

	//deleteData(head,4);//ɾ��ֵΪ4�Ľڵ�
	//PrintList(head);

	//List* new=reverseList(head);//
	//PrintList(new);

	List* new=copyList(head);
	PrintList(new);

	return 0;
}