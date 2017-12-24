void write1();//写入 结点
	void write2();//写入边
	bool check(int id);
};

bool Manage::addVertex()
{
	
	Vertex a;
	cout << "请输入要添加结点的编号：" << endl;
	cin >> a.id;
	cout << "请输入要添加结点的名称：" << endl;
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
	cout << "请输入要添加边的结点1的编号：" << endl;
	cin >> b;
	cout << "请输入要添加的边的结点2的编号：" << endl;
	cin >> c;
	if (!check(b)||!check(c))
	{
		return false;
	}
	cout << "请输入边的权值：" << endl;
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
		cout << "路由表中尚无该结点！\n";
		cout << "是否添加该结点？\n";
		cout << "1.是      2.否";
		int ans;
		cin >> ans;
		switch (ans)
		{
		default:return;
		case 1: {
			Vertex a;
			a.id = id;
			cout << "请输入要添加结点的名称：" << endl;
			cin >> a.name;
			Route.insertVertex(a);
			write1();
		}break;
		case 2:return false;
		}
	}
	return true;
}