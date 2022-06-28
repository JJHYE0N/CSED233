#include "graph.h"
#include <fstream>
#include <iostream>
#include <string>
#define INF 2147483647 
using namespace std;


/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////
/*  Write your codes if you have additional functions  */
void Graph::_SCC(int idx, int* check_include, int* connect) {
    if((check_include[idx] == 1) || (connect[idx] == 1)) return;
    else{
        check_include[idx] = 1;
        for(int i=0; i<size; i++) {
            if(matrix_dfs[idx][i] != 0){
                _SCC(i, check_include, connect);
            }
        }
    }
}
void Graph::_SCC_2(int idx, int* check_include, int* connect) {
    if((check_include[idx] != 0) || (connect[idx] == 1)) return;
    else{
        check_include[idx] = 1;
        for(int i=0; i<size; i++) {
            if(matrix_dfs[i][idx] != 0){
                _SCC_2(i, check_include, connect);
            }
        }
    }
}
void Graph::sorting() {
    for(int i=0; i<size; i++) {
        sort_dfs[i]=vertices[i];
    }
    string temp;
    for(int p=0;p<size-1;p++){
        for(int q=p+1;q<size;q++){
            if(sort_dfs[p]>sort_dfs[q]){
                temp=sort_dfs[p];
                sort_dfs[p]=sort_dfs[q];
                sort_dfs[q]=temp;
            }
        }
    }
    string pre_i;
    string pre_j;

    int sort_i;
    int sort_j;

    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            if(adjmat[i][j]==1) {
                pre_i=vertices[i];
                pre_j=vertices[j];
                for (int a=0; a<size; a++) {
                    if(pre_i==sort_dfs[a]) {
                        sort_i=a;
                    }
                }
                for (int b=0; b<size; b++) {
                    if(pre_j==sort_dfs[b]) {
                        sort_j=b;
                    }
                }
                matrix_dfs[sort_i][sort_j]=adjmat[i][j];
            }
        }
    }

}

void Graph::_DFS(int index, string& result,int* check_dfs_include){
    if(check_dfs_include[index] == 0){
        check_dfs_include[index] = 1;
        result +=sort_dfs[index];
        result.push_back(' ');
        for(int i = 0; i<size; i++){
            if(matrix_dfs[index][i] == 1){
                _DFS(i, result, check_dfs_include);
            }
        }
    }
}

void Graph::_dijkstra(int pre[], int i, string &s)
{
    if (pre[i] == -1)
        return;

    _dijkstra(pre, pre[i],s);
    s+=vertices[i];
    s+=" ";
}

void Graph::floyd(int(*board)[NodeMaxCount], int i, int j,string &result) {
    if (board[i][j] != 0)
    {
        floyd(board,i,board[i][j],result);
        result+=vertices[board[i][j]];
        result+=" ";
        floyd(board,board[i][j],j,result);
    }
}
///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////


int Graph::addDirectedEdge(string nodeA, string nodeB) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int i,j;
    int exist_A=0,exist_B=0;
    for (i=0; i<size; i++) {
        if (vertices[i]==nodeA) {
            exist_A=1;
            break;
        }
    }
    if (exist_A==0) {
        vertices[i] = nodeA;
        size += 1;
    }
    for (j=0; j<size; j++) {
        if (vertices[j]==nodeB) {
            exist_B=1;
            break;
        }
    }
    if(exist_B==0) {
        vertices[j] = nodeB;
        size += 1;
    }
    adjmat[i][j]=1;

    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int Graph::addDirectedEdge(string nodeA, string nodeB, int weight) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int i,j;
    int exist_A=0,exist_B=0;
    for (i=0; i<size; i++) {
        if (vertices[i]==nodeA) {
            exist_A=1;
            break;
        }
    }
    if (exist_A==0) {
        vertices[i] = nodeA;
        size += 1;
    }
    for (j=0; j<size; j++) {
        if (vertices[j]==nodeB) {
            exist_B=1;
            break;
        }
    }
    if(exist_B==0) {
        vertices[j] = nodeB;
        size += 1;
    }
    adjmat[i][j]=weight;

    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int Graph::addUndirectedEdge(string nodeA, string nodeB) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int i,j;
    int exist_A=0,exist_B=0;
    for (i=0; i<size; i++) {
        if (vertices[i]==nodeA) {
            exist_A=1;
            break;
        }
    }
    if (exist_A==0) {
        vertices[i] = nodeA;
        size += 1;
    }
    for (j=0; j<size; j++) {
        if (vertices[j]==nodeB) {
            exist_B=1;
            break;
        }
    }
    if(exist_B==0) {
        vertices[j] = nodeB;
        size += 1;
    }
    adjmat[i][j]=1;
    adjmat[j][i]=1;

    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int Graph::addUndirectedEdge(string nodeA, string nodeB, int weight) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int i,j;
    int exist_A=0,exist_B=0;
    for (i=0; i<size; i++) {
        if (vertices[i]==nodeA) {
            exist_A=1;
            break;
        }
    }
    if (exist_A==0) {
        vertices[i] = nodeA;
        size += 1;
    }
    for (j=0; j<size; j++) {
        if (vertices[j]==nodeB) {
            exist_B=1;
            break;
        }
    }
    if(exist_B==0) {
        vertices[j] = nodeB;
        size += 1;
    }
    adjmat[i][j]=weight;
    adjmat[j][i]=weight;

    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

string Graph::DFS() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    sorting();
    string result;
    for(int i = 0; i<size; i++){
        if(check_dfs_include[i]==0){
            if(i != 0){
                result.push_back('\n');
            }
            _DFS(i, result, check_dfs_include);
            result.pop_back();
        }
    }
    return result;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int Graph::getTreeCount() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int i,j;
    int treeCount=0;

    int check_include[size];
    for (int k=0; k<size; k++) {
        check_include[k]=0;
    }

    for (i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j && adjmat[i][j] == 1) {
                if (check_include[i]==0 && check_include[j]==0) {
                    treeCount+=1;
                }
                else if (check_include[i]==0 && check_include[j]==1) {
                    treeCount+=0;
                }
                else if (check_include[i]==1 && check_include[j]==0) {
                    treeCount+=0;
                }
                else if (check_include[i]==1 && check_include[j]==1) {
                    treeCount-=1;
                }

                check_include[i]=1;
                check_include[j]=1;
                adjmat[i][j]=0;
                adjmat[j][i]=0;
            }
        }
    }
    return treeCount;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

string Graph::getStronglyConnectedComponent() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int connect[NodeMaxCount] = {0, };
    string s;
    sorting();
    int check_include[NodeMaxCount] = { 0,};

    for(int x=0;x<size;x++) {
        if(connect[x] == 0){
            for(int y=0;y<size;y++){
                check_include[y] = 0;
            }
            _SCC(x, check_include, connect);
            for(int y=0;y<size;y++) {
                if(check_include[y]==1){
                    check_include[y] = 0;
                }
                else{  check_include[y] = -1;  }
            }
            _SCC_2(x, check_include, connect);
            num_vertex = 0;
            for(int y=0;y<size;y++)
                if(check_include[y] == 1) {
                    con_vertices[num_vertex] = y;
                    num_vertex++;
                    connect[y] = 1;
                }
            if(max_vertex < num_vertex) {
                max_vertex = num_vertex;
                for(int y=0;y<max_vertex;y++){
                    max_vertices[y] = con_vertices[y];
                }
            }
        }
    }
    for(int x=0;x<max_vertex;x++) {
        s += (sort_dfs[max_vertices[x]]+' ');
    }
    s.pop_back();
    return s;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

string Graph::getDijkstraShortestPath(string source, string destination) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int start,end;
    for (int i=0; i<size; i++) {
        if(vertices[i]==source) {
            start = i;
            break;
        }
    }
    for (int i=0; i<size; i++) {
        if(vertices[i]==destination) {
            end = i;
            break;
        }
    }

    for (int p = 0; p < size; p++) {
        for (int q = 0; q < size; q++) {
            dijkstra_mat[p][q]=adjmat[p][q];
        }
    }
    int check_include[size];
    for (int i=0; i<size; i++) {
        check_include[i]=0;
    }
    int pre[size];
    for (int i=0; i<size; i++) {
        pre[i] = -1;
    }
    int d[size];
    for (int i = 0; i < size; i++) {
        d[i] = INF;
    }

    d[start] = 0;
    int min, min_index;
    for (int c = 0; c < size - 1; c++) {
        min = INF;
        for (int i = 0; i < size; i++) {
            if (check_include[i] == 0 && d[i] <= min) {
                min = d[i];
                min_index = i;
            }
        }
        int a = min_index;
        check_include[a] = 1;
        for (int b = 0; b < size; b++) {
            if (!check_include[b] && dijkstra_mat[a][b] && d[a] + dijkstra_mat[a][b] < d[b]) {
                pre[b] = a;
                d[b] = d[a] + dijkstra_mat[a][b];
            }
        }
    }

    string s;
    string result;
    result+=vertices[start];
    result+=" ";
    _dijkstra(pre, end,s);
    result+=s;
    result+= to_string(d[end]);
    if (d[end]>=2000000000||d[end]<=-2000000000) result="error";
    return result;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

string Graph::getFloydShortestPath(string source, string destination) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int i, j;
    string temp;
    int check_include[size];

    for (int p = 0; p < size; p++) {
        for (int q = 0; q < size; q++) {
            if (adjmat[p][q] != 0) floyd_mat[p][q] = adjmat[p][q];
            else {
                floyd_mat[p][q] = INF;
            }
        }
        check_include[p] = 0;
    }

    for (i = 0; i < size; i++) {
        if (vertices[i] == source) {
            break;
        }
    }
    check_include[i] = 1;
    for (j = 0; j < size; j++) {
        if (vertices[j] == destination) {
            break;
        }
    }
    check_include[j] = 1;

    int board[NodeMaxCount][NodeMaxCount];
    for (int i=0; i<size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }

    for (int z = 0; z < size; z++) {
        for (int x = 0; x < size; x++) {
            for (int y = 0; y < size; y++) {
                    if (floyd_mat[x][z] + floyd_mat[z][y] < floyd_mat[x][y] && floyd_mat[x][z]!= INF && floyd_mat[z][y]!=INF) {
                        board[x][y]=z;
                        floyd_mat[x][y] = floyd_mat[x][z] + floyd_mat[z][y];

                    }
            }
        }
    }

    for (i = 0; i < size; i++) {
        if (vertices[i] == source) {
            break;
        }
    }
    for (j = 0; j < size; j++) {
        if (vertices[j] == destination) {
            break;
        }
    }

    string s;
    string result;
    floyd(board,i,j,s);
    result+=vertices[i];
    result+=" ";
    result+=s;
    result+=vertices[j];
    result+=" ";
    result+= to_string(floyd_mat[i][j]);

    return result;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int Graph::primMST(ofstream &fout, string startNode) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int sum=0;
    int check_include[size];
    for (int x=0; x<size; x++) {
        check_include[x] = 0;
    }
    for (int x=0; x<size; x++) {
        if (vertices[x]==startNode) {
            check_include[x]=1;
            break;
        }
    }

    int end=1;
    int i,j;
    int temp_from_idx,temp_to_idx,temp_val;
    while (end) {
        end=0;
        temp_val=INF;
        for (i = 0; i < size; i++) {
            if (check_include[i] == 1) {
                for (int j = 0; j<size; j++) {
                    if (i!=j&&adjmat[i][j]!=0&&adjmat[i][j]<temp_val&&check_include[j]==0) {
                        temp_val=adjmat[i][j];
                        temp_from_idx=i;
                        temp_to_idx=j;
                    }
                }
            }

        }
        check_include[temp_to_idx]=1;
        fout << vertices[temp_from_idx] << " " << vertices[temp_to_idx] << " " << temp_val << endl;
        sum+=temp_val;

        for (int k=0; k<size; k++) {
            if(check_include[k]==0) {
                end=1;
            }
        }
    }

    return sum;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int Graph::kruskalMST(ofstream &fout) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    string s[size];

    for (int p=0; p<size; p++) {
        s[p]=vertices[p];
    }
    string temp;
    for(int p=0;p<size-1;p++){
        for(int q=p+1;q<size;q++){
            if(s[p]>s[q]){
                temp=s[p];
                s[p]=s[q];
                s[q]=temp;
            }
        }
    }
    int tempnum=INF;
    int tempval=INF;
    int i,j,k,sum=0;
    int tempcheck[size];
    for (int l=0; l<size; l++) {
        tempcheck[l]=0;
    }
    for (i=0; i<size; i++) {
        tempnum=INF;
        tempval=INF;

        for (k=0; k<size; k++) {
            if (vertices[k]==s[i]) {
                break;
            }
        }

        for (j=0; j<size; j++) {
            if(k!=j&&adjmat[k][j]<tempval&&adjmat[k][j]!=0) {
                tempval=adjmat[k][j];
                tempnum=j;
            }
        }
        if (tempnum!=INF&&tempcheck[k]<tempval) {
            if(vertices[k]<vertices[tempnum]) {
                fout << vertices[k] << " " << vertices[tempnum] << " " << tempval << endl;
            } else {
                fout << vertices[tempnum] << " " << vertices[k] << " " << tempval << endl;
            }
            adjmat[k][tempnum] = INF;
            adjmat[tempnum][k] = INF;
            tempcheck[k]=tempval;
            tempcheck[tempnum]=tempval;
            sum+=tempval;
        }
    }
    return sum;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}