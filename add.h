void write1();//д�� ���
	void write2();//д���
	bool check(int id);
};

bool Manage::addVertex()
{
	
	Vertex a;
	cout << "������Ҫ��ӽ��ı�ţ�" << endl;
	cin >> a.id;
	cout << "������Ҫ��ӽ������ƣ�" << endl;
	cin >> a.name;
	Route.insertVertex(a);
	write1();
}
void Manage::write1()
{
	ofstream infile("C:\\Users\\lenovo\\Desktop\\vertex.txt");
	infile.open("C:\\Users\\lenovo\\Desktop\\vertex.txt");
	for (int i = 0; i < Route.NumberOfVertices; i++)
	{
		infile << Route.NodeTable[i].name << ' ' << Route.NodeTable[i].id << '\n';
	}
	infile.close();
}
bool Manage::addEdge()
{
	int b, c;
	double cost;
	cout << "������Ҫ��ӱߵĽ��1�ı�ţ�" << endl;
	cin >> b;
	cout << "������Ҫ��ӵıߵĽ��2�ı�ţ�" << endl;
	cin >> c;
	if (!check(b)||!check(c))
	{
		return false;
	}
	cout << "������ߵ�Ȩֵ��" << endl;
	cin >> cost;
	Route.insertEdge(b, c, cost);
	write2();
}
void Manage::write2()
{
	ofstream infile("C:\\Users\\lenovo\\Desktop\\vertex.txt");
	infile.open("C:\\Users\\lenovo\\Desktop\\vertex.txt");
	for (int i = 0; i < Route.NumberOfVertices; i++)
	{
		infile << Route.NodeTable[i].name << ' ';
		Edge *current = Route.NodeTable[i].adj;
		while (current != NULL)
		{
			infile << Route.NodeTable[i].adj->dest <<' '<< current->dest<<' ' << current->cost<<'\n';
		}
	}
	infile.close();
}
bool Manage::check(int id)
{
	if (!Route.getVertexPos(id))
	{
		cout << "·�ɱ������޸ý�㣡\n";
		cout << "�Ƿ���Ӹý�㣿\n";
		cout << "1.��      2.��";
		int ans;
		cin >> ans;
		switch (ans)
		{
		default:return;
		case 1: {
			Vertex a;
			a.id = id;
			cout << "������Ҫ��ӽ������ƣ�" << endl;
			cin >> a.name;
			Route.insertVertex(a);
			write1();
		}break;
		case 2:return false;
		}
	}
	return true;
}