 #include<iostream>

using namespace std;

struct node
{
	int data;
	struct node*link;
};

struct vertexlist
{
	struct node*vlisthead;
};

struct Graph
{
	int v;
	struct vertexlist *vl*v2;
};

struct Graph *
createGraph (int n)
{
	int c, a;
	cout << "\n Number of nodes =";
	cin>> n;
	adjmat[n][n];
	do
	{
			cout << "\nEnter vertex 1";
			cin >> v1;
			cout << "\nEnter vertex 2";
			cin >> v2;
			cout << "\nEnter the cost of edge between them";
			cin c;
			adjmat[v1][v2]= adjmat[v2][v1] = c;
			cout << "\nDo you want more edges?\n"
			cin >> a;
			
	}while(a==1);
};

struct Graph *
displayGraph()
{
	int i,j;
	for(i=1; i< n+1; i++)
	{
		for(j=1; j< n+1;j++)
		{
			cout<< "The cost matrix is \n"+adjmat[i][j];
		};
	};
};

struct Graph*
Prims()
{
	int i, j,s;
	visit=[n];
	for (i=1; i<n+1; i++)
	{
		visit[i]= 0;
		cout << "Enter Current Vertex";
		cin >> s;
		visit[s]= 
	}
	
}
