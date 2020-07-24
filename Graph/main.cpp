#include "Graph.h"
#include <conio.h>

extern int f(int &, int &);

void main()
{
	setlocale(LC_ALL, "rus");
	Graph *graph = new Graph;
	graph->graph_menu();
}