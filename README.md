# Training_Code
### Priority_Queue 사용법
>**queue<pair<int,int>> q // priority_queue<int> pq의 사용으로 프린터 큐 알고리즘을 완성**  
  **배열의 우선순위를 주고 싶은 경우 priority_queue에 pus------- 내림차순 자동 정렬**  
  **해당 value에 해당하는 index값을 따로 분리하고 싶지 않은 경우  -------- pair<int, int>사용**  
  **절대값과 음수를 따로 따로 비교하고 싶은 경우 priority_queue cmp struct 생성 후 순위 부여**  
 
### Dinamic Programming 풀이
 >**DP 사용 문제의 경우 최솟값, 최댓값 찾는 문제가 대부분**  
 **사용할 수 있는 경우가 제한적이고 첫 번째 & 두 번째 인덱스값을 초기화해주는 경우가 많음**  
 **많은 문제를 풀어보면서 감을 익혀야 좋음**  
 
### DFS 와 BFS 탐색법
 >**DFS와 BFS 모두 Adjacent array 가 필요함**  
 **visited와 이중 벡터 map은 방문한 경우 1을 방문하지 않은 경우 0을 입력해서 코드를 짠다**  
 **한개의 줄을 한개씩 받는 코드 ---> scanf("%1d", &arr[i][j]);**  
 **int 말고 string으로 입력받을 경우 하나 하나 분리가 가능한 장점이 있음**  
 **미로에서 최소 경로 찾는 문제 --> 단순히 DFS를 사용하면 미로의 길 개수만 파악이 가능함**  
 **최소경로를 찾기 위해서 -> BackTrack + 1 해주는 같은 이중 배열이 필요하다.**  
 
 ### Math
 >**String 타입으로 입력을 받고 string[0] - '0' 을 하면 실제 숫자처럼 사용할 수 있음**  
 **String으로 숫자를 입력받을 경우 각각의 숫자를 활용하기 쉽다**  
 **cout.precision() 함수를 사용하면 표현하는 숫자의 범위를 지정할 수 있다**
 **cout<<fixed()를 사용할 경우 소수점 아래의 숫자 범위를 지정할 수 있다**
 
 ### DS
 >**Stack으로 괄호의 VPS 유무를 따지는 문제에서 Stack을 n 번 실행할 때마다 초기화 해줘야함**
 **for 문 안에서 stack<char> S를 선언한다**  
  
 ### TREE
 >**문자를 숫자로 바꾸기 위해서 root의 index 는 root - 'A' 를 통해서 숫자로 바꿔준다.**  
 **root_index = root - 'A' // root 문자를 index로 바꿔주는 작업**  
 **struct Node {}; 선언 -> Node *node; -> node[root_index].right = &node[right - 'A'] 주소할당**  
 **Tree에서 부모노드를 찾는 법**  
 **Adjecant array를 만들어서 DFS를 통해 parent를 하나씩 배열에 넣어준다.**  
 **vector<int> tree[MAX] // 이중 포인터를 통해서 (이중 벡터) 간접 배열을 만들어주고 BFS, DFS 한다**  
 
 ### Divide and Conquer(재귀함수를 이용한 규칙성)
 >**1. 제일 작은 패턴을 중심으로 논리식 하나를 완성한다.**  
 **2. 문제에서 원하는 N배 만큼 증가시킨 후 논리식에서 일정하게 바뀌는 값을 파악한다.**  

 
  
