# Training_Code

|문제유형|푼 문제 개수|백준 번호|
|-|-|-|
|Priority Queue|   2  |    |
|Dinamic Programming|   4   | 2839, 1463, 9095|
|DFS & BFS|   4   |1260, 2667, 10026, 11725, 2178|
|Math|   13   |1000, 1001, 10998, 10869, 1008, 2739, 10430, 8393, 1330, 10871, 10950, 2753, 2588, 11720, |
|Data Structure|   9   |10828, 9012, 1158, 10773, 1874, 1966, 2164, 11866, **3190**|
|Tree|   4   |1991, 11725, 1967, 1167, 5639|
|Divide and Conquer|   2   |2447, |
|Greedy Algorithm|   2   |2839, 11399, 11047, 1931|
|String|   3   |11720, 1152, 10809|

## Priority_Queue 사용법
**1. queue<pair<int,int>> q // priority_queue<int> pq의 사용으로 프린터 큐 알고리즘을 완성**  
  **2. 배열의 우선순위를 주고 싶은 경우 priority_queue에 pus------- 내림차순 자동 정렬**  
  **3. 해당 value에 해당하는 index값을 따로 분리하고 싶지 않은 경우  -------- pair<int, int>사용**  
  **4. 절대값과 음수를 따로 따로 비교하고 싶은 경우 priority_queue cmp struct 생성 후 순위 부여**  
  ```cpp
  queue<pair<int,int> > q;
  priority_queue<int> pq;

  queue<pair<int,int>> pi;
  priority_queue<pi, vector<pi>, greater<pi>> q;
  ```
 

---
## Dinamic Programming 풀이
 **1. DP 사용 문제의 경우 최솟값, 최댓값 찾는 문제가 대부분**  
 **2. 사용할 수 있는 경우가 제한적이고 첫 번째 & 두 번째 인덱스값을 초기화해주는 경우가 많음**  
 **3. 많은 문제를 풀어보면서 감을 익혀야 좋음**  
 ```cpp
  int num;
  cin >> num;

  vector<int> dp(num+1, MAX);
  dp[3] = 1;
  dp[5] = 1;

  for(int i = 6 ; i <= num ; i++) {
      dp[i] = min(dp[i-5] + 1, dp[i-3] + 1);
  }
 ```
 ```cpp
  vector<int> dp(num+4, 12);

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for(int j = 0 ; j < num ; j++) {
      scanf("%d", &number);
      for(int i = 4 ; i <=number ; i++) {
          dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
      }
      printf("%d\n", dp[number]);
  }
 ```
 
---
## DFS 와 BFS 탐색법
 **1. DFS와 BFS 모두 Adjacent array 가 필요함**  
 **2. visited와 이중 벡터 map은 방문한 경우 1을 방문하지 않은 경우 0을 입력해서 코드를 짠다**  
 **3. 한개의 줄을 한개씩 받는 코드 ---> scanf("%1d", &arr[i][j]);**  
 **4. int 말고 string으로 입력받을 경우 하나 하나 분리가 가능한 장점이 있음**  
 **5. 미로에서 최소 경로 찾는 문제 --> 단순히 DFS를 사용하면 미로의 길 개수만 파악이 가능함**  
 **6. 최소경로를 찾기 위해서 -> BackTrack + 1 해주는 같은 이중 배열이 필요하다.**  
```cpp
// visited 함수 초기화 및 arr 집 유무 확인
for(int i = 1 ; i <= num ; i++) {
    for(int j = 1 ; j <= num ; j++) {
        scanf("%1d", &arr[i][j]); // 숫자를 하나씩 입력받는 문법
        visited[i][j] = 0;
    }
}
```
```cpp
void BFS(int start, int end) {
    visited[start][end] = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(start, end));

    while(!q.empty()) {
        int X = q.front().second;
        int Y = q.front().first;
        q.pop();

        for(int i = 0 ; i < 4 ; i++) {
            int newX = X + dx[i];
            int newY = Y + dy[i];
            if(newX >= 0 && newX < M && newY >= 0 && newY < N && miro[newY][newX] == 1 &&
                visited[newY][newX] == 0 && check[newY][newX] == 0) {
                check[newY][newX] = check[Y][X] + 1;
                visited[newY][newX] = 1;
                q.push(make_pair(newY, newX));
            }
        }
    }
}
```
---
 ## Math
 **1. String 타입으로 입력을 받고 string[0] - '0' 을 하면 실제 숫자처럼 사용할 수 있음**  
 **2. String으로 숫자를 입력받을 경우 각각의 숫자를 활용하기 쉽다**  
 **3. cout.precision() 함수를 사용하면 표현하는 숫자의 범위를 지정할 수 있다**
 **4. cout<<fixed()를 사용할 경우 소수점 아래의 숫자 범위를 지정할 수 있다**

---
 ## Data Structure
 **1. Stack으로 괄호의 VPS 유무를 따지는 문제에서 Stack을 n 번 실행할 때마다 초기화 해줘야함**  
 **2. for 문 안에서 stack<char> S를 선언한다**  
 ```cpp
  //VPS 찾는 문제
    
      for(int j = 0 ; j < arr.length() ; j++) {
        if( Q.empty() || arr[j] == '(' ) {
            Q.push(arr[j]);
        }
        else if(Q.top() == '(') {
            Q.pop();
        } 

  }
 ```
**3-1. 3190번 Dummy 게임 문제에서 직접적으로 필요한 배열은 snake(dequeu), arr[i][j], visited[i][j], dx, dy**  
**3-2. pair<int, int> 로 선언하는 것은 vector 이거나 deque로 한다.**  
```cpp
 vector<pair<int, char>> movement;
 pair<int, int> tail;
 deque<pair<int,int>> snake;
 int arr[MAX][MAX] = {0,};
 bool visited[MAX][MAX] = {false,};
```
 
---
 ## TREE
 **1. 문자를 숫자로 바꾸기 위해서 root의 index 는 root - 'A' 를 통해서 숫자로 바꿔준다.**  
 **2. root_index = root - 'A' // root 문자를 index로 바꿔주는 작업**  
 **3. struct Node {}; 선언-> Node node; -> node[root_index].right = &node[right - 'A'] 주소할당**
 **4. Tree에서 부모노드를 찾는 법**  
 **5. Adjecant array를 만들어서 DFS를 통해 parent를 하나씩 배열에 넣어준다.**  
 **6. vector<int> tree[MAX] // 이중 포인터를 통해서 (이중 벡터) 간접 배열을 만들어주고 BFS, DFS 한다**  

---
 ## Divide and Conquer(재귀함수를 이용한 규칙성)
 **1. 제일 작은 패턴을 중심으로 논리식 하나를 완성한다.**  
 **2. 문제에서 원하는 N배 만큼 증가시킨 후 논리식에서 일정하게 바뀌는 값을 파악한다.**  

---
 ## Greedy 알고리즘
 **1. DP 문제와 유사하게 느껴질 수 있지만 조금 더 디테일한 알고리즘을 짠다고 생각함.**  
 **2. 최소 개수 문제는 DP 알고리즘에 비해 읽기 더 쉬운 코드를 작성할 수 있다.**  

---
## String 
 **1. string으로 숫자를 입력 받으면 실제 숫자로 사용하기 위해서는 - '0' 을 해줘야 한다.**  
 **2. 개행 문자 입력을 하기 위해서는 getline(cin, line)을 사용한다**  
 **3. isspace함수를 사용해서 공백을 인식한다**  
 **4. string.find("문자열", 찾을 문자열) 을 통해 해당 문자가 어느 index에 있는지 반환해주는 STL**  
 
 
  
