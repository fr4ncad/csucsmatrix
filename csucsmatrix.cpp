// csucsmatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <iostream>
#include <vector>
#include <stdlib.h>

/*
6 7
0 1
1 4
3 1
3 5
2 0
2 3
1 2
*/



class Csucsmatrix
{
public:
	vector<vector<bool>>* csucsmatrix;
	int N;
	Csucsmatrix()
	{
		int M;
		int a,b;
		cin >> N >> M;
		csucsmatrix= new vector<vector<bool>>(N,vector<bool>(N));
		for (size_t i = 0; i < M; i++)
		{
			cin >> a >> b;
			csucsmatrix->at(a)[b]=1;
			csucsmatrix->at(b)[a]=1;
		}
		

	}
	void Dyagnostics()
	{
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				/*if (csucsmatrix->at(i)[j]==0)
				{
					cerr << " " << " ";
				}
				else
				{
					cerr << csucsmatrix->at(i)[j] << " ";
				}*/
				cerr << csucsmatrix->at(i)[j] << " ";
			}
			cerr << endl;
		}
	}
	bool van_el(int a, int b)
	{
		return csucsmatrix->at(a)[b] == 1 ? 1 : 0;
	}
	void add_edge(int a, int b)
	{
		if (a<N && b<N)
		{
			csucsmatrix->at(a)[b] = 1;
			csucsmatrix->at(b)[a] = 1;
		}
		else
		{
			cerr << "None existing edge" << endl;
		}
	}
	void remove_edge(int a, int b)
	{
		if (a < N && b < N)
		{
			csucsmatrix->at(a)[b] = 0;
			csucsmatrix->at(b)[a] = 0;
		}
		else
		{
			cerr << "None existing edge" << endl;
		}
	}
	void add_node()
	{
		for (size_t i = 0; i < N; i++)
		{
			csucsmatrix->at(i).push_back(0);
		}
		csucsmatrix->push_back(vector<bool>(N+1));
		N++;
	}
	int degree(int a)
	{
		int sum = 0;
		for (size_t i = 0; i < csucsmatrix->at(a).size(); i++)
		{
			sum += csucsmatrix->at(a)[i];
		}
		return sum;
	}
	bool loop(int a)
	{
		return csucsmatrix->at(a)[a];
	}
	bool isolated(int a)
	{
		int sum = 0;
		for (size_t i = 0; i < csucsmatrix->at(a).size(); i++)
		{
			sum += csucsmatrix->at(a)[i];
		}
		return sum==0?1:0;
	}
	bool connected()
	{
		for (size_t i = 0; i < N; i++)
		{
			int sum = 0;
			for (size_t j = 0; j < csucsmatrix->at(i).size(); j++)
			{
				sum += csucsmatrix->at(i)[j];
			}
			if (sum == 0) return 0;
		}
		return 1;
	}
	int find(bool (*predicate)(int));
	int count(bool (*predicate)(int));
	int where(bool (*predicate)(int));
	vector<int> shortest_path(int a, int b);
	~Csucsmatrix()
	{
	}

private:

};


int main()
{
	Csucsmatrix csucs;
	cerr << endl;
	//csucs.add_node();
	cerr<<csucs.connected();
	//cerr << csucs.isolated(6);
	//csucs.add_edge(4, 4);
	//cerr << csucs.loop(4) << endl;
	//cerr << csucs.degree(0) << endl << endl;
	//csucs.add_node();
	//csucs.add_edge(6, 6);
	//csucs.Dyagnostics();
	//cerr << csucs.van_el(1, 4) << endl;
	//csucs.add_edge(6, 6);
	//csucs.Dyagnostics();
	cerr << endl<< endl;
	csucs.Dyagnostics();
}

/*
6 7
0 1
1 4
3 1
3 5
2 0
2 3
1 2
*/
