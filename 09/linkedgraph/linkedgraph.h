#ifndef _GRAPH_ADJLIST_
#define _GRAPH_ADJLIST_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct ListNodeType
{
	int data;
	int	weight;
	struct ListNodeType* pLLink;
	struct ListNodeType* pRLink;
} ListNode;

typedef struct LinkedListType
{
	ListNode *frontNode;
	ListNode *rearNode;
} LinkedList;

typedef struct LinkedGraphType
{
	int maxVertexCount;		// 최대 노드 개수
	int currentVertexCount;	// 현재 사용되는 노드의 개수
	int currentEdgeCount;	// 현재 간선의 개수.
	int graphType;			// 그래프 종류: 1-Undirected, 2-Directed
	LinkedList** ppAdjEdge;	// 간선 저장을 위한 연결 리스트 (포인터)의 배열
	int *pVertex;			// 노드 저장을 위한 1차원 배열
} LinkedGraph;

// 리스트
LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, ListNode element);
int removeLLElement(LinkedList* pList, int VertexID);
ListNode* getLLElement(LinkedList* pList, int VertexID);

void clearLinkedList(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);

// 그래프 생성
LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);

// 그래프 삭제
void deleteLinkedGraph(LinkedGraph* pGraph);

// 공백 그래프 여부 판단
int isEmptyLG(LinkedGraph* pGraph);

// 노드 추가
int addVertexLG(LinkedGraph* pGraph, int vertexID);

// 간선 추가
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// 노드의 유효성 점검.
int checkVertexValid(LinkedGraph* pGraph, int vertexID);

// 노드 제거
int removeVertexLG(LinkedGraph* pGraph, int vertexID);

// 간선 제거
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
void deleteGraphNode(LinkedList* pList, int delVertexID);

// 간선 개수 반환
int getEdgeCountLG(LinkedGraph* pGraph);

// 노드 개수 반환
int getVertexCountLG(LinkedGraph* pGraph);

// 최대 노드 개수 반환
int getMaxVertexCountLG(LinkedGraph* pGraph);

// 그래프 종류 반환.
int getGraphTypeLG(LinkedGraph* pGraph);

// 그래프 정보 출력
void displayLinkedGraph(LinkedGraph* pGraph);

void deleteLinkedGraph(LinkedGraph* pGraph);


//제거
int removeVertexLG(LinkedGraph* pGraph, int vertexID);

// 간선 제거
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
void deleteGraphNode(LinkedList* pList, int delVertexID);

// 간선 개수 반환
int getEdgeCountLG(LinkedGraph* pGraph);

// 노드 개수 반환
int getVertexCountLG(LinkedGraph* pGraph);

// 최대 노드 개수 반환
int getMaxVertexCountLG(LinkedGraph* pGraph);

// 그래프 종류 반환.
int getGraphTypeLG(LinkedGraph* pGraph);

// 그래프 정보 출력
void displayLinkedGraph(LinkedGraph* pGraph);

void deleteLinkedGraph(LinkedGraph* pGraph);

void BFS_graph(LinkedGraph *pGraph, int VertexID);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define TRUE				1
#define FALSE				0

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2

#endif