#include "Graph.h"

/*----------------------------------------------LAB_1----------------------------------------------*/

/*-----------------------Меню-----------------------*/
void Graph::graph_menu()
{
	// Создаем необходимые текстовые файлы
	FILE *file = fopen("ad_list.txt", "w");
	fclose(file);
	file = fopen("data.txt", "a");
	fclose(file);
	file = fopen("ad_matrix.txt", "w");
	fclose(file);
	file = fopen("in_matrix.txt", "w");
	fclose(file);

	cout << "\n -1) Завершение работы\n 1) Создание графа\n 2) Определение числа вершин\n 3) Определение числа ребер\n 4) Определение степени вершины";
	cout << "\n 5) Определение степенной последовательности\n 6) Определение матрицы смежности\n 7) Определение матрицы инцидентности";
	cout << "\n 8) Определение списка смежности\n 9) Определение изолированных и висячих вершин\n 10) Определение истоков и стоков";
	cout << "\n 11) Определение расстояния между вершинами\n 12) Определение эксцентриситета вершины\n 13) Определение диаметра и радиуса графа";
	cout << "\n 14) Определение центра графа\n 15) Определение периферийных вершин\n 16) Добавление вершины";
	cout << "\n 17) Удаление вершины\n 18) Добавление ребра\n 19) Удаление ребра\n 20) Определение дополнения графа";
	cout << "\n 21) Подразбиение ребра\n 22) Стягивание графа\n 23) Отождествление вершин\n 24) Размножение вершины";
	cout << "\n 25) Дублирование вершины\n 26) Объединение графов\n 27) Соединение графов\n 28) Произведение графов";
	cout << "\n 29) Поиск в глубину\n 30) Поиск в ширину\n 31) Алгоритм Краскала\n 32) Алгоритм Дейкстры\n 33) Сетевое планирование\n 34) Алгоритм Эдмондса — Карпа\n";

	while (1)
	{
		close.clear();
		data.clear();
		cout << "\n# ";
		char c[10] = { 0 };
		gets_s(c, 10);
		if (!strcmp(c, "0"))
		{
			cout << "\n 1) Создание графа\n 2) Определение числа вершин\n 3) Определение числа ребер\n 4) Определение степени вершины";
			cout << "\n 5) Определение степенной последовательности\n 6) Определение матрицы смежности\n 7) Определение матрицы инцидентности";
			cout << "\n 8) Определение списка смежности\n 9) Определение изолированных и висячих_вершин\n 10) Определение истоков и стоков";
			cout << "\n 11) Определение расстояния между вершинами\n 12) Определение эксцентриситета вершины\n 13) Определение диаметра и радиуса графа";
			cout << "\n 14) Определение центра графа\n 15) Определение периферийных вершин\n 16) Добавление вершины";
			cout << "\n 17) Удаление вершины\n 18) Добавление ребра\n 19) Удаление ребра\n 20) Определение дополнения графа";
			cout << "\n 21) Подразбиение ребра\n 22) Стягивание графа\n 23) Отождествление вершин\n 24) Размножение вершины";
			cout << "\n 25) Дублирование вершины\n 26) Объединение графов\n 27) Соединение графов\n 28) Произведение графов";
			cout << "\n 29) Выход\n 0) Помощь\n";
		}
		else if (!strcmp(c, "1")) create_graph();
		else if (!strcmp(c, "2")) cout << "Число вершин: " << get_vertex_number() << endl;
		else if (!strcmp(c, "3")) cout << "Число ребер: " << get_edge_number() << endl;
		else if (!strcmp(c, "4"))
		{
			char a[10] = { 0 };
			cout << "\nВведите номер вершины # ";
			gets_s(a, 10);
			get_vertex_degree(atoi(a));
		}
		else if (!strcmp(c, "5")) get_power_sequence();
		else if (!strcmp(c, "6")) get_adjacency_matrix();
		else if (!strcmp(c, "7")) get_incidence_matrix();
		else if (!strcmp(c, "8")) get_adjacency_list();
		else if (!strcmp(c, "9")) get_isolated_and_hanging_vertex();
		else if (!strcmp(c, "10")) get_sources_and_drains();
		else if (!strcmp(c, "11"))
		{
			int num = 0;
			char a[10] = { 0 };
			cout << "\nВведите номер первой вершины # ";
			gets_s(a, 10);
			cout << "\n";
			char b[10] = { 0 };
			cout << "\nВведите номер второй вершины # ";
			gets_s(b, 10);
			if (atoi(a) == atoi(b))
				cout << "Расстояние: 0";
			else
			{
				num = get_distance(atoi(a), atoi(b), 0);
				if (num == 0) cout << "Расстояние: inf";
				else cout << "Расстояние: " << num;

			}
		}
		else if (!strcmp(c, "12"))
		{
			char a[10] = { 0 };
			cout << "\nВведите номер вершины # ";
			gets_s(a, 10);
			cout << "Эксцентриситет: " << get_eccentricity(atoi(a)) << endl;
		}
		else if (!strcmp(c, "13"))
		{
			get_diameter_and_radius();
			cout << "\n Диаметр: " << diameter << "\n Радиус: " << radius << endl;
		}
		else if (!strcmp(c, "14")) get_center();
		else if (!strcmp(c, "15")) get_peripheral();
		else if (!strcmp(c, "16"))
		{
			char a[10] = { 0 };
			cout << "\nВведите номер вершины # ";
			gets_s(a, 10);
			add_vertex(atoi(a));
		}
		else if (!strcmp(c, "17"))
		{
			char a[10] = { 0 };
			cout << "\nВведите номер вершины # ";
			gets_s(a, 10);
			remove_vertex(atoi(a));
		}
		else if (!strcmp(c, "18"))
		{
			char b[10] = { 0 };
			cout << "\nВведите номер первой вершины # ";
			gets_s(b, 10);
			cout << "\n";
			char g[10] = { 0 };
			cout << "\nВведите номер второй вершины # ";
			gets_s(g, 10);
			cout << "\n";
			add_edge(get_free(1), atoi(b), atoi(g));
		}
		else if (!strcmp(c, "19"))
		{
			char b[10] = { 0 };
			cout << "\nВведите номер первой вершины # ";
			gets_s(b, 10);
			cout << "\n";
			char g[10] = { 0 };
			cout << "\nВведите номер второй вершины # ";
			gets_s(g, 10);
			cout << "\n";
			remove_edge(0, atoi(b), atoi(g));
		}
		else if (!strcmp(c, "20")) get_complement_graph();
		else if (!strcmp(c, "21"))
		{
			char a[10] = { 0 };
			cout << "\nВведите номер ребра # ";
			gets_s(a, 10);
			undercutting(atoi(a));
		}
		else if (!strcmp(c, "22")) retraction(false);
		else if (!strcmp(c, "23")) retraction(true);
		else if (!strcmp(c, "24"))
		{
			char a[10] = { 0 };
			cout << "\nВведите номер вершины # ";
			gets_s(a, 10);
			duplication(atoi(a), true);
		}
		else if (!strcmp(c, "25"))
		{
			char a[10] = { 0 };
			cout << "\nВведите номер вершины # ";
			gets_s(a, 10);
			duplication(atoi(a), false);
		}
		else if (!strcmp(c, "26")) merger();
		else if (!strcmp(c, "27")) connection();
		else if (!strcmp(c, "28")) multiplication();
		else if (!strcmp(c, "29"))
		{
			char b[10] = { 0 };
			cout << "\nВведите номер вершины # ";
			gets_s(b, 10);
			DFS(atoi(b));
		}
		else if (!strcmp(c, "30"))
		{
			char b[10] = { 0 };
			cout << "\nВведите номер вершины # ";
			gets_s(b, 10);
			BFS(atoi(b));

			// Убираем информацию о посещении
			vector <vertex_data> ::iterator it = Vertex.begin();
			for (size_t i = 0; i < Vertex.size(); i++)
				it[i].visited = false;
		}
		else if (!strcmp(c, "31")) Kruskal();
		else if (!strcmp(c, "32"))
		{
			char b[10] = { 0 };
			cout << "\nВведите номер первой вершины # ";
			gets_s(b, 10);
			cout << "\n";
			char g[10] = { 0 };
			cout << "\nВведите номер второй вершины # ";
			gets_s(g, 10);
			cout << "\n";
			Dijkstra_algorithm(atoi(b), atoi(g));
		}
		else if (!strcmp(c, "33"))
		{
			char b[10] = { 0 };
			cout << "\nВведите T # ";
			gets_s(b, 10);
			cout << "\n";
			network_planning(atoi(b));
		}
		else if (!strcmp(c, "34")) Edmonds_Karp_algorithm();
		else if (!strcmp(c, "-1")) exit(0);
	}
}

/*-----------------------Создание_графа-----------------------*/
void Graph::create_graph()
{
	cout << "В каком виде задается Граф:\n 1) Список смежности\n 2) Матрица смежности\n 3) Матрица инцидентности\n 4) Матрица весов\n" << endl;
	char c;
	
	while (1)
	{
		cout << "Выберите номер: # ";
		cin >> c;
		if (c == '1' || c == '2' || c == '3' || c == '4') // В файле список смежности
			break;
		else
			cout << "ОШИБКА: Введите 1, 2 или 3\n" << endl;
	}
	
	cout << "\nГраф ориентированный 1 - да, 2 - нет: # ";
	char o;
	cin >> o;
	if (o == '1') oriented = true;
	else oriented = false;

	ifstream fin("data.txt"); // Открываем файл для чтения

	if (!fin.is_open())
	{
		cout << "Невозможно открыть файл data.txt";
		return;
	}

	char buff[1000] = { 0 };
	fin.read(buff, 1000); // Считываем
	
	string str = string(buff);
	string sub;
	fin.close();

	if (c == '1') // Список смежности
	{
		int open = 0;
		while (1)
		{
			open = str.find('{', open);
			if (open != -1)
			{
				int close = str.find('}', open) - 1;
				sub = str.substr(open + 1, str.find('}', open) - 1);

				// Создаем узел вершины
				// Проверяем есть ли у нее смежные вершины
				bool one_number;
				if (sub.find(' ', 0) == -1) one_number = true;
				else one_number = false;

				string number = sub.substr(0, sub.find(' ', 0));

				vertex_data ver;
				int num = atoi(number.c_str());
				vector <vertex_data> ::iterator it;
				int father = 0;

				if (Vertex.size() > 0) // Если существуют узлы
				{
					it = Vertex.begin();
					bool find = false;
					for (size_t i = 0; i < Vertex.size(); i++) // В поисках нашего узла
					{
						if (num == it[i].number)
						{
							find = true;
							father = i;
							break;
						}
					}

					// Узел не был найден, создаем с конца и записываем его номер в father
					if (find == false)
					{
						struct vertex_data ver;
						ver.number = num;
						Vertex.push_back(ver);
						father = Vertex.size() - 1;
					}
				}
				else // Иначе создаем новый
				{
					struct vertex_data ver;
					ver.number = num;
					Vertex.push_back(ver);
					father = Vertex.size() - 1;

				}

				sub = sub.substr(sub.find(' ', 0) + 1, sub.length());

				while (1) // Проходим по всем числам и записываем их в массив
				{
					if (one_number == true) break;
					number = sub.substr(0, sub.find(' ', 0));

					int son = 0;
					num = atoi(number.c_str());
					bool find = false;
					it = Vertex.begin();
					for (size_t i = 0; i < Vertex.size(); i++) // Ищем совпадение по номеру
					{
						if (num == it[i].number)
						{
							find = true;
							son = i;
							break;
						}
					}
					if (find == false)
					{
						vertex_data dummy;
						dummy.number = num;
						Vertex.push_back(dummy);
						son = Vertex.size() - 1;
					}

					it = Vertex.begin();

					// После создания узлов, записываем для них ребра, так же запись идет в вектор Edge
					if (oriented == true) // Если граф ориентированный то добавляем не раздумывая
					{
						edge_data edge;
						edge.A_vertex = it[father].number;
						edge.B_vertex = it[son].number;
						edge.number = Edge.size() + 1;
						Edge.push_back(edge);

						it[father].edge.push_back(edge.number);
						it[son].edge.push_back(edge.number);
					}
					else if (if_ad_2(it[son].number, it[father].number) == false) // Иначе смотрим есть ли ребро, где son является A, т.е. были ли созданы ребра ранее
					{
						edge_data edge;
						edge.A_vertex = it[father].number;
						edge.B_vertex = it[son].number;
						edge.number = Edge.size() + 1;
						Edge.push_back(edge);

						it[father].edge.push_back(edge.number);
						it[son].edge.push_back(edge.number);
					}

					if (sub.find(' ', 0) == -1) break;
					sub = sub.substr(sub.find(' ', 0) + 1, sub.length());
					if (sub.length() == 0) break;
				}
				open = 0;
				str = str.substr(close + 2, str.length());
			}
			else break;
		}
	}
	else if (c == '2') // Матрица смежности обязательно \n в конце
	{
		// Создаем вершину под номером 1, и попутно создаем новые вершины и добавляем к ним ребра пока не дойдем до \n
		// Затем тоже самое выполняем циклом увеличивая счетчик пока не дойдем до конца 

		int num = 1; // Номер вершины
		int count = 0; // Количество всех вершин
		add_vertex(num); // Создаем первую вершину
		int a = 0; // Номер откуда отрезаем
		int b = 0;
		int n = 0;
		int g = 0;
		int y = 0;

		// Подсчитали количество переходов
		str.push_back('\0');
		for (int i = 0; i < str.length(); i++) 
			if (str[i] == '\n')
			{
				count++;
				add_vertex(count); // Создаем новую вершину
				g++;
			}

		while (1) // Создаем остальные вершины и ребра
		{
			a = str.find_first_not_of(' ', 0); // Находим первый не пробел
			b = str.find_first_of(" \n", a + 1)+1; // Находим первый пробел

			sub = str.substr(a, b - 1);
			y++; // Переходим на рассмотр следующего y

			//cout << sub << " ";

			int ed_num = atoi(sub.c_str());
			if (ed_num > 0 && y == num) // Петля или несколько петель
			{
				while (1)
				{
					add_edge(get_free(1), num, y);
					ed_num -= 2; // Отнимаем двоичку
					Edge;
					if (ed_num == 0) break;
				}
			}
			else if (ed_num > 0) // Если ребро
			{
				if (oriented == true) // Если граф ориентированный то не задумываясь добавляем ребра
				{
					while (1)
					{
						add_edge(get_free(1), num, y);
						ed_num -= 1;
						if (ed_num == 0) break;
					}
				}
				else if (if_ad(num, y) == false) // В противном случае, добавляем ребра если между вершинами еще нет ребер
				{
					while (1)
					{
						add_edge(get_free(1), num, y);
						ed_num -= 1;
						if (ed_num == 0) break;
					}
				}
			}

			n = 0;
			for (int i = 0; i < str.length(); i++) 
				if (str[i] == '\n') 
					n++;
			if (n == 0) 
				break;
			n = 0;

			str = str.substr(b, str.length()); // Вместе с пробелом после отрезаем

			for (size_t i = 0; i < str.length(); i++) 
				if (str[i] == '\n') 
					n++;

			if (n < g)
			{
				n = 0;
				y = 0;
				g--; // так же уменьшаем значение g
				if (g == 0) break;
				num++; // рассматриваем следующую вершину
				//cout << '\n';
			}
		}
	}
	else if (c == '3') // Матрица инцидентности
	{
		// Создаем матрицу
		// Количество вершин определяем количеством пробелов в первой строке
		// количество вершин количеством \n
		// обрабатываем как бы вершины

		int count = 0; // Количество всех вершин
		int g = 0;
		int b = 0;
		int e = 0;


		str.push_back('\0');
		for (int i = 0; i < str.length(); i++) // Подсчитываем и создаем новые вершины
			if (str[i] == '\n')
			{
				count++;
				add_vertex(count); // Создаем новую вершину
				g++;
			}

		b = str.find_first_of("\n", 0) + 1; // Находим первый переход
		sub = str.substr(0, b);

		for (int i = 0; i < sub.length(); i++)
			if (sub[i] == ' ')
				e++;
		e += 1;

		vector<vector<int>> matrix(count); // Матрица инцидентности
		for (int i = 0; i < count; i++) // Создаем матрицу
			matrix[i].resize(e);

		for (int i = 0; i < count; i++)
			for (int j = 0; j < e; j++)
				matrix[i][j] = 0;
		
		// matrix[вершины][ребра]
		int a = 0;
		int y = 0;
		int n = 0;
		int num = 0;
		int dummy = 0;
		while (1) // Заполняем матрицу
		{
			dummy++;
			a = str.find_first_not_of(' ', 0); // Находим первый не пробел
			b = str.find_first_of(" \n", a + 1) + 1; // Находим первый пробел

			sub = str.substr(a, b - 1);

			//cout << sub << " ";

			int ed_num = atoi(sub.c_str());
			//cout << ed_num << ' ';
			matrix[num][y] = ed_num;

			y++; // Переходим на рассмотр следующего y

			n = 0;
			for (int i = 0; i < str.length(); i++)
				if (str[i] == '\n')
					n++;
			if (n == 0)
				break;
			n = 0;

			str = str.substr(b, str.length()); // Вместе с пробелом после отрезаем

			for (int i = 0; i < str.length(); i++)
				if (str[i] == '\n')
					n++;

			if (n < g)
			{
				n = 0;
				y = 0;
				g--; // так же уменьшаем значение g
				if (g == 0) break;
				num++; // рассматриваем следующую вершину
				//cout << '\n';
			}
		}

		// Проходим по матрице и создаем ребра 
		int A = -1, B = -1, pair = 0; // Если равно 1 то записываем в A смотрим на пару
		for (int j = 0; j < e; j++)
		{
			for (int i = 0; i < count; i++)
			{
				if (matrix[i][j] == 1)
				{
					if (oriented == true) // Если орграф
					{
						A = i + 1;
						pair++;
					}
					else // В противном случае
					{
						if (A == -1)
						{
							A = i + 1;
							pair++;
						}
						else if (B == -1)
						{
							B = i + 1;
							pair++;
						}
					}
				}
				else if (matrix[i][j] == -1)
				{
					B = i + 1;
					pair++;
				}
				else if (matrix[i][j] == 2)
				{
					A = i + 1;
					pair = 1;
				}
			}
			if (pair == 2)
				add_edge(j + 1, A, B);
			else add_edge(j + 1, A, A); // Петля
			pair = 0;
			A = -1;
			B = -1;
		}

	}
	else if (c == '4')
	{
		// Создаем вершину под номером 1, и попутно создаем новые вершины и добавляем к ним ребра пока не дойдем до \n
		// Затем тоже самое выполняем циклом увеличивая счетчик пока не дойдем до конца 

		int num = 1; // Номер вершины
		int count = 0; // Количество всех вершин
		add_vertex(num); // Создаем первую вершину
		int a = 0; // Номер откуда отрезаем
		int b = 0;
		int n = 0;
		int g = 0;
		int y = 0;

		// Подсчитали количество переходов
		str.push_back('\0');
		for (int i = 0; i < str.length(); i++)
			if (str[i] == '\n')
			{
				count++;
				add_vertex(count); // Создаем новую вершину
				g++;
			}

		while (1) // Создаем ребра
		{
			if (oriented == false)
			{
				a = str.find_first_not_of(' ', 0); // Находим первый не пробел
				b = str.find_first_of(" \n", a + 1) + 1; // Находим первый пробел

				sub = str.substr(a, b - 1);
				y++; // Переходим на рассмотр следующего y

				int ed_num = atoi(sub.c_str());

				if (ed_num != 0 && if_ad(num, y) == false) // Если не ноль, то есть ребро
				{
					add_edge(get_free(1), num, y);
					Edge.at(Edge.size() - 1).weight = ed_num;
				}

				n = 0;
				for (int i = 0; i < str.length(); i++)
					if (str[i] == '\n')
						n++;
				if (n == 0)
					break;
				n = 0;

				str = str.substr(b, str.length()); // Вместе с пробелом после отрезаем

				for (int i = 0; i < str.length(); i++)
					if (str[i] == '\n')
						n++;

				if (n < g)
				{
					n = 0;
					y = 0;
					g--; // так же уменьшаем значение g
					if (g == 0) break;
					num++; // рассматриваем следующую вершину
						   //cout << '\n';
				}
			}
			else // Граф ориентированный
			{
				a = str.find_first_not_of(' ', 0); // Находим первый не пробел
				b = str.find_first_of(" \n", a + 1) + 1; // Находим первый пробел

				sub = str.substr(a, b - 1);
				y++; // Переходим на рассмотр следующего y

				int ed_num = atoi(sub.c_str());

				if (ed_num != 0)
				{
					add_edge(get_free(1), num, y);
					Edge.at(Edge.size() - 1).weight = ed_num;
				}

				n = 0;
				for (int i = 0; i < str.length(); i++)
					if (str[i] == '\n')
						n++;
				if (n == 0)
					break;
				n = 0;

				str = str.substr(b, str.length()); // Вместе с пробелом после отрезаем

				for (int i = 0; i < str.length(); i++)
					if (str[i] == '\n')
						n++;

				if (n < g)
				{
					n = 0;
					y = 0;
					g--; // так же уменьшаем значение g
					if (g == 0) break;
					num++; // рассматриваем следующую вершину
						   //cout << '\n';
				}
			}
		}
	}
}

/*-----------------------Определение_числа_вершин-----------------------*/
int Graph::get_vertex_number()
{
	return Vertex.size();
}

/*-----------------------Определение_числа_ребер-----------------------*/
int Graph::get_edge_number()
{
	return Edge.size();
}

/*-----------------------Определение_степени_вершины-----------------------*/
void Graph::get_vertex_degree(int number)
{
	vector <vertex_data> :: iterator it = Vertex.begin();
	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
	{
		if (it[i].number == number) // Нашли совпадение 
		{
			if (oriented == false) // Не ориентированный граф
				cout << "Степень вершины: " << it[i].edge.size() << endl;
			else // Ориентированный граф
			{
				vector <edge_data> :: iterator it_2 = Edge.begin();
				int in = 0, out = 0;
				for (size_t j = 0; j < Edge.size(); j++) // Проходим по всем ребрам
				{
					if (it_2[j].A_vertex == it[i].number)
						out++;
					else if (it_2[j].B_vertex == it[i].number)
						in++;
				}
				cout << "Полустепень исхода: " << out << "\nПолустепень захода: " << in << endl;
			}
			return;
		}
	}
	return;
}

/*-----------------------Определение_степенной_последовательности-----------------------*/
void Graph::get_power_sequence()
{
	if (oriented == false)
	{
		vector <vertex_data> ::iterator it = Vertex.begin();
		vector <int> dummy;
		vector <int> ::iterator it_2;
		for (size_t i = 0; i < Vertex.size(); i++)
			dummy.push_back(it[i].edge.size());
		sort(dummy.begin(), dummy.end());
		it_2 = dummy.begin();
		cout << "Степенная последовательность: ";
		for (size_t j = 0; j < dummy.size(); j++)
			cout << it_2[j] << ' ';
		cout << '\n';
	}
	else // Если ориентированный граф
	{
		vector <vertex_data> ::iterator ver_it = Vertex.begin();
		vector <int> in;
		vector <int> out;
		vector <int> ::iterator it;

		for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
		{
			in.push_back(get_in_out(ver_it[i].number, true)); // Получаем полустепень захода
			out.push_back(get_in_out(ver_it[i].number, false)); // Полустепень исхода
		}

		sort(in.begin(), in.end());
		sort(out.begin(), out.end());

		cout << "Полустепени исхода: ";
		for (size_t i = 0; i < out.size(); i++)
			cout << out[i] << ' ';
		cout << '\n';
		cout << "Полустепени захода: ";
		for (size_t i = 0; i < in.size(); i++)
			cout << in[i] << ' ';
		cout << '\n';

	}
}

/*-----------------------Определение_матрицы_смежности-----------------------*/
void Graph::get_adjacency_matrix()
{
	vector<vector<int>> adjacency_matrix(Vertex.size()); // Матрица смежности
	for (size_t i = 0; i < Vertex.size(); i++) // Создаем матрицу
		adjacency_matrix[i].resize(Vertex.size());

	vector <vertex_data> ::iterator it;
	vector <edge_data> ::iterator it_2;
	vector <int> dummy;
	vector <int> ::iterator it_3;

	it = Vertex.begin();
	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
		dummy.push_back(it[i].number); // Готовим к сортировке вершины

	sort(dummy.begin(), dummy.end()); // Получили отсортированный массив номеров вершин

	it = Vertex.begin();
	it_3 = dummy.begin();

	for (size_t i = 0; i < dummy.size(); i++) // Прописываем для каждой вершины ее номер в матрице
	{
		for (size_t j = 0; j < Vertex.size(); j++) // Проходим по всем вершинам в поисках совпадения
		{
			if (it_3[i] == it[j].number)
			{
				it[j].adjacency_num = i; // Записываем в узел номер места в матрице
				break;
			}
		}
	}

	// Производим запосление матрицы нулями
	for (size_t i = 0; i < Vertex.size(); i++)
	{
		for (size_t j = 0; j < Vertex.size(); j++)
		{
			adjacency_matrix[i][j] = 0;
		}
	}

	it_2 = Edge.begin();

	for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
	{
		if (oriented == true) // Если граф ориентированный
		{
			for (size_t j = 0; j < dummy.size(); j++) // Проходим по всем вершинам
			{
				if (it_2[i].A_vertex == it_3[j]) // Нашли совпадение источника
				{
					if (it_2[i].A_vertex == it_2[i].B_vertex) // Если петля
					{
						adjacency_matrix[j][j] += 2;
					}
					else
					{
						adjacency_matrix[j][get_pos(it_2[i].B_vertex, 1)] += 1;
					}
					break;
				}
			}
		}
		else // В противном случае плюсуем и началу и концу даже если это ребро 
		{
			adjacency_matrix[get_pos(it_2[i].A_vertex, 1)][get_pos(it_2[i].B_vertex, 1)] += 1;
			adjacency_matrix[get_pos(it_2[i].B_vertex, 1)][get_pos(it_2[i].A_vertex, 1)] += 1;
		}
	}

	out.open("ad_matrix.txt"); // Открываем файл для записи

	out << "Номера вершин: ";
	for (size_t i = 0; i < dummy.size(); i++)
		out << it_3[i] << ' ';
	out << "\n\n";

	for (size_t i = 0; i < Vertex.size(); i++)
	{
		for (size_t j = 0; j < Vertex.size(); j++)
		{
			out << adjacency_matrix[i][j] << ' ';
		}
		out << '\n';
	}
	out.close();
}

/*-----------------------Определение_матрицы_инцидентности-----------------------*/
void Graph::get_incidence_matrix()
{
	vector<vector<int>> incidence_matrix(Vertex.size()); // Матрица инцидентности
	for (size_t i = 0; i < Vertex.size(); i++) // Создаем матрицу
		incidence_matrix[i].resize(Edge.size());

	vector <vertex_data> ::iterator it;
	vector <edge_data> ::iterator it_2;
	vector <int> dummy;
	vector <int> dummy_2;
	vector <int> ::iterator it_3; // Для dummy
	vector <int> ::iterator it_4; // Для dummy_2

	it = Vertex.begin();
	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
		dummy.push_back(it[i].number); // Готовим к сортировке вершины

	it_2 = Edge.begin();
	for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
		dummy_2.push_back(it_2[i].number); // Готовим к сортировке ребра

	sort(dummy.begin(), dummy.end()); // Получили отсортированный массив номеров вершин
	sort(dummy_2.begin(), dummy_2.end()); // Получили отсортированный массив номеров ребер

	it = Vertex.begin();
	it_3 = dummy.begin();

	for (size_t i = 0; i < dummy.size(); i++) // Прописываем для каждой вершины ее номер в матрице
	{
		for (size_t j = 0; j < Vertex.size(); j++) // Проходим по всем вершинам в поисках совпадения
		{
			if (it_3[i] == it[j].number)
			{
				it[j].adjacency_num = i; // Записываем в узел номер места в матрице
				break;
			}
		}
	}

	it_2 = Edge.begin();
	it_4 = dummy_2.begin();

	for (size_t i = 0; i < dummy_2.size(); i++) // Прописываем для каждого ребра его номер в матрице
	{
		for (size_t j = 0; j < Edge.size(); j++) // Проходим по всем ребрам в поисках совпадения
		{
			if (it_4[i] == it_2[j].number)
			{
				it_2[j].incidence_num = i; // Записываем в узел номер места в матрице
				break;
			}
		}
	}

	// Производим запосление матрицы нулями
	for (size_t i = 0; i < Vertex.size(); i++)
	{
		for (size_t j = 0; j < Edge.size(); j++)
		{
			incidence_matrix[i][j] = 0;
		}
	}

	it_2 = Edge.begin();

	for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
	{
		if (oriented == true) // Если граф ориентированный
		{
			incidence_matrix[get_pos(it_2[i].A_vertex, 1)][it_2[i].incidence_num] += 1;
			incidence_matrix[get_pos(it_2[i].B_vertex, 1)][it_2[i].incidence_num] -= 1;
		}
		else
		{
			incidence_matrix[get_pos(it_2[i].A_vertex, 1)][it_2[i].incidence_num] += 1;
			incidence_matrix[get_pos(it_2[i].B_vertex, 1)][it_2[i].incidence_num] += 1;
		}
	}

	out.open("in_matrix.txt"); // Открываем файл для записи

	out << "Номера вершин: ";
	for (size_t i = 0; i < dummy.size(); i++)
		out << it_3[i] << ' ';
	out << "\n";
	out << "Номера ребер: ";
	for (size_t i = 0; i < dummy_2.size(); i++)
		out << it_4[i] << ' ';
	out << "\n\n";

	for (size_t i = 0; i < Vertex.size(); i++)
	{
		for (size_t j = 0; j < Edge.size(); j++)
		{
			out << incidence_matrix[i][j] << ' ';
		}
		out << '\n';
	}
	out.close();
}

/*-----------------------Определение_списка_смежности-----------------------*/
void Graph::get_adjacency_list()
{
	vector <vertex_data> ::iterator ver_it  = Vertex.begin();
	vector <edge_data> ::iterator ed_it = Edge.begin();
	vector <int> ::iterator dummy_it;
	out.open("ad_list.txt"); // Открываем файл для записи
	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
	{
		out << "{" << ver_it[i].number;
		dummy_it = ver_it[i].edge.begin();
		for (size_t j = 0; j < ver_it[i].edge.size(); j++) // Просматриваем все ребра этой вершины 
		{
			for (size_t k = 0; k < Edge.size(); k++) // Попутно сравнивая со всеми существующими ребрами
			{
				if (dummy_it[j] == ed_it[k].number) // Нашли ребро среди всех ребер
				{
					if (oriented == true) // Если граф ориентированный
					{
						if (ed_it[k].A_vertex == ver_it[i].number) // Наша вершина - источник
							out << ' ' << ed_it[k].B_vertex;
					}
					else
					{
						if (ed_it[k].A_vertex == ver_it[i].number)
							out << ' ' << ed_it[k].B_vertex;
						else
							out << ' ' << ed_it[k].A_vertex;
					}
				}
			}
		}
		out << "}";
	}
	out.close(); // Не забываем закрывать за собой
}

/*-----------------------Определение_изолированных_и_висячих_вершин-----------------------*/
void Graph::get_isolated_and_hanging_vertex()
{
	cout << "Изолированные вершины: ";
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем узлам
	{
		if (ver_it[i].edge.size() == 0)
			cout << ver_it[i].number << ' ';
	}
	cout << '\n';

	cout << "Висячие вершины: ";
	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем узлам
	{
		if (ver_it[i].edge.size() == 1)
			cout << ver_it[i].number << ' ';
	}
	cout << '\n';
}

/*-----------------------Определение_истоков_и_стоков-----------------------*/
void Graph::get_sources_and_drains()
{
	cout << "Истоки: ";
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	vector <edge_data> ::iterator ed_it = Edge.begin();
	vector <int> ::iterator dummy_it;

	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем узлам
	{
		dummy_it = ver_it[i].edge.begin();
		int in = 0, out = 0; 
		for (size_t j = 0; j < ver_it[i].edge.size(); j++) // Просматриваем все ребра этой вершины 
		{
			for (size_t k = 0; k < Edge.size(); k++) // Попутно сравнивая со всеми существующими ребрами
			{
				if (dummy_it[j] == ed_it[k].number) // Нашли ребро среди всех ребер
				{
					if (ed_it[k].A_vertex == ver_it[i].number) // Наша вершина источник для этого ребра
						out++;
					else in++; // Или сток
				}
			}
		}
		// После просмотра всех ребер можем делать вывод о вершине 
		if (in == 0 && out != 0)
			cout << "Исток: " << ver_it[i].number << endl;
		else if (in != 0 && out == 0)
			cout << "Сток: " << ver_it[i].number << endl;
	}
}

/*-----------------------Определение_расстояния_между_вершинами-----------------------*/
int Graph::get_distance(int A, int B, int dis)
{
	if (A == B) return dis; // Мы нашли 
	vector <edge_data> ::iterator ed_it = Edge.begin();
	bool stuck = true;
	vector <int> ::iterator it = close.begin();
	bool find = false;

	for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам и смотрим где вешрина А будет источником
	{
		if (oriented == true)
		{
			if (ed_it[i].A_vertex == A) // Нашли одно из ребер с началом в А
			{
				if (close.size() != 0) // Если у нас есть список вершин куда нам нельзя
				{
					for (size_t j = 0; j < close.size(); j++) // Проходим по этому списку
					{
						it = close.begin();
						if (ed_it[i].B_vertex == it[j]) // Нашли совпадение, не рассматриваем
						{
							find = true;
							break;
						}
					}
				}
				if (find == true)
				{
					find = false;
					continue;
				}
				close.push_back(A);
				int result = get_distance(ed_it[i].B_vertex, B, dis + 1);
				close.pop_back();
				data.push_back(result); // Записываем овет
				stuck = false;
				//if (dis == 1)break;
			}
		}
		else // Граф неориентированный
		{
			if (ed_it[i].A_vertex == A) // Нашли одно из ребер с началом в А
			{
				if (close.size() != 0) // Если у нас есть список вершин куда нам нельзя
				{
					for (size_t j = 0; j < close.size(); j++) // Проходим по этому списку
					{
						it = close.begin();
						if (ed_it[i].B_vertex == it[j]) // Нашли совпадение, не рассматриваем
						{
							find = true;
							break;
						}
					}
				}
				if (find == true)
				{
					find = false;
					continue;
				}
				close.push_back(A);
				int result = get_distance(ed_it[i].B_vertex, B, dis + 1);
				close.pop_back();
				//if (result != 0) dis = result;
				data.push_back(result); // Записываем овет
				stuck = false;
				//if (dis == 1)break;
			}
			if (ed_it[i].B_vertex == A) // Если не орграф, то рассматриваем вариант с другого конца
			{
				if (close.size() != 0) // Если у нас есть список вершин куда нам нельзя
				{
					for (size_t j = 0; j < close.size(); j++) // Проходим по этому списку
					{
						it = close.begin();
						if (ed_it[i].A_vertex == it[j]) // Нашли совпадение, не рассматриваем
						{
							find = true;
							break;
						}
					}
				}
				if (find == true)
				{
					find = false;
					continue;
				}
				close.push_back(A);
				int result = get_distance(ed_it[i].A_vertex, B, dis + 1);
				close.pop_back();
				//if (result != 0) dis = result;
				data.push_back(result); // Записываем овет
				stuck = false;
				//if (dis == 1)break;
			}
		}
	}

	if (stuck == true) // Если мы дошли до листа
		return 0;
	else
	{
		// Просматриваем все полученные значения
		sort(data.begin(), data.end());
		vector <int> ::iterator it = data.begin();
		for (size_t i = 0; i < data.size(); i++)
			if (it[i] != 0)
			{
				int ret = it[i];
				data.clear();
				return ret; // Первое ненулевое значение отправляем в качестве ответа
			}
		data.clear();
		return 0; // Если все были нули но отправляем ноль 
	}
}

/*-----------------------Определение_эксцентриситета_вершины-----------------------*/
int Graph::get_eccentricity(int A)
{
	int ec = 0;
	vector <vertex_data> ::iterator it = Vertex.begin();
	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
	{
		int dis = get_distance(A, it[i].number, 0); // Получаем расстояние
		if (dis > ec) ec = dis;
	}

	for (size_t i = 0; i < Vertex.size(); i++) // Записываем эксцентриситет в узел, потом пригодится
		if (it[i].number == A)
		{
			it[i].ec = ec;
			break;
		}
	return ec;
}

/*-----------------------Определение_диаметра_и_радиуса_графа-----------------------*/
void Graph::get_diameter_and_radius()
{
	diameter = 0;
	radius = 0;
	vector <vertex_data> ::iterator it = Vertex.begin();

	for (size_t i = 0; i < Vertex.size(); i++) // Получаем эксцентриситет всех вершин 
		get_eccentricity(it[i].number);

	vector <int> dummy;

	for (size_t i = 0; i < Vertex.size(); i++) // Готовим к сортировке
		dummy.push_back(it[i].ec);

	sort(dummy.begin(), dummy.end()); // Сортируем

	vector <int> ::iterator it_2 = dummy.begin();

	diameter = it_2[dummy.size() - 1];
	radius = it_2[0];

	for (size_t i = 0; i < dummy.size(); i++)
	{

		if (it_2[i] == 2 && diameter != 2)
		{
			radius = 2;
			break;
		}
		else if (it_2[i] == 1)
			radius = 1;
	}
}

/*-----------------------Определение_центра_графа-----------------------*/
void Graph::get_center()
{
	get_diameter_and_radius();

	cout << "Центр: ";
	vector <vertex_data> ::iterator it = Vertex.begin();
	for (size_t i = 0; i < Vertex.size(); i++)
		if (it[i].ec == radius)
			cout << it[i].number << ' ';
	cout << '\n';
}

/*-----------------------Определение_периферийных_вершин-----------------------*/
void Graph::get_peripheral()
{
	get_diameter_and_radius();

	cout << "Периферийные_вершины: ";
	vector <vertex_data> ::iterator it = Vertex.begin();
	for (size_t i = 0; i < Vertex.size(); i++)
		if (it[i].ec == diameter)
			cout << it[i].number << ' ';
	cout << '\n';
}

/*-----------------------Добавление_вершины-----------------------*/
bool Graph::add_vertex(int num)
{
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	bool find = false;

	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
	{
		if (ver_it[i].number == num)
		{
			find = true;
			break;
		}
	}

	if (find == true)
	{
		//cout << "Вершина с номером " << num << " уже существует, попробуйте другую" << endl;
		return false;
	}
	else
	{
		vertex_data new_ver;
		new_ver.number = num;
		Vertex.push_back(new_ver);
		//cout << "Вершина " << num << " добавлена" << endl;
		return true;
	}
}

/*-----------------------Удаление_вершины-----------------------*/
bool Graph::remove_vertex(int num)
{
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	vector <int> ::iterator it;

	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
	{
		if (ver_it[i].number == num) // Нашли удаляемую вершину
		{
			while(ver_it[i].edge.size() > 0) // Пока размер массива его ребер больше нуля
			{
				it = ver_it[i].edge.begin();
				remove_edge(it[0], 0, 0); // Производим удаление ребра
			}
			Vertex.erase(ver_it + i); // Удаляем вершину
			return true;
		}
	}
	return false;
}

/*-----------------------Добавление_ребра-----------------------*/
bool Graph::add_edge(int num, int A, int B)
{ 
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	vector <edge_data> ::iterator ed_it = Edge.begin();
	vector <int> ::iterator it;

	for (size_t i = 0; i < Edge.size(); i++) // Ищем совпадение среди ребер
		if (ed_it[i].number == num) return false; // Такое ребро уже существует

	int pos_A = -1; // Номера в массиве вершин
	int pos_B = -1;

	for (size_t i = 0; i < Vertex.size(); i++) // Ищем А и В среди всех вершин
	{
		if (ver_it[i].number == A) pos_A = i; // Прокатит даже если добавляем петлю
		if (ver_it[i].number == B) pos_B = i;
	}

	if (pos_A != -1 && pos_B != -1) // Если нашли обе вершины
	{
		if(pos_A == pos_B) // Петля
			ver_it[pos_A].edge.push_back(num);
		else
		{
			// Добавляем номер нового ребра в локальные списки вершин
			ver_it[pos_A].edge.push_back(num);
			ver_it[pos_B].edge.push_back(num);
		}
		// Добавляем в массив новое ребро
		edge_data new_edge;
		new_edge.number = num;
		new_edge.A_vertex = A;
		new_edge.B_vertex = B;
		Edge.push_back(new_edge);
		return true;
	}
	else return false;
}

/*-----------------------Удаление_ребра-----------------------*/
bool Graph::remove_edge(int num, int A, int B)
{
	if (num != 0)
	{
		vector <edge_data> ::iterator ed_it = Edge.begin();

		for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
		{
			if (ed_it[i].number == num) // Нашли наше ребро
			{
				rem_from_vert(ed_it[i].A_vertex, num); // Удаляем информацию о ребре
				rem_from_vert(ed_it[i].B_vertex, num); // на двух вершинах
				Edge.erase(ed_it + i); // Удаляем ребро из списка
				return true;
			}
		}
		return false;
	}
	else // Если не передали номер вершины, а вершины
	{
		vector <edge_data> ::iterator ed_it = Edge.begin();

		for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
		{
			if (ed_it[i].A_vertex == A && ed_it[i].B_vertex == B) // Нашли наше ребро
			{
				rem_from_vert(ed_it[i].A_vertex, ed_it[i].number); // Удаляем информацию о ребре
				rem_from_vert(ed_it[i].B_vertex, ed_it[i].number); // на двух вершинах
				Edge.erase(ed_it + i); // Удаляем ребро из списка
				return true;
			}
		}
		return false;
	}
}

/*-----------------------Определение_дополнения_графа-----------------------*/
void Graph::get_complement_graph()
{
	Graph dummy; // Для операций пользуемся вторым графом
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	vector <edge_data> ::iterator ed_it = Edge.begin();
	int ed_num = 1; // Номера ребер которые мы будем добавлять в новый граф
	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
	{
		dummy.add_vertex(ver_it[i].number); // Добавляем эту вершину во второй граф
		for (size_t j = i; j < Vertex.size(); j++) // Написали i так как вершины ДО i нет смысла рассматривать
		{
			if (i == j)continue; // Не проверяем смежность с самим собой
			else
			{
				if (if_ad(ver_it[i].number, ver_it[j].number) == false) // Проверка на смежность не пройдена, ПРОВЕРКА ИДЕТ В ОБЕ СТОРОНЫ, РАБОТАЕТ ДЛЯ ОБЫЧНОГО ГРАФА
				{
					dummy.add_vertex(ver_it[j].number); // Добавляем еще вершину во второй граф
					dummy.add_edge(ed_num, ver_it[i].number, ver_it[j].number); // Добавляем ребро между двумя не смежными вершинами
					ed_num++;
				}
			}
		}
	}

	// Копируем ребра и вершины как новый основной граф
	Vertex.clear();
	Vertex.assign(dummy.Vertex.begin(), dummy.Vertex.end());

	Edge.clear();
	Edge.assign(dummy.Edge.begin(), dummy.Edge.end());


	// Вывод в файл
	cout << "Как вывести ответ:\n 1) Список смежности\n 2) Матрица смежности\n 3) Матрица инцидентности\n";
	char c;
	while (1)
	{
		cout << "Выберите номер: # ";
		cin >> c;
		if (c == '1' || c == '2' || c == '3') // В файле список смежности
			break;
		else
			cout << "ОШИБКА: Введите 1, 2 или 3\n" << endl;
	}
	if (c == '1') dummy.get_adjacency_list();
	else if (c == '2') dummy.get_adjacency_matrix();
	else if (c == '3') dummy.get_incidence_matrix();
}

/*-----------------------Подразбиение_ребра-----------------------*/
bool Graph::undercutting(int num)
{
	vector <edge_data> ::iterator ed_it = Edge.begin();
	for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
	{
		if (ed_it[i].number == num) // Нашли наше ребро
		{
			int ver_num = get_free(0);// Ищем номер для нашей новой вершины
			add_vertex(ver_num); // Создаем вершину с этим новым номером 

			int A = ed_it[i].A_vertex; // Сохраняем вершины с которыми была связь
			int B = ed_it[i].B_vertex;

			remove_edge(num, 0, 0); // Удаляем наше ребро
			add_edge(num, A, ver_num); // Создаем ребро от начала до середины 

			int ed_num = get_free(1);
			add_edge(ed_num, ver_num, B); // Создаем ребро от середины до конца

			return true;
		}
	}
	return false;
}

/*-----------------------Стягивание_графа_+_отождествление_вершин-----------------------*/
bool Graph::retraction(bool identification)
{
	vector <int> dummy;
	int check = 0;
	vector <int> ::iterator it;
	while (1)
	{
		if (identification == false)
		{
			cout << "\nВведите по одному номера вершин или 0 для выполнения операции: # ";
			char c[10] = { 0 };
			gets_s(c, 10);
			if (c[0] == '0')
			{
				if (dummy.size() > 1) break;
				else cout << "\nНе указано больше одной вершины\n";
			}
			string s = string(c);
			check = atoi(s.c_str());
			if (check_num(check, 0) == true)
				dummy.push_back(check);
			else cout << "\nТакой вершины нет\n";
		}
		else // При отождествлении вершин необходимо соблюдать условие что вершины инцидентны одному ребру
		{
			cout << "\nВведите по одному номера двух вершин или 0 для выполнения операции: # ";
			char c[10] = { 0 };
			gets_s(c, 10);
			if (c[0] == '0')
			{
				if (dummy.size() == 2)
				{
					it = dummy.begin();
					if (if_ad(it[0], it[1]) == true) // Инцидентны ребру 
						break;
					else
					{
						dummy.clear();
						cout << "\nНе инцидентными одному ребру\n";
						continue;
					}
				}
				else
				{
					cout << "\nНе указано две вершины\n";
					continue;
				}
			}
			string s = string(c);
			check = atoi(s.c_str());
			if (check_num(check, 0) == true)
				dummy.push_back(check);
			else cout << "\nТакой вершины нет\n";
		}
	}

	// В dummy хранятся все вершины для стягивания
	// Создаем новую вершину, создаем новые ребра такие как и у исходников, удаляем исходники
	int num = get_free(0); // Получили свободный номер вершины
	it = dummy.begin();
	add_vertex(num); // Создали новую вершину

	// Проходим по всем полученным вершинам, копируем ребра
	for (size_t i = 0; i < dummy.size(); i++)
		copy_the_edges(num, it[i]);

	// Удаляем полученные вершины
	for (size_t i = 0; i < dummy.size(); i++)
		remove_vertex(it[i]);
	return true;
}

/*-----------------------Размножение_+_дублирование_вершины-----------------------*/
bool Graph::duplication(int num, bool reproduction)
{
	if (check_num(num, 1) == false) // Проверка на существование вершины
		return false;
	int new_ver = get_free(0); // Получаем номер новой вершины
	add_vertex(new_ver); // Добавляем новую вершину в граф
	copy_the_edges(new_ver, num); // Копируем ребра из источника
	if (reproduction == true) // Если выполняется размножение, то добавляется ребро между вершинами
		add_edge(get_free(1), num, new_ver);
	return true;
}

/*-----------------------Объединение_графов-----------------------*/
bool Graph::merger()
{
	Graph B;
	B.create_graph(); // Создаем второй граф

	vector <vertex_data> ::iterator A_it = Vertex.begin();
	vector <vertex_data> ::iterator B_it = B.Vertex.begin();
	vector <edge_data> ::iterator B_ed_it = B.Edge.begin();

	// Задаем новые номера для второго графа
	for (size_t i = 0; i < B.Vertex.size(); i++)
		B.add_sec(B_it[i].number, get_free(0) + i + 10); // Передаем свой свободный номер
	//B.add_sec(B_it[0].number, 3);
	//B.add_sec(B_it[1].number, 5);

	// Создаем новые вершины с номерами которые мы присвоили
	for (size_t i = 0; i < B.Vertex.size(); i++)
	{
		add_vertex(B_it[i].sec_num);
		A_it = Vertex.begin();
		A_it[B_it[i].sec_num - 1].sec_num = -1; // Понадобится в connection()
	}

	// Создаем новые ребра
	for (size_t i = 0; i < B.Edge.size(); i++)
		add_edge(get_free(1), B_ed_it[i].sec_A, B_ed_it[i].sec_B);

	cout << "Операция выполнена\n";

	return true;
}

/*-----------------------Соединение_графов-----------------------*/
bool Graph::connection()
{
	// Сначала производим обтединение графов
	merger();

	vector <vertex_data> ::iterator it = Vertex.begin();

	// Проходим по всем вершинам
	for (size_t i = 0; i < Vertex.size(); i++)
	{
		if (it[i].sec_num != -1) // Если эта вершина является первоначальной, то для нее делаем поиск и соединяем со всеми новыми 
		{
			for (size_t j = 0; j < Vertex.size(); j++) // Ищем вершины с sec_num == -1
			{
				if (it[j].sec_num == -1) // Нашли одну из добавленных 
					add_edge(get_free(1), i + 1, j + 1); // Добавляем ребро между ними
			}
		}
	}
	return true;
}

/*-----------------------Произведение_графов-----------------------*/
bool Graph::multiplication()
{ 
	// Создаем два графа один для В второй для вывода
	Graph B;
	Graph C;
	B.create_graph();

	vector <vertex_data> ::iterator A_it = Vertex.begin();
	vector <vertex_data> ::iterator B_it = B.Vertex.begin();
	vector <vertex_data> ::iterator C_it;
	Edge;
	B.Edge;
	C.Vertex;
	C.Edge;

	// Проходим по всем вершинам обоих графов 
	int num = 1;
	for (size_t i = 0; i < Vertex.size(); i++)
	{
		for (size_t j = 0; j < B.Vertex.size(); j++)
		{
			C.add_vertex(num);
			C_it = C.Vertex.begin();
			C_it[num - 1].a = A_it[i].number;
			C_it[num - 1].b = B_it[j].number;
			num++;
		}
	}

	// Проходим по всем вершинам нового графа
	C_it = C.Vertex.begin();
	for (size_t i = 0; i < C.Vertex.size(); i++) // Поочередно просматриваем каждую вершину
	{
		for (size_t j = i + 1; j < C.Vertex.size(); j++) // и сравниваем a с a и b c b
		{
			if (C_it[i].a == C_it[j].a) // Совпадение в первых числах, смотрим существование ребра между  b и b
			{
				if (B.if_ad(C_it[i].b, C_it[j].b) == true) // Между вершинами есть ребро
				{
					C.add_edge(C.get_free(1), C_it[i].number, C_it[j].number); // Добавляем это ребро 
				}
			}
			else if (C_it[i].b == C_it[j].b)// Совпадение во вторых числах, смотрим существование ребра между  а и а
			{
				if (if_ad(C_it[i].a, C_it[j].a) == true) // Между вершинами есть ребро
				{
					C.add_edge(C.get_free(1), C_it[i].number, C_it[j].number); // Добавляем это ребро 
				}
			}
		}
	}
	C.oriented = true;
	C.get_adjacency_list();

	// Копируем ребра и вершины как новый основной граф
	Vertex.clear();
	Vertex.assign(C.Vertex.begin(), C.Vertex.end());

	Edge.clear();
	Edge.assign(C.Edge.begin(), C.Edge.end());

	return true;
}

/*-----------------------Добавление_дополнительной_нумерации-----------------------*/
void Graph::add_sec(int fir, int sec)
{
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	vector <edge_data> ::iterator ed_it = Edge.begin();

	// Проходим по всем вершинам
	for (size_t i = 0; i < Vertex.size(); i++)
		if (ver_it[i].number == fir)
		{
			ver_it[i].sec_num = sec;
			break;
		}

	// Проходим по всем ребрам
	for (size_t i = 0; i < Edge.size(); i++)
	{
		if (ed_it[i].A_vertex == fir) // Номер начала совпадает с изначальным
			ed_it[i].sec_A = sec; // Производим запись второго номера
		if (ed_it[i].B_vertex == fir)
			ed_it[i].sec_B = sec;
	}
}

/*-----------------------Копирование_ребер_для_вершин-----------------------*/
void Graph::copy_the_edges(int to, int from)
{
	vector <edge_data> ::iterator ed_it = Edge.begin();

	for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
	{
		ed_it = Edge.begin();
		if (ed_it[i].A_vertex == from) // Нашли совпадение в источнике
			add_edge(get_free(1), to, ed_it[i].B_vertex);
		ed_it = Edge.begin();
		if (ed_it[i].B_vertex == from) //Нашли совпадение в конечной
			add_edge(get_free(1), ed_it[i].A_vertex, to);
	}
}

/*-----------------------Получить_свободный_номер_вершины_или_ребра-----------------------*/
int Graph::get_free(bool what)
{
	int num = 0;
	bool find = false;
	if (what == 0) // Вершину
	{
		vector <vertex_data> ::iterator it = Vertex.begin();
		while (1)
		{
			num++;
			for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
				if (it[i].number == num)// Нашли совпадение
				{
					find = true;
					break;
				}; 
			if(find == false) return num;
			else find = false;
		}
	}
	else // Ребро
	{
		vector <edge_data> ::iterator it = Edge.begin();
		int num = 0;
		while (1)
		{
			num++;
			for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
				if (it[i].number == num)// Нашли совпадение
				{
					find = true;
					break;
				};
			if (find == false) return num;
			else find = false;
		}
	}
}

/*-----------------------Проваерка_на_существование_номера_вершины_или_ребра-----------------------*/
bool Graph::check_num(int A, bool what)
{
	if (what == 0) // Вершина
	{
		vector <vertex_data> ::iterator it = Vertex.begin();
		for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
			if (it[i].number == A) return true; // Нашли
		return false;
	}
	else // Ребро
	{
		vector <edge_data> ::iterator it = Edge.begin();
		for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
			if (it[i].number == A) return true; // Нашли
		return false;
	}
}

/*-----------------------Проверка_на_смежность-----------------------*/
bool Graph::if_ad(int A, int B)
{
	vector <edge_data> ::iterator ed_it = Edge.begin();
	for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
	{
		// Если между вершинами есть ребро
		if ((ed_it[i].A_vertex == A && ed_it[i].B_vertex == B) || (ed_it[i].A_vertex == B && ed_it[i].B_vertex == A))
			return true; // Проверка пройдена
	}
	return false; // Проверка не пройдена
}

/*-----------------------Проверка_на_смежность_в_строго_определенном_порядке-----------------------*/
bool Graph::if_ad_2(int A, int B)
{
	vector <edge_data> ::iterator ed_it = Edge.begin();
	for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
	{
		// Если между вершинами есть ребро
		if (ed_it[i].A_vertex == A && ed_it[i].B_vertex == B)
			return true; // Проверка пройдена
	}
	return false; // Проверка не пройдена
}

/*-----------------------Удаление_информации_о_ребре_из_вершины-----------------------*/
void Graph::rem_from_vert(int ver, int ed)
{
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	vector <int> ::iterator it;

	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
	{
		if (ver_it[i].number == ver) // Нашли обрабатываемую вершину
		{
			it = ver_it[i].edge.begin();
			for (size_t j = 0; j < ver_it[i].edge.size(); j++) // Проходим по всем ее ребрам
			{
				if (it[j] == ed) // Нашли удаляемое ребро
				{
					ver_it[i].edge.erase(it + j); // Удаляем найденное ребро
					return;
				}
			}
		}
	}
} 

/*-----------------------Определение_позиции_в_матрице-----------------------*/
int Graph::get_pos(int number, int what)
{
	if (what == 1 || what == 2) // Если надо вернуть номер вершины
	{
		vector <vertex_data> ::iterator it = Vertex.begin();
		for (size_t i = 0; i < Vertex.size(); i++)
		{
			if (it[i].number == number)
				return it[i].adjacency_num;
		}
		return -1;
	}
	else // Если надо вернуть номер ребра
	{
		vector <edge_data> ::iterator it = Edge.begin();
		for (size_t i = 0; i < Edge.size(); i++)
		{
			if (it[i].number == number)
				return it[i].incidence_num;
		}
		return -1;
	}
}

/*-----------------------Получаем_число_заходов_и_исходов-----------------------*/
int Graph::get_in_out(int num, bool in_)
{
	vector <edge_data> ::iterator ed_it = Edge.begin();
	int in = 0;
	int out = 0;

	for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем вершинам
	{
		if (ed_it[i].A_vertex == num) out++;
		if (ed_it[i].B_vertex == num) in++;
	}
	if (in_ == true) return in;
	else return out;
}

/*----------------------------------------------LAB_2----------------------------------------------*/

/*-----------------------Поиск_в_глубину-----------------------*/
void Graph::DFS(int num)
{
	close.push_back(num);
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	vector <edge_data> ::iterator ed_it;
	vector <int> ::iterator it;
	int sec_num = 0;

	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
	{
		if (ver_it[i].number == num) // Нашли нашу вершину
		{
			it = ver_it[i].edge.begin();
			for (size_t j = 0; j < ver_it[i].edge.size(); j++) // Проходим по всем ребрам этой вершины
			{
				// Смотрим можно ли перейти на другой конец ребра
				sec_num = check_close(num, it[j]);
				if (sec_num != -1) // Получили ответ в виде номера новой рассматриваемой вершины
				{
					cout << "{" << num << ' ' << sec_num << "}";
					DFS(sec_num);
				}
			}
			break;
		}
	}
}

/*-----------------------Поиск_в_ширину-----------------------*/
void Graph::BFS(int num)
{
	if (data.size() == 0) data.push_back(num); // Записываем первый номер в список, по сути это начало пути
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	vector <edge_data> ::iterator ed_it;
	vector <int> ::iterator it;
	int sec_num = 0;

	for (size_t i = 0; i < Vertex.size(); i++) // Сначала проходим по всем вершинам 
	{
		if (ver_it[i].number == num) // Нашли нашу вершину
		{
			ver_it[i].visited = true; // К примеру первая вершина
			it = ver_it[i].edge.begin();
			for (size_t j = 0; j < ver_it[i].edge.size(); j++) // Проходим по всем инцидентным ребрам
			{
				sec_num = check_visited(num, ver_it[i].edge[j]); // Смотрим можно ли пометить, если да то там и помечаем
				if (sec_num != -1) // Вершину пометили для нас и вернули ее номер
				{
					cout << "{" << num << " " << sec_num << "}";
					data.push_back(sec_num); // Записываем номер куда надо будет пойти в вектор
				}
			}
			break;
		}
	}
	
	it = data.begin(); // Постоянно обновлять
	for (size_t i = 0; i < data.size(); i++) // Переходим на рассмотр новых вершин
	{
		if (it[i] == num) // Как только нашли в очереди только что рассмотренную вершину
		{
			if (i + 1 < data.size())
			{
				BFS(it[i + 1]); // Приступаем к рассмотрению следующей
				break; // Таким образом мы пройдем по постоянно увеличиваемому вектору
			}
		}
	}
}

/*-----------------------Алгоритм_Краскала-----------------------*/
void Graph::Kruskal()
{
	// Подготавливаем вектор весов ребер
	vector <edge_data> ::iterator ed_it = Edge.begin();
	for (size_t i = 0; i < Edge.size(); i++)
	{
		ed_it[i].sec_A = 0; // sec_А будет отвечать за использование
		data.push_back(ed_it[i].weight); // Записываем веса
	}
	sort(data.begin(), data.end()); // Сортируем веса

	// Дублируем вершины
	Graph dummy;
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
		dummy.add_vertex(ver_it[i].number); // И дублируем их в новом графе

	int global_weight = 0;
	vector <int> ::iterator it = data.begin();
	for (size_t i = 0; i < data.size(); i++) // Проходим по всему отсортированному вектору вебер
	{
		for (size_t j = 0; j < Edge.size(); j++) // Проходим по всем ребрам 
		{
			// Если нашли ребро с нужным нам весом и оно не было использовано
			if (it[i] == ed_it[j].weight && ed_it[j].sec_A == 0)
			{
				ed_it[j].sec_A = 1; // Сразу помечаем его как рассмотренное
				// Перед добавлением смотрим, есть ли уже путь между этими вершинами
				if (dummy.find_path(ed_it[j].A_vertex, ed_it[j].B_vertex) == false)
				{
					// Если пути нет, значит можно добавить ребро и не получить цикл
					dummy.add_edge(dummy.get_free(1), ed_it[j].A_vertex, ed_it[j].B_vertex);
					global_weight += ed_it[j].weight;
				}
				dummy.close.clear();
				break; // Обязательно выходим из цикла чтобы не нарушить алгоритм
			}
		}
	}

	cout << "Общий вес: " << global_weight << endl;

	// Вывод в файл
	cout << "Как вывести ответ:\n 1) Список смежности\n 2) Матрица смежности\n 3) Матрица инцидентности\n";
	char c;
	while (1)
	{
		cout << "Выберите номер: # ";
		cin >> c;
		if (c == '1' || c == '2' || c == '3') // В файле список смежности
			break;
		else
			cout << "ОШИБКА: Введите 1, 2 или 3\n" << endl;
	}
	if (c == '1') dummy.get_adjacency_list();
	else if (c == '2') dummy.get_adjacency_matrix();
	else if (c == '3') dummy.get_incidence_matrix();
}

/*-----------------------Проверка_на_существование_пути_от_вершины_до_вершины-----------------------*/
bool Graph::find_path(int num, int vert) // num - искомая, vert - рассматриваемая
{
	if (num == vert) return true;
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	vector <edge_data> ::iterator ed_it = Edge.begin();
	vector <int> ::iterator it;

	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
	{
		if (ver_it[i].number == vert) // Нашли рассматриваемую вершину
		{
			it = ver_it[i].edge.begin();
			for (size_t j = 0; j < ver_it[i].edge.size(); j++) // Проходим по всем ее инцидентным ребрам
			{
					close.push_back(vert); // Закрываем доступ в нашу вершину
					int sec_vert = check_close(vert, it[j]); // Вернет номер вершины куда можно перейти
					if (sec_vert != -1) // Если можно перейти
					{
						sec_vert = find_path(num, sec_vert); // Переходим на следующую вершину
						close.pop_back(); // Достаем нашу вершину
						if (sec_vert == true) // Если нашли совпадение
							return true;
					}
			}
			// Если оказались тут, значит не нашли совпадения
			return false;
		}
	}
}

/*-----------------------Проверка_на_возможность_перехода-----------------------*/
int Graph::check_close(int vert, int ed)
{
	vector <edge_data> ::iterator ed_it = Edge.begin();
	vector <int> ::iterator cl_it = close.begin();
	int second_vert = -1;
	for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
	{
		if (ed_it[i].number == ed) // Нашли наше ребро
		{
			if (ed_it[i].A_vertex == vert) // Надо просмотреть вторую вершину
			{
				second_vert = ed_it[i].B_vertex;
				break;
			}
			else
			{
				second_vert = ed_it[i].A_vertex;
				break;
			}
		}
	}

	// Проверяем на наличие в векторе запрещенных вершин
	for (size_t i = 0; i < close.size(); i++)
	{
		if (cl_it[i] == second_vert)
			return -1;
	}

	return second_vert;
}

/*-----------------------Проверка_на_возможность_пометить_вершину-----------------------*/
int Graph::check_visited(int vert, int ed)
{
	vector <edge_data> ::iterator ed_it = Edge.begin();
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
	{
		if (ed_it[i].number == ed) // Нашли наше ребро
		{
			if (ed_it[i].A_vertex == vert) // Надо просмотреть вторую вершину
			{
				for (size_t j = 0; j < Vertex.size(); j++) // Ищем вторую вершину
				{
					if (ver_it[j].number == ed_it[i].B_vertex) // Нашли вторую вершину
					{
						if (ver_it[j].visited != true) // Если никем не помечена
						{
							ver_it[j].visited = true; // Устанавливаем флаг что сюда уже не пойдут 
							return ver_it[j].number; // Возвращаем номер вершины куда пойдем дальше
						}
						else return -1;
					}
				}
			}
			else // Надо просмотреть первую вершину
			{
				for (size_t j = 0; j < Vertex.size(); j++) // Ищем первую вершину
				{
					if (ver_it[j].number == ed_it[i].A_vertex) // Нашли первую вершину
					{
						if (ver_it[j].visited != true)
						{
							ver_it[j].visited = true; // Устанавливаем флаг что сюда уже не пойдут 
							return ver_it[j].number; // Возвращаем номер вершины куда пойдем дальше
						}
						else return -1;
					}
				}
			}
		}
	}
}

/*----------------------------------------------LAB_3----------------------------------------------*/

/*-----------------------Алгоритм_Дейкстры_поиска_кротчайшего_пути-----------------------*/
void Graph::Dijkstra_algorithm(int A, int B)
{
	// Создаем матрицу расстояний
	vector<vector<int>> distance_matrix(Vertex.size());
	for (size_t i = 0; i < Vertex.size(); i++)
		distance_matrix[i].resize(Vertex.size());

	// ПРЕДКИ
	vector<vector<int>> prev(Vertex.size());
	for (size_t i = 0; i < Vertex.size(); i++)
		prev[i].resize(Vertex.size());

	// Производим обнуление матрицы
	for (size_t i = 0; i < Vertex.size(); i++)
		for (size_t j = 0; j < Vertex.size(); j++)
			distance_matrix[i][j] = 0;

	// ПРЕДКИ
	for (size_t i = 0; i < Vertex.size(); i++)
		for (size_t j = 0; j < Vertex.size(); j++)
			prev[i][j] = 0;

	// Создаем вектор номеров, по которому будем ориентироваться, первой идет стартовая вершина
	data.push_back(A);
	create_Dijkstra_list(A); // Принцип жадности
	// Заполняем матрицу
	vector <int> ::iterator d_it = data.begin();
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	for (size_t i = 0; i < data.size(); i++) // Проходим вершины в реализованном порядке (вертикаль)
	{
		if (i == 0) // Заполняем первую строку      
		{
			for (size_t j = 0; j < Vertex.size(); j++) // Проходим по всем вершинам (горизонталь)
			{
				int weight = get_weight(d_it[i], ver_it[j].number); // Получаем вес ребра между вершинами, 0 если ребра нет
				distance_matrix[i][j] = weight; // Даже если 0 то там все равно все 0 заполнено
				
				if(weight != 0) prev[i][j] = d_it[i];  //ПРЕДКИ
				cout << prev[i][j] << " ";
			}
			cout << endl;
		}
		else // Заполняем остальную часть
		{
			for (size_t j = 0; j < Vertex.size(); j++) // Проходим по всем вершинам (горизонталь)
			{
				int weight = get_weight(d_it[i], ver_it[j].number);
				distance_matrix[i][d_it[i] - 1] = distance_matrix[i - 1][d_it[i] - 1]; // Копируем свой вес

				prev[i][j] = prev[i - 1][j]; // ПРЕДКИ

				if (weight != 0) // Если между вершинами существует ребро
				{
					weight += distance_matrix[i][d_it[i] - 1]; // К весу ребра добавляем вес всего пути до вершины
					if (distance_matrix[i - 1][j] == 0) // Если вес ранее отсутствовал, записываем
					{
						distance_matrix[i][j] = weight;

						prev[i][j] = d_it[i]; // ПРЕДКИ

					}
					else if(distance_matrix[i - 1][j] > weight) // Или если предыдущий вес больше найденного
					{
						distance_matrix[i][j] = weight; // То перезаписываем

						prev[i][j] = d_it[i]; // ПРЕДКИ

					}
					else // Или полученный вес оказался больше уже имеющегося
					{
						distance_matrix[i][j] = distance_matrix[i - 1][j]; // Копируем данные на строку вниз

						//prev[i][j] = d_it[i - 1]; // ПРЕДКИ
					}
				}
				else // Копируем данные на строку вниз
				{
					distance_matrix[i][j] = distance_matrix[i - 1][j];
				}
			}
		}
	}

	ver_it = Vertex.begin();
	cout << "   ";
	for (size_t i = 0; i < Vertex.size(); i++)
		cout << ver_it[i].number << " ";

	cout << "\n\n";

	for (size_t i = 0; i < Vertex.size(); i++)
	{
		cout << d_it[i] << "  ";
		for (size_t j = 0; j < Vertex.size(); j++)
		{
			cout << distance_matrix[i][j] << " ";
		}
		cout << "\n";
	}

	// ПРЕДКИ

	cout << "   ";
	for (size_t i = 0; i < Vertex.size(); i++)
		cout << ver_it[i].number << " ";
	cout << "\n\n";

	for (size_t i = 0; i < Vertex.size(); i++)
	{
		cout << d_it[i] << "  ";
		for (size_t j = 0; j < Vertex.size(); j++)
		{
			cout << prev[i][j] << " ";
		}
		cout << "\n";
	}

}

/*-----------------------Создание_очереди_обработки_вершин-----------------------*/
void Graph::create_Dijkstra_list(int num)
{
	// Сохраняем номер вершины в список запрета и список ответа
	close.push_back(num);

	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	vector <edge_data> ::iterator ed_it = Edge.begin();
	vector <int> ::iterator it;
	vector <int> sec_vec; // Номера вершин, смежных с нашей

	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем веришнам
	{
		if (ver_it[i].number == num) // Нашли рассматриваемую
		{
			// Проходим по всем ребрам и добавляем в ветор номера смежных вершин, при рекурсии сравнивать с data
			it = ver_it[i].edge.begin();
			for (size_t j = 0; j < ver_it[i].edge.size(); j++)
			{
				int sec = get_sec_num(num, it[j]);
				if (sec != 0) 
					sec_vec.push_back(sec); // Смежные вершины
			}
			// Сортируем смежные вершины
			vector <int> dummy;
			it = sec_vec.begin();
			for (size_t j = 0; j < sec_vec.size(); j++) // Собираем все веса в кучу
				dummy.push_back(get_weight(num, it[j]));
			sort(dummy.begin(), dummy.end());
			vector <int> dummy_2;
			vector <int> ::iterator dum_it = dummy.begin();
			while (sec_vec.size() != 0)
			{
				for (size_t j = 0; j < dummy.size(); j++) // Проходим по отсортированному списку весов
				{
					it = sec_vec.begin();
					for (size_t k = 0; k < sec_vec.size(); k++) // Проходим по списку смежных вершин
					{
						if (dum_it[j] == get_weight(num, it[k])) // Нашли совпадающий вес
						{
							dummy_2.push_back(it[k]); // Копируем номер вершины
							sec_vec.erase(sec_vec.begin() + k);
							break;
						}
					}
				}
			}
			sec_vec.swap(dummy_2);

			// Проверка на наличие вершин в векторе data
			for (size_t j = 0; j < sec_vec.size(); j++)
			{
				bool find = false;
				it = sec_vec.begin();
				int sec = it[j];
				it = data.begin();
				for (size_t k = 0; k < data.size(); k++) // Ищем совпадение в векторе data
				{
					if (it[k] == sec)
					{
						find = true;
						break;
					}
				}
				if (find == false) // Если совпадения не было найдено
					data.push_back(sec); // Добавляем в очередь вершину
			}
			if (data.size() == Vertex.size())
				return;
			// Рекурсия, рассматриваем не заблокироавнные вершины
			for (size_t j = 0; j < sec_vec.size(); j++)
			{
				bool find = false;
				it = sec_vec.begin();
				int sec = it[j];
				it = close.begin();
				for (size_t k = 0; k < close.size(); k++)
				{
					if (it[k] == sec)
					{
						find = true; 
						break;
					}
				}
				if (find == false)
					create_Dijkstra_list(sec);
				if (data.size() == Vertex.size())
					return;
			}
		}
	}
}

/*-----------------------Получание_номера_вершины_инцидентной_ребру-----------------------*/
int Graph::get_sec_num(int A, int ed) 
{
	vector <edge_data> ::iterator ed_it = Edge.begin();
	for (size_t i = 0; i < Edge.size(); i++)
		if (ed_it[i].number == ed)
			if (ed_it[i].A_vertex == A)
				return ed_it[i].B_vertex;
	return 0;
}

/*-----------------------Получение_веса_ребра_между_указанными_вершинами_в_определенном_порядке-----------------------*/
int Graph::get_weight(int A, int B)
{
	vector <edge_data> ::iterator ed_it = Edge.begin();
	for (size_t i = 0; i < Edge.size(); i++)
		if (ed_it[i].A_vertex == A && ed_it[i].B_vertex == B)
			return ed_it[i].weight;
	return 0;
}

/*-----------------------Алгоритм_сетевого_планирования-----------------------*/
void Graph::network_planning(int T)
{
	// Проверка на существование только одного стока
	check_sources_and_drains();
	// Строим матрицу
	vector<vector<int>> matrix(Vertex.size()); // Матрица смежности
	for (size_t i = 0; i < Vertex.size(); i++) // Создаем матрицу
		matrix[i].resize(7); // w(0) t(1) ebeg(2) efin(3) lbeg(4) lfin(5) res(6) prev хранится в векторе

	// Обнуляем матрицу
	for (size_t i = 0; i < Vertex.size(); i++)
	{
		matrix[i][0] = i + 1;
		for (int j = 1; j < 7; j++)
			matrix[i][j] = 0;
	}

	vector <vertex_data> ::iterator v_it = Vertex.begin(); // Для поиска и рассмотрения вершины
	vector <vertex_data> ::iterator v2_it = Vertex.begin(); // Для рассмотрения следующей вершины, по нему меняем вес
	vector <edge_data> ::iterator e_it = Edge.begin();
	vector <int> ::iterator it;

	vector<vector<int>> prev(Vertex.size()); // Матрица prev вершин для каждой вершины

	// Задаем размеры матрици prev и заполняем ее
	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
	{
		prev[i].resize(get_prev_count(v_it[i].number)); // Выделяем память под каждую prev каждой вершины
		for (size_t j = 0; j < prev[i].size(); j++) // Обнуляем значения
		{
			prev[i][j] = 0;
		}
		// Заполняем prev
		for (size_t j = 0; j < Edge.size(); j++) // Проходим по всем ребрам
		{
			if (e_it[j].B_vertex == v_it[i].number) // Если наш номер на конце, то источник
			{
				for (size_t k = 0; k < prev[v_it[i].number - 1].size(); k++) // Проходим по вектору prev и добавляем номера предков
				{
					if (prev[v_it[i].number - 1][k] == 0) // Нашли пустое поле
					{
						prev[v_it[i].number - 1][k] = e_it[j].A_vertex; // Добавили номер предка 
						break;
					}
				}
			}
		}
	}

	// Проходим по всем вершинам, заполняя t, ebeg, efin
	for (size_t i = 0; i < Vertex.size(); i++)
	{
		it = v_it[i].edge.begin();
		int t = matrix[v_it[i].number - 1][3]; // Получили efin рассматриваемой вершины
		for (size_t j = 0; j < v_it[i].edge.size(); j++) // Проходим по всем инцидентным ребрам вершины
		{
			int sec = get_sec_num(v_it[i].number, it[j]);
			if (sec != 0) // Если получили номер вершины В
			{
				// Суммируем веса в таблице и в ребре 
				int wt = get_weight(v_it[i].number, sec); // Получаем вес ребра, время выполнения
				int efin = t + wt; // Получили наиб. ранний возм. срок оконч. работы
				if (matrix[sec - 1][3] == 0 || matrix[sec - 1][3] < efin) // Если efin в таблице пуст или значение меньше полученного
				{
					matrix[sec - 1][1] = wt; // Обновляем t
					matrix[sec - 1][2] = efin - wt; // Обновляем ebeg
					matrix[sec - 1][3] = efin; // Обновляем efin
				}
			}
		}
	}

	// Заполняем lbeg, lfin и res
	matrix[Vertex.size() - 1][5] = T;
	for (size_t i = Vertex.size() - 1; i != -1; i--)
	{
		matrix[i][4] = matrix[i][5] - matrix[i][1];
		for (size_t j = 0; j < prev[i].size(); j++)
		{
			if (matrix[prev[i][j] - 1][5] == 0 || matrix[prev[i][j] - 1][5] > matrix[i][4]) // Если lfin предка пуст или значение больше полученного
			{
				matrix[prev[i][j] - 1][5] = matrix[i][4]; // обновляем lfin предка
			}
		}
	}

	// Заполняем res
	for (size_t i = 0; i < Vertex.size(); i++)
	{
		matrix[i][6] = matrix[i][5] - matrix[i][3];
	}

	// Вывод ответа в консоль
	cout << "w  t  ebeg efin lbeg lfin res prev\n";
	for (size_t i = 0; i < Vertex.size(); i++)
	{
		cout << matrix[i][0];
		if (matrix[i][0] > 9) cout << ' ';
		else cout << "  ";
		cout << matrix[i][1];
		if (matrix[i][1] > 9) cout << ' ';
		else cout << "  ";
		cout << matrix[i][2];
		if (matrix[i][2] > 9) cout << "   ";
		else cout << "    ";
		cout << matrix[i][3];
		if (matrix[i][3] > 9) cout << "   ";
		else cout << "    ";
		cout << matrix[i][4];
		if (matrix[i][4] > 9) cout << "   ";
		else cout << "    ";
		cout << matrix[i][5];
		if (matrix[i][5] > 9) cout << "   ";
		else cout << "    ";
		cout << matrix[i][6];
		if (matrix[i][6] > 9) cout << "  ";
		else cout << "   ";
		for (size_t j = 0; j < prev[i].size(); j++)
			cout << prev[i][j] << " ";
		cout << "\n";
	}
}

/*-----------------------Корректировка_графа_при_наличии_нескольких_стоков-----------------------*/
void Graph::check_sources_and_drains()
{
	vector <vertex_data> ::iterator ver_it = Vertex.begin();
	vector <edge_data> ::iterator ed_it = Edge.begin();
	vector <int> ::iterator dummy_it;
	vector <int> sources; // Вектор истоков
	vector <int> drains; // Вектор стоков

	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем узлам
	{
		dummy_it = ver_it[i].edge.begin();
		int in = 0, out = 0;
		for (size_t j = 0; j < ver_it[i].edge.size(); j++) // Просматриваем все ребра этой вершины 
		{
			for (size_t k = 0; k < Edge.size(); k++) // Попутно сравнивая со всеми существующими ребрами
			{
				if (dummy_it[j] == ed_it[k].number) // Нашли ребро среди всех ребер
				{
					if (ed_it[k].A_vertex == ver_it[i].number) // Наша вершина источник для этого ребра
						out++;
					else in++; // Или сток
				}
			}
		}
		// После просмотра всех ребер можем делать вывод о вершине 
		if (in == 0 && out != 0) 
			sources.push_back(ver_it[i].number);
		else if (in != 0 && out == 0)
			drains.push_back(ver_it[i].number);
	}

	if (drains.size() != 1) // Если несколько стоков
	{
		add_vertex(get_free(0));
		for (size_t i = 0; i < drains.size(); i++) // Проходим по всем стокам
		{
			add_edge(get_free(1), drains.at(i), Vertex.size()); // Соединяем с последней вершиной
			Edge.at(Edge.size() - 1).weight = 0; // Вес 0
		}
	}
}

/*-----------------------Получение_количества_предков-----------------------*/
int Graph::get_prev_count(int num)
{
	vector <edge_data> ::iterator e_i = Edge.begin();
	int count = 0;
	for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
	{
		if (e_i[i].B_vertex == num) // Если наш номер на конце, то источник
			count++;
	}
	return count;
}

/*----------------------------------------------LAB_4----------------------------------------------*/

/*-----------------------Алгоритм_Эдмондса_Карпа-----------------------*/
void Graph::Edmonds_Karp_algorithm()
{
	vector <edge_data> ::iterator e_it = Edge.begin();
	// Определение стока и истока
	int source = 0;
	int drain = 0;
	get_source_and_drain(source, drain);
	cout << "Исток: " << source << "\nСток: " << drain << endl;

	// Обнуляем значение использованных ребер
	for (size_t i = 0; i < Edge.size(); i++)
		e_it[i].used = 0;
	bool stuck = false; // Если дошли до момента, когда можно брать входящие ребра
	int sum = 0;
	// Постоянно делаем обход в ширину
	while (1)
	{
		int res = BFS_2(source, drain, stuck); // Выполняем обход в ширину
		if (res == -1 && stuck == true) // Если ничего не нашли при рассмотрении вх. ребер
			break; // Заканчиваем работу
		else if (res == -1 && stuck == false) // Если впервые зашли в тупик
			stuck = true; // Фктивируем рассмотрение входящих ребер
		else sum += res; // В противном случае суммируем результат
		close.clear();
		data.clear();
	}
	cout << "sum=" << sum << endl;
}

/*-----------------------Поиск_в_ширину_для_Эдмонса_Карпа-----------------------*/
int Graph::BFS_2(int A, int B, bool stuck)
{
	vector <edge_data> ::iterator e_it = Edge.begin();
	vector <int> ::iterator it;
	// В data храним список ребер
	// В close храним вершины, куда нельзя возвращаться, по совместительстыву, вывод пути
	// Дошли до нашей рассматривемой вершины
	if (A == B)
	{
		int f = 0;
		// Вывод ответа через close
		vector <int> back;
		vector <int> forv;
		for (size_t i = 0; i < close.size(); i++)
		{
			cout << close.at(i); // Выводим вершину
			if (i < data.size()) // Выводим ребро если не вышли за их количество, ребер на 1 меньше вершин
			{
				if (e_it[data[i] - 1].A_vertex == close.at(i))
				{
					cout << "-(" << e_it[data[i] - 1].weight - e_it[data[i] - 1].used << ")->";
					if (f == 0 || f > e_it[data[i] - 1].weight - e_it[data[i] - 1].used)
						f = e_it[data[i] - 1].weight - e_it[data[i] - 1].used;
					forv.push_back(e_it[data[i] - 1].number);
				}
				else
				{
					if (e_it[data[i] - 1].weight == e_it[data[i] - 1].used)
						if(f > e_it[data[i] - 1].used)
							f = e_it[data[i] - 1].weight;
						else if (f > e_it[data[i] - 1].weight - e_it[data[i] - 1].used && (e_it[data[i] - 1].weight - e_it[data[i] - 1].used != 0))
							f = e_it[data[i] - 1].weight - e_it[data[i] - 1].used;

					cout << "<-(" << e_it[data[i] - 1].used << ")-";
					back.push_back(e_it[data[i] - 1].number);
				}
			}
		}
		// Производим изменение количества потока
		for (size_t i = 0; i < back.size(); i++)
		{
			e_it[back.at(i) - 1].used -= f;
		}
		for (size_t i = 0; i < forv.size(); i++)
		{
			e_it[forv.at(i) - 1].used += f;
		}
		cout << " f=" << f << "\n";
		return f; // Возвращаем f
	}
	else
	{
		int v = 0; // Для записи номера второй вершины
		vector <int> local_close; // Дл каждой рекурсии свой вектор
		while (1)
		{
			int num = 0;
			int weight = 0;
			// Проходим по всем ребрам в поисках ребра, с самой маленькой пропускной способностью 
			for (size_t i = 0; i < Edge.size(); i++)
			{
				if (e_it[i].A_vertex == A)
				{
					if ((weight == 0 || weight > e_it[i].weight) && e_it[i].used < e_it[i].weight && check_close(e_it[i].A_vertex, e_it[i].number) != -1) // Нашли ребро, вес которого меньше и его еще можно использовать
					{
						// Еще одна проверка на локальный черный список
						bool find = false;
						for (size_t j = 0; j < local_close.size(); j++)
						{
							if (local_close.at(j) == e_it[i].B_vertex)
							{
								find = true;
								break;
							}
						}
						// Если вершина нам подходит
						if (find == false)
						{
							weight = e_it[i].weight;
							num = e_it[i].number;
							v = e_it[i].B_vertex;
						}
					}
				}
			}
			// Можем рассмотреть входящие ребра если ничего не нашли
			if (stuck == true && num == 0)
			{
				for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
				{
					if (e_it[i].B_vertex == A && e_it[i].used != 0) // Нашли не нулевой входящий
					{
						if ((weight == 0 || weight > e_it[i].weight) && e_it[i].used != 0 && check_close(e_it[i].B_vertex, e_it[i].number) != -1) // Нашли ребро, вес которого меньше и его еще можно использовать
						{
							// Еще одна проверка на локальный черный список
							bool find = false;
							for (size_t j = 0; j < local_close.size(); j++)
							{
								if (local_close.at(j) == e_it[i].A_vertex)
								{
									find = true;
									break;
								}
							}
							// Если вершина нам подходит
							if (find == false)
							{
								weight = e_it[i].weight;
								num = e_it[i].number;
								v = e_it[i].A_vertex;
							}
						}
					}
				}
			}
			// Если ничего не нашли то выход с -1
			if (num == 0)
			{
				return -1;
			}
			else
			{
				if (close.size() == 0)
					close.push_back(A);
				close.push_back(v); // Добавляем вершину в вектор close
				data.push_back(num); // Добавляем ребро в вектор data
				int res = BFS_2(v, B, stuck); // Рекурсивный вызов
				if (res != -1) return res;
				close.pop_back();
				data.pop_back(); // Так как вернулись, то удаляем ребро и вершину из списка финального ответа
				if (res == -1) // Если вызов оказался не удачным
				{
					local_close.push_back(v); // То заносим веришну в локальный черный список, чтобы больше не рассматривать ее
					// Проверка на окончание работы цикла
					int out = 0;
					for (size_t i = 0; i < Edge.size(); i++) // Проходим по всем ребрам
					{
						if (e_it[i].A_vertex == A)
							out += 1;
						if (stuck == true) // + Рассматриваем входящие если можно
							if (e_it[i].B_vertex == A)
								out += 1;
					}
					if (out == local_close.size()) // Рассмотрели все возможные пути и не нашли ответ
						return -1;
				}
			}
		}
	}
	return -1;
}

/*-----------------------Получение_истока_и_стока-----------------------*/
void Graph::get_source_and_drain(int &source, int &drain)
{
	vector <edge_data> ::iterator e_it = Edge.begin();
	vector <vertex_data> ::iterator v_it = Vertex.begin();
	vector <int> ::iterator it;

	for (size_t i = 0; i < Vertex.size(); i++) // Проходим по всем вершинам
	{
		int in = 0;
		int out = 0;
		it = v_it[i].edge.begin();
		for (size_t j = 0; j < v_it[i].edge.size(); j++) // Проходим по инцидентным ребрам
		{
			for (size_t k = 0; k < Edge.size(); k++) // Ищем по номеру среди всех ребер
			{
				if (it[j] == e_it[k].number) // Нашли совпадение
				{
					if (e_it[k].A_vertex == v_it[i].number) // Исходит
					{
						out++;
					}
					else in++;
					break;
				}
			}
		}
		// Рассматриваем результат
		if (in == 0) // Нашли исток
			source = v_it[i].number;
		else if (out == 0) // Нашли сток
			drain = v_it[i].number;

		if (source != 0 && drain != 0) // Если все нашли то на выход
			return;
	}
}

Graph::Graph()
{
}

Graph::~Graph()
{
	Vertex.clear();
	Edge.clear();
}