#include <map>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <utility>
#define ll long long

using namespace std;

int n,m,first_node ;

void print(vector<int>graph[],int v)
{
    for (int i = 1; i <= v ; i++)
    {
        int f = graph[i].size();
        cout<<i<< " : ";
        for (int j = 0; j < f; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
void print(vector<vector<ll>>graph,int v)
{
    for (int i = 1; i <= v ; i++)
    {
        cout<<i<< " : ";
        for (int j = 1; j <= v; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int degree(vector<int>graph[],int node)
{
    return graph[node].size();
}

void dfs(int node,vector<int>graph[],vector<int>&visited)
{
    cout<<node<<" ";
    visited[node] = 1;
    int siz = graph[node].size();
    for (int j = 0; j <siz ; j++)
    {
        if(!visited[graph[node][j]])
        {
            dfs(graph[node][j],graph,visited);
        }
    }
}

void bfs(int node, vector<int>graph[], vector<int>& visited, queue<int>& que)
{

    visited[node] = 1;
    que.push(node);
    while (!que.empty())
    {
        int f = que.front();
        int siz = graph[f].size();
        que.pop();
        cout << f << " ";
        for (int i = 0; i < siz; i++)
        {
            if (!visited[graph[f][i]])
            {
                que.push(graph[f][i]);
                visited[graph[f][i]] = 1;
            }
        }
    }
}

int count_graphs(vector<int>graph[],int v, vector<int>& visited)
{
    int cnt = 0;
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            dfs(i, graph, visited);
            cout<<" ";
            cnt++;
        }
    }
    //cout<<"NUMBER OF CONNECTED GRAPHS : ";
    return cnt;
}

int shortest_path(int start,int target,vector<int>graph[])
{
    if (start == target)
    {
        return 0;
    }

    vector<int>visited(n+1,0);
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start]=1;

    while (!q.empty())
    {
        int node = q.front().first, dist = q.front().second,n =graph[node].size();
        q.pop();
        for (int i=0; i<n; i++)
        {
            if (graph[node][i] == target)
            {
                return dist + 1;
            }

            if (!visited[graph[node][i]])
            {
                visited[graph[node][i]]=1;
                q.push({graph[node][i], dist + 1});
            }
        }
    }
    return -1;
}

/////////////////////////////////////////directed

bool isCyclic_util_directed(vector<int> adj[], vector<bool> visited, int curr)
{
    if(visited[curr]==true)
        return true;

    visited[curr] = true;
    bool f = false;

    int x =adj[curr].size();
    for(int i=0; i<x; ++i)
    {
        f = isCyclic_util_directed(adj, visited, adj[curr][i]);
        if(f==true)
            return true;
    }

    return false;
}

bool isCyclic_directed(int V, vector<int> adj[])
{
    vector<bool> visited(V,false);
    bool f = false;

    for(int i=0; i<V; ++i)
    {
        visited[i] = true;
        int x = adj[i].size();
        for(int j=0; j<x; ++j)
        {
            f = isCyclic_util_directed(adj,visited,adj[i][j]);
            if(f==true)
                return true;
        }
        visited[i] = false;
    }

    return false;
}
///////////////////////////////////////////////////directed


////////////////////////////////////////////////undirected

bool isCyclic_util_undirected(vector<int> adj[], vector<int> visited, int curr)
{
    if(visited[curr]==2)
        return true;

    visited[curr] = 1;
    bool f = false;
    int x = adj[curr].size();
    for(int i=0; i<x; ++i)
    {
        if(visited[adj[curr][i]]==1)
            visited[adj[curr][i]] = 2;
        else
        {
            f = isCyclic_util_undirected(adj, visited, adj[curr][i]);
            if(f==true)
                return true;
        }
    }
    return false;
}

bool isCyclic_undirected(int V,vector<int> adj[])
{
    vector<int> visited(V,0);
    bool f = false;
    for(int i=0; i<V; ++i)
    {
        visited[i] = 1;
        int x =adj[i].size();
        for(int j=0; j<x; ++j)
        {
            f = isCyclic_util_undirected(adj,visited,adj[i][j]);
            if(f==true)
                return true;
        }
        visited[i] = 0;
    }
    return false;
}
///////////////////////////////////////////////////undirected

/////////////////////////////////////////////////// dijkistra


void dijkstra(int start, vector<pair<int, int>> adj[], int V)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V+1, INT_MAX);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        int q = adj[u].size();
        for (int i=0; i<q; i++)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Node Distance from Source" << endl;
    for (int i = 1 ; i<=V ; i++)
    {
        cout << i << "   " << dist[i] << endl;
    }
}

///////////////////////////////////////////////////

vector<vector<ll>> Floyd_Warshall(vector<vector<ll>>v,int n)
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                v[i][j] = min(v[i][j],v[i][k]+v[k][j]);
            }
        }
    }
    return v;
}


///////////////////////////////////////////////////

int main()
{
    cin>>n>>m;
    vector<int>graph[n+1];
    vector<vector<ll>> x(n+1, vector<ll>(n+1,INT_MAX));
    queue<int>que;

    int t;
    cout<<"1- weighted  2-unweighted : ";
    cin>>t;
    if(t==1)
    {
        vector<pair<int, int>> graph[n+1];

        for (int i = 0; i < m; i++)
        {
            int u, v, weight;
            cin >> u >> v >> weight;
            graph[u].push_back({v, weight});
            x[u][v]=weight;
            //graph[v].push_back({u, weight});
        }

        first_node = -1;
        for (int i = 1; i <= n; i++)
        {
            if (!graph[i].empty())
            {
                first_node = i;
                break;
            }
        }

        dijkstra(first_node, graph, n);
        vector<vector<ll>>f = Floyd_Warshall(x,n);
        print(f,n);
    }

    else
    {
        for(int i=0; i<m; i++)
        {
            int r,c;
            cin>>r>>c;
            graph[r].push_back(c) ;
            graph[c].push_back(r) ;
        }

        cout<<isCyclic_undirected(n,graph)<<endl;


        first_node = -1;
        for (int i = 1; i <= n; i++)
        {
            if (!graph[i].empty())
            {
                first_node = i;
                break;
            }
        }

        if(first_node!=-1)
        {
            vector<int>visited(n+1,0);
            dfs(first_node,graph,visited);
            cout<<endl;

            vector<int>visited2(n+1,0);
            bfs(first_node,graph,visited2,que);
            cout<<endl;

            vector<int>visited3(n+1,0);
            cout<<count_graphs(graph,n,visited3)<<endl;

            cout<<"shortest path from first node to n : "<<shortest_path(first_node,n,graph)<<endl;

            print(graph,n);
        }

    }






}


