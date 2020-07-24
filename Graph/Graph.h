#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

#pragma once
class Graph
{
private:
	struct edge_data // Информация о ребре
	{
		int number; // Номер ребра
		int A_vertex; // Начальная вершина
		int B_vertex; // Конечная вершина
		int sec_A; // Для операций
		int sec_B;
		int incidence_num; // Номер в матрице инцидентности
		int used;
		int weight; // Вес
	};
	struct vertex_data // Информация о вершине
	{
		int number; // Номер вершины
		int sec_num; // Второй номер вершины, используется в некоторых операциях
		vector <int> edge; // Список всех ребер вершины
		int adjacency_num; // Номер в матрице смежности
		int ec; // Эксцентриситета вершины
		int a; // Двузначное значение 
		int b; // используемое при перемножении
		bool visited;
		vector <int> prev; // Номера вершин, использующиеся в Алгоритме сетевого планирования
	};
	vector <edge_data> Edge; // Вектор всех ребер
	vector <vertex_data> Vertex; // Вектор всех вершин
	vector <int> close; // Используется в get_distance(), хранит вершины куда нельзя возвращаться 
	vector <int> data; // Используется в get_distance(), хранит ответы
	int diameter;
	int radius;
	FILE *file;
	ofstream out; // Поток для записи в файл
	bool oriented; // Граф ориентированный

public:
	void graph_menu(); // Начало работы
	Graph();
	~Graph();
	
private:
	/*-----------------------LAB_1-----------------------*/
	void create_graph(); // Создание графа
	int get_vertex_number(); // Определение числа вершин
	int get_edge_number(); // Определение числа ребер
	void get_vertex_degree(int number); // Определение степени вершины
	void get_power_sequence(); // Определение степенной последовательности
	void get_adjacency_matrix(); // Определение матрицы смежности
	void get_incidence_matrix(); // Определение матрицы инцидентности
	void get_adjacency_list(); // Определение списка смежности
	void get_isolated_and_hanging_vertex(); // Определение изолированных и висячих вершин
	void get_sources_and_drains(); // Определение истоков и стоков
	int get_distance(int A, int B, int dis); // Определение расстояния между двумя вершинами
	int get_eccentricity(int A); // Определение эксцентриситета вершины
	void get_diameter_and_radius(); // Определение диаметра и радиуса графа
	void get_center(); // Определение центра графа
	void get_peripheral(); // Определение периферийных вершин
	bool add_vertex(int num); // Добавление вершины
	bool remove_vertex(int num); // Удаление вершины
	bool add_edge(int num, int A, int B); // Добавление вершины
	bool remove_edge(int num, int A, int B); // Удаление ребра
	void get_complement_graph(); // Определение дополнения графа
	bool undercutting(int num); // Подразбиение ребра
	bool retraction(bool identification); // Стягивание графа + отождествление вершин
	bool duplication(int num, bool reproduction); // Дублирование вершины + размножение
	bool merger(); // Объединение графов
	bool connection(); // Соединение графов
	bool multiplication(); // Произведение графов
	int get_pos(int num, int what); // Получение информации о позиции в матрице
	void rem_from_vert(int ver, int ed); // Удаление информации о ребре из вершины
	bool if_ad(int ver1, int ver2); // Проверка на смежность
	bool if_ad_2(int ver1, int ver2); // Проверка на смежность в строго определенном порядке
	bool check_num(int A, bool what); // Проверка на существование номера
	void copy_the_edges(int to, int from); // Копирование ребер для вершин
	int get_free(bool what); // Получить свободный номер вершины или ребра
	void add_sec(int fir, int sec); // Добавление дополнительной нумерации
	int get_in_out(int num, bool in_); // Получаем число заходов и исходов
	/*-----------------------LAB_2-----------------------*/
	void DFS(int num); // Поиск в глубину
	void BFS(int num); // Поиск в ширину
	void Kruskal(); // Алгоритм Краскала
	int check_close(int vert, int ed); // Проверка на возможность перехода
	int check_visited(int vert, int ed); // Проверка на возможность пометить вершину
	bool find_path(int num, int vert); // Проверка на существование пути от вершины до вершины
	/*-----------------------LAB_3-----------------------*/
	void Dijkstra_algorithm(int A, int B); // Алгоритм Дейкстры поиска кротчайшего пути
	void network_planning(int T); // Алгоритм сетевого планирования
	void create_Dijkstra_list(int A); // Создание очереди обработки вершин
	int get_sec_num(int A, int ed); // Получание номера вершины инцидентной ребру
	int get_weight(int A, int B); // Получение веса ребра между указанными вершинами в определенном порядке
	void check_sources_and_drains(); // Корректировка графа, при наличии нескольких стоков
	int get_prev_count(int num); // Получение количества предков
	/*-----------------------LAB_4-----------------------*/
	void Edmonds_Karp_algorithm(); // Алгоритм Эдмондса - Карпа
	int BFS_2(int A, int B, bool stuck); // Поиск в ширину для Эдмонса - Карпа
	void get_source_and_drain(int &source, int &drain); // Получение истока и стока
};