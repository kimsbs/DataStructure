#include "linkedgraph.h"

void *free_graph(LinkedGraph *pGraph)
{
    printf("Malloc Error\n");
    free(pGraph);
    pGraph = NULL;
    return (NULL);
}

void *free_vertex(LinkedGraph *pGraph)
{
    free(pGraph->pVertex);
    pGraph->pVertex = NULL;
    return(free_graph(pGraph));
}

void *free_edge(LinkedGraph *pGraph)
{
    free(pGraph->ppAdjEdge);
    pGraph->ppAdjEdge = NULL;
    return(free_vertex(pGraph));
}

void *free_edgenode(LinkedGraph *pGraph, int i)
{
    for (int j = 0; j < i; j++)
    {
        free(pGraph->ppAdjEdge[j]);
        pGraph->ppAdjEdge[j] = 0;
    }
    return (free_edge(pGraph));
}

// 그래프 생성
LinkedGraph* createLinkedGraph(int maxVertexCount)
{
    LinkedGraph *graph;

    if (maxVertexCount <= 0)
    {
        printf("maxVertexCount can not be zero or minus\n");
        return (NULL);
    }
    graph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
    if (!graph)
    {
        printf("Malloc Error");
        return (NULL);
    }
    graph->maxVertexCount = maxVertexCount;
    graph->currentVertexCount = 0;
    graph->currentEdgeCount = 0;
    graph->graphType = GRAPH_UNDIRECTED;
    graph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
    if (!graph->pVertex)
        return (free_graph(graph));
    graph->ppAdjEdge = (LinkedList **)calloc(maxVertexCount, sizeof(int *));
    if (!graph->ppAdjEdge)
        return(free_vertex(graph));
    for(int i = 0 ; i < maxVertexCount ; i++)
    {
        graph->ppAdjEdge[i] = createLinkedList();
        if (!graph->ppAdjEdge[i])
            return (free_edgenode(graph, i)); 
    }
    return (graph);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
    LinkedGraph *graph;

    graph = createLinkedGraph(maxVertexCount);
    if (!graph)
    {
        printf("Malloc Error");
        return (NULL);
    }
    graph->graphType = GRAPH_DIRECTED;
    return (graph);
}

// 공백 그래프 여부 판단
int isEmptyLG(LinkedGraph* pGraph);

// 노드 추가
int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
    if(!pGraph || !pGraph->pVertex || !pGraph->ppAdjEdge)
        return (FALSE);
     if(vertexID >= pGraph->maxVertexCount ||\
        pGraph->pVertex[vertexID] == USED)
    {
        printf("node is already exist\n");
        return (FALSE);
    }
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;
    return(TRUE);
}

// 간선 추가
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
    ListNode elem = {toVertexID, 0, 0, 0};
    if(!checkVertexValid(pGraph, fromVertexID) || 
        !checkVertexValid(pGraph, toVertexID))
        return (FALSE);
    addLLElement(pGraph->ppAdjEdge[fromVertexID], elem);
    if(pGraph->graphType == GRAPH_UNDIRECTED)
    {
        elem.data = fromVertexID;
        addLLElement(pGraph->ppAdjEdge[toVertexID], elem);
    }
    pGraph->currentEdgeCount++;
    return (TRUE);
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
    ListNode elem = {toVertexID, weight, 0, 0};
    if(!checkVertexValid(pGraph, fromVertexID) || 
        !checkVertexValid(pGraph, toVertexID))
        return (FALSE);
    addLLElement(pGraph->ppAdjEdge[fromVertexID], elem);
    if(pGraph->graphType == GRAPH_UNDIRECTED)
    {
        elem.data = fromVertexID;
        elem.weight = weight;
        addLLElement(pGraph->ppAdjEdge[toVertexID], elem);
    }
    pGraph->currentEdgeCount++;
    return (TRUE);
}

// 노드의 유효성 점검.
int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
    if(!pGraph || !pGraph->pVertex || !pGraph->ppAdjEdge ||
        !pGraph->ppAdjEdge[vertexID])
        return (FALSE);
    if (vertexID >= pGraph->maxVertexCount ||
        pGraph->pVertex[vertexID] == NOT_USED)
        return (FALSE);
    return (TRUE);
}

// 노드 제거
int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
    ListNode    *curr;
    ListNode    *next;
    int         to;
    if (!checkVertexValid(pGraph, vertexID)|| pGraph->currentVertexCount <= 0 ||
        vertexID >= pGraph->maxVertexCount)
        return (FALSE);
    curr = pGraph->ppAdjEdge[vertexID]->frontNode;
    if(!curr)
        return (FALSE);
    while(curr)
    {
        next = curr->pRLink;
        to = curr->data;
        removeEdgeLG(pGraph, vertexID, to);
        if(pGraph->graphType == GRAPH_DIRECTED)
            removeEdgeLG(pGraph, to, vertexID);
        curr = next;
    }
    pGraph->pVertex[vertexID] = NOT_USED;
    return (TRUE);
}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{    
    if(!checkVertexValid(pGraph, fromVertexID) || 
        !checkVertexValid(pGraph, toVertexID))
        return (FALSE);
    deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID);
    if(pGraph->graphType == GRAPH_UNDIRECTED)
        deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
    pGraph->currentEdgeCount--;
    return (TRUE);
}

void deleteGraphNode(LinkedList* pList, int delVertexID)
{
    if(pList && pList->frontNode)
        removeLLElement(pList, delVertexID);
}

// 노드 개수 반환
int getVertexCountLG(LinkedGraph* pGraph)
{
    return (!pGraph ? -1 : pGraph->currentVertexCount);
}

// 최대 노드 개수 반환
int getMaxVertexCountLG(LinkedGraph* pGraph)
{
    return (!pGraph ? -1 : pGraph->maxVertexCount);
}

// 그래프 종류 반환.
int getGraphTypeLG(LinkedGraph* pGraph)
{
    return (!pGraph ? FALSE : pGraph->graphType);
}

void displayLinnkedList(LinkedList* pList)
{
    ListNode *curr;
    ListNode *next;

    curr = pList->frontNode;
    while(curr)
    {
        next = curr->pRLink;
        printf("[%d : %d] ", curr->data, curr->weight);
        curr = next;
    }
    printf("\n");
}

void displayLinkedGraph(LinkedGraph* pGraph)
{
    if(!pGraph || !pGraph->pVertex || !pGraph->ppAdjEdge)
        return ;
    printf("\n========Info==========\n");
    printf("maxVertexCount : %d\n", pGraph->maxVertexCount);
    printf("currentVertexCount : %d\n", pGraph->currentVertexCount);
    printf("currentEdgeCount : %d\n", pGraph->currentEdgeCount);
    printf("graphType : ");
    if(pGraph->graphType == GRAPH_UNDIRECTED)
        printf("GRAPH_UNDIRECTED\n");
    else
        printf("GRAPH_DIRECTED\n");
    printf("========Graph=========\n"); 
    for(int i = 0 ; i < pGraph->maxVertexCount ; i++)
    {
        printf("%d : ", i);
        displayLinnkedList(pGraph->ppAdjEdge[i]);    
    }
    printf("======================\n");
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
    for(int i = 0 ; i < pGraph->maxVertexCount ; i++)
    {
        removeVertexLG(pGraph, i);
        free(pGraph->ppAdjEdge[i]);
        //deleteLinkedList(pGraph->ppAdjEdge[i]);
        pGraph->ppAdjEdge[i] = 0;
    }
    free(pGraph->ppAdjEdge);
    pGraph->ppAdjEdge = 0;
    free(pGraph->pVertex);
    pGraph->pVertex = 0;
    free(pGraph);
    pGraph = 0;
}

//노드에 있는 간선들 큐에 넣기
void enqueue(LinkedGraph* pGraph, LinkedList *queue, int *visited, int VertexID)
{
    ListNode *curr;
    ListNode tmp = {0, 0, 0, 0};
    curr = pGraph->ppAdjEdge[VertexID]->frontNode; //노드내 간선들의 간선
    while(curr)
    {
        if(visited[curr->data] == 0) // 재방문 막기
        {
            tmp.data = curr->data;
            addLLElement(queue, tmp);
            visited[curr->data] = 1;
        }
        curr = curr->pRLink;
    }   
}

void BFS_graph(LinkedGraph *pGraph, int VertexID)
{
    LinkedList *queue;
    ListNode *Qnode;
    ListNode node = {VertexID, 0, 0, 0};
    int   *visited;

    visited = (int *)calloc(pGraph->maxVertexCount, sizeof(int));
    queue = createLinkedList();
    addLLElement(queue, node); //큐에 시작 노드 넣기
    visited[VertexID] = 1;
    Qnode = queue->frontNode;
    while(Qnode)
    {
        printf("%d ", Qnode->data); // 큐 원소들 출력
        enqueue(pGraph, queue, visited, Qnode->data);
        Qnode = Qnode->pRLink;
    }
    printf("\n");
    deleteLinkedList(queue);
    free(visited);
}

void DFS_stackin(LinkedGraph *pGraph, int *stack, int *visited, int curr)
{
    ListNode *node;

    for(int i = 0 ; i < curr ; i++)
    printf("%d ", stack[i]);
    printf("\n");

    node = pGraph->ppAdjEdge[stack[curr]]->frontNode;
    while(node)
    {
        if(visited[node->data] == 0)
        {
            visited[node->data] = 1;
            stack[curr + 1] = node->data;
            DFS_stackin(pGraph, stack, visited, curr + 1);
            visited[node->data] = 0;
        }
        node = node->pRLink;
    }
}

void DFS_graph(LinkedGraph *pGraph, int VertexID)
{
    int *stack;
    int *visited;

    visited = (int *)calloc(pGraph->maxVertexCount, sizeof(int));
    stack = (int *)calloc(pGraph->maxVertexCount, sizeof(int));
    visited[VertexID] = 1;
    stack[0] = VertexID;
    DFS_stackin(pGraph, stack, visited, 0);
    free(stack);
    free(visited);
    printf("\n");
}

void test()
{
    int i = 0;
    LinkedGraph *pG1 = 0;
    LinkedGraph *pG2 = 0;
    LinkedGraph *pG4 = 0;

    pG1 = createLinkedGraph(6);
    pG2 = createLinkedDirectedGraph(6);
    pG4 = createLinkedDirectedGraph(6);
    if (pG1 && pG2 && pG4)
    {
        for (i = 0; i < 6; i++)
        {
            addVertexLG(pG1, i);
            addVertexLG(pG2, i);
            addVertexLG(pG4, i);
        }

        addEdgeLG(pG1, 0, 1);
        addEdgeLG(pG1, 0, 2);
        addEdgeLG(pG1, 1, 2);
        addEdgeLG(pG1, 2, 3);
        addEdgeLG(pG1, 3, 4);
        addEdgeLG(pG1, 3, 5);
        addEdgeLG(pG1, 4, 5);

        addEdgeLG(pG2, 0, 1);
        addEdgeLG(pG2, 1, 2);
        addEdgeLG(pG2, 2, 0);
        addEdgeLG(pG2, 2, 1);
        addEdgeLG(pG2, 2, 3);
        addEdgeLG(pG2, 3, 2);
        addEdgeLG(pG2, 3, 4);
        addEdgeLG(pG2, 4, 5);
        addEdgeLG(pG2, 5, 3);
        
        addEdgewithWeightLG(pG4, 0, 1, 4);
        addEdgewithWeightLG(pG4, 1, 2, 1);
        addEdgewithWeightLG(pG4, 2, 0, 2);
        addEdgewithWeightLG(pG4, 2, 1, 3);
        addEdgewithWeightLG(pG4, 2, 3, 2);
        addEdgewithWeightLG(pG4, 3, 2, 1);
        addEdgewithWeightLG(pG4, 3, 4, 1);
        addEdgewithWeightLG(pG4, 4, 5, 1);
        addEdgewithWeightLG(pG4, 5, 3, 2);

        printf("G1: Undirected\n");
        displayLinkedGraph(pG1);
        //BFS_graph(pG1, 3);
        //DFS_graph(pG1, 4);
        printf("G2: Directed\n");
        displayLinkedGraph(pG2);
        printf("G4: Directed Weighted\n");
        displayLinkedGraph(pG4);

        deleteLinkedGraph(pG1);
        deleteLinkedGraph(pG2);
        deleteLinkedGraph(pG4);

        printf("G1: Undirected\n");
        displayLinkedGraph(pG1);
        printf("G2: Directed\n");
        displayLinkedGraph(pG2);
        printf("G4: Directed Weighted\n");
        displayLinkedGraph(pG4);
    }
}

int main()
{
    test();
    system("leaks a.out");
    return 0;
}

// 0 : [1 : 0] [2 : 0] 
// 1 : [0 : 0] [2 : 0] 
// 2 : [0 : 0] [1 : 0] [3 : 0] 
// 3 : [2 : 0] [4 : 0] [5 : 0] 
// 4 : [3 : 0] [5 : 0] 
// 5 : [3 : 0] [4 : 0] 

// 0 : 
// 1 : [2 : 0] 
// 2 : [1 : 0] [3 : 0] 
// 3 : [2 : 0] [5 : 0] 
// 4 : [5 : 0] 
// 5 : [3 : 0] [4 : 0] 