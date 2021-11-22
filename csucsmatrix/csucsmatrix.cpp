// csucsmatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <stack>

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
		//cerr << N << " " << count(0, [](int x) {return true; }) << endl;
		return N == count(0, [](int x) {return true; });
	}
	int find(int csucs, bool (*predicate)(int))
	{
		queue<int> toDo;
		vector<char> cols(N, 'w');
		toDo.push(csucs);
		
		while (!toDo.empty())
		{
			int cTask = toDo.front();
			toDo.pop();
			if (predicate(cTask))
			{
				return cTask;
			}
			cols[cTask] = 'b';

			for (size_t i = 0; i < N; i++)
			{
				if (csucsmatrix->at(i)[cTask]&&cols[i]=='w')
				{
					toDo.push(i);
					cols[i] = 'g';
				}
			}

		}


		return -1;
	}
	int count(int csucs, bool (*predicate)(int))
	{
		queue<int> toDo;
		int cunt = 0;
		vector<char> cols(N, 'w');
		toDo.push(csucs);

		while (!toDo.empty())
		{
			int cTask = toDo.front();
			toDo.pop();
			if (predicate(cTask))
			{
				++cunt;
			}
			cols[cTask] = 'b';

			for (size_t i = 0; i < N; i++)
			{
				if (csucsmatrix->at(i)[cTask] && cols[i] == 'w')
				{
					toDo.push(i);
					cols[i] = 'g';
				}
			}
		}


		return cunt;
	}
	vector<int> where(int csucs, bool (*predicate)(int))
	{
		queue<int> toDo;
		vector<char> cols(N, 'w');
		toDo.push(csucs);
		vector<int> hol;

		while (!toDo.empty())
		{
			int cTask = toDo.front();
			toDo.pop();
			if (predicate(cTask))
			{
				hol.push_back(cTask);
			}
			cols[cTask] = 'b';

			for (size_t i = 0; i < N; i++)
			{
				if (csucsmatrix->at(i)[cTask] && cols[i] == 'w')
				{
					toDo.push(i);
					cols[i] = 'g';
				}
			}

		}


		return hol;
	}
	
	
	//todo
	vector<int> shortest_path(int a, int b)
	{
		stack<int> toDo;
		vector<char> cols(N, 'w');
		toDo.push(a);
		vector<int> ut;

		while (!toDo.empty())
		{
			int cTask = toDo.top();
			toDo.pop();
			if (cTask==b)
			{
				return ut;
			}
			cols[cTask] = 'b';
			for (size_t i = 0; i < N; i++)
			{
				
				if (csucsmatrix->at(i)[cTask] && cols[i] == 'w')
				{
					ut.push_back(cTask);
					toDo.push(i);
					cols[i] = 'g';
				}
				else if (!ut.empty())
				{
					ut.pop_back();
				}
				
			}

		}
		
	}
	~Csucsmatrix()
	{
	}

private:

};


int main()
{
	Csucsmatrix csucs;
	cerr << endl;
	for (auto& i : csucs.shortest_path(0, 4))
	{
		cerr << i << " ";
	}
	
	/*for (auto& i : csucs.where(0, [](int x) {return x%2==0;}))
	{
		cerr << i << " ";
	}*/
	//cerr << csucs.count(1, [](int x) {return x % 2 == 0 && x<3; });
	//csucs.add_node();
	//cerr<<csucs.connected();
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
