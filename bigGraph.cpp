

#include <iostream>
#include <fstream>
#include <list>                                                                                                      
using namespace std;                                                                                                 
#define INF 9999                                                                                                     
class graph
{
    public:
        graph();
        graph( int n );              // constructor, x is # of nodes
        void bfs( int x );           // breadth-first node order
        void bfssp( int x );         // breadth-first spanning tree
        void dfs( int x );           // depth-first node order
        void dfssp( int x );         // depth-first spanning tree
        void primm(int x);
        void dijkstra(int x);
        void kruskal();
        void mprint();               // print representation
        void fill( ifstream& file ); // fill graph from data file
    private:
        int arr[100][100];
        int *adjList;
        int num;
        int edge;
        //bool *visited;
};

graph::graph(int n){

        //arr = (int**)malloc(sizeof(int*)*n);
        num = n;
        int i, j;

        for(i = 0; i < n; i++){
            //arr[i] = (int*)malloc(sizeof(int)*n);
            for(j = 0; j < n; j++)
                arr[i][j] = 0;
        }

}
void graph:: fill(ifstream& file){
        int w,r, l, m, n;
        file >> w;
        cout << w << endl;
        edge = w;

    for(r = 0; r < w; r++){
        file >> l;
        file >> m;
        file >> n;
        arr[l][m] = n;
        arr[m][l] = n;
        //arr[v][w];
        }
}

void graph::bfs(int x){
    int n, i;
    list<int> queue(num);
    int visited[num+1];
    for(i = 1; i <= num; i++){
        visited[i] = 0;
    }
    cout<<"BFS:"<<endl;
    queue.push_back(x);
    while(!queue.empty()) {
        n = queue.front();
        queue.pop_front();

        if(visited[n] == 0){
        visited[n] = 1;
        cout<<n<<" ";
        for(i=1; i <=num; i++) {
            if(visited[i] == 0 && arr[n][i] != 0) {
                queue.push_back(i);
                }
            }
        }
    }

    cout << endl;

}

void graph::bfssp( int x ){
    int n, i,j, m;
    int ret[100] = {0};
    list<int> queue(0);
    list<int> queue2(0);
    int visited[num+1];
    for(i = 1; i <= num; i++){
        visited[i] = 0;
    }
    cout<<"BFSSP:"<<endl;
    queue.push_back(x);
    queue2.push_back(x);
    while(!queue.empty()) {
        n = queue.front();
        queue.pop_front();
        j = queue2.front();
        queue2.pop_front();

        if(visited[n] == 0){
        cout<<j<<"-"<<n<< " ";
        visited[n] = 1;
        //cout<<n<<"-";
        for(i=1; i <=num; i++) {
            if(visited[i] == 0 && arr[n][i] != 0) {
                queue.push_back(i);
                queue2.push_back(n);
                    ret[i]= n;
                    //visited[i] = 1;

                    //cout<<"First loop"<<ret[i]<<endl;
                }
            }
        }
    }

    cout << endl;

}

void graph::dfs(int x){
 int n, i;
    list<int> stack(0);
    int visited[num+1];
    for(i = 1; i <= num; i++){
        visited[i] = 0;
    }

    cout<<"DFS:"<<endl;

    stack.push_front(x);
    while(!stack.empty()) {
        n = stack.back();
        stack.pop_back();
        if(visited[n] == 0){
        visited[n] = 1;
        cout<<n<<" ";
        for(i=num; i >=1; i--) {
            if(visited[i] == 0 && arr[n][i] != 0) {
                stack.push_back(i);
                }
            }
        }
    }
    cout<<endl;
}

void graph::dfssp(int x){
 int n, i, j;
    list<int> stack(0);
    list<int>stack2(0);
    int ret[100] = {0};
    int visited[num+1];
    for(i = 1; i <= num; i++){
        visited[i] = 0;
    }

    cout<<"DFSSP:"<<endl;

    stack.push_front(x);
    stack2.push_front(x);
    while(!stack.empty()) {
        n = stack.back();
        stack.pop_back();

        j = stack2.back();
        stack2.pop_back();
        if(visited[n]== 0){
        visited[n] = 1;
        cout<<j<<"-"<<n<<" ";
        for(i=num; i >=1; i--) {
            if(visited[i] == 0 && arr[n][i] != 0) {
                stack.push_back(i);
                stack2.push_back(n);
                    ret[i]= n;
                    //cout<<n<<"-"<<i<<" ";
                    //visited[i] = 1;
                }
            }
        }
    }
    cout<<endl;

}

void graph::mprint(){


    //arr = (int*)calloc(v,sizeof(int*));

for(int i = 1; i <= num;i++){
    for(int j = 1; j <= num;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;

    }

}

void graph:: primm(int x){
    int n, i, j,u, t;
    int min_ind, min, total = 0;
    int max, max_ind;
    int key[num+1];
    int key2[num+1];
    bool set[num+1];
    for(n = 0; n < num+1; n++){
        key[n] = INF, set[n] = false;
        key2[t] = INF, set[t] = false;
    }
    key[x] = 0;
    //key2[x] = 0;
    cout<<"Prim:"<<endl;

    for(j = 0; j < num; j++){
        min = INF;
        //max = INF;
        for(i = 0; i < num+1; i++){
            if(!set[i] && key[i] < min){
                min = key[i], min_ind = i;
            }
        }

        set[min_ind] = true;

        if(min_ind==x) {
            cout << "Start at: " << min_ind << endl;

        } else {
            cout<< key2[min_ind] << "-"<< min_ind << " "<<endl;
            cout<<"weight: "<<key[min_ind]<<endl;

            total += key[min_ind];
            cout << "Total: " << total <<endl;
        }

        for(i = 0; i <= num+1; i++)
            if(arr[min_ind][i] && !set[i] && arr[min_ind][i] < key[i]){
                key[i] = arr[min_ind][i];
                key2[i] = min_ind;
                //total +=key[min_ind];
            }

    }
    //cout << "Here";

}
void graph:: kruskal(){
    int n, j, k, i = 0, total = 0;
    //adrew fix ask tom
    int size[edge] = {0};
    int size2[edge]= {0};
    int visited[num] = {0};


    for(j = 1; j <= num; j++){
        for(k = j+1; k <= num; k++){
            if(arr[j][k] != 0){

                size[i] = j;
                size2[i] = k;
                i++;
            }
        }
    }

        cout << "Kruskal: "<<endl;

    for(j = 0; j < edge; j++){
        for(k =0 ; k < edge-1; k++){
            if(arr[size[k]][size2[k]] >= arr[size[k+1]][size2[k+1]]){
                i = size[k];
                size[k] = size[k+1];
                size[k+1] = i;

                i = size2[k];
                size2[k] = size2[k+1];
                size2[k+1] = i;

            }
        }
    }

    for(j = 0; j < edge; j++) {
        if(visited[size[j]] != 1 ){

            cout << size[j] << "-" << size2[j] << endl;
            cout << "Weight: " << arr[size[j]][size2[j]] << endl;
            total += arr[size[j]][size2[j]];

            visited[size[j]] = 1;
            visited[size2[j]] = 1;

        }
        else if(visited[size2[j]] != 1){

            cout << size[j] << "-" << size2[j] << endl;
            cout << "Weight: " << arr[size[j]][size2[j]] << endl;
            total += arr[size[j]][size2[j]];

            visited[size[j]] = 1;
            visited[size2[j]] = 1;

        }
    }

    cout << total << endl;
}


void graph:: dijkstra(int x){

    int k, j, m;
    int dist[num];
    bool set[num];
    int min, min_ind;
    min_ind = 1;

    for( k = 1; k <= num; k++){
        dist[k] = INF;
        set[k] = false;

    }

            dist[x] = 0;

    cout << "Dijkstra: "<<endl;
    for(j = 1; j<= num; j++){
            min = INF;
            for(m = 1; m <= num; m++){
            if(!set[m] && dist[m] <= min){

                min = dist[m];
                min_ind = m;

            }
        }


    set[min_ind] = true;

    for(k = 1; k <= num; k++){

        if(arr[min_ind][k] != 0 && dist[min_ind] + arr[min_ind][k] < dist[k]){

            //cout<<dist[k]<<endl;
            dist[k] = dist[min_ind] + arr[min_ind][k];
        }
    }



}

    printf("Vertx\t\t Distance from Source\n");
        for(k = 1; k <= num; k++){
                printf("%d \t\t %d\n", k, dist[k]);
            }
}

int main( int argc, char *argv[] )
{
    int size;
    int location;
    ifstream ifp;

    //checking to see if file was entered on command line
    if ( argc != 2 )
    {
        cout << "File was not entered\n";
        return 2;
    }

    ifp.open( argv[1] );

    // checking to see if file was opened successfully
    if( ! ifp.is_open() )
    {
        cout << "File could not be opened\n";
        return 3;
    }

    // reading in number of nodes
    ifp >> size;

    //create graph with an an adjadceny matrix of
    // size = num of nodes x num of nodes
    cout << "graph" << endl;
    graph g( size );

    //fill adjacency matrix
    cout << "fill" << endl;
    g.fill( ifp );

    //print the matrix
    cout << "print" << endl;
    g.mprint();
    cout << endl << endl;

    //ask for starting location
    cout << "Enter the starting location: ";
    cin >> location;

    // calculate DFS
    g.dfs( location );
    cout << endl << endl;

    //calculate DFS-SP
    g.dfssp( location );
    cout << endl << endl;

    //calculate BFS
    g.bfs( location );
    cout << endl << endl;

    //calculate BFS-SP
    g.bfssp( location );
	    cout << endl << endl;

    //calulate prim
    g.primm(location);
    cout << endl << endl;

    //caluate duj
    g.dijkstra(location);
    cout <<endl<<endl;
    //kruskul
    g.kruskal();
    cout<<endl<<endl;
    return 0;
}
